#include <iostream>
#include "registrar.h"
#include "student.h"
#include "course.h"

using namespace std;

namespace reg {
    Registrar::Registrar() {}

    ostream& operator<<(ostream& os, const Registrar& rhs) {
        os << "Registrar's Report" << endl;
        os << "Courses: ";
        for (size_t i = 0; i < rhs.courses.size(); ++i) {
            os << endl << *rhs.courses[i];
        }
        os << endl << "Students: ";
        for (size_t i = 0; i < rhs.students.size(); ++i) {
            os << endl << *rhs.students[i];
        }
        os << '\n';
        return os;
    }

    bool Registrar::addCourse(const std::string & corName) {
        size_t corInd = findCourse(corName);
        if (corInd < courses.size()) {
            return false;
        } else {
            courses.push_back(new Course(corName));
            return true;
        }
    }

    bool Registrar::addStudent(const std::string & stdName) {
        size_t stdInd = findStudent(stdName);
        if (stdInd < students.size()){
            return false;
        } else {
            students.push_back(new Student(stdName));
            return true;
        }
    }

    bool Registrar::enrollStudentInCourse(const string &studentName,
                                          const string &courseName) {
        size_t stdInd = findStudent(studentName);
        size_t corInd = findCourse(courseName);
        if (stdInd == students.size()) {
            if (corInd == courses.size()) {
                cout << "student: " << studentName << " and " << "course: ";
                cout << courseName << "are both not exist.";
            }
            return false;
        }
        else if (corInd == courses.size()) {
            cout << "course: " << studentName << "didn't exist";
            return false;
        }
        else {
            bool addStudent = courses[corInd]->addStudent(students[stdInd]);
            bool addCourse = students[stdInd]->addCourse(courses[corInd]);
            return addCourse && addStudent;
        }
    }

    bool Registrar::cancelCourse(const std::string &courseName) {

        size_t corInd = findCourse(courseName);
        if (corInd == courses.size()) {
            cout << "course: " << courseName << " doesn't exist." << endl;
            return false;
        }
        courses[corInd]->removeStudentsFromCourse();
        delete courses[corInd];

        for (size_t i = corInd; i < courses.size()-1; i++) {
            courses[i] = courses[i+1];
        }
        courses.pop_back();
        return true;
    }

    bool Registrar::changeStudentName(const string& name, const string& newName){
        size_t stdInd = findStudent(name);
        if (stdInd == students.size()) {
            return false;
        }
        else {
            students[stdInd]->setName(newName);
            return true;
        }
    }

    bool Registrar::dropStudentFromCourse(const string &studentName,
                                          const string &courseName){

        size_t stdInd = findStudent(studentName);
        size_t corInd = findCourse(courseName);
        if (stdInd == students.size()) {
            if (corInd == courses.size()) {
                cout << "student: " << studentName << " and " << "course: ";
                cout << courseName << "are both not exist.";
            }
            return false;
        }
        else if (corInd == courses.size()) {
            cout << "course: " << studentName << "didn't exist";
            return false;
        }
        else {
            courses[corInd]->removeStudentsFromCourse();
            return true;
        }
    }

    bool Registrar::removeStudent(const std::string &studentName) {
        size_t stdInd = findStudent(studentName);

        if (stdInd == students.size()){
            cout << "student: " << studentName << "doesn't exist." << endl;
            return false;
        }
        else {
            students[stdInd]->dropCourse();
            return true;
        }
    }

    void Registrar::purge() {
        for (size_t i; i < students.size(); ++i) {
            delete students[i];
        }
        for (size_t i; i < courses.size(); ++i) {
            delete courses[i];
        }
        students.clear();
        courses.clear();
    }

    size_t Registrar::findCourse(const std::string& corName) const {
        for (size_t i = 0; i < courses.size(); ++i) {
            if (corName == courses[i]->getName()){
                return i;
            }
        }
        return courses.size();
    }

    size_t Registrar::findStudent(const std::string & stdName) const {
        for (size_t i = 0; i < students.size(); ++i) {
            if (stdName == students[i]->getName()) {
                return i;
            }
        }
        return students.size();
    }

}
