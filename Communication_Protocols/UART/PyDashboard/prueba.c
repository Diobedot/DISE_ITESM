#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <windows.h>

uint8_t main(void){
    uint16_t count;
    for(count=0; count<=200; count++){
		  printf("\n%d", count);
          Sleep(10); 
	  }
      for(count; count>=1; count--){
		  printf("\n%d", count);
          Sleep(10); 
	  }
}