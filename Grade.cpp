//
// Created by Ivo Ribeiro on 15/03/2023.
//

#include "Grade.h"

Grade::Grade(const std::list<Discipline> &disciplines,
             const std::list<Student> &students,
             int grade) : disciplines(disciplines),
             students(students),
             grade(grade) {}
