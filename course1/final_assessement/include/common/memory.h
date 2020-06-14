/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Ahmed Amrani Akdi
 * @date 14/06/2020
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief moves a length of bytes from src to dst
 *
 * This function takes two byte pointers (one source and one destination) 
 * and a length of bytes to move from the source location to the destination. 
 *
 * @param src pointer to the length of bytes
 * @param dst pointer to the destination
 * @param length size_t length of the bytes
 *
 * @return dst pointer
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief copies length of byte pointed by src to dst
 *
 * This function takes two byte pointers (one source and one destination) 
 * and a length of bytes to copy from the source location to the destination.
 * The behavior is undefined if there is overlap of source and destination. 
 * Copy should still occur, but will likely corrupt your data.
 *
 * @param src pointer to the length of bytes
 * @param dst pointer to the destination
 * @param length size_t length of the bytes
 *
 * @return dst pointer
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief set all elements to value
 *
 * This should take a pointer to a source memory location, a length in bytes 
 * and set all locations of that memory to a given value.
 * if value = 0, then has the same functionality as my_memzero
 *
 * @param src Pointer to length of bytes
 * @param length size_t length of the bytes
 * @param value int value to set to
 *
 * @return src.
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief reverses the array pointed by src
 *
 * This should take a pointer to a memory location and a length in bytes 
 * and reverse the order of all of the bytes. 
 *
 * @param src Pointer to length of bytes
 * @param length size_t length of the bytes
 *
 * @return src.
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief for reserving a length of words, and for free memory pointed by src
 */
int32_t * reserve_words(size_t length);
void free_words(int32_t * src);

#endif /* __MEMORY_H__ */
