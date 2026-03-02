#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
    public:
        Complex(double=1, double=1, double=2, double=3);
        void function();
        void setRealPart1(double);
        double getRealPart1();
        void setImaginaryPart1(double);
        double getImaginaryPart1();
        void setRealPart2(double);
        double getRealPart2();
        void setImaginaryPart2(double);
        double getImaginaryPart2();
    private:
        double realPart1;
        double imaginaryPart1;
        double realPart2;
        double imaginaryPart2;
};

#endif
