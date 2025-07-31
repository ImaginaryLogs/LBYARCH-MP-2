# LBYARCH-MP-2

![Static Badge](https://img.shields.io/badge/AY2425--T3-LBYARCH-red) 	![C](https://img.shields.io/badge/C-00599C?logo=c&logoColor=white) ![Static Badge](https://img.shields.io/badge/assembly-green)

A C and x86 assembly code that adds vectors together.

## Output

Screenshot of Output (with analytics and correction check):

<img width="648" height="777" alt="Kernel Testing (Both)" src="https://github.com/user-attachments/assets/07bc1acb-3b1e-4c5f-9c40-19a6b74ecc3e" />

## Architecture

```zsh
nasm -f win64 daxpy_asm.asm -o daxpy_asm.o
gcc -O2 -o daxpy.exe daxpy.c daxpy_asm.o -lm
daxpy.exe
```

### Assembly

Instrucitons used:

- `movsd` for loading double-precision values into XMM registers
- `mulsd` for scalar double-precision multiplication
- `addsd` for scalar double-precision addition
- `Loop` for repeating the instructions

## Analysis

| Vector Size           | Total C Version (seconds) | Avg. C Version (seconds)  | Total ASM Version (seconds) |  Avg. ASM Version (seconds)   |
|-----------------------|---------------------------|---------------------------|-----------------------------|-------------------------------|
| 2^20   (1,048,576)    |  0.041000                 |  0.001367                 |  0.042000                   | 0.001400                      |
| 2^24  (16,777,216)    |  0.628000                 |  0.020933                 |  0.670000                   | 0.022333                      |
| 2^28 (268,435,456)    | 24.084000                 |  0.802800                 | 27.329000                   | 0.910967                      |

A brief view of the screenshots and data show that the C version of the program generally runs faster than the Assembly equivalent, albeit often within a small marigin. The performance of both kernels were incredibly fast when the size of the vectors where within 2^20 and 2^20. But as it came closer to 20^30, the runtime for both version lengthened rapidly from less than a second to almost half a minute. Despite this, both programs execute properly and pass the correctness checks, with a margin of error of 1e-9 (0.000000001). The highest vector size was set to 2^28 as the runtime was drastically longer when it was 2^30 and consumed almost 8GB worth of memory to run.
