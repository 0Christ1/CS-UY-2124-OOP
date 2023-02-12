//
// Sagar Risal
// Header File for Noble
// Noble.h
//
#ifndef HW7_NOBLE_H
#define HW7_NOBLE_H
#include <string>

namespace WarriorCraft {

    class Noble {
    public:
        // returns name of noble
        const std::string &getName() const;

        // setter and getter for alive
        bool isAlive() const;

        void setAlive(bool new_alive);

        // helper method for battle, GETS total strength of army
        // pure virtual method
        virtual double getStrength() const = 0;

        // helper method for battle, SETS total strength of army
        // pure virtual method
        virtual void setStrength(double reduced_portion) = 0;

        // method that makes two nobles battle each other
        virtual void battle(Noble &noble2);

        // pure virtual method for display
        virtual void display() const = 0;

    protected:
        // constructor for noble
        explicit Noble(const std::string &name);

        // fields
        std::string name;
        bool alive;

    };

}

#endif //HW7_NOBLE_H
