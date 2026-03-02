#pragma once

#include <string>
#include "Gun.h"

class Soldier {
public:
    Soldier(std::string name);
    void addGun(Gun* ptr_gun);
    void addBulletToGun(int num);
    bool fire();
    ~Soldier();

private:
    std::string _name;
    Gun *_ptr_gun;
};
