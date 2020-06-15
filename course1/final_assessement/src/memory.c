/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Ahmed Amrani Akdi
 * @date 14/06/2020
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t* my_memmove(uint8_t* src, uint8_t* dst, size_t length){
  // we move first the bytes to a tmp location then we copy it to dst
  // this way, we handle the overlap
  uint8_t* t = (uint8_t*)malloc(length*sizeof(uint8_t));
  size_t i;
  // copy to t
  for(i = 0; i < length; i++){
     *(t+i) = *(src+i);
  }
  // move to dst
  for(i = 0; i < length; i++){
     *(dst+i) = *(t+i);
  }
  
  free(t);
  return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
  int i;
  for(i = 0; i < length; i++){
     *(dst+i) = *(src+i);
  }
  return dst;
}

uint8_t* my_memset(uint8_t * src, size_t length, uint8_t value){
  size_t i;
  for(i = 0; i < length; i++){
     *(src+i) = value;
  }
  return src;
}

uint8_t* my_memzero(uint8_t * src, size_t length){
  size_t i;
  for(i = 0; i < length; i++){
     *(src+i) = 0;
  }
  return src;
}

uint8_t* my_reverse(uint8_t* src, size_t length){
  // we move first the bytes to a tmp location then
  // we iterate starting from last item to first item and affecting the elements to
  // src
  uint8_t* t = (uint8_t*)malloc(length*sizeof(uint8_t));
  size_t i;
  // copy to t
  for(i = 0; i < length; i++){
     *(t+i) = *(src+i);
  }
  // move to src
  for(i = 0; i < length; i++){
     *(src+i) = *(t+length-i-1);
  }
  
  free(t);
  return src;
}

int32_t * reserve_words(size_t length){
  // allocates in memory length words and returns a pointer 
  int32_t *ptr = (int32_t*)malloc(length * sizeof(int32_t));
  /*if(ptr == NULL){
    ptr = NULL;
    return NULL;
  }*/
  return ptr;
}

void free_words(int32_t * src)
  // frees memory pointed by src;
  free(src);
}








