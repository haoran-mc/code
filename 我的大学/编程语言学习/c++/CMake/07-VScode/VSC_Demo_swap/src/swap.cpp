#include "swap.h"

void swap::run() {
    int tmp;
    tmp = _a;
    _a = _b;
    _b = tmp;
}

void swap::printInfo() {
    std::cout << "a = " << _a << std::endl;
    std::cout << "b = " << _b << std::endl;
}