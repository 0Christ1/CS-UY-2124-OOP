#include <iostream>
#include "course.h"
#include "student.h"
using namespace std;

namespace reg{

    Course::Course(const string &courseName): name(courseName) {}

    size_t Course::find_studentInd(const Student& rhs) const {
        for(size_t i = 0; i < students.size(); ++i) {
            if (students[i] == &rhs) {
                return i;
            }
        }
        return students.size();
    }

    ostream& operator<<(ostream& os, const Course& rhs) {
        os << rhs.name << ": ";
        if (rhs.students.size() == 0) {
            os << "No Students";
            return os;
        } else {
            for (size_t i = 0; i < rhs.students.size(); ++i) {
                os << rhs.students[i]->getName() << ' ';
            }
            return os;
        }
    }

    const string &Course::getName() const {return name;}

    bool Course::addStudent(Student* rhs) {
        size_t stdInd = find_studentInd(*rhs);
        if (stdInd < students.size()) {
            cout << "student: " << rhs->getName() << " already exists." << endl;
            return false;
        }
        else {
            students.push_back(rhs);
            return true;
        }
    }

    bool Course::removeStudent(Student* rhs) {
        bool removed = false;
        for (size_t i = 0; i < students.size(); ++i) {
            if (!removed && rhs == students[i]) {
                students[i]->removedFromCourse(this);
                removed = true;
            } else if (removed) {
                students[i-1] = students[i];
            }
        }
        if (removed) {
            students.pop_back();
            return true;
        } else {
            return false;
        }
    }

    void Course::removeStudentsFromCourse() {
        for (size_t i = 0; i < students.size(); ++i) {
            students[i]->removedFromCourse(this);
        }
        students.clear();
    }
}

