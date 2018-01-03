/**
    Write a program for calculating the value of function given as series, with error E > 0.
    Meaning that for a given error E performed ratio |f(x)_{n} - f(x)_{n-1}| <= E. 
    To determine the number of members, compare the sum value with the feature value obtained by using
    the standard functions C++: atan(x)

    if x > 1: arctg(x) = Pi/2 + sum from n=0 to infinity: f_n(n, x)
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>

// (-1)^{n+1} / ((2*n+1) * x^{2*n+1})
float f_n(int n, int x) {
    int m = 2 * n + 1;
    int z = m * pow(x, m);

    if (n & 1 != 0) {
        return 1 / z;
    } else {
        return -1 / z;
    }
}

const float EPS = 0.001f;
int main() {
    float y, x;
    std::cout << "x = ";
    std::cin >> x;

    if (x > 1) {
        int n = 0;
        y = f_n(n, x) + M_PI / 2;
        do {
            y_0 = y;
            n++;
            y += f_n(n, x);
        } while (abs(y - y_0) > EPS);
        
        std::cout << "Result of iterative calculation: " << std::setw(9) << std::setprecision(5) << y << std::endl;
        std::cout << "Result of direct calculation: " << std::setw(9) << std::setprecision(5) << atan(x) << std::endl;
    }
    return 0;
}