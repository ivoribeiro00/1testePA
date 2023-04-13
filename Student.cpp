//
// Created by Ivo Ribeiro on 15/03/2023.
//

#include <iostream>
#include <cmath>
#include "Student.h"
#include "Grade.h"

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
    //todo check if student already exists
    for (auto &student_: this->list_of_student) {
        if (student_.getStudentId() == student.getStudentId()) {
            //todo show error message with the student display
            std::cout << "Student: (" << student.getStudentId() << ") already exists" << std::endl;

            return -1;
        }
    }
    this->list_of_student.push_back(student);
    return 0;

}

void Student::addGrade(int grade) {
    grades.push_back(grade);
}

int Student::getMinGrade() const {
    if (grades.empty()) {
        return 0; // Return a default value if no grades exist
    }
    int minGrade = grades[0];
    for (int i = 1; i < grades.size(); ++i) {
        if (grades[i] < minGrade) {
            minGrade = grades[i];
        }
    }
    return minGrade;
}

int Student::getMaxGrade() const {
    if (grades.empty()) {
        return 0; // Return a default value if no grades exist
    }
    int maxGrade = grades[0];
    for (int i = 1; i < grades.size(); ++i) {
        if (grades[i] > maxGrade) {
            maxGrade = grades[i];
        }
    }
    return maxGrade;
}

double Student::getAverageGrade() const {
    if (grades.empty()) {
        return 0.0; // Return a default value if no grades exist
    }
    int sum = 0;
    for (int grade: grades) {
        sum += grade;
    }
    return static_cast<double>(sum) / grades.size();
}

double Student::getStandardDeviation() const {
    if (grades.empty()) {
        return 0.0; // Return a default value if no grades exist
    }
    double average = getAverageGrade();
    double sum = 0.0;
    for (int grade: grades) {
        sum += pow(grade - average, 2);
    }
    double variance = sum / grades.size();
    return sqrt(variance);
}

void Student::getDisciplines() {

    //todo get all the disciplines of the student
}

void Student::displayGrades() {

    //todo display all the grades of the student



}




