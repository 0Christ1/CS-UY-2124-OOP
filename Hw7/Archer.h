//
// Sagar Risal
// Header File for Archer
// Archer.h
//

#ifndef HW7_ARCHER_H
#define HW7_ARCHER_H

#include "Warrior.h"

namespace WarriorCraft {

    class Archer : public Warrior {
    public:
        Archer(const std::string &name, double strength);

    protected:
        void display() const override;
    };
}

#endif //HW7_ARCHER_H
