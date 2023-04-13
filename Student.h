//
// Created by Ivo Ribeiro on 15/03/2023.
//

#ifndef INC_1TESTEPA_STUDENT_H
#define INC_1TESTEPA_STUDENT_H


#include <string>
#include <list>
#include <vector>



class Student {

public:

    Student(std::string name, std::uint32_t student_id);

    void setBirthDate(int day, int month, int year);

    //todo display student information by id.
    int displayStudent(int student_id);


    void display();

    int getStudentId() const;

    const std::string &getName() const;


    void addGrade(int grade);

    int getMinGrade() const;

    int getMaxGrade() const;

    double getAverageGrade() const;

    double getStandardDeviation() const;


    void getDisciplines();

    void displayGrades();

private:
    std::uint32_t student_id;
    std::string name;
    std::uint32_t birthDate;
    std::uint32_t email;

    std::vector<int> grades;
};

typedef std::list<Student> StudentList_t;

class StudentList {
public:

    //todo be able to insert/retrieve students (by Id).
    int insertStudent(Student &student);

    int retrieve(Student student);

    //todo display all students
    void displayAllStudents();


private:
    StudentList_t list_of_student;

};

#endif //INC_1TESTEPA_STUDENT_H
