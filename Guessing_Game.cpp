// Author : Muhammad Asad (asadasghar836@gmail.com)

#include <iostream> // Library for input/output
#include <stdlib.h> // Library for generating random numbers
#include <time.h>   // Library for generating a seed based on time
using namespace std;

// ANSI color codes for colored output
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_BLUE    "\x1b[34m"

// Function to generate a random number between min and max 
int randomNumber(int min, int max) {
    srand(time(0)); // Seed the random number generator with the current time
    return min + rand() % max; // Generate a random number within the range [min, max]
}

int main() {
    // Declaration & Initialization of variables
    int num = 0;
    char choice;
    int size = 0;
    
    // Main loop for the game
    do {
        // Generates random number within the range of 1 & 100
        const int random = randomNumber(1,100);
        
        // Taking input from User
        cout << "<---GUESSING GAME--->" << endl;
        cout << "Enter a number : ";
        cin >> num;
        
        // Loop until user guesses the correct number
        while (true) {
            // Giving feedback according to user's input
            if (num < random) {
                cout << ANSI_COLOR_RED << "Too Small" << ANSI_COLOR_RESET << endl;
            } else if (num > random) {
                cout << ANSI_COLOR_RED << "Too Big" << ANSI_COLOR_RESET << endl;
            } else if (num == random) {
                cout << ANSI_COLOR_GREEN << "You Win" << ANSI_COLOR_RESET << endl;
                break; // Break out of the loop if the user guesses correctly
            }
            cout << "Enter the Number Again : ";
            cin >> num;
        }
        
        // Ask if the user wants to continue playing
        cout << "=== Do you want to continue the game? If YES press Y/y, if NO press N/n ===" << endl;
        cin >> choice;
    } while (choice != 'N' && choice != 'n');

    // Game exit message
    cout << ANSI_COLOR_BLUE << "GAME EXITED" << ANSI_COLOR_RESET << endl;
    return 0;
}
