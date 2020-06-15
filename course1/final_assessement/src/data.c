/**
 * @brief this file contains 2 functions my_itoa and my_atoi to convert 
 * int32_t to uint8_t ASCII string and viceversa.
 *
 *
 * @author Ahmed Amrani Akdi
 * @date 26/05/2020
 *
 */


#include "data.h"
#include "memory.h"

uint8_t my_itoa(uint32_t data, uint8_t * ptr, uint32_t base){
   
  //*ptr = '\0';

  if (data == 0) {
    *ptr = 48;
    *(ptr + 1) = '\0';
    return 2;
  }

  uint8_t length = 0;
  uint32_t rest;
  uint8_t neg = 0;

  if (data < 0) {
    neg = 1;
    data *= (-1);
  }

  // since we don't know how big the number is, we will extract the digits from right to
  // left, at the end we use my_reverse, to reverse the string
  while (data > 0) {
    rest = data % base;
    data = data / base;
    *(ptr + length) = rest + 48;
    length++;
  }

  if (neg == 1) {
    // we add '-' at the start
    *(ptr + length) = 45;
  }
  
  ptr = my_reverse(ptr, length);
    
  *(ptr + length) = '\0';
  return length + 1;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
  
  uint32_t num = 0;
  uint8_t neg = 0;
  // check for '-'
  if (*ptr == 45) {
    i++;
    neg = 1;
  }
  
  // for example '1','2','3','\0' & base = 10 -> digits = 3
  // i = 0 ::: num = 0*10 + 1 = 1
  // i = 1 ::: num = 1*10 + 2 = 12
  // i = 2 ::: num = 12*10 + 3 = 123
  uint8_t i = 0;
  for(i = 0; i < digits; i++){
    num = num*base + (*(ptr+i) -48);
  }
 
  if (neg == 1) {
    num = num * (-1);
  }
  
  return num;
}
