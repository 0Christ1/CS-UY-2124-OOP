//
// Sagar Risal
// Header File for PersonWithStrengthToFight
// PersonWithStrengthToFight.h
//

#ifndef HW7_PERSONWITHSTRENGTHTOFIGHT_H
#define HW7_PERSONWITHSTRENGTHTOFIGHT_H

#include "Noble.h"

namespace WarriorCraft {

    class PersonWithStrengthToFight : public Noble {
    public:
        PersonWithStrengthToFight(const std::string &name, double strength);

        double getStrength() const override;

        void setStrength(double reduced_portion) override;

        void battle(Noble &noble2) override;

        void display() const override;

    private:
        double strength;
    };

}

#endif //HW7_PERSONWITHSTRENGTHTOFIGHT_H
