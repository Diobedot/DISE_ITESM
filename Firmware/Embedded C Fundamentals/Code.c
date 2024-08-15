//Mancilla Delgado Dionisio Alberto
//Embedded C Fundamentals Task
//Remember to comment each section of the code

 #include <stdio.h>
 int main()
 {
    printf("size of char is %d byte(s)\r\n",sizeof(char));
    printf("size of unsigned char is %d byte(s)\r\n",sizeof(unsigned char));
    printf("size of short is %d byte(s)\r\n",sizeof(short));
    printf("size of unsigned short is %d byte(s)\r\n",sizeof(unsigned short));
    printf("size of int is %d byte(s)\r\n",sizeof(int));
    printf("size of unsigned int is %d byte(s)\r\n",sizeof(unsigned int));
    printf("size of long is %d byte(s)\r\n",sizeof(long));
    printf("size of unsigned long is %d byte(s)\r\n",sizeof(unsigned long));
    printf("size of float is %d byte(s)\r\n",sizeof(float));
    printf("size of double is %d byte(s)\r\n",sizeof(double));
    printf("size of long long is %d byte(s)\r\n",sizeof(long long));
    printf("size of unsigned long long is %d byte(s)\r\n",sizeof(unsigned long long));
   return (0);
 }
 
 #include <stdio.h>
 int main()
 {
  int myvar_a = 1;
  int myvar_b = 7;
  int myvar_c = myvar_a + myvar_b;
  int myvar_d = myvar_a + myvar_b + myvar_c;
  /* printing C variable value */
  printf("Address of vars %p, %p, %p, %p\n", &myvar_a, &myvar_b,&myvar_c, &myvar_d);
  printf("The sum of a and b is %d", myvar_d);
  return (0);
 }

  #include <stdio.h>
 typedef unsigned char EMBuint8;
 typedef unsigned short EMBuint16;
 typedef unsigned int EMBuint32;
 typedef char EMBint8;
 typedef short EMBint16;
 typedef int EMBint32;
 int main()
 {
  printf("\n\r Size of EMBuint8 is %ld", sizeof(EMBuint8));
  printf("\n\r Size of EMBuint16 is %ld", sizeof(EMBuint16));
  printf("\n\r Size of EMBuint32 is %ld", sizeof(EMBuint32));
  
  printf("\n\r Size of EMBint8 is %ld", sizeof(EMBint8));
  printf("\n\r Size of EMBint16 is %ld", sizeof(EMBint16));
  printf("\n\r Size of EMBint32 is %ld", sizeof(EMBint32));
  return (0);
 }

#include <stdio.h>
#include <stdint.h>
 int main()
 {
   //uint32
  uint32_t myvar_a = 0xAAAAAAAA;
  uint32_t myvar_b = 0x11111111;
  uint32_t myvar_c = myvar_a + myvar_b;
  printf("The sum of a and b is %x\n", myvar_c);
  
  //uint16
  uint16_t myvar_a2 = 0xAAAA;
  uint16_t myvar_b2 = 0x1111;
  uint16_t myvar_c2 = myvar_a + myvar_b;
  printf("The sum of a and b is %x\n", myvar_c2);
  
  //uint8
  uint8_t myvar_a3 = 0xAA;
  uint8_t myvar_b3 = 0x11;
  uint8_t myvar_c3 = myvar_a + myvar_b;
  printf("The sum of a and b is %x\n", myvar_c3);
  return (0);
 }

#include <stdio.h>
 #define OPTION_1 /* Define the OPTION_1 control token */
 //#undef OPTION_1  /* Undefine the OPTION_1 control token */
 int counter0 = 0;
 #ifdef OPTION_1    /* include in the code if OPTION_1 is defined */
 int counter1 = 0;
 #endif
 int main() {
     int i;
     for(i=0; i<5 ;i++) {
     printf("counter 0 = %d\r\n", counter0++);
 #ifdef OPTION_1    /* include in the code if OPTION_1 is defined */
    printf("counter 1 = %d\r\n", counter1++);
 #endif
     }
    return(0);
 }

#include <stdio.h>
 #define SUMmac(a,b) (a + b)
 #define TIMESmac(a,b) ((a) * (b))
 int main()
 {
    int y, y1;
    y = 5 * SUMmac(4, 5) ;
    printf("y = %d\r\n", y);
    int offset = 5;
    y1 = 5 * TIMESmac(offset-1, offset+3) ;
    printf("y1 = %d\r\n", y1);
  return (0);
 }

 #include <stdio.h>
 #include <stdint.h>
 #define array_size 10
 int main()
 {
   uint32_t data_array_v1[array_size] = {0,1,2,3,4,5,6,7,8,9};
   for (uint8_t i=0; i<array_size; i++) {
        printf("ValueV1 is %lu\r\n", data_array_v1[i]);
    }
  return (0);
 }