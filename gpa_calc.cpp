/*******************************************************************************
** File Name:       gpa_calc.cpp
** Author:          Taha Zeeshan
** Description:     calculates gpa
*******************************************************************************/

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

void validNumber(int& number);
void validGrade(float& number);
void findHighest(float grades[], int n, string courses[]);
void findLowest(float grades[], int n, string courses[]);
void findAverage(float grades[], int n);

int main(){
    int numberOfGrades = 0;
    int i = 1;
    int x = 0;
    float grade;
    string *courses = nullptr;
    float *grades = nullptr;

    cout << "How many grades? ";
    validNumber(numberOfGrades);
    
    if(numberOfGrades == 0)
        cout << "No grades were entered";
    
    grades = new float[numberOfGrades];
    courses = new string[numberOfGrades];
    
    while(i <= numberOfGrades){
        cout << "Course " << i << ": ";
        getline(cin >> ws, courses[x]);
        cout << "Grade " << i << ": ";
        validGrade(grade);
        
        grades[x] = grade;
        i++;
        x++;
    }
    
    cout << endl;
    
    findHighest(grades, numberOfGrades, courses);
    findLowest(grades, numberOfGrades, courses);
    findAverage(grades, numberOfGrades);
    
    delete [] courses;
    delete [] grades;
    grades = 0;
    
    return 0;
}

//******************************************************************************
// Function Name: validNumber
// Parameters:   int
// Description:   only allows for valid numerical input for number of classes
//******************************************************************************

void validNumber(int& number){
    bool invalidResponse = true;

    while(invalidResponse){

        cin >> number;

        if(cin.fail()){
                cin.clear();
                cin.ignore();
        }
        else if (number >= 0){
            invalidResponse = false;
        }
        if (invalidResponse){
            cout << "\ninvalid input, enter a valid number: ";
        }
    }
}

//******************************************************************************
// Function Name: validGrade
// Parameters:   float
// Description:   only allows for valid input 1-5 for the grades
//******************************************************************************

void validGrade(float& number){
    bool invalidResponse = true;

    while(invalidResponse){

        cin >> number;

        if(cin.fail()){
                cin.clear();
                cin.ignore();
        }
        else if (number >= 0 && number < 6){
            invalidResponse = false;
        }
        if (invalidResponse){
            cout << "\ninvalid input, enter a valid number 0-5: ";
        }
    }
}

//******************************************************************************
// Function Name: findHighest
// Parameters:   float, int, string
// Description:   finds the highest grade that was entered and outputs which
//                class it was from along with the grade.
//******************************************************************************

void findHighest(float grades[], int n, string courses[]){
    int i;
    int y = 0;
    float max;
    int vals[y + 1];
    
    max = grades[0];

        for(i = 1; i < n; i++)
        {
            if(grades[i] > max)
                max = grades[i];
        }
    
        for(i = 0; i < n; i++)
        {
            if(grades[i] == max){
                vals[y] = i;
                y++;
            }
    }
    
        for (i = 0; i < y; i++){
            cout << courses[vals[i]] << " has the highest grade: " << grades[vals[i]] << endl;
        }

}

//******************************************************************************
// Function Name: findLowest
// Parameters:   float, int, string
// Description:   finds the lowest grade that was entered and outputs which
//                class it was from along with the grade.
//******************************************************************************

void findLowest(float grades[], int n, string courses[]){
    int i;
    int y = 0;
    float min;
    int vals[y + 1];
    
    min = grades[0];
    

        for(i = 1; i < n; i++)
        {
            if(grades[i] < min)
                min = grades[i];
        }
    
        for(i = 0; i < n; i++)
        {
            if(grades[i] == min){
                vals[y] = i;
                y++;
            }
    }
    
        for (i = 0; i < y; i++){
            cout << courses[vals[i]] << " has the lowest grade: " << grades[vals[i]] << endl;
        }

}

//******************************************************************************
// Function Name: findAverage
// Parameters:   float, int, string
// Description:   finds the average grade from all of them and tells you what
//                it is.
//******************************************************************************

void findAverage(float grades[], int n){
    int i = 0;
    float sum = 0;
    float averageGrade;
    
       for(i = 0; i < n; i++){
           sum += grades[i];
       }
    
       averageGrade = (float)sum / n;
    
        if(n > 0)
            cout << "The average grade is: " << averageGrade << endl;
    
}
