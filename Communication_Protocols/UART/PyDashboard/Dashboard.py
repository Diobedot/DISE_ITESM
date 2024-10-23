
import tkinter as tk
import math
import serial
import threading

class RPMGauge(tk.Canvas):
    def __init__(self, parent, width=300, height=300, max_rpm=1000, bg_color="white", tick_color="black", **kwargs):
        super().__init__(parent, width=width, height=height, bg=bg_color, **kwargs)
        self.width = width
        self.height = height
        self.max_rpm = max_rpm
        self.bg_color = bg_color
        self.tick_color = tick_color
        self.rpm = 0
        self.center = (width // 2, height // 2)
        self.radius = min(width, height) // 2 - 20
        self.create_oval(20, 20, width-20, height-20, outline="black", width=2)
        self.draw_ticks()
        self.needle = None
        self.update_needle()

    def draw_ticks(self):
        for i in range(0, self.max_rpm + 1, 200):
            angle = math.radians(225 - (270 * i / self.max_rpm))
            x1 = self.center[0] + (self.radius - 20) * math.cos(angle)
            y1 = self.center[1] - (self.radius - 20) * math.sin(angle)
            x2 = self.center[0] + self.radius * math.cos(angle)
            y2 = self.center[1] - self.radius * math.sin(angle)
            self.create_line(x1, y1, x2, y2, fill=self.tick_color, width=2)
            label_x = self.center[0] + (self.radius - 40) * math.cos(angle)
            label_y = self.center[1] - (self.radius - 40) * math.sin(angle)
            self.create_text(label_x, label_y, text=str(i), font=("Arial", 10), fill=self.tick_color)

    def update_needle(self):
        if self.needle:
            self.delete(self.needle)
        angle = math.radians(225 - (270 * self.rpm / self.max_rpm))
        x = self.center[0] + (self.radius - 40) * math.cos(angle)
        y = self.center[1] - (self.radius - 40) * math.sin(angle)
        self.needle = self.create_line(self.center[0], self.center[1], x, y, fill="red", width=4)

    def set_rpm(self, rpm):
        self.rpm = min(max(rpm, 0), self.max_rpm)
        self.update_needle()

class DoorLockStatus(tk.Frame):
    def __init__(self, parent, **kwargs):
        super().__init__(parent, **kwargs)
        self.locked = True
        self.status_label = tk.Label(self, text="Doors Locked", font=("Arial", 16), bg="green", fg="white", width=20)
        self.status_label.pack(pady=10)

    def update_status(self, locked):
        self.locked = locked
        if self.locked:
            self.status_label.config(text="Doors Locked", bg="green")
        else:
            self.status_label.config(text="Doors Unlocked", bg="red")

class RPMApp(tk.Tk):
    def __init__(self, serial_port="COM5", baud_rate=9600):
        super().__init__()
        self.title("Car Instruments")
        self.geometry("400x500")

        self.gauge = RPMGauge(self, width=300, height=300, max_rpm=1000, bg_color="lightblue", tick_color="darkblue")
        self.gauge.pack(pady=20)

        self.door_lock_status = DoorLockStatus(self)
        self.door_lock_status.pack(pady=20)

        self.serial_port = serial.Serial(serial_port, baud_rate, timeout=1)
        self.after(100, self.read_serial_data)

    def read_serial_data(self):
        if self.serial_port.in_waiting > 0:
            try:
                data = self.serial_port.readline().decode('utf-8').strip()
                rpm, door_status = map(int, data.split(','))
                self.gauge.set_rpm(rpm)
                self.door_lock_status.update_status(door_status == 1)
            except ValueError:
                pass  # Ignore errors in case of corrupt data
        self.after(100, self.read_serial_data)

if __name__ == "__main__":
    # Replace '/dev/ttyUSB0' with your actual serial port (e.g., 'COM3' on Windows)
    app = RPMApp(serial_port='COM5', baud_rate=9600)
    app.mainloop()