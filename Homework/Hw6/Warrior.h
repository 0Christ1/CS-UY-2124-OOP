/*
  hw06: Warriors' Battle 5.0
  Goal: focus on Cyclic Association and Separate Compilation
  Problem: We are revisiting the world of Nobles and Warriors,
           now adding one new feature: not only can warriors be fired,
           they can also run away.
  Created by Haoran Chen on 10/25/22.
 */

#ifndef WARRIOR_H
#define WARRIOR_H

#include <iostream>

namespace WarriorCraft {
    class Noble;

    class Warrior {
        // output operator
        friend std::ostream& operator<<(std::ostream&, const Warrior&);
    public:
        Warrior(const std::string&, double);
        // getters and setters
        const std::string& getName() const;
        double getStrength() const;
        bool isHired() const;
        void setHired(bool);
        void setStrength(double);
        void setBoss(Noble*);
        bool runaway();

    private:
        std::string name;
        double strength;
        bool hired;
        Noble* boss;
    };
}

#endif //WARRIOR_H
