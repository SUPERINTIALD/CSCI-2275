#include "fundamentals_2.hpp"

char calcLetterGrade(double avg)
{
    char grade;

    if(avg >= 90){
        grade = 'A';
    } else if(avg>=80 && avg <= 89.9){
        grade = 'B';
    } else if (avg >= 70 && avg <= 79.9){
        grade = 'C';
    } else if (avg >= 60 && avg <= 69.9){
        grade = 'D';
    } else if (avg <= 60){
        grade = 'F';
    }
    
    return grade;
}

void addStudentData(studentData students[], string studentName, int homework, int recitation, int quiz, int exam, int index)
{
        students[index].studentName = studentName;
        students[index].homework = homework;
        students[index].recitation = recitation;
        students[index].quiz = quiz;
        students[index].exam = exam;
        students[index].average = (homework + recitation + quiz + exam) / 4.0;

}