//
// Created by Ivo Ribeiro on 15/03/2023.
//

#include <cmath>
#include <iostream>
#include <map>
#include "Grade.h"

Grade::Grade(float value, Student *student, Discipline *discipline) {
    this->value;
}

const ListOfGrades &GradeList::getListOfGrades() const {
    return list_of_grades;
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

void GradeList::addGrade(float value, Student *student, Discipline *discipline) {
    Grade grade(value, student, discipline);
    list_of_grades.push_back(grade);

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

void GradeList::displayClassGradesStatistics(const GradeList &gradeList) {

    //todo Create a map to hold the grades for each discipline
    std::map<Discipline*, std::vector<float>> gradesByDiscipline;

    //todo Iterate over all the grades in the list
    for (auto& grade : list_of_grades) {
        //todo Get the discipline for the grade
        Discipline* discipline = grade.getDiscipline();

        //todo Add the grade to the corresponding vector in the map
        gradesByDiscipline[discipline].push_back(grade.getValue());
    }

    //todo Iterate over the map to calculate statistics for each discipline
    for (auto& entry : gradesByDiscipline) {
        //todo Get the discipline and grades vector from the map entry
        Discipline* discipline = entry.first;
        std::vector<float>& grades = entry.second;

        //todo Calculate statistics for the grades
        float sum = 0;
        float min = grades[0];
        float max = grades[0];
        for (float grade : grades) {
            sum += grade;
            if (grade < min) {
                min = grade;
            }
            if (grade > max) {
                max = grade;
            }
        }
        float mean = sum / grades.size();
        float variance = 0;
        for (float grade : grades) {
            variance += std::pow(grade - mean, 2);
        }
        variance /= grades.size();
        float stddev = std::sqrt(variance);

        //todo Display the statistics for the discipline
        std::cout << "Discipline: " << discipline->getName() << std::endl;
        std::cout << "Number of grades: " << grades.size() << std::endl;
        std::cout << "Minimum grade: " << min << std::endl;
        std::cout << "Maximum grade: " << max << std::endl;
        std::cout << "Average grade: " << mean << std::endl;
        std::cout << "Standard deviation: " << stddev << std::endl;
        std::cout << std::endl;
    }
}

void GradeList::displayGradesStudent(const Student& student) const {
    std::cout << "Grades for student " << student.getName() << ":" << std::endl;

    for (const auto &grade : this->list_of_grades) {
        if (grade.getStudent() == &student) {
            std::cout << "Discipline: " << grade.getDiscipline()->getName() << std::endl;
            std::cout << "Year: " << grade.getYear() << "  Semester: " << grade.getSemester() << std::endl;
            std::cout << "Grade: " << grade.getValue() << std::endl << std::endl;
        }
    }
}

/*
    //todo Get the list of grades for the class
    const ListOfGrades &grades = gradeList.getListOfGrades();

    //todo Calculate min, max, and average
    float sum = 0.0;
    float minGrade = grades.front().getValue();
    float maxGrade = grades.front().getValue();
    for (const Grade &grade: grades) {
        float value = grade.getValue();
        sum += value;
        if (value < minGrade) {
            minGrade = value;
        }
        if (value > maxGrade) {
            maxGrade = value;
        }
    }
    float avgGrade = sum / grades.size();

    //todo Calculate standard deviation
    std::vector<float> deviations;
    for (const Grade &grade: grades) {
        float deviation = grade.getValue() - avgGrade;
        deviations.push_back(deviation);
    }
    float sumSquares = 0.0;
    for (const float &deviation: deviations) {
        sumSquares += pow(deviation, 2);
    }
    float stdDeviation = sqrt(sumSquares / deviations.size());

    //todo Sort the vector containing the intermediate results of the standard deviation
    std::sort(deviations.rbegin(), deviations.rend());

    //todo Display the results

    std::cout << "Class grades statistics:" << std::endl;
    std::cout << "  Minimum grade: " << minGrade << std::endl;
    std::cout << "  Maximum grade: " << maxGrade << std::endl;
    std::cout << "  Average grade: " << avgGrade << std::endl;
    std::cout << "  Standard deviation: " << stdDeviation << std::endl;
    std::cout << "  Grades from highest to lowest:" << std::endl;

    for (const float &deviation: deviations) {
        std::cout << "    " << avgGrade + deviation << std::endl;
    }

}
 */


