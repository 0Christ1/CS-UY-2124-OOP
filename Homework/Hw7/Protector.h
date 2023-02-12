//
// Sagar Risal
// Header File for Protector
// Protector.h
//
#ifndef HW7_PROTECTOR_H
#define HW7_PROTECTOR_H

#include <string>
#include "Lord.h"

namespace WarriorCraft {

// Parent class for Wizards and Warriors
    class Protector {
        // friend ostream& display(ostream& os) const;
    public:
        // returns name of warrior
        const std::string &getName() const;

        // returns strength of warrior
        double getStrength() const;

        // sets strength of warrior
        void setStrength(double new_strength);

        // returns false if not hired and true if hired
        bool isHired() const;

        // sets the hired status for warrior
        void setLord(Lord *newLord);

        // leaves the noble army
        bool runaway();

        // pure virtual display function
        virtual void display() const = 0;

    protected:
        // initialization
        Protector(const std::string &name, double strength);

        // fields
        std::string name;
        double strength;
        Lord *lord;
    };

}

#endif //HW7_PROTECTOR_H
