/*
---------------------------------------------------
Name: Bianca Murillo
Student ID: 
COP 1334 - Introduction to C++ Programming
Fall 2023 - T 5:30 PM - 8:50 PM
Assignment # 3
Plagiarism Statement
I certify that this assignment is my own work and that I have not
copied in part or whole or otherwise plagiarized the work of other
students, persons, Generative Pre-trained Generators (GPTs) or any other AI
tools. I understand that students involved in academic dishonesty will face
disciplinary sanctions in accordance with the College's Student Rights
and Responsibilities Handbook (https://www.mdc.edu/rightsandresponsibilities)
01234567890123456789012345678901234567890123456789012345678901234567890123456789
----------------------------------------------------------
*/
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  ifstream inputFile;
  float minTemp = 150, maxTemp = 0, avgTemp = 0, fileTemp;
  int minDay, maxDay,aboveAvgCount = 0;
  float totalTemp = 0, dayCount = 0 ;

  inputFile.open("October2023MiamiTemps.txt");

  if (!inputFile) {
    cout << "Is your file open?" << endl;
  } else {
    // read and process
    while (inputFile >> fileTemp) {
      // cout << dayCount << " " << fileTemp <<  endl;
      dayCount++;
      totalTemp += fileTemp;

      if (fileTemp < minTemp) {
        minTemp = fileTemp;
        minDay = dayCount;
      }

      if (fileTemp > maxTemp) {
        maxTemp = fileTemp;
        maxDay = dayCount;
      }
    }
    avgTemp = totalTemp / dayCount;
    inputFile.clear();
    inputFile.seekg(0);
    while (inputFile >> fileTemp) {
      if (fileTemp > avgTemp) {
        aboveAvgCount++;
      }
    }

    // cout << avgTemp;
    inputFile.close();

    ofstream outputFile;
    outputFile.open("October2023MiamiTemps.out");

    outputFile << showpoint;
    outputFile << setprecision(2) << fixed;
     
    outputFile << "Average Temperature: "<< avgTemp << "°F"<< endl;
    outputFile << "Maximum Temperature: " << maxTemp << "°F"<< " on Day "
               << noshowpoint << maxDay << endl;
    outputFile << "Minimum temperature: " << minTemp << "°F"<< " on Day "
               << noshowpoint << minDay << endl;
    outputFile << "Days above Average: " << noshowpoint<< aboveAvgCount
               << " days" << endl;

    outputFile.close();
  }
}