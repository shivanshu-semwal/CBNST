#include <stdio.h>
#include <math.h>

double f(double x) {
    return 6 * x * x + 11 * x - 35;
}

int main() {

    double c = 0, x0, x1;

    // calculating tolerance
    int noDigits=4;
    double t = 0.5 * pow(10.0, -noDigits); 
    
    x0 = 0;
    x1 = 1;

    // input range till valid range is found
    while (f(x0) * f(x1) > 0) {
        printf("Enter a valid range:: ");
        scanf("%lf %lf", &x0, &x1);
    }
    double x_prev = 0;
    while (1) {
        x_prev = c;
        c = (x0 + x1) / 2;
        if (f(c) == 0) {
            printf("Result is :: %lf", c);
            break;
        } else if (f(x0) * f(c) < 0) {
            x1 = c;
        } else {
            x0 = c;
        }
        if (c - x_prev <= t) {
            printf("Result is :: %lf  within %lf tolerance", c, t);
            break;
        }
    }
    return 0;
}