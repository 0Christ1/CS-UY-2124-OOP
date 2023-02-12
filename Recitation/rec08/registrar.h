#ifndef REGISTRAR_H
#define REGISTRAR_H
#include <iostream>
#include <vector>

namespace reg {

    class Student;

    class Course;

    class Registrar {

        friend std::ostream& operator<<(std::ostream& os, const Registrar& rhs);

    public:
        Registrar();

        bool addCourse(const std::string & corName);

        bool addStudent(const std::string & stdName);

        bool enrollStudentInCourse(const std::string &studentName,
                                   const std::string &courseName);

        bool cancelCourse(const std::string &courseName);

        bool changeStudentName(const std::string& name, const std::string& newName);

        bool dropStudentFromCourse(const std::string &studentName,
                                              const std::string &courseName);

        bool removeStudent(const std::string& studentName);

        void purge();

    private:
        size_t findCourse(const std::string& corName) const;

        size_t findStudent(const std::string & stdName) const;

        std::vector<Course*> courses;

        std::vector<Student*> students;
    };
}



#endif //REGISTRAR_H
