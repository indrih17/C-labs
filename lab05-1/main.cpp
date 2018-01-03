/**
    Calculate and display in a table the value of the function y(x)
    on the interval from x0 to xn with step dx.
    A, B, C, D, X, x0, xn, and dx are real numbers
    whose values are entered from the keyboard.
*/

#include <stdio.h>
#include <math.h>

int main() { 
    float A, B, C, D;
    printf("input A, B, C, D: ");
    scanf("%f%f%f%f", &A, &B, &C, &D);

    float x0, xn, dx;
    printf("input x0, xn, dx: ");
    scanf("%f%f%f", &x0, &xn, &dx);
    printf("+-----------+-----------+\n");
    printf("|     x     |     y     |\n");
    printf("+-----------+-----------+\n");

    for (float x = x0; x <= xn; x += dx) {
        float y;
        if (A > B + C) {
            y = (A - B - C) * x + D;
        } else {
            y = (A + B + C) * pow(x, 3) + D;
        }

        printf("| %9.3f | %9.3f |\n", x, y);
     }
    printf("+-----------+-----------+ \n");
    return 0;
}