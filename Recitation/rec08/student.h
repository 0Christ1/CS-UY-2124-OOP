#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <vector>

namespace reg{

    class Course;

    class Student{
        friend std::ostream& operator<<(std::ostream& os, const Student& rhs);

    public:
        Student(const std::string &name);

        const std::string& getName() const;

        bool addCourse(Course*);

        void dropCourse();

        void removedFromCourse(Course*);

        void setName(const std::string &name);

    private:
        size_t find_courseInd(const Course& rhs) const;
        std::string name;
        std::vector<Course*> courses;
    };
}

#endif //STUDENT_H

