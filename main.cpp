// Math Tutor - Version 2
// CSC150 - Program Fundamentals I
// Section: 3
// Team: Jayaditya Meesala and Javion Wilkins
// GitHub: https://github.com/shakoooni/Math-Tutor---Version-2
// Description: The Math Tutor V2 asks the user for there name and then ask a math question
#include <stdio.h>
#include <iostream>   // cout, cin
#include <string>     // string, getline
#include <cstdlib>    // rand, srand
#include <ctime>      // time for srand seed
using namespace std;

int main() {
    // variables
    string name;
    int leftNum = 0;
    int rightNum = 0;
    int mathType = 0;
    char mathSymbol = '?';
    int correctAnswer = 0, userAnswer = 0, temp = 0;

    // seed randomness
    srand(time(0));


    cout << R"(***********************************************************************
      __  __       _   _       _____      _
     |  \/  | __ _| |_| |__   |_   _|   _| |_ ___  _ __
     | |\/| |/ _` | __| '_ \    | || | | | __/ _ \| '__|
     | |  | | (_| | |_| | | |   | || |_| | || (_) | |
     |_|  |_|\__,_|\__|_| |_|   |_| \__,_|\__\___/|_|

***********************************************************************
*                      Welcome to the Math Tutor!                     *
***********************************************************************
*     Math joke: Parallel lines so close, yet never meant to meet.    *
***********************************************************************)" << endl;

    // get full name
    cout << "Enter your full name: ";
    getline(cin, name);

    // random numbers and operator type
    leftNum  = rand() % 10 + 1;
    rightNum = rand() % 10 + 1;
    mathType = rand() % 4 + 1;

    // decide operator and compute correct answer
    cout << endl << "Alright, " << name << " - here is your challenge..." << endl;
    switch (mathType) {
        case 1: // addition
            mathSymbol = '+';
            correctAnswer = leftNum + rightNum;
        cout << "What is " << leftNum << " " << mathSymbol << " " << rightNum << "? :  ";
            break;
        case 2: // subtraction
            mathSymbol = '-';
            if (leftNum < rightNum) { temp = leftNum; leftNum = rightNum; rightNum = temp; }
            correctAnswer = leftNum - rightNum;
        cout << "What is " << leftNum << " " << mathSymbol << " " << rightNum << "? :  ";
            break;
        case 3: // multiplication takes our 2 numbers and multiplies them together
            mathSymbol = '*';
            correctAnswer = leftNum * rightNum;
        cout << "What is " << leftNum << " " << mathSymbol << " " << rightNum << "? :  ";
            break;
        case 4: // division confirms the left number is bigger than the right number
            mathSymbol = '/';
            correctAnswer = leftNum; // original left before scaling
            leftNum *= rightNum;     // make division clean
        cout << "What is " << leftNum << " " << mathSymbol << " " << rightNum << "? :  ";
            break;
        default: // error fallback
            cout << endl << "*** ERROR ***" << endl;
            cout << "Invalid math type: " << mathType << endl;
            cout << "Error Code: -1" << endl;
            cout << "Please contact your instructor." << endl;
            return -1;
    }


    //space for the user to answer the question
    cin >> userAnswer;

    // results asqi art for the results to make it look good
    cout << endl;
    cout << "+--------------------- RESULT -------------------+" << endl;
    cout << "| Question : " << leftNum << " " << mathSymbol << " " << rightNum << endl;
    cout << "| Your Ans : " << userAnswer << endl;
    if (userAnswer == correctAnswer)
        cout << "| Correct? : YES" << endl;
    else
        cout << "| Correct? : NO (Correct = " << correctAnswer << ")" << endl;
    cout << "+------------------------------------------------+" << endl;

    // outro
    cout << endl << "Thanks for playing, " << name << "!" << endl;
    return 0;
}
