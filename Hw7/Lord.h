//
// Sagar Risal
// Header File for Lord
// Lord.h
//
#ifndef HW7_LORD_H
#define HW7_LORD_H

#include <string>
#include <vector>

#include "Noble.h"

namespace WarriorCraft {

    class Protector;

    class Lord : public Noble {
    public:
        // initialization
        explicit Lord(const std::string &name);

        // method to hire a protector which takes a reference to a Protector
        // and adds it to the vector of protector pointers
        bool hires(Protector &protector);

        // method to fire a warrior which takes a Lord's name
        // and deletes it to the vector of warrior pointers
        bool fire(Protector &protector);

        // helper method for fire with actual implementation
        bool fireHelper(Protector &protector);

        // setters and getters for strength
        double getStrength() const override;

        void setStrength(double reduced_portion) override;

        void battle(Noble &noble2) override;

        void display() const override;

    private:
        std::vector<Protector *> army;
    };

}

#endif //HW7_LORD_H
