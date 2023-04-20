//
// Created by Ivo Ribeiro on 15/03/2023.
//

#ifndef INC_1TESTEPA_GRADE_H
#define INC_1TESTEPA_GRADE_H


#include <list>
#include "Discipline.h"

class Grade {
    //eu preciso do codigo da disciplina
    //eu preciso do codigo do aluno
    //eu preciso da nota
public:

    Grade(float value, Student *student, Discipline *discipline);

    float getValue() const;

    Student *getStudent() const;

    Discipline *getDiscipline() const;


private:
    float value;
    Student *student;
    Discipline *discipline;
    int year;
    int semester;

public:
    int getYear() const;

    int getSemester() const;

};

typedef std::list<Grade> ListOfGrades;

class GradeList {
public:

    void addGrade(const Grade &grade);

    float getGradeAverage() const;

private:
    ListOfGrades list_of_grades;
};


#endif //INC_1TESTEPA_GRADE_H
