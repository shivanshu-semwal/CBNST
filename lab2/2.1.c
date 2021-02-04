/*
Give the demonstration of the built-in C functions of following mathematical functions
    a. Sin x
    b. Cos x
    c. Tan x
    d. Cosec x
    e. Sec x
    f. Cot x
    g. Log 10 (x)
    h. Ln x
    i. Log 2 (x)
    j. e x
*/

#include <stdio.h>
#include <math.h>

#define PI 3.1415

int main(){
    float angle=((float)30/180)*(PI); // 30 degree
    printf("sin(%.2f) :: %.2f\n", angle, sin(angle));
    printf("cos(%.2f) :: %.2f\n", angle, cos(angle));
    printf("tan(%.2f) :: %.2f\n", angle, tan(angle));
    printf("cosec(%.2f) :: %.2f\n", angle, 1/sin(angle));
    printf("sec(%.2f) :: %.2f\n", angle, 1/cos(angle));
    printf("cot(%.2f) :: %.2f\n", angle, 1/tan(angle));

    angle = 2;
    printf("log_10(%.2f) :: %.2f\n", angle, log10f(angle));
    printf("ln(%.2f) :: %.2f\n", angle, logf(angle));
    printf("log_2(%.2f) :: %.2f\n", angle, log2f(angle));
    printf("e^x(%.2f) :: %.2f\n", angle, exp(angle));
}