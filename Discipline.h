//
// Created by Ivo Ribeiro on 15/03/2023.
//

#ifndef INC_1TESTEPA_DISCIPLINE_H
#define INC_1TESTEPA_DISCIPLINE_H


#include <string>
#include <list>
#include "Student.h"


class Discipline {
public:

    const std::string &getName() const;

    Discipline(std::string name, std::string code, int semester, int year);

    void DisplayOrder();

    bool constainsStudent(const Student &student) const;

    void addStudent(Student &student);

    const int &getSemester() const;

    const int &getYear() const;

    const std::string &getCode() const;


private:
    std::string name;
    std::string code;
    int semester;
    int year;
    std::list<Student *> students;

};

typedef std::list<Discipline> DisciplineList_t;

class DisciplineList {

public:

    void addStudentToDiscipline(Student &student, Discipline &discipline);

    void displayStudentsOfDiscipline(Discipline discipline);

private:
    DisciplineList_t list_of_discipline;
    std::list<Student *> students;


};

#endif //INC_1TESTEPA_DISCIPLINE_H
