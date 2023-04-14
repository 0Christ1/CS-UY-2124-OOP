/**
 * hw07: Medieval Battle 6.0
 * Haoran Chen
 * Protectors header: class fields and prototypes
 */

#ifndef PROTECTORS_H
#define PROTECTORS_H

#include <iostream>
#include "Noble.h"
#include "Protectors.h"

namespace WarriorCraft {

    class Protectors {
        // output overloading
        friend std::ostream& operator<<(std::ostream& os, const Protectors& rhs);
    public:
        Protectors(const std::string&, double);

        // getters
        const std::string& getName() const;
        const std::string& getBossName() const;
        Lord* getBoss() const;
        double getStrength() const;

        // setters
        void setBoss(Lord*);
        void setStrength(double);

        // pure virtual method
        virtual void defending() const = 0;

        // runaway method
        bool runaway();

    private:
        std::string name;
        double strength;
        Lord* boss;
    };

    // derived class of Protectors
    class Wizard : public Protectors {
    public:
        Wizard(const std::string&, double);
        void defending() const;
    };

    class Warriors : public Protectors {
    public:
        Warriors(const std::string&, double);
        void defending() const;
    };

    class Archer : public Warriors{
    public:
        Archer(const std::string&, double);
        void defending() const;
    };

    // derived class of Warriors
    class Swordsman : public Warriors {
    public:
        Swordsman(const std::string&, double);
        void defending() const;
    };
}

#endif //PROTECTORS_H
