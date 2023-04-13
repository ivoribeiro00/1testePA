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

    Grade(float value, Student* student, Discipline* discipline);

    const Grade &getValue();

private:
    //std::list<Discipline*> disciplines;
    //std::list<Student*> students;
    float value;
    int year;
    int semester;

};

typedef std::list<Grade> ListOfGrades;

class GradeList{
public:
private:
    ListOfGrades list_of_grades;
};


#endif //INC_1TESTEPA_GRADE_H
