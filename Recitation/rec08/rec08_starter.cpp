/*
 * Haoran Chen
  rec08_starter.cpp
  Starter Code for required functionality
  Yes, of course, you may add other methods.
  And no, this won't compile. You have to fix the cyclic association.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student;

class Registrar;

class Course {
    friend ostream& operator<<(ostream& os, const Course& rhs);
public:
    // Course methods needed by Registrar
    Course(const string& courseName);
    const string& getName() const;
    bool addStudent(Student*);
    void removeStudentsFromCourse();

private:
    size_t find_studentInd(const Student& rhs) const;
    string name;
    vector<Student*> students;
};

class Student {
    friend ostream& operator<<(ostream& os, const Student& rhs);
public:
    // Student methods needed by Registrar
    Student(const string& name);
    const string& getName() const;
    bool addCourse(Course*);

    // Student method needed by Course
    void removedFromCourse(Course*);



private:
    size_t find_courseInd(const Course& rhs) const;
    string name;
    vector<Course*> courses;
};

class Registrar {
    friend ostream& operator<<(ostream& os, const Registrar& rhs);
public:
    Registrar();
    bool addCourse(const string&);
    bool addStudent(const string&);
    bool enrollStudentInCourse(const string& studentName,
                               const string& courseName);
    bool cancelCourse(const string& courseName);
    void purge();

private:
    size_t findStudent(const string&) const;
    size_t findCourse(const string&) const;

    vector<Course*> courses;
    vector<Student*> students;
};

int main() {

    Registrar registrar;

    cout << "No courses or students added yet\n";
    cout << registrar << endl;
     
    cout << "AddCourse CS101.001\n";
    registrar.addCourse("CS101.001");
    cout << registrar << endl;

    cout << "AddStudent FritzTheCat\n";
    registrar.addStudent("FritzTheCat");
    cout << registrar << endl;

    cout << "AddCourse CS102.001\n";
    registrar.addCourse("CS102.001");
    cout << registrar << endl;

    cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
    cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
    cout << registrar << endl;

    cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
    cout << "Should fail, i.e. do nothing, "
         << "since Bullwinkle is not a student.\n";
    registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
    cout << registrar << endl;

    cout << "CancelCourse CS102.001\n";
    registrar.cancelCourse("CS102.001");
    cout << registrar << endl;
   
    /*
    // [OPTIONAL - do later if time]
    cout << "ChangeStudentName FritzTheCat MightyMouse\n";
    registrar.changeStudentName("FritzTheCat", "MightyMouse");
    cout << registrar << endl;  

    cout << "DropStudentFromCourse MightyMouse CS101.001\n";
    registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
    cout << registrar << endl;  

    cout << "RemoveStudent FritzTheCat\n";
    registrar.removeStudent("FritzTheCat");
    cout << registrar << endl;  
    */

    cout << "Purge for start of next semester\n";
    registrar.purge();
    cout << registrar << endl;
}


// Course constructor and methods
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

void Course::removeStudentsFromCourse() {
    for (size_t i = 0; i < students.size(); ++i) {
        students[i]->removedFromCourse(this);
    }
    students.clear();
}


//Student constructor or methods
ostream& operator<<(ostream& os, const Student& rhs){
    os << rhs.name << ": ";
    if (rhs.courses.size() == 0){
        os << "No courses" << endl;
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

Student::Student(const std::string &name) : name(name){}

const string &Student::getName() const {return name;}

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



// Registrar's constructor and methods
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