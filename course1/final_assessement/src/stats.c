/**
 * @file stats.h
 * @brief source code for statistical analysis functions.
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


//#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

/* find_maximum */
int find_maximum(unsigned int* ptr, int size){
  // give the first element to max
  int max = ptr[0];
  // i variable for the loop
  int i;
  for( i = 1 ; i < size ; i++){
    // we compare each element to the max, if it's bigger, then it becomes max
    if( max < ptr[i] )
      max = ptr[i];
  }
  return max;
}

/* find_minimum */
int find_minimum(unsigned int* ptr, int size){
  // give the first element to min
  int min = ptr[0];
  // i variable for the loop
  int i;
  for( i = 1 ; i < size ; i++){
    // we compare each element to the min, if it's smaller, then it becomes min
    if( min > ptr[i] )
      min = ptr[i];
  }
  return min;
}

/* find_mean */
float find_mean(unsigned int* ptr, int size){
  float sum = 0;
  // i variable for the loop
  int i;
  // we sum the elements of the array then we take the average
  for( i = 0 ; i < size ; i++){
    sum = sum + ptr[i];
  }
  return sum/size;
}

/* find_median */
float find_median(unsigned int* ptr, int size){
  float median;
  sort_array(ptr, size);
  // size%2 == 0 checks for parity
  if( size%2 == 0){
    // average of the two middle elements
    median = (float)(ptr[size/2]+ptr[size/2-1])/2;
  } else {
    median = ptr[size/2];
  }
  return median;
}

/* print_array */
void print_array(uint8_t* ptr, int size){
  // verbose flag, compile time switch, for printing the array
  #ifdef VERBOSE
  // i variable for the loop
  int i;
  PRINTF("\nThe array is:\n[");
  for( i = 0; i < size; i++){
    // %d because int
    PRINTF(" %d,", ptr[i]);
  }
  PRINTF("\b]");
  #endif
}

/* sort_array */
void sort_array(unsigned int* ptr, int size){
  // big stores the index of biggest element on each iteration
  int big;
  // temp is used for swapping elements
  int temp;
  // i and j variables for the loops
  int i, j;
  // i goes from 0 to size - 1, if there is only 1 element left, then that's it position
  for( i = 0; i < size - 1; i++){
    big = i;
    for(j = i + 1; j < size; j++){
      if ( ptr[j] > ptr[big] )
        big = j;
    }
    temp = ptr[i];
    ptr[i] = ptr[big];
    ptr[big] = temp;
  }
}

/* print_statistics */
void print_statistics(uint8_t* ptr, int size, float mean, float median, int min, int max){
  print_array(ptr, size);
  PRINTF("\nSize of the array: %d", size);
  PRINTF("\nMinimum value: %d", min);
  PRINTF("\nMaximum value: %d", max);
  PRINTF("\nMedian of the dataset: %f", median);
  PRINTF("\nMean of the dataset: %f", mean);
  PRINTF("\n");
}

/*
// Main:
void main() {
  // dataset
  unsigned int test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  
  // printing the array
  print_array(test, SIZE);
  
  // statistical variables
  int min, max;
  float median, mean;
  
  // statistical analysis:
  min = find_minimum(test, SIZE);
  max = find_maximum(test, SIZE);
  median = find_median(test, SIZE);
  mean = find_mean(test, SIZE);
  
  // print the calculated statistics
  print_statistics(test, SIZE, mean, median, min, max);
}*/
