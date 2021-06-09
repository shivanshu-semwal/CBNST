#include <math.h>
#include <stdio.h>

/* Defining the function for which the integral is to be calculated */
double f(double x) {
    return (1 / (1 + x * x));
}

int main() {

    int i, n;
    double x0, xn, h, y[20], so, se, ans, x[20];

    //  taking input
    printf("\nEnter values of x0(lower limit), xn(upper limit), h(height of each sub interval):\n");
    scanf("%lf%lf%lf", &x0, &xn, &h);

    // calculating the number of intervals
    n = (xn - x0) / h;
    if (n % 2 == 1) {
        n = n + 1;
    }
    h = (xn - x0) / n;

    printf("%lf interval size ~ %d intervals\n", h, n);
    printf("x\t\ty\n");

    for (i = 0; i <= n; i++) {
        x[i] = x0 + i * h;
        y[i] = f(x[i]);
        printf("%lf\t%lf\n", x[i], y[i]);
    }

    so = 0; //sum of add terms
    se = 0; //sum of even terms

    for (i = 1; i < n; i++) {
        if (i % 2 == 1) {
            so = so + y[i];
        } else {
            se = se + y[i];
        }
    }
    ans = (h / 3) * (y[0] + y[n] + 4 * so + 2 * se);

    printf("Value of the integral is:: %lf", ans);

    return 0;
}