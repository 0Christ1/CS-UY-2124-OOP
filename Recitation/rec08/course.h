#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <vector>

namespace reg {

    class Student;

    class Course{
        friend std::ostream& operator<<(std::ostream& os, const Course& rhs);

    public:
        Course(const std::string &courseName);

        const std::string &getName() const;

        bool addStudent(Student* rhs);

        bool removeStudent(Student* rhs);

        void removeStudentsFromCourse();

    private:
        size_t find_studentInd(const Student& rhs) const;
        std::string name;
        std::vector<Student*> students;
    };
}

#endif //COURSE_H
