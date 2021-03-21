#include <stdio.h>
#include <math.h>

double f(double x) {
    return 6 * x * x + 11 * x - 35;
}

double f0(double x) {
    return 12 * x + 11;
}

int main() {
    double xn, xn0;

    // calculating tolerance
    int noDigits = 4;
    double t = 0.5 * pow(10.0, -noDigits);

    // input
    printf("Enter initial approximation:: ");
    scanf("%lf", &xn);
    xn0 = xn;

    printf("x_i\t| f(x_i)\n");
    while (1) {
        xn = xn0 - (f(xn0) / f0(xn0));
        printf("%lf\t| %lf\n", xn, f(xn));
        if (f(xn) == 0) {
            printf("Result :: %lf", xn);
            break;
        } else if (fabs(xn0 - xn) < t) {
            printf("Result:: %lf within %lf tolerance.", xn, t);
            break;
        }
        xn0 = xn;
    }
    return 0;
}