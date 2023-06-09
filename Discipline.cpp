//
// Created by Ivo Ribeiro on 15/03/2023.
//

#include <iostream>
#include <vector>
#include <map>
#include "Discipline.h"


Discipline::Discipline(std::string name, std::string code, int semester, int year) {
    this->name = name;
    this->code = code;
    this->semester = semester;
    this->year = year;
}

const std::string &Discipline::getName() const {
    return name;
}

const int &Discipline::getSemester() const {
    return semester;
}

const int &Discipline::getYear() const {
    return year;
}

void Discipline::DisplayOrder() {

    //todo display the students of a discipline in alphabetical order
    std::vector<Student *> students;
    for (auto &student: this->students) {
        students.push_back(student);
    }
    std::sort(students.begin(), students.end(),
              [](Student *a, Student *b) {
                  return a->getName() < b->getName();
              });
    for (auto &student: students) {
        student->display();
    }

}

bool Discipline::constainsStudent(const Student &student) const {

    for (const auto &student_: this->students) {
        if (student_->getStudentId() == student.getStudentId()) {
            return true;
        }
    }
    return false;
}


void Discipline::addStudent(Student &student) {
    //todo check if the student is already enrolled in the discipline
    if (this->constainsStudent(student)) {
        std::cout << "Student already enrolled in discipline" << std::endl;
        return;
    }
    //todo add the student to the discipline
    this->students.push_back(&student);
    std::cout << "The student has been enrolled in the discipline." << std::endl;

}

const std::string &Discipline::getCode() const {
    return code;
}

void DisciplineList::displayStudentsOfDiscipline(Discipline discipline) {

    //todo display the students of a discipline
    discipline.DisplayOrder();

}

void DisciplineList::addStudentToDiscipline(Student &student, Discipline &discipline) {

    //todo check if the discipline already contains the student
    if (discipline.constainsStudent(student)) {
        std::cout << "Student already in discipline" << std::endl;
        return;
    }
    //todo add the student to the discipline
    discipline.addStudent(student);

}










