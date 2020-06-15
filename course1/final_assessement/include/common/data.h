/**
 * @brief Header file for data.c
 * containts 2 functions for converting from ascii to int, and viceversa
 *
 *
 * @author Ahmed Amrani Akdi
 * @date 15/06/2020
 *
 */
#ifndef __DATA_H__
#define __DATA_H__
 
/**
 * Function : my_itoa
 * Description : converts integer to ascii string
 *
 * @param uint32_t data : integer to convert to string
 * @param uint8_t *ptr : pointer that will point to the start of the string
 * @param uint32_t base : base of integer 
 * 
 * @return uint8_t lenght : length of the resulting string
 */
 
uint8_t my_itoa(uint32_t data, uint8_t * ptr, uint32_t base)
 
/**
 * Function : my_atoi
 * Description : converts integer to ascii string
 *
 * @param uint8_t *ptr : pointer pointing to the start of the string
 * @param uint8_t digits: number of digits of the number
 * @param uint32_t base : base of integer 
 * 
 * @return uint32_t num: the resulting integer from converting the ascii string
 */
 
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)

#endif /* __DATA_H__ */
