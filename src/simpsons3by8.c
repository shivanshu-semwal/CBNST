#include <math.h>
#include <stdio.h>

double f(double x) {
    return (1 / (1 + x * x));
}

int main() {

    double lower, upper, integration = 0.0, stepSize, k;
    int i, subInterval;

    printf("Enter lower limit of integration: ");
    scanf("%lf", &lower);
    printf("Enter upper limit of integration: ");
    scanf("%lf", &upper);
    printf("Enter number of sub intervals: ");
    scanf("%d", &subInterval);

    if(subInterval % 3 != 0){
        printf("Number of subintervals should be multiple of 3.\n");
        return 1;
    }

    stepSize = (upper - lower) / subInterval;
    integration = f(lower) + f(upper);

    for (i = 1; i <= subInterval - 1; i++) {
        k = lower + i * stepSize;
        if (i % 3 == 0)
            integration = integration + 2 * f(k);
        else
            integration = integration + 3 * f(k);
    }
    integration = integration * stepSize * 3 / 8;

    printf("\nValue of the integral is:: %lf", integration);

    return 0;
}