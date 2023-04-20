//
// Created by Ivo Ribeiro on 15/03/2023.
//

#include "Grade.h"

Grade::Grade(float value, Student *student, Discipline *discipline) {
    this->value;
}

float Grade::getValue() const {
    return value;
}

Discipline *Grade::getDiscipline() const {
    return discipline;
}

Student *Grade::getStudent() const {
    return student;
}

int Grade::getYear() const {
    return year;
}

int Grade::getSemester() const {
    return semester;
}


float GradeList::getGradeAverage() const {
    float sum = 0.0;
    int count = 0;

    for (const auto &grade: list_of_grades) {
        sum += grade.getValue();
        ++count;
    }

    if (count == 0) {
        return 0.0;  // avoid division by zero
    }

    return sum / count;
}

std::vector<Grade *> Student::getGradesByYearSemester() const {
    std::vector<Grade *> sorted_grades;
    for (auto grade: grades) {
        if (grade.getStudent() == this) {
            sorted_grades.push_back(&grade);
        }
    }
    std::sort(sorted_grades.begin(), sorted_grades.end(),
              [](Grade *a, Grade *b) {
                  if (a->getYear() == b->getYear()) {
                      return a->getSemester() < b->getSemester();
                  } else {
                      return a->getYear() < b->getYear();
                  }
              });
    return sorted_grades;
}

