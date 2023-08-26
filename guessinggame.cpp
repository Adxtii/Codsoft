#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

    int number, guess, tries = 0;
    srand(time(0)); 
    number = rand() % 100 + 1; 

    cout << "Welcome to the Number Guessing Game!" << endl;

    do
    {

        cout << "Enter a guess between 1 and 100: ";
        cin >> guess;

        tries++;

        if (guess < 1 || guess > 100)
        {
            cout << "Invalid input. Please try again." << endl;
        }

        else if (guess > number)
        {
            cout << "Too high. Try again." << endl;
        }

        else if (guess < number)
        {
            cout << "Too low. Try again." << endl;
        }

        else
        {
            cout << "You got it! Congratulations!" << endl;
            cout << "You guessed the number in " << tries << " tries." << endl;
            break; 
        }
    } while (true);

    return 0; 
}
