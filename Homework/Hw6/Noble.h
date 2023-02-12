/*
  hw06: Warriors' Battle 5.0
  Goal: focus on Cyclic Association and Separate Compilation
  Problem: We are revisiting the world of Nobles and Warriors,
           now adding one new feature: not only can warriors be fired,
           they can also run away.
  Created by Haoran Chen on 10/25/22.
 */

#ifndef NOBLE_H
#define NOBLE_H

#include <iostream>
#include <vector>

namespace WarriorCraft{
    class Warrior;
    class Noble {
        // output operator
        friend std::ostream& operator<<(std::ostream&, const Noble&);
    public:
        Noble(const std::string&);

        // get Noble's name
        const std::string& getName() const;

        // set new strength method
        void setNewStrength(double);

        // get total strength method
        double getTotalStrength() const;

        // battle method
        void battle(Noble&);

        // hire method
        bool hire(Warrior&);

        // fire method
        bool fire(Warrior&);

        // remove warrior
        bool removeWar(const Warrior& war);

    private:
        std::string name;
        std::vector<Warrior*> vec_war;
        bool alive;
    };
}

#endif //NOBLE_H
