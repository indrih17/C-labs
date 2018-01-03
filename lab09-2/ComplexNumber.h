#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H 

struct ComplexNumber {
    int realPart;
    int imaginaryPart;
};

ComplexNumber createComplexNumber();
void print(ComplexNumber);
ComplexNumber multiplication(ComplexNumber, ComplexNumber);

#endif