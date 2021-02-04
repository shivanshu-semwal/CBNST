#include <stdio.h>
#include <stdlib.h>

int **to_lower(int n, int a[n][n]) {
    int **aa = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        *(aa + i) = malloc(sizeof(int) * n);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aa[i][j] = a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            aa[i][j] = 0;
        }
    }
    return aa;
}

int **to_upper(int n, int a[n][n]) {
    int **aa = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        *(aa + i) = malloc(sizeof(int) * n);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aa[i][j] = a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = n - i; j < n; j++) {
            aa[i][j] = 0;
        }
    }
    return aa;
}

void print_matrix(int **a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the dimension of matrix:: ");
    scanf("%d\n", &n);

    int a[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d ", &a[i][j]);
        }
    }
    int **aa = to_lower(n, a);
    int **bb = to_upper(n, a);
    printf("Input:: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    // print_matrix(a, n);
    printf("Upper:: \n");
    print_matrix(aa, n);
    printf("Lower:: \n");
    print_matrix(bb, n);
    return 0;
}