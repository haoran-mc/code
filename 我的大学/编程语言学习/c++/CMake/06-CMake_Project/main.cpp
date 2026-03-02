#include "Gun.h"
#include "Soldier.h"
#include <iostream>

void test() {
    Soldier soldier("xudanduo");
    soldier.addGun(new Gun("AK47"));
    soldier.addBulletToGun(20);
    soldier.fire();
}

int main() {
    std::cout << "This is a test string..." << std::endl;
    test();
    return 0;
}
