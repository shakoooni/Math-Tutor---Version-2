// Math Tutor - Version 2
// CSC150 - Program Fundamentals I
// Section: 3
// Team: Jayaditya Meesala and Javion Wilkins
// GitHub: https://github.com/shakoooni/Math-Tutor---Version-2

#include <iostream>   // cout, cin
#include <string>     // string, getline
#include <cstdlib>    // rand, srand
#include <ctime>      // time for srand seed
using namespace std;

int main() {
    // variables
    string name;
    int leftNum = 0, rightNum = 0, mathType = 0;
    char mathSymbol = '?';
    int correctAnswer = 0, userAnswer = 0, temp = 0;

    // seed randomness
    srand(static_cast<unsigned int>(time(0)));


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
    switch (mathType) {
        case 1: // addition
            mathSymbol = '+';
            correctAnswer = leftNum + rightNum;
            break;
        case 2: // subtraction
            mathSymbol = '-';
            if (leftNum < rightNum) { temp = leftNum; leftNum = rightNum; rightNum = temp; }
            correctAnswer = leftNum - rightNum;
            break;
        case 3: // multiplication
            mathSymbol = '*';
            correctAnswer = leftNum * rightNum;
            break;
        case 4: // division
            mathSymbol = '/';
            correctAnswer = leftNum; // original left before scaling
            leftNum *= rightNum;     // make division clean
            break;
        default: // error fallback
            cout << endl << "*** ERROR ***" << endl;
            cout << "Invalid math type: " << mathType << endl;
            cout << "Error Code: -1" << endl;
            cout << "Please contact your instructor." << endl;
            return -1;
    }

    // question
    cout << endl << "Alright, " << name << " - here is your challenge..." << endl;
    cout << "What is " << leftNum << " " << mathSymbol << " " << rightNum << "? :  ";
    cin >> userAnswer;

    // results
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
