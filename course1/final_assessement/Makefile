#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

# EXAMPLES:
#  make build PLATFORM=HOST VERBOSE=VERBOSE COURSE=COURSE1
#------------------------------------------------------------------------------
# Update 15/06/2020 final assessement, changed variables to reflect the new structure of 
# folder, namely the paths
# and added course1.h and course1.c to sources.mk
# 
#
# Use: make [TARGET] [PLATFORM-OVERRIDES] [VERBOSE] [COURSE]
# Verbose : verbose cppflag for printing the array on data.c
# COURSE : course cppflag for COURSE1 final assessement test functions
#------------------------------------------------------------------------------
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      build: compile, link everything and create dependencies for the sources
#      clean: removes created files except source files
#      compile-all: compile all and generate object files from source files (do not link)
#      %i: generate the preprocessed output of all c-program implementation
#      %asm: generate assembly output of c-program implementation files and the final 
#          output executable
#      %o: generate the object file for all c-source files (but do not link)
#      %dep: generate the dependencies
#
# Platform Overrides:
#      PLATEFORM=HOST : build the executable to be run on Linux system using gcc compiler
#      PLATEFORM=MSP432: build the executable to be run on MSP432 target using arm-none-eabi-gcc compiler
#
# Author: Ahmed Amrani Akdi
# date: 02/06/2020
# references: 
# https://manned.org/arm-none-eabi-gcc/34fd6095
# https://manpages.debian.org/jessie/binutils-arm-none-eabi/arm-none-eabi-ld.1.en.html
# https://www.gnu.org/software/make/manual/html_node/Phony- ...
# 	Targets.html#:~:text=A%20phony%20target%20is%20one,name%2C%20and%20to%20improve%20performance.
# https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
# https://www.oreilly.com/library/view/managing-projects-with/0596006101/ ...
# 	ch01.html#:~:text=The%20prerequisites%20or%20dependents%20are, ...
# 	the%20target%20from%20the%20prerequisites.&text=The%20target%20file%20foo.o,The%20prerequisites%20foo.
# https://devhints.io/makefile
# https://www.thegeekstuff.com/2012/09/objdump-examples/
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM := HOST

# verbose for printing array 
VERBOSE = NOVERBOSE

# COURSE for course testing funtions
COURSE = NOCOURSE

# General flags for both platforms
FLAGS := -Wall \
	 -Werror \
	 -g \
	 -O0 \
	 -std=c99

TARGET := c1m3

# depending on platform, which command to execute
ifeq ($(PLATFORM), MSP432)
    # Architecture specific variables
    LINKER_FILE = -Xlinker -T msp432p401r.lds
    CPU = cortex-m4
    ARCH = armv7e-m
    SPECS = nosys.specs
    ARCH_FLAGS = -mthumb \
		 -mfloat-abi=hard \
		 -mfpu=fpv4-sp-d16

    # Compiler flags and defines
    # Compiler that will perform the build
    CC = arm-none-eabi-gcc 
    # the linker
    LD = arm-none-eabi-ld
    # C programming flags for gcc
    # flags for chosing architecture, etc.
    CFLAGS = $(FLAGS) $(ARCH_FLAGS) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS)
    # linker flags
    # when we invok ld indirectly we use -Wl, // -L for path, -T for file
    LDFLAGS = -Xlinker -Map=$(TARGET).map $(LINKER_FILE)
    # C preprocessor flags
    # -I flag adds directories to be searched for header files
    CPPFLAGS = -DMSP432 $(INCLUDES)

    # Architecture specific source files
    SRCS =   ./src/main.c \
	     ./src/memory.c \
	     ./src/data.c \
	     ./src/corse.c \
	     ./src/stats.c \
	     ./src/interrupts_msp432p401r_gcc.c \
	     ./src/startup_msp432p401r_gcc.c \
	     ./src/system_msp432p401r.c

    SIZE = arm-none-eabi-size
    OBJDMP = arm-none-eabi-objdump

else
    #Compiler flags and defines
    CC = gcc
    CFLAGS = $(FLAGS)
    CPPFLAGS = -DHOST $(INCLUDES) # -DVERBOSE -DCOURSE1
    LDFLAGS = -Wl,-Map=$(TARGET).map
    SIZE = size
    OBJDMP = objdump
    
    # Source files for the host
    SRCS =   ./src/main.c \
	     ./src/memory.c \
	     ./src/data.c \
	     ./src/course1.c \
	     ./src/stats.c

endif

ifeq ($(VERBOSE), VERBOSE)
    CPPFLAGS += -DVERBOSE
endif

ifeq ($(COURSE), COURSE1)
    CPPFLAGS += -DCOURSE1
endif

# using a list of source files to generate other variables
OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.dep)
ASMS := $(SRCS:.c=.asm)
PREP := $(SRCS:.c=.i)

# just checking
print-%  : ; @echo $* = $($*)

# Generate the object file for all c-source files (but do not link)
# $< first prerequisite, $@ target, % for pattern matching
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

# Generate assembly output of c-program implementation files and the final output executable
%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

%.asm: %.out
	$(OBJDMP) -D $< > $@

# generate the preprocessed output of all c-program implementation
%.i: %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

# generate the dependencies
%.dep: %.c
	$(CC) -E -M $< $(CPPFLAGS) -o $@

# compile all and generate object files from source files (do not link)
# phony protection, basically "it's the same as make %.o"
# phony proection for target names that aren't files names
.PHONY: compile-all
compile-all: $(OBJS)

# compile, link everything and create dependencies for the sources
# this way makefile build satisfies $deps and $target.out
.PHONY: build
build: $(DEPS) $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

# removes created files except source files
.PHONY: clean
clean: 
	rm -f $(OBJS) $(DEPS) $(ASMS) $(PREP) $(TARGET).out $(TARGET).map $(TARGET).asm
