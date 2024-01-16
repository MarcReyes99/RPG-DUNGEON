#pragma once
#include <string>


enum GearType { HATRED, BOOTS, POWDER, MUG, FEATHER, MUSHROOM_RED, FACEMASK, SHIELD, MUSHROOM_GREEN, BOOK };

struct Gears {
    GearType type;
    std::string name;
    int value;
    int hp;
    int stamina;
    int agility;
};