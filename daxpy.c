// daxpy.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <malloc.h> // For _aligned_malloc and _aligned_free on Windows

// Correct declaration — assembly expects pointer to a
extern void daxpy_asm(double* z, double* x, double* y, double* a, int n);

// Wrapper that converts double a → pointer &a
void daxpy_asm_bridge(double* z, double* x, double* y, double a, int n) {
    daxpy_asm(z, x, y, &a, n);
}

void daxpy_c(double* z, double* x, double* y, double a, int n) {
    for (int i = 0; i < n; i++) {
        z[i] = a * x[i] + y[i];
    }
}

void init_vectors(double* x, double* y, int n) {
    for (int i = 0; i < n; i++) {
        x[i] = rand() / (double)RAND_MAX;
        y[i] = rand() / (double)RAND_MAX;
    }
}

int check_correctness(double* z1, double* z2, int n) {
    for (int i = 0; i < n; i++) {
        if (fabs(z1[i] - z2[i]) > 1e-9) {
            return 0;
        }
    }
    return 1;
}

void print_first_ten(double* z) {
    for (int i = 0; i < 10; i++) {
        printf("z[%d] = %f\n", i, z[i]);
    }
}

void benchmark(void (*kernel)(double*, double*, double*, double, int), 
               const char* name, 
               double* z, double* x, double* y, double a, int n) {
    clock_t start, end;
    double total = 0.0;

    for (int i = 0; i < 30; i++) {
        start = clock();
        kernel(z, x, y, a, n);
        end = clock();
        total += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("%s average time over 30 runs (n=%d): %f seconds\n", name, n, total / 30);
}

int main() {
    int sizes[] = {1 << 20, 1 << 24, 1 << 28};
    double A = 2.0;

    for (int s = 0; s < 3; s++) {
        int n = sizes[s];
        printf("\nTesting size: %d\n", n);

        double *x = (double*)_aligned_malloc(n * sizeof(double), 16);
        double *y = (double*)_aligned_malloc(n * sizeof(double), 16);
        double *z_c = (double*)_aligned_malloc(n * sizeof(double), 16);
        double *z_asm = (double*)_aligned_malloc(n * sizeof(double), 16);

        if (!x || !y || !z_c || !z_asm) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        init_vectors(x, y, n);

        benchmark(daxpy_c, "C Version", z_c, x, y, A, n);
        benchmark(daxpy_asm_bridge, "ASM Version", z_asm, x, y, A, n);

        if (check_correctness(z_c, z_asm, n)) {
            printf("Correctness Check Passed!\n");
        } else {
            printf("Correctness Check Failed!\n");
        }

        printf("First 10 values of z:\n");
        print_first_ten(z_asm);

        _aligned_free(x);
        _aligned_free(y);
        _aligned_free(z_c);
        _aligned_free(z_asm);
    }

    return 0;
}
