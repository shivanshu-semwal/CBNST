/* 
    Lagrange Interpolation
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of values availiable: ");
    scanf("%d", &n);

    double x[n];
    double y[n];
    // x is stored in row 1 and y in row 2

    printf("Enter the values [x y]:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    double x1;
    printf("Enter the value for x: ");
    scanf("%lf", &x1);

    double y1 = 0;

    for (int i = 0; i < n; i++) {
        double mul = 1;
        mul *= y[i];
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            if (mul == 0) break;
            mul *= (x1 - x[j]) / (x[i] - x[j]);
        }
        y1 += mul;
    }

    printf("Value of y is: %lf\n", y1);

    return 0;
}