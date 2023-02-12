//
// Sagar Risal
// Header File for Wizard
// Wizard.h
//

#ifndef HW7_WIZARD_H
#define HW7_WIZARD_H

#include "Protector.h"

namespace WarriorCraft {

    class Wizard : public Protector {

    public:
        Wizard(const std::string &name, double strength);

    protected:
        void display() const override;
    };
}

#endif //HW7_WIZARD_H
