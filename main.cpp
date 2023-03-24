#include <iostream>

#include "Student.h"
#include "Discipline.h"


int main() {
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

    Discipline discipline1("Complementos de Analise Matematica", "L9011", 1, 2);
    Discipline discipline2("Fisica", "L9012", 1, 1);
    Discipline discipline3("Complementos de Programação", "L9013", 1, 1);
    Discipline discipline4("Algoritmos e Estruturas de Dados", "L9014", 1, 1);
    Discipline disciplin5("Redes de Comunicação", "L9015", 1, 1);
    Discipline discipline6("Probabilidades e Estatistica", "L9016", 1, 2);
    Discipline discipline7("Base de Dados", "L9017", 1, 2);
    Discipline discipline8("Programacao Avancada", "L9018", 1, 2);
    Discipline discipline9("Computação e Representação Grafica", "L9019", 1, 2);
    Discipline discipline10("Historia da Cultura Portuguesa", "L9020", 1, 2);
    Discipline discipline11("Etica", "L9021", 1, 2);


    StudentList studentList;
    studentList.insertStudent(student2);
    studentList.insertStudent(student3);
    studentList.insertStudent(student1);
    studentList.displayAllStudents();

    studentList.insertStudent(student1);
    studentList.retrieve(student1);


    studentList.insertStudent(student4);

    //printf /n
    std::cout << std::endl;


    DisciplineList disciplineList;
    //add a student to a discipline
    disciplineList.addStudentToDiscipline(student1, discipline1);
    disciplineList.addStudentToDiscipline(student2, discipline1);
    disciplineList.addStudentToDiscipline(student15, discipline1);
    disciplineList.addStudentToDiscipline(student4, discipline1);
    disciplineList.addStudentToDiscipline(student3, discipline1);


    discipline1.displayStudentsOfDiscipline(discipline1);



    return 0;
}
