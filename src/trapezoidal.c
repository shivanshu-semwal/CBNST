/* 
    trapezoidal rule
*/

#include <stdio.h>
#include <stdlib.h>

double f(double x){
    return x*x;
}

int main(){
    double x_0, x_n, n;
    printf("Enter the lower limit: ");
    scanf("%lf", &x_0);
    printf("Enter the upper limit: ");
    scanf("%lf", &x_n);
    printf("Enter the no od partitions n: ");
    scanf("%lf", &n);
    
    double y=0;
    double h = (x_n - x_0)/n;

    for(int i=1;i<n;i++)
    return 0;
}