#include <iostream>
#include <fstream>
#include "../code_2/fundamentals_2.hpp"
#include <sstream>
#include <string>

using namespace std;


// int getScore(string s, string delimiter, int pos){
    
//    std::istringstream ss(s);
//     std::string token;

//     while(std::getline(ss, token, ',')) {
//         std::cout << token << '\n';
//     }
// }

int main(int argc, char* argv[])
{
    string inFileName = argv[1];
    string outFileName = argv[2];
    string lowerBoundLetterGradeStr = argv[3];
    string upperBoundLetterGradeStr = argv[4];
    char lowerBoundLetterGrade = lowerBoundLetterGradeStr[0];
    char upperBoundLetterGrade = upperBoundLetterGradeStr[0];

    studentData students[100];

    string studentName;
    string homeworkStr;
    string recitationStr;
    string quizStr;
    string examStr;
    int homework;
    int recitation;
    int quiz;
    int exam;
    int length = 0;
    ifstream inputFile;
    inputFile.open(inFileName);
    string fileLine;

    if(inputFile.is_open()){
        while(getline(inputFile,fileLine,'\n')){
            std::istringstream ss(fileLine);
            std::getline(ss, studentName, ',');
            std::getline(ss, homeworkStr, ',');
            std::getline(ss, recitationStr, ',');
            std::getline(ss, quizStr, ',');
            std::getline(ss, examStr, ',');

            
            homework = std::stoi(homeworkStr);
            recitation = std::stoi(recitationStr);
            quiz = std::stoi(quizStr);            
            exam = std::stoi(examStr);

            addStudentData(students, studentName, homework, recitation, quiz, exam, length);
            // // cout << addStudentData << endl;
            length ++;
        }
    }
    else
    {
        cout << "Opening File Failed" << endl;
        return -1;
    }
    char grade;

    // Create and open a text file
    ofstream MyFile(outFileName);


    for (int i=0; i< length; i++){
        grade = calcLetterGrade(students[i].average);
        

        if (int(grade) <= int(lowerBoundLetterGrade) && int(grade) >= int(upperBoundLetterGrade)){
            cout << students[i].studentName << "," << students[i].average << "," << grade << endl;
            MyFile << students[i].studentName << "," << students[i].average << "," << grade << endl;
        }
    }
    // Close the file
    MyFile.close();

    return 0;
}