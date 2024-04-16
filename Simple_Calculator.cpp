// Author : Muhammad Asad (asadasghar836@gmail.com)
#include <iostream>
using namespace std;

int main()
{
    // Declaration of variables
    double firstNum = 0;
    double secondNum = 0;
    int choice = 0;
    char check;

    // Main loop for the calculator program
    do
    {
        cout << "<--- YOU CAN INPUT DECIMAL VALUES --->" << endl;
        cout << endl;

        // Taking input of two decimal numbers
        cout << "Enter first number:";
        cin >> firstNum;
        cout << "Enter second number:";
        cin >> secondNum;

        // Menu for operations
        cout << "Press 1 : For Addition" << endl;
        cout << "Press 2 : For Subtraction" << endl;
        cout << "Press 3 : For Multiplication" << endl;
        cout << "Press 4 : For Division" << endl;
        cout << "Press 5 : For Exit" << endl;
        cin >> choice;

        // Perform operation based on user's choice
        if (choice == 1)
        {
            cout << firstNum << " + " << secondNum << " = " << firstNum + secondNum << endl;
        }
        else if (choice == 2)
        {
            cout << firstNum << " - " << secondNum << " = " << firstNum - secondNum << endl;
        }
        else if (choice == 3)
        {
            cout << firstNum << " * " << secondNum << " = " << firstNum * secondNum << endl;
        }
        else if (choice == 4)
        {
            if (secondNum != 0)
            {
                cout << firstNum << " / " << secondNum << " = " << firstNum / secondNum << endl;
            }
            else
            {
                cout << "Error: Division by zero!" << endl;
            }
        }
        else if (choice == 5)
        {
            break; // Exit the loop and end the program
        }
        else
        {
            cout << "Invalid choice! Please enter a number from 1 to 5." << endl;
        }

        // Ask if the user wants to continue
        cout << "<=== Do you want to continue? If yes, press Y/y. If no, press N/n ===>" << endl;
        cin >> check;
    } while (check != 'N' && check != 'n');

    cout << "Program is Ended" << endl;
    return 0;
}
