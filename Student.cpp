//
// Created by Ivo Ribeiro on 15/03/2023.
//

#include <iostream>
#include "Student.h"

Student::Student(std::string name, std::uint32_t student_id) {
    this->name = name;
    this->student_id = student_id;
}

void Student::setBirthDate(int day, int month, int year) {
    this->birthDate = day + month + year;
}


void Student::display() {
    std::cout << "ID: " << this->student_id << " Name: " << this->name << std::endl;

}

int Student::displayStudent(int student_id) {
    if (this->student_id == student_id) {
        this->display();
        return 0;
    }
    return -1;
}

int Student::getStudentId() const {
    return this->student_id;
}

const std::string &Student::getName() const {
    return name;
}




void StudentList::displayAllStudents() {
    for (auto &student: this->list_of_student) {
        student.display();
    }
}

int StudentList::retrieve(Student student) {
    for (auto &student_: this->list_of_student) {
        if (student_.getStudentId() == student.getStudentId()) {
            student.display();
            return 0;
        }
    }
    return -1;
}

int StudentList::insertStudent(Student &student) {
    //check if student already exists
    for (auto &student_: this->list_of_student) {
        if (student_.getStudentId() == student.getStudentId()) {
            //show error message with the student display
            std::cout << "Student: (" << student.getStudentId() << ") already exists" << std::endl;

            return -1;
        }
    }
    this->list_of_student.push_back(student);
    return 0;

}




