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

    Grade(float value, Student *student, Discipline *discipline, int year, int semester);

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
    const ListOfGrades &getListOfGrades() const;

    //addGrade
    void addGrade(float value, Student *student, Discipline *discipline);


    void addGradeToStudentOfDiscipline(Student &student, Discipline &discipline, int i);

    void displayGradesOfDiscipline(Discipline discipline);

    void displayGradesOfStudent(Student student);

    void displayGradesOfStudentOrderedByYearAndSemester(Student student);

    void displayStatisticsOfDiscipline(Discipline discipline);

private:
    ListOfGrades list_of_grades;
};


#endif //INC_1TESTEPA_GRADE_H
