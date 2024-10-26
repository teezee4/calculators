# Calculators
- GPA Calculator
- GPA Calculator(comp) - Enhanced Version
- Interest Calculator
  
# GPA Calculator

Welcome to the **GPA Calculator**, created by **Taha Zeeshan**. This program allows you to enter grades for multiple courses, then calculates and displays the highest, lowest, and average grades. This easy-to-use program leverages input validation, dynamic memory management, and essential functions to provide a comprehensive GPA calculation experience.

## Features
- **Grade Entry for Multiple Courses**: Enter grades for each course, with input validation to ensure values between 0 and 5.
- **Dynamic Memory Management**: The program dynamically allocates memory for the grades and courses entered.
- **Grade Analysis**: Displays the highest, lowest, and average grades along with the corresponding course names.
- **User-Friendly Validation**: Ensures all inputs for the number of courses and grade values are valid.

## Program Functionality
1. **Enter the Number of Grades**: The program prompts for the number of grades, which determines the size of the data to be entered.
2. **Input Course Names and Grades**: Enter each course's name and grade (between 0 and 5), with validation ensuring valid input.
3. **Display Results**:
   - The highest grade and its associated course(s)
   - The lowest grade and its associated course(s)
   - The average grade across all courses

## Getting Started
To run the program:
1. **Compile and Execute**: Compile the code using a C++ compiler and run the executable:
   ```bash
   g++ gpa_calc.cpp -o gpa_calc
   ./gpa_calc

# GPA Calculator Comp (Enhanced)

Welcome to the **Enhanced GPA Calculator**, created by **Taha Zeeshan**! This advanced program provides a streamlined way to enter and manage student grades, calculate GPA, and display letter grades. Complete with a menu-driven interface, grade validation, and unit testing, it’s designed to make GPA management easy and reliable.

## Features
- **Grade Management**: Enter grades, view them along with corresponding letter grades, and calculate a GPA with a letter-grade equivalent.
- **Input Validation**: Ensures that all inputs for grades and menu options are valid, reducing errors.
- **GPA Calculation**: Averages entered scores to compute GPA and converts it into a letter grade.
- **Date Class & Unit Testing**: The program includes a simple `date` class and a unit test to ensure the grade conversion is accurate.

## Program Functionality
1. **Start with a Greeting**: Displays a welcome message and the current date.
2. **Menu Options**:
   - **Add Grades**: Enter individual grades (0-100).
   - **Display All Grades**: View all entered grades along with their letter grades.
   - **Process All Grades**: Computes and displays the GPA, along with its letter-grade equivalent.
   - **Quit Program**: Exit the program and display a farewell message.
3. **Unit Testing**: Automatically verifies the grade conversion logic.

## Getting Started
To run the program:
1. **Compile and Execute**: Use a C++ compiler to build the program and run the executable:
   ```bash
   g++ gpa_calc_comp.cpp -o gpa_calc_comp
   ./gpa_calc_comp

# Interest Calculator Program

This **Interest Calculator** program, created by **Taha Zeeshan**, calculates both **simple interest** and **compound interest** based on user input. Designed with a menu-driven interface, it allows users to select the type of interest calculation, input key financial data, and receive a precise result. 

## Features
- **Interest Calculation**: Offers two types of interest calculations: simple and compound.
- **User-Friendly Interface**: Menu-driven options for easy navigation.
- **Input Validation**: Ensures only valid numerical input for each financial parameter.
- **Precision Output**: Displays interest accrued and total amount with two-decimal precision.

## Program Functionality
1. **Welcome Message**: Displays a greeting message at the start.
2. **Menu Options**:
   - **Simple Interest Calculation**: Calculates interest using the simple interest formula.
   - **Compound Interest Calculation**: Calculates interest using the compound interest formula.
   - **Quit**: Exits the program.
3. **Calculation Parameters**: Asks for the following inputs depending on the selected option:
   - Principal amount
   - Interest rate (as a percentage)
   - Time (in years)
   - Compounding period (only for compound interest)

## Getting Started
To compile and run the program, use the following commands:
```bash
g++ interest_calc.cpp -o interest_calc
./interest_calc
