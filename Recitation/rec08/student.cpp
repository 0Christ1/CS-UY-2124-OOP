#include <iostream>
#include "student.h"
#include "course.h"
using namespace std;

namespace reg {

    Student::Student(const string &name) : name(name){}

    const string &Student::getName() const {return name;}

    void Student::setName(const string& newName) {Student::name = newName;}

    bool Student::addCourse(Course* rhs) {
        size_t corInd = find_courseInd(*rhs);
        if (corInd < courses.size()) {
            cout << "course: " << rhs->getName() << " already exists." << endl;
            return false;
        } else {
            courses.push_back(rhs);
            return true;
        }
    }

    void Student::dropCourse() {
        for (size_t i = 0; i < courses.size(); ++i) {
            courses[i]->removeStudent(this);
        }
    }

    void Student::removedFromCourse(Course* rhs) {
        for (size_t i = 0; i < courses.size(); ++i) {
            if (rhs == courses[i]) {
                for (size_t j = i; j < courses.size() - 1; ++j) {
                    courses[j] = courses[j + 1];
                }
                courses.pop_back();
                return;
            }
        }
    }

    ostream& operator<<(ostream& os, const Student& rhs){
        os << rhs.name << ": ";
        if (rhs.courses.size() == 0){
            os << "No courses";
            return os;
        } else {
            for (size_t i = 0; i < rhs.courses.size(); ++i) {
                os << rhs.courses[i]->getName() << ' ';
            }
            return os;
        }
    }

    size_t Student::find_courseInd(const Course& rhs) const {
        for (size_t i = 0; i < courses.size(); ++i) {
            if (courses[i] == &rhs) {
                return i;
            }
        }
        return courses.size();
    }
}

