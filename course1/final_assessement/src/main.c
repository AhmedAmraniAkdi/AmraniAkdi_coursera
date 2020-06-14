/**
 * @file main.c
 * @brief Main entry point to the final assessment
 *
 * This file contains the main code for the course final assessment, if compiled with compile time
 * switch -DCOURSE1, executes course1();
 *
 * @author Ahmed Amrani Akdi
 * @date 14/06/2020
 *
 */
#include "course1.h"

/* A pretty boring main file */
int main(void) {
  // compile time switch -DCOURSE1
  #ifdef COURSE1
  course1();
  #endif
}

