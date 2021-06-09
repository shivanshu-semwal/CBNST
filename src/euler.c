#include <stdio.h>

float fun(float x, float y) {
    double f;
    f = x + y;
    return f;
}

main() {
    
    double a, b, x, y, h, t, k;
    
    printf("\nEnter x0,y0,h,xn: ");
    scanf("%lf %lf %lf %lf", &a, &b, &h, &t);
    
    x = a;
    y = b;

    printf("\n  x\t  y\n");
    while (x <= t) {
        k = h * fun(x, y);
        y = y + k;
        x = x + h;
        printf("%0.3f\t%0.3f\n", x, y);
    }

    return 0;
}