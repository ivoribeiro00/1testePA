#include <iostream>
#include <fstream>

#include "Student.h"
#include "Discipline.h"
#include "Grade.h"


int main() {
    StudentList studentList;
    DisciplineList disciplineList;
    GradeList gradeList;

    //todo region Students
    Student student1("Ivo José Bento Ribeiro", 11109322);
    Student student2("Afonso Gil Chorao Abreu Cunha", 11108821);
    Student student3("Breno Kiniane Faustino De Oliveira", 11094620);
    Student student4("David Pires Rita Dos Santos Coelho", 11037320);
    Student student5("Diogo Cabeleira De Freitas", 11028916);
    Student student6("Diogo Rafael Cleriguinho Simões", 11085620);
    Student student7("Guilherme Gonçalves Da Cruz Cabral", 11040620);
    Student student8("João Henrique Gonçalves Costa", 11084821);
    Student student9("João Martinez Conduto Aboim", 11102920);
    Student student10("João Morais Bagulho", 11005421);
    Student student11("João Pedro Gomes Alves De Almeida Costa", 11057718);
    Student student12("João Rafael Silva Angrola", 11050218);
    Student student13("Jorge Alexandre Gomes Madeira", 11012421);
    Student student14("Matheus Castro Maciel Lopes Marciano", 11011521);
    Student student15("Pedro Paulo Oom De Vasconcellos E Souza", 11001622);
    Student student16("Salvador Lacerda Folque De Gouveia", 11097121);
    Student student17("Tomas Madeira Carrasco Guilherme", 11094421);
    Student student18("Xavier Maria Marta De Barros", 11038021);

    //todo region Disciplines
    Discipline discipline1("Complementos de Analise Matematica", "L9011", 1, 2);
    Discipline discipline2("Fisica", "L9012", 1, 1);
    Discipline discipline3("Complementos de Programação", "L9013", 1, 1);
    Discipline discipline4("Algoritmos e Estruturas de Dados", "L9014", 1, 1);
    Discipline discipline5("Redes de Comunicação", "L9015", 1, 1);
    Discipline discipline6("Probabilidades e Estatistica", "L9016", 1, 2);
    Discipline discipline7("Base de Dados", "L9017", 1, 2);
    Discipline discipline8("Programacao Avancada", "L9018", 1, 2);
    Discipline discipline9("Computação e Representação Grafica", "L9019", 1, 2);
    Discipline discipline10("Historia da Cultura Portuguesa", "L9020", 1, 2);
    Discipline discipline11("Etica", "L9021", 1, 2);

    //todo insert students
    studentList.insertStudent(student2);
    studentList.insertStudent(student3);
    studentList.insertStudent(student1);
    studentList.insertStudent(student4);

    //todo display all students from the list
    studentList.displayAllStudents();

    //todo try to inser student1 again and display the result (error)
    studentList.insertStudent(student1);
    //todo retrieve student1 information
    studentList.retrieve(student1);

    //todo printf /n
    std::cout << std::endl;


    //todo add a student to a discipline
    disciplineList.addStudentToDiscipline(student1, discipline1);
    disciplineList.addStudentToDiscipline(student1, discipline5);
    disciplineList.addStudentToDiscipline(student2, discipline1);
    disciplineList.addStudentToDiscipline(student4, discipline1);
    disciplineList.addStudentToDiscipline(student3, discipline1);
    disciplineList.addStudentToDiscipline(student8, discipline1);
    disciplineList.addStudentToDiscipline(student15, discipline1);
    disciplineList.addStudentToDiscipline(student16, discipline1);
    disciplineList.addStudentToDiscipline(student14, discipline1);


    //todo display all students of a discipline ordered by name alphabetically
    disciplineList.displayStudentsOfDiscipline(discipline1);
    //printf /n
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    //get code of discipline and print it
    //std::cout << "Code of discipline: " << discipline1.getCode() << std::endl;

    //todo grades region

    //todo add grade to a student of a discipline
    gradeList.addGradeToStudentOfDiscipline(student1, discipline1, 10);
    gradeList.addGradeToStudentOfDiscipline(student2, discipline1, 12);
    gradeList.addGradeToStudentOfDiscipline(student1, discipline5, 15);
    //todo \n
    std::cout << std::endl;

    std::cout << " Testing error's: " << std::endl;
    //todo try to insert a grade to a student that is already in the discipline (error)
    gradeList.addGradeToStudentOfDiscipline(student1, discipline1, 11);
    //todo try to insert a grade to a student that is not in the discipline (error)
    gradeList.addGradeToStudentOfDiscipline(student1, discipline2, 12);

    //todo \n
    std::cout << std::endl;

    //todo display all grades of a discipline
    gradeList.displayGradesOfDiscipline(discipline1);

    //todo \n
    std::cout << std::endl;

    //todo display all grades of a student
    gradeList.displayGradesOfStudent(student1);

    //todo \n
    std::cout << std::endl;

    //todo display all grades of a student (ordered by year and semester)
    gradeList.displayGradesOfStudentOrderedByYearAndSemester(student1);

    //todo display minimum, maximum, average and standard deviation of all grades of a discipline
    gradeList.displayStatisticsOfDiscipline(discipline1);

    return 0;
}
