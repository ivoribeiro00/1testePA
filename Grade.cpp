//
// Created by Ivo Ribeiro on 15/03/2023.
//

#include <cmath>
#include <iostream>
#include <map>
#include "Grade.h"

Grade::Grade(float value, Student *student, Discipline *discipline, int year, int semester) {
    this->value = value;
    this->student = student;
    this->discipline = discipline;
    this->year = year;
    this->semester = semester;
}

const ListOfGrades &GradeList::getListOfGrades() const {
    return list_of_grades;
}

void GradeList::addGradeToStudentOfDiscipline(Student &student, Discipline &discipline, int i) {

    //todo check if the student is enrolled in the discipline
    if (!discipline.constainsStudent(student)) {
        std::cout << "Student " << student.getName() << " is not enrolled in the discipline" << std::endl;
        //std::cout << "Student is not enrolled in the discipline" << std::endl;
        return;
    }

    //todo check if the student already has a grade in the discipline
    for (auto &grade: this->list_of_grades) {
        if (grade.getDiscipline()->getCode() == discipline.getCode() &&
            grade.getStudent()->getStudentId() == student.getStudentId()) {
            std::cout << "Student " << student.getName() << " already has a grade in this discipline" << std::endl;
            return;
        }
    }
    Grade grade(i, &student, &discipline, discipline.getYear(), discipline.getSemester());
    this->list_of_grades.push_back(grade);
    //print the grade has been added
    std::cout << "The Grade " << i << " has been added to student " << student.getName() << " in discipline "
              << discipline.getName() << std::endl;

}

void GradeList::displayGradesOfDiscipline(Discipline discipline) {

    //todo display the grades of a discipline in alphabetical order
    std::vector<Grade> grades;
    for (auto &grade: this->list_of_grades) {
        if (grade.getDiscipline()->getCode() == discipline.getCode()) {
            grades.push_back(grade);
        }
    }
    std::sort(grades.begin(), grades.end(),
              [](Grade a, Grade b) {
                  return a.getStudent()->getName() < b.getStudent()->getName();
              });
    std::cout << "Grades of discipline: " << discipline.getName() << std::endl;
    for (auto &grade: grades) {
        std::cout << grade.getStudent()->getName() << " " << grade.getValue() << std::endl;
    }

}

void GradeList::displayGradesOfStudent(Student student) {

    //todo display the grades of a student in alphabetical order
    std::vector<Grade> grades;
    for (auto &grade: this->list_of_grades) {
        if (grade.getStudent()->getStudentId() == student.getStudentId()) {
            grades.push_back(grade);
        }
    }
    std::sort(grades.begin(), grades.end(),
              [](Grade a, Grade b) {
                  return a.getDiscipline()->getName() < b.getDiscipline()->getName();
              });
    std::cout << "Grades of student: " << student.getName() << std::endl;
    for (auto &grade: grades) {
        std::cout << grade.getDiscipline()->getName() << " " << grade.getValue() << std::endl;
    }


}

void GradeList::displayGradesOfStudentOrderedByYearAndSemester(Student student) {

    //todo display the grades of a student ordered by year and semester
    std::vector<Grade> grades;
    for (auto &grade: this->list_of_grades) {
        if (grade.getStudent()->getStudentId() == student.getStudentId()) {
            grades.push_back(grade);
        }
    }
    std::sort(grades.begin(), grades.end(),
              [](Grade a, Grade b) {
                  if (a.getYear() == b.getYear()) {
                      return a.getSemester() < b.getSemester();
                  }
                  return a.getYear() < b.getYear();
              });

    std::cout << "All Grades of student: " << student.getName() << ", Ordered by Year and Semester" << std::endl;
    for (auto &grade: grades) {

        std::cout << grade.getDiscipline()->getName() << " year: " << grade.getYear() << " semester: " << grade.getSemester() << " grade: "
                  << grade.getValue() << std::endl;

    }


}

void GradeList::displayStatisticsOfDiscipline(Discipline discipline) {

    //todo display the statistics of a discipline
    std::vector<Grade> grades;
    for (auto &grade: this->list_of_grades) {
        if (grade.getDiscipline()->getCode() == discipline.getCode()) {
            grades.push_back(grade);
        }
    }
    std::sort(grades.begin(), grades.end(),
              [](Grade a, Grade b) {
                  return a.getValue() < b.getValue();
              });
    std::cout << std::endl;
    std::cout << "Statistics of discipline: " << discipline.getName() << std::endl;
    std::cout << "Min: " << grades[0].getValue() << std::endl;
    std::cout << "Max: " << grades[grades.size() - 1].getValue() << std::endl;
    float sum = 0;
    for (auto &grade: grades) {
        sum += grade.getValue();
    }
    std::cout << "Average: " << sum / grades.size() << std::endl;
    float variance = 0;
    for (auto &grade: grades) {
        variance += pow(grade.getValue() - sum / grades.size(), 2);
    }
    std::cout << "Variance: " << variance / grades.size() << std::endl;
    std::cout << "Standard Deviation: " << sqrt(variance / grades.size()) << std::endl;


}

float Grade::getValue() const {
    return value;
}

int Grade::getYear() const {
    return year;
}

int Grade::getSemester() const {
    return semester;
}

Student *Grade::getStudent() const {
    return student;
}

Discipline *Grade::getDiscipline() const {
    return discipline;
}



