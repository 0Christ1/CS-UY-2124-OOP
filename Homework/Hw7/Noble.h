/**
 * hw07: Medieval Battle 6.0
 * Haoran Chen
 * Noble header: class fields and prototypes
 */

#ifndef NOBLE_H
#define NOBLE_H

#include <iostream>
#include <vector>

namespace WarriorCraft {

    // forward declaration
    class Protectors;

    class Noble {
        // output overloading
        friend std::ostream &operator<<(std::ostream &, const Noble &);

    public:
        Noble(const std::string &);

        // pure virtual methods
        virtual void battleCry() const = 0;

        virtual double getStrength() const = 0;

        virtual void setNewStrength(double) = 0;

        virtual void display() const = 0;

        // getter for Noble's Name
        const std::string& getNobleName() const;

        // battle method
        void battle(Noble &);

    protected:
        // only accessible for battle method and child class
        bool isAlived() const;

    private:
        std::string name;
        bool alive;
    };

    // derived class of Noble
    class Lord : public Noble{
    public:
        Lord(const std::string&);

        // battleCry method
        void battleCry() const;

        // get total strength method
        double getStrength() const;

        // set new strength method
        void setNewStrength(double);

        // hires method
        bool hires (Protectors&);

        // fires method
        bool fires (Protectors&);

        // remove protector method
        bool removePro(const Protectors&);

        // display method
        void display() const;

    private:
        std::vector<Protectors*> army;
    };

    // derived class of Noble
    class PersonWithStrengthToFight : public Noble{
    public:
        PersonWithStrengthToFight(const std::string&, double);
        // battleCry method
        void battleCry() const;

        // getter and setter
        double getStrength() const;
        void setNewStrength(double);

        // display method
        void display() const;

    private:
        double strength;
    };
}
#endif //NOBLE_H
