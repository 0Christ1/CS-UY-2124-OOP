/*
  rec06_start.cpp
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Section {

    friend ostream& operator<<(ostream& os, const Section& rhs);

public:
    Section(const string& in_name, const string& in_day, int in_time):
            name(in_name), time(in_day, in_time) {};

    void addStudent(const string& name) {
        records.push_back(new StudentRecord(name));
    }

    void addGrade(const string& student_name, int grade, size_t week) {
        for (size_t i = 0; i < records.size(); ++i) {
            if (records[i]->getName() == student_name) {
                records[i]->addGrade(grade, week);
                return;
            }
        }
    }

    ~Section() {
        cout << "\nSection " << name << " is being deleted" << endl;
        for (size_t i = 0; i < records.size(); ++i) {
            cout << "Deleting " << records[i]->getName() << endl;
            delete records[i];
        }
    }

    Section(const Section& old_rhs): name(old_rhs.name), time(old_rhs.time) {
        for (size_t i = 0; i < old_rhs.records.size(); ++i) {
            records.push_back(new StudentRecord(*old_rhs.records[i]));
        }
    }

private:

    class Timeslot{
        friend ostream& operator<<(ostream& os, const Timeslot &rhs){
            os << " [Day: " << rhs.day << ", Start time: ";
            int new_time = 0;
            if (rhs.time > 12) {
                new_time = rhs.time - 12;
                os << new_time << "pm],";
            } else if (rhs.time == 12) {
                os << rhs.time << "pm],";
            } else if (rhs.time < 12){
                os << rhs.time << "am],";
            }
            return os;
        }
    public:
        Timeslot(const string& in_day, int in_time) : day(in_day), time(in_time){}
    private:
        string day;
        int time;
    };

    class StudentRecord{
        friend ostream& operator<<(ostream& os, const StudentRecord& rhs){
            os << "Name: " << rhs.name << ", Grades: ";
            for (size_t i = 0; i < rhs.grades.size(); ++i) {
                os << rhs.grades[i] << ' ';
            }
            return os;
        }
    public:
        StudentRecord(const string& in_name) : name(in_name), grades(14, -1){}

        const string& getName() const {
            return name;
        }

        void addGrade(int grade, size_t week) {
            grades[week-1] = grade;
        }

    private:
        string name;    // student name
        vector<int> grades;
    };
    string name;        //section name
    Timeslot time;
    vector<StudentRecord*> records;
};

ostream& operator<<(ostream& os, const Section& rhs) {
    os << "Section: " << rhs.name << ", Time slot:" << rhs.time;
    if (rhs.records.size() == 0) {
        os << "Student: None";
    } else {
        os << " Student: ";
        for (size_t i = 0; i < rhs.records.size(); ++i) {
            os << endl << *(rhs.records[i]);    // rhs.records[i] is a pointer
        }
    }
    return os;
}


class LabWorker{
    friend ostream& operator<<(ostream& os, const LabWorker& rhs);
public:
    LabWorker(const string& in_name) : name(in_name), section(nullptr) {}

    void addSection (Section& rhs) {
        section = &rhs;
    }

    void addGrade(const string& student_name, int grade, size_t week) {
        section->addGrade(student_name, grade, week);
    }
private:
    string name;    // worker name
    Section* section;
};

ostream& operator<<(ostream& os, const LabWorker& rhs) {
    if (rhs.section == nullptr) {
        os << rhs.name << " does not have a section.";
    } else {
        os << rhs.name << " has Section: " << *rhs.section;
    }
    return os;
}


// Test code
void doNothing(Section sec) { cout << sec << endl; }

int main() {

    cout << "Test 1: Defining a section\n";
     Section secA2("A2", "Tuesday", 16);
     cout << secA2 << endl;

    cout << "\nTest 2: Adding students to a section\n";
     secA2.addStudent("John");
     secA2.addStudent("George");
     secA2.addStudent("Paul");
     secA2.addStudent("Ringo");
     cout << secA2 << endl;

    cout << "\nTest 3: Defining a lab worker.\n";
     LabWorker moe( "Moe" );
     cout << moe << endl;

    cout << "\nTest 4: Adding a section to a lab worker.\n";
     moe.addSection( secA2 );
     cout << moe << endl;

    cout << "\nTest 5: Adding a second section and lab worker.\n";
     LabWorker jane( "Jane" );
     Section secB3( "B3", "Thursday", 11 );
     secB3.addStudent("Thorin");
     secB3.addStudent("Dwalin");
     secB3.addStudent("Balin");
     secB3.addStudent("Kili");
     secB3.addStudent("Fili");
     secB3.addStudent("Dori");
     secB3.addStudent("Nori");
     secB3.addStudent("Ori");
     secB3.addStudent("Oin");
     secB3.addStudent("Gloin");
     secB3.addStudent("Bifur");
     secB3.addStudent("Bofur");
     secB3.addStudent("Bombur");
     jane.addSection( secB3 );
     cout << jane << endl;

    cout << "\nTest 6: Adding some grades for week one\n";
     moe.addGrade("John", 17, 1);
     moe.addGrade("Paul", 19, 1);
     moe.addGrade("George", 16, 1);
     moe.addGrade("Ringo", 7, 1);
     cout << moe << endl;

    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
     moe.addGrade("John", 15, 3);
     moe.addGrade("Paul", 20, 3);
     moe.addGrade("Ringo", 0, 3);
     moe.addGrade("George", 16, 3);
     cout << moe << endl;

    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
         << "those students (or rather their records?)\n";

    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
         << "then make sure the following call works:\n";
     doNothing(secA2);
     cout << "Back from doNothing\n\n";

} // main
