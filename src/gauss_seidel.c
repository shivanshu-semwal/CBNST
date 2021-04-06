#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    printf("Enter the dimensions:: ");
    scanf("%d", &n);
    double a[n][n + 1];

    // Input
    printf("Enter the matrix in form [A|B]: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    // Printing input matrix
    printf("\nInput Matrix:: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (j == n) printf(" | ");
            printf("%.2lf ", a[i][j]);
        }
        printf("\n");
    }

    /* Checking if matrix is suitable for gauss jacobi method */
    double sum_diagonal = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][i] == 0) {
            printf("\n Diagonal element 0 cannot apply gauss jacobi \n");
            return 0;
        }
        sum_diagonal += fabs(a[i][i]);
    }
    double sum_all = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum_all += fabs(a[i][j]);
        }
    }
    if (2 * sum_diagonal < sum_all) {
        printf("\nCannot apply gauss jacobi method..\n");
        return 0;
    }

    double *x = (double *)malloc(sizeof(double) * n);
    double *xp = (double *)malloc(sizeof(double) * n);
    memset(x, 0, n);
    memset(xp, 0, n);

    int no_of_digits = 4;
    double tol = 0.5 * pow(10, -no_of_digits);

    printf("\n=======================\n");
    for (int i = 0; i < n; i++) printf("x_%d||\t", i);
    printf("\n-----------------------\n");
    int flag = 0;

    int iteration = 0;

    while (flag != n) {
        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += a[i][j] * x[j];
            }
            for (int j = i + 1; j < n; j++) {
                sum += a[i][j] * xp[j];
            }
            x[i] = (a[i][n] - sum) / a[i][i];
        }
        for (int i = 0; i < n; i++) printf("%.4lf\t", x[i]);
        printf("\n");

        for (int i = 0; i < n; i++) {
            if (fabs(x[i] - xp[i]) < tol) flag++;
        }

        /* storing new x to px */
        double *tmp;
        tmp = x;
        x = xp;
        xp = tmp;

        // iteration++;
        // if (iteration == 15) {
        //     printf("\n Iteration exceeded \n");
        //     break;
        // }
    }
    printf("\n=======================\n");
    printf("Final result ..... \n");
    for (int i = 0; i < n; i++) {
        printf("x_%d = %.4lf\t", i, xp[i]);
    }
    free(xp);
    free(x);
    return 0;
}