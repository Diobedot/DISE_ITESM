//Mancilla Delgado Dionisio Alberto
//Data types, structures and unions

#include <stdio.h>
#include <stdint.h>


void PrintToBinary8(uint8_t);


int8_t main() {
    uint32_t i;
    uint8_t x_reg;
    /* Boolean and bit wise operations */
    /* Class example */
    //uint8_t a = 5 || (!3) && 6;
    //uint8_t b = (5 | (~3)) & 6;
    int a = 8 && (!10) || 14;
    int b = 8 & (~10) | 14;

    printf ("The a value is: %x ", a);
    PrintToBinary8(a);
    printf ("The a value is: %x ", b);
    PrintToBinary8(b);
 
/* End of main program */
    return(0);
}
void PrintToBinary8(uint8_t num) {
  for(int i=7;i>=0;i--){
    if (num & (1<<i))
        printf("1");
    else
        printf("0");
  }  
  printf("\n");
}

#include <stdio.h>
#include <stdint.h>


void PrintToBinary8(uint8_t);


int main() {
    uint32_t i;
    uint8_t x_reg;
    uint8_t mask;
       
    x_reg = 0x92;
    printf ("x_reg value before set operation is: %x ", x_reg);
    PrintToBinary8(x_reg);
    /* New x_reg value here */
    mask = (1<<5 | 1<<3);
    x_reg = x_reg | mask;
    printf ("x_reg value after  set operation is: %x ", x_reg);
    PrintToBinary8(x_reg);  
    /*Operation  - clear bit*/
    x_reg = 0x92;
    printf ("x_reg value before clear operation is: %x ", x_reg);
    PrintToBinary8(x_reg);
    /* New x_reg value here */
    mask = ~(1<<7 | 1<<1);
    x_reg = x_reg & mask;
    printf ("x_reg value after  clear operation is: %x ", x_reg);
    PrintToBinary8(x_reg); 
    /*Operation  - toggle bit*/
    x_reg = 0x92;
    printf ("x_reg value before toggle operation is: %x ", x_reg);
    PrintToBinary8(x_reg);
    /* New x_reg value here */
    mask = (1<<4 | 1<<0);
    x_reg = x_reg ^ mask;
    printf ("x_reg value after  toggle operation is: %x ", x_reg);
    PrintToBinary8(x_reg); 


/* End of main program */
    return(0);
}
void PrintToBinary8(uint8_t num) {
  for(int i=7;i>=0;i--){
    if (num & (1<<i))
        printf("1");
    else
        printf("0");
  }  
  printf("\n");
}

#include <stdio.h>
#include <stdint.h>
#define BITPOS0 (1 << 0)      /*0x01L*/
#define BITPOS1 (1 << 1)      /*0x02L*/
#define BITPOS2 (1 << 2)      /*0x04L*/
#define BITPOS3 (1 << 3)      /*0x08L*/
#define BITPOS4 (1 << 4)      /*0x10L*/
#define BITPOS5 (1 << 5)      /*0x20L*/
#define BITPOS6 (1 << 6)      /*0x40L*/
#define BITPOS7 (1 << 7)      /*0x80L*/
void PrintToBinary8(uint8_t);


int main() {
    uint32_t i;
    uint8_t x_reg;
    uint8_t mask;
    x_reg = 0x92;
    printf ("x_reg value before set operation is: %x ", x_reg);
    PrintToBinary8(x_reg);
    /* New x_reg value here */
    mask = (BITPOS5 | BITPOS3);
    x_reg = x_reg | mask;
    printf ("x_reg value after  set operation is: %x ", x_reg);
    PrintToBinary8(x_reg);  
    /*Operation  - clear bit*/
    x_reg = 0x92;
    printf ("x_reg value before clear operation is: %x ", x_reg);
    PrintToBinary8(x_reg);
    /* New x_reg value here */
    mask = ~(BITPOS7 | BITPOS1);
    x_reg = x_reg & mask;
    printf ("x_reg value after  clear operation is: %x ", x_reg);
    PrintToBinary8(x_reg); 
/* End of main program */
    return(0);
}
void PrintToBinary8(uint8_t num) {
  for(int i=7;i>=0;i--){
    if (num & (1<<i))
        printf("1");
    else
        printf("0");
  }  
  printf("\n");
}

//Example: Inserting and extracting bits (fields)

#include <stdio.h>
#include <stdint.h>

void PrintToBinary8(uint8_t);
void PrintToBinary16(uint16_t);
void PrintToBinary32(uint32_t);

int main() {
    uint32_t i;

    uint16_t time = 0x843;     /* hour: 5, minutes:6, seconds: 5 */
    uint16_t minutes = 0, seconds =0, hours =0;
    uint16_t TmpTime;
    uint16_t newmin = 4;
    /* extracting minutes */
    printf ("Current time is: %x \n", time);
    /* code here */
    seconds = time & 0x1F;
    printf ("Seconds are:     %f \n", (float) seconds/2);
    minutes = (time>>5) & 0x3F;
    printf ("Minutes are:     %d \n", minutes);
    hours = (time>>11) & 0x1F;
    printf ("hours are:     %d \n", hours);
    
    TmpTime = time & ~(0x3F<<5);  /* Clear old minutes */
    TmpTime = TmpTime | (newmin & 0x3F) << 5;  /* including new minutes */
    /* inserting new time */

    printf ("Old time is: %x \n", time);
    printf ("NEW time is: %x \n", TmpTime);
    /* code here */
    seconds = TmpTime & 0x1F;
    printf ("Seconds are:     %f \n", (float) seconds/2);
    minutes = (TmpTime>>5) & 0x3F;
    printf ("Minutes are:     %d \n", minutes);
    hours = (TmpTime>>11) & 0x1F;
    printf ("hours are:     %d \n", hours);
    //printf ("New minutes are: %x \n", minutes);
/* End of main program */
    return(0);
}
void PrintToBinary8(uint8_t num) {
  for(int i=7;i>=0;i--){
    if (num & (1<<i))
        printf("1");
    else
        printf("0");
  }  
  printf("\n");
}
void PrintToBinary16(uint16_t num) {
  for(int i=15;i>=0;i--){
    if (num & (1<<i))
        printf("1");
    else
        printf("0");
  }  
  printf("\n");
}
void PrintToBinary32(uint32_t num) {
  for(int i=31;i>=0;i--){
    if (num & (1<<i))
        printf("1");
    else
        printf("0");
  }  
  printf("\n");
}

#include <stdio.h>
#include <stdint.h>

uint8_t main(void){
  typedef union{
    uint16_t bb;
    uint8_t b[2];
  }ex_union;
  ex_union var;
  var.bb = 0xAABB;
  printf("%ld\n", sizeof(var));
  printf("%x\n", var.bb);
  printf("%x\n", var.b[0]);
  printf("%x\n", var.b[1]);
  return 0;
}

#include <stdio.h>
#include <stdint.h>


void PrintToBinary8(uint8_t);
void PrintToBinary16(uint16_t);
void PrintToBinary32(uint32_t);
int main() {
    uint32_t i;


    uint32_t time = 0x00009285, new_time = 0x00;     /* hour: 5, minutes:6, seconds: 5 */
    uint32_t minutes = 0, hours = 0, new_hour;
    uint32_t mask;
    /* extracting minutes */
    printf ("Current time is: %x \n", time);
    /* code here */
    mask = (0x3F);
    hours = (time>>12) & mask;
    printf ("Hours are:     %x \n", hours);
    minutes = (time>>6) & mask;
    printf ("Minutes are:     %d \n", minutes);
    new_hour = 0x0B;
    new_time = time & ~(0x3F<<12);
    new_time = time | (new_hour<<12);
    printf ("New hour is:     %d \n", new_hour);
    
/* End of main program */
    return(0);
}
void PrintToBinary8(uint8_t num) {
  for(int i=7;i>=0;i--){
    if (num & (1<<i))
        printf("1");
    else
        printf("0");
  }  
  printf("\n");
}
void PrintToBinary16(uint16_t num) {
  for(int i=15;i>=0;i--){
    if (num & (1<<i))
        printf("1");
    else
        printf("0");
  }  
  printf("\n");
}
void PrintToBinary32(uint32_t num) {
  for(int i=31;i>=0;i--){
    if (num & (1<<i))
        printf("1");
    else
        printf("0");
  }  
  printf("\n");
}



#include <stdio.h>
#include <stdint.h>

union qe4union {	
  uint32_t dd ;	
  uint16_t dw[2] ;	
  uint8_t  db[4] ;	
} ;	
int main(){
union qe4union var;
var.dd = 0xAABBCCDD;
printf("\n %x", sizeof(var)); 
printf("\n %x",var.dd );         
printf("\n %x",var.dw[1]);    
printf("\n %x",var.db[1]);      
return(0);
}



#include <stdio.h>
#include <stdint.h>

uint8_t main(void){
  typedef union{
    uint32_t reg;
    struct{
      uint32_t  seconds :6,
                minutes :6,
                hours   :6,
                        :14;
    }bits;
  }MY_TIME;
  MY_TIME time;
  uint32_t seconds = 0, minutes = 0, hours = 0, new_hour = 0;
  time.reg = 0x00009285;
  printf("Current time = %x\n", time.reg);
  seconds = time.bits.seconds;
  minutes = time.bits.minutes;
  hours = time.bits.hours;
  printf("Seconds = %d\n", seconds);
  printf("Minutes = %d\n", minutes);
  printf("Hours = %d\n", hours);
  new_hour = 0x0A;
  time.bits.hours = new_hour;
  printf("New Hour = %d", time.bits.hours);
  return 0;
}