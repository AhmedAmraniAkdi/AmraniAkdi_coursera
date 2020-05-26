/**
 * @file stats.h
 * @brief Header file for statistical analysis functions.
 *
 * This file contains the following statistical analysis functions:
 *
 * print_statistics - A function that prints the statistics of an array including 
 * minimum, maximum, mean, and median.
 *
 * print_array - Given an array of data and a length, prints the array to the screen
 *
 * find_median - Given an array of data and a length, returns the median value
 *
 * find_mean - Given an array of data and a length, returns the mean
 *
 * find_maximum - Given an array of data and a length, returns the maximum
 *
 * find_minimum - Given an array of data and a length, returns the minimum
 *
 * sort_array - Given an array of data and a length, sorts the array from largest to
 * smallest. (The zeroth Element should be the largest value, and the last element (n-1)
 * should be the smallest value. )
 *
 * @author Ahmed Amrani Akdi
 * @date 26/05/2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__
 
/**
 * Function : print_statistics
 * Description : accepts a pointer to the array of the dataset and its size
 * and prints all the statistical analysis of the dataset to the screen, namely, 
 * the medan, the mean, the maximum and the minimum.
 *
 * @param int *arr : Pointer to array containing the dataset.
 * @param int size : size of the array containing the dataset.
 * @param float mean : mean of the dataset.
 * @param float median : median of the dataset.
 * @param int min : minimum value of the dataset.
 * @param int max : maximum value of the dataset.
 */
 
 void print_statistics(int* arr, int size, float mean, float median, int min, int max);
 
/**
 * Function : print_array
 * Description : accepts a pointer to the array of the dataset and its size
 * and prints it to the screen.
 *
 * @param int *arr : Pointer to array containing the dataset.
 * @param int size : size of the array containing the dataset.
 */
 
 void print_array(int* arr, int size);
 
/**
 * Function : find_median
 * Description : accepts a pointer to the array of the dataset and its size
 * and returns the median element of the dataset.
 * Sorts first the array then takes the median :
 * If size is even then the median is the average of the two middle elements.
 * If size is odd then the median is the middle element.
 *
 * @param int *arr : Pointer to array containing the dataset.
 * @param int size : size of the array containing the dataset.
 *
 * @return float median : the median of the dataset.
 */
 
float find_median(int* arr, int size);
 
/**
 * Function : mean
 * Description : accepts a pointer to the array of the dataset and its size
 * and returns the mean value of the dataset.
 *
 * @param int *arr : Pointer to array containing the dataset.
 * @param int size : size of the array containing the dataset.
 *
 * @return float mean : the mean of the dataset.
 */
 
 float mean(int* arr, int size);
 
/**
 * Function : find_maximum
 * Description : accepts a pointer to the array of the dataset and its size
 * and returns the maximum value of the dataset.
 *
 * @param int *arr : Pointer to array containing the dataset.
 * @param int size : size of the array containing the dataset.
 *
 * @return int max : maximum value of the dataset.
 */
 
 int find_maximum(int* arr, int size);
 
/**
 * Function : find_minimum
 * Description : accepts a pointer to the array of the dataset and its size
 * and returns the minimum value of the dataset.
 *
 * @param int *arr : Pointer to array containing the dataset.
 * @param int size : size of the array containing the dataset.
 *
 * @return int min : minimum value of the dataset.
 */
 
 int find_minimum(int* arr, int size);
 
/**
 * Function : sort_array
 * Description : accepts a pointer to the array of the dataset and its size
 * and sorts it, the function uses selection sort algorithm.
 * Selection sort : we start find the biggest element of the array then we put it
 * in the first position (ptr[0]), now the unsortedarray to sort goes from 1 to size-1;
 * we apply the same logic, until the array is fully sorted.
 *
 * @param int *arr : Pointer to array containing the dataset.
 * @param int size : size of the array containing the dataset.
 */
 
 void sort_array(int* arr, int size);


#endif /* __STATS_H__ */
