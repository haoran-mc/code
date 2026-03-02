#include <cstdio>
#include "Complex.h" //类的复用

Complex::Complex(double a, double b, double x, double y):
    realPart1(a), imaginaryPart1(b), realPart2(x), imaginaryPart2(y) {

    }

void Complex::setRealPart1(double a) {
    realPart1 = a;
}

double Complex::getRealPart1() {
    return realPart1;
}

void Complex::setRealPart2(double x) {
    realPart2 = x;
}

double Complex::getRealPart2() {
    return realPart2;
}

void Complex::setImaginaryPart1(double b) {
    imaginaryPart1 = b;
}

double Complex::getImaginaryPart1() {
    return imaginaryPart1;
}

void Complex::setImaginaryPart2(double y) {
    imaginaryPart2 = y;
}

double Complex::getImaginaryPart2() {
    return imaginaryPart2;
}

void Complex::function() {
    printf("the first complex is (%lf, %lf)\n", realPart1, imaginaryPart1);
    printf("the second complex is (%lf, %lf)\n", realPart2, imaginaryPart2);
    printf("the D-value of two complex numbers is: (%lf, %lf)\n", realPart1-realPart2, imaginaryPart1-imaginaryPart2);
    printf("the sum of two complex numbers is: (%lf, %lf)\n", realPart1+realPart2, imaginaryPart1+imaginaryPart2);
}
