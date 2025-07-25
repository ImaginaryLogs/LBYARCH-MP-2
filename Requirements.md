# DAXPY (A*X + Y)

A C and x86 assembly code that adds vectors together.

Write the kernel in (1) C program and (2) an x86-64 assembly language. The kernel is to perform the DAXPY (A*X + Y) function.

## **Input**
Scalar variable n (integer) contains the length of the vector; scalar variable A is a double-precision float. Vectors X, Y, and Z are double-precision floats.

*Required to use functional scalar SIMD registers  
*Required to use functional scalar SIMD floating-point instructions

## **Process**
$Z[i] = A \cdot X[i] + Y[i]$

## **Example**

A --> 2.0  
x -> 1.0, 2.0, 3.0  
y -> 11.0, 12.0, 13.0  
(answer) z --> 13.0, 16.0, 19.0

## **Output** 
Store the result in vector Z. Display the result of the first ten elements of vector Z for all versions of the kernel (i.e., C and x86-64).

## Note

1. Write a C main program to call the kernels of the C version and the x86-64 assembly language.  
2. Time the kernel portion only.  
3. For each kernel version, time the process for vector size `n = {2^20, 2^24, 2^30}`.  
   If `2^30` is not possible, you may reduce it to `2^28` or `2^29`.  
4. You must run at least **30 times** for each version to get the average execution time.  
5. For the data, you may initialize each vector and scalar variable with the same or different random values.  
6. You will need to check the correctness of your output.  
   - If the C version is your "sanity check answer key," then the output of the x86-64 version has to be compared against it.  
7. Output in GitHub (make sure that I can access your GitHub):  
   a. GitHub README containing the following (debug and release mode; C and x86-64):  
      i. Comparative execution time and short analysis of the performance of the kernels  
      ii. Screenshot of the program output with the correctness check (C)  
      iii. Screenshot of the program output, including the correctness check (x86-64)  
      iv. Short videos (5–10 minutes) showing your source code, compilation, and execution of the C and x86-64 program  
   b. Visual Studio project folder containing complete files (source code: C, x86-64, and all other required files) for others to load and execute your program.

Rubric:

| C main program with initialization and correct call/passing parameters to C and x86-64 | 10 |
|----------------------------------------------------------------------------------------|:--:|
| Correct output (C version)                                                             | 10 |
| Correct output (x86-64)                                                                | 40 |
| Comparative result                                                                     | 20 |
| Analysis of result                                                                     | 10 |
| Short video                                                                            | 10 |
| Not following instructions                                                             | -10 per instruction |
|Note: No usage of functional scalar SIMD registers and scalar SIMD instructions         | grade = 0 |
