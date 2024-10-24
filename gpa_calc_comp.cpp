// gpa_calc_comp.cpp
// Taha Zeeshan

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//function prototypes
void programGreeting();
void mainMenu();
void optionFunction(int& option);
void validScore(float& score);
void printScores(float grades[], int gradeCount);
string calculateGrade(int score);
void calculateGpa(float grades[], int gradeCount);
void unitTest();

class date{
    int month; // variable for month
    int day;   // variable for day
    int year;  //variable for year
public:
    void setVal(int, int, int);
    void selfTest();
};

//date class function to set values and print date
void date::setVal(int x, int y, int z){
    month = x;
    day = y;
    year = z;
    
    //prints date
    cout << month << "/" << day << "/" << year;
}

void date::selfTest(){
    bool pass = true;
    
    // checks for right month
    if (month != 2)
        pass = false;
    
    // checks for right day
    if (day != 20)
        pass = false;
    
    // checks for right year
    if (year != 2022)
        pass = false;
    
    // informs wether date was set right
    if (pass == true)
        cout << "date set correctly";
    else
        cout << "date set incorrectly";
}

int main(){
    int option = 0;     //option chosen by user
    int gradeCount = 0; //number of scores entered
    bool repeat = true;
    float *grades = nullptr; // array for all the scores
    
    programGreeting();
    
    date today;
    
    // external date initialization
    today.setVal(2, 20, 2022);
    
    cout << endl;
    
    // executing the test for correct date
    today.selfTest();
    
    grades = new float[gradeCount];
    
    // will keep going until user quits
    while (repeat){
        
        // displays menu options
        mainMenu();
        
        optionFunction(option);
        
        if (option == 1){
            
            gradeCount++;
            
            cout << "Enter Score: ";
            
            //make sure entered score is a valid value
            validScore(grades[gradeCount-1]);
        }

        else if (option == 2){
            
            printScores(grades, gradeCount);
        }
    
        else if (option == 3){
            
            //prints scores for refrence
            printScores(grades, gradeCount);
            
            // compute GPA
            calculateGpa(grades, gradeCount);
        }

        else if (option == 4){
            cout << "Thanks for using my program!\n";
            
            //ends loop and quits program
            repeat = false;
        }
    }
    
    // executes test to check the grade function
    unitTest();
}

//greeting function
void programGreeting(){
    cout << "Taha Zeeshan\n" << "February 20, 2022\n";
    cout << "Welcome to the GPA Calculator\n";
}

//display for the menu
void mainMenu(){
    cout << "\nMain Menu\n";
    cout << "1. Add Grades\n";
    cout << "2. Display All Grades\n";
    cout << "3. Process All Grades\n";
    cout << "4. Quit Program\n";
}

// only allows valid input for option
void optionFunction(int& option){
    bool invalidResponse = true;

    while(invalidResponse){

        cin >> option;

        if(cin.fail()){
                cin.clear();
                cin.ignore();
        }

        if (option == 1 || option == 2 || option == 3 || option == 4){
            invalidResponse = false;
       }
        if(invalidResponse == true){
        cout << "Invalid number! Please choose 1-4: ";
        cout << endl;
    }
    }
}

// only allows valid input for scores
void validScore(float& score){
    bool invalidResponse = true;

    while(invalidResponse){

        cin >> score;

        if(cin.fail()){
            cin.clear();
            cin.ignore();
        }
        else if (score >= 0 && score <= 100){
            invalidResponse = false;
        }
        
        if (invalidResponse == true){
            cout << "\ninvalid, please enter a score 0 - 100: ";
        }
    }
}

// function to print scores
void printScores(float grades[], int gradeCount){
    cout << "#     Score     Grade\n";
    
    for (int i = 0; i < gradeCount; i++)
    {
        int score = grades[i];
        
        cout << i << "     " << score << "        ";
        
        // Letter Grades
        cout << calculateGrade(score);
        cout << endl;
    }
}

// function that returns letter grades
string calculateGrade(int score){
    if (score > 100 || score < 0)
        return "invalid";
        
    if (score >= 90)
        return "A";
    
    else if (score >= 80)
        return "B";
    
    else if (score >= 70)
        return "C";
        
    else if(score >= 60)
        return "D";
        
    else
        return "F";
    
}

// function for calculating gpa
void calculateGpa(float grades[], int gradeCount){
    float gpa = 0;
    int added = 0;
    
    for (int i = 0; i < gradeCount; i++)
    {
        added += grades[i];
    }
    
    gpa = added/gradeCount;
    
    cout << "\nStudent GPA\n";
    cout << gpa << "  ";
    
    cout << calculateGrade(gpa);
    
    cout << endl;
}

// Component Test Grade Conversion
void unitTest(){
    bool passed = true;
    int test[7]{-1, 50, 60, 70, 80, 90, 110};
    string correctResult[7]{"invalid", "F", "D", "C", "B", "A", "invalid"};
    string calculatedResult[7];
    
    cout << "Score   Actual Grade   Calculated Grade\n";
    for (int i = 0; i < 7; i++)
    {
        cout << test[i];
        cout << "       " << correctResult[i];
        cout << "             " << calculateGrade(test[i]);
        cout << endl;
        
        if (correctResult[i] != calculateGrade(test[i])){
            passed = false;
        }
        
    }
        if (passed == true){
            cout << "Unit Test Passed\n";
        }
        else{
            cout << "Unit Test Failed\n";
        }
    
}
