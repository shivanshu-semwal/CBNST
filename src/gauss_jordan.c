#include <stdio.h>
#include <stdlib.h>

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
    printf("Input Matrix:: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (j == n) printf(" | ");
            printf("%.2lf ", a[i][j]);
        }
        printf("\n");
    }
    // converting lower triangular matrix
    for (int i = 0; i < n; i++) {
        if (a[i][i] == 0) {
            for (int j = i + 1; j < n; j++) {
                if (a[j][i] != 0) {
                    for (int k = 0; k < n + 1; k++) {
                        double temp = a[i][k];
                        a[i][k] = a[j][k];
                        a[j][k] = temp;
                    }
                }
            }
        }
        if (a[i][i] == 0) {
            fprintf(stderr, "Given system of eq do not have a Unique Solution.");
            return 1;
        }
        // make the first element 1
        double temp = a[i][i];
        for (int j = i; j < n + 1; j++) {
            a[i][j] = a[i][j] / temp;
        }
        for (int j = i + 1; j < n; j++) {
            if (a[j][i] != 0) {
                double div = a[j][i] / a[i][i];
                for (int k = i; k < n + 1; k++) {
                    a[j][k] = a[j][k] - a[i][k] * div;
                }
            }
        }
    }
    printf("Upper Triangular:: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (j == n) printf(" | ");
            printf("%.2lf ", a[i][j]);
        }
        printf("\n");
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            // R_j <- R_j - (a[j][i] / a[i][i]) * R_i
            double div = a[j][i] / a[i][i];
            for (int k = 0; k < n + 1; k++) {
                a[j][k] = a[j][k] - div * a[i][k];
            }
        }
    }
    printf("Diagonal :: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (j == n) printf(" | ");
            printf("%.2lf ", a[i][j]);
        }
        printf("\n");
    }
    double x[n]; // array to store solutions
    for (int i = 0; i < n; i++) {
        x[i] = a[i][n];
    }
    printf("Solutions: \n");
    for (int i = 0; i < n; i++) {
        printf("x_%d = %lf\n", i, x[i]);
    }
    return 0;
}