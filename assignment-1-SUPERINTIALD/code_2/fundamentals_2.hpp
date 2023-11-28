#ifndef READFILE2_H__
#define READFILE2_H__

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct studentData {
    string studentName;
    int homework;
    int recitation;
    int quiz;
    int exam;
    double average;
};

// TODO add detailed explanation on what the function should do
/* 
This function needs to get the data from the file, students.csv, and then separate it from the commas to get each value
corresponding to each parameter. Once it gets the data from homework, recitation, quiz, and exam, it will calculate the average.
The calcLetterGrade gets the input from the addStudentData's average and then calculates the grade with if else statements.
This then prints out which letter grade the average corresponds to. 
*/
void addStudentData(studentData students[], string studentName, int homework, int recitation, int quiz, int exam, int length);
char calcLetterGrade(double avg);


#endif // READFILE2_H__