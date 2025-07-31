#!/bin/bash
nasm -f win64 daxpy_asm.asm -o daxpy_asm.o
gcc -O2 -o daxpy.exe daxpy.c daxpy_asm.o -lm
daxpy.exe