/*******************************************************************************
** File Name:       interest_calc.cpp
** Author:          Taha Zeeshan
** Description:     calculates simple interest or compound interest
*******************************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void welcomeMessage();
void menuFunction();
void optionFunction(int& option);
void executeOption(int& option, bool& repeat);
void validNumber(float& number);
void simpleInterest();
void compoundInterest();


int main(){
    int option = 0;
    bool repeat = true;

    welcomeMessage();

    while(repeat){
        menuFunction();

        optionFunction(option);

        executeOption(option, repeat);
    }
   return 0;
}

//******************************************************************************
// Function Name: welcomeMessage
// Parameters:   none
// Description:   prints a welcome message.
//******************************************************************************

void welcomeMessage(){
    cout << "Welcome to my Interest Calculation program!\n";
}

//******************************************************************************
// Function Name: menuFunction
// Parameters:   none
// Description:   provides options for what user wants to do.
//******************************************************************************

void menuFunction(){
    cout << "\nWhat would you like to do today?\n";
    cout << "Pick an option from below:\n";
    cout << "1. Simple Interest\n";
    cout << "2. Compound Interest\n";
    cout << "3. Quit\n";
}

//******************************************************************************
// Function Name: optionFunction
// Parameters:   int
// Description:   only allows for valid inputs 1-3 at option menu
//******************************************************************************

void optionFunction(int& option){
    bool invalidResponse = true;

    while(invalidResponse){

        cin >> option;

        if(cin.fail()){
                cin.clear();
                cin.ignore();
        }

        if (option == 1 || option == 2 || option == 3){
            invalidResponse = false;
       }
        if(invalidResponse == true){
        cout << "Invalid Option! Please choose 1-3!";
        cout << endl;
    }
    }
}

//******************************************************************************
// Function Name: executeOption
// Parameters:   int, bool
// Description:   executes which ever option the user picked.
//******************************************************************************

void executeOption(int& option, bool& repeat){
    if (option == 1){
    simpleInterest();
}

    else if (option == 2){
    compoundInterest();
}

    else if (option == 3){
    cout << "Thank you for using my program!\n";
    repeat = false;
}

    cout << endl;
}

//******************************************************************************
// Function Name: validNumber
// Parameters:   float
// Description:   only allows for valid numerical input
//******************************************************************************

void validNumber(float& number){
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
        
        if (invalidResponse == true){
            cout << "\ninvalid input, please enter a positive number: ";
        }

    }

}

//******************************************************************************
// Function Name: simpleInterest
// Parameters:   none
// Description:   calculates and then outputs both the simple interest and the
//                total accrued amount, based on the principal amount, interest
//                rate, and time that  the user enters.
//******************************************************************************

void simpleInterest()
{
    float principalAmount;
    float interestRate;
    float timeYears;
    float interest;
    float totalAccrued;

    cout << "\nEnter the Principal Amount: ";
    validNumber(principalAmount);
    cout << "\nEnter the interest rate: ";
    validNumber(interestRate);
    cout << "\nEnter the time in years: ";
    validNumber(timeYears);

    interest = principalAmount * (interestRate/100) * timeYears;
    totalAccrued = principalAmount + interest;

    cout << "\nInterest accrued: $" << fixed << setprecision(2) << interest;
    cout << "\nTotal Accrued Amount(principal + interest): $" << fixed << setprecision(2) << totalAccrued;
}

//******************************************************************************
// Function Name: compoundInterest
// Parameters:   none
// Description:   calculates and then outputs both the compound interest and the
//                total accrued amount, based on the principal amount, interest
//                rate, time, and compound period that  the user enters.
//******************************************************************************

void compoundInterest(){
    float principalAmount;
    float interestRate;
    float timeYears;
    float interest;
    float totalAccrued;
    float compoundPeriod;

    cout << "\nEnter the Principal Amount: ";
    validNumber(principalAmount);
    cout << "\nEnter the interest rate: ";
    validNumber(interestRate);
    cout << "\nEnter the time in years: ";
    validNumber(timeYears);
    cout << "\nEnter the number of compounding periods per year: ";
    validNumber(compoundPeriod);

    interest = principalAmount * pow((1 + (interestRate / 100) / compoundPeriod), (compoundPeriod * timeYears)) - principalAmount;
    totalAccrued = principalAmount + interest;

    cout << "\nInterest accrued: $" << fixed << setprecision(2) << interest;
    cout << "\nTotal Accrued Amount(principal + interest): $" << fixed << setprecision(2) << totalAccrued;
    }
