#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Definion:: int parseExpr(char *a, int *coeff, int *degree){}
    Parses a expression in form ax^b, and set the coeff to a and degree to b respectively
    returns:: 0 - successful parsing, -1 - unsuccessful parsing
*/
int parseExpr(char *a, int *coeff, int *degree) {
    int i;
    int x_flag = 0;
    int d_flag = 0;

    int temp = 0;
    for (i = 0; i < strlen(a); i++) {
        if (a[i] == 'x') {
            if (i == 0) // first letter is x so coeff should be 1
                temp = 1;
            x_flag = 1;
            if (i != strlen(a) - 1 && a[i + 1] == '^') {
                d_flag = 1;
                i++;
            }
            i++;
            break;
        }
        temp = temp * 10 + (a[i] - '0');
    }
    *coeff = temp;

    temp = 0;
    if (d_flag) {
        for (; i < strlen(a); i++) {
            temp = temp * 10 + (a[i] - '0');
        }
        *degree = temp;
        return 0; //
    } else if (x_flag) {
        *degree = 1;
        return 0; //
    } else {
        *degree = 0;
        return 0; //
    }
}

int main() {

    // initializing array to store expression
    char a[1000];
    int i;
    printf("Enter the expression:: ");
    scanf("%s", a);

    // removing spaces
    char b[1000];
    for (i = 0; i <= strlen(a); i++) {
        if (a[i] == ' ')
            continue;
        b[i] = a[i];
    }

    int coeff[100];  //storing coeff
    int degree[100]; //storing degrees
    int n = strlen(b);
    int count = 0;

    int start = 0;
    for (i = 0; i < n; i++) {
        if (b[i] == '+' || b[i] == '-' || b[i] == '=') {
            char *expr = (char *)malloc(sizeof(char) * (i - start));
            int k = 0;
            for (int j = start; j < i; j++)
                expr[k++] = b[j];
            expr[k] = '\0';

            int deg, cof;
            if (parseExpr(expr, &cof, &deg) == 0) {
                coeff[count] = cof;
                degree[count] = deg;
                count++;
            }
            free(expr);
            start = i + 1;
            if (b[i] == '=')
                break;
        }
    }

    for (i = 0; i < count; i++) {
        printf("deg:: %d coeff:: %d\n", degree[i], coeff[i]);
    }

    return 0;
}