/*	Brad Haydell
Upgraded Guessing Game Program
PRG / 410
January 11, 2016
R.Bradley Andrews

The guessing game chooses a random number and gives the user
15 chances to guess the number.  If the user's guess is not
correct, then the program will let the user know whether the
guess is too high or too low.  The program will also display 
the guesses that have already been made.

************************************************************************

Program changes:

December 21, 2015

- Added Function reviewGuess(int randomNumber, int guessed) which
returns a 1 if guess is too high, -1 if guess is too low, 0 if
guess is correct.

- Created an overall loop that allows user to choose if they want
to play again or not, if so, computer will choose another random
number

- Added switch to take the result of reviewGuess() to let the user
know if they guess it too high, too low, or correct.

January 11, 2016

- Removed RanNum function and moved random number generator to beginning
of main while loop, which will give a new random number for every game
played.

- Added array that will displays all guesses throughout the current game
Array will not be displayed until after the first guess.

- Created a message for when the user does not guess the random number 
within 15 tries. 

*************************************************************************
*/
// Directives

#include <iostream>
#include <ctime>
#include <stdlib.h>     
#include <array>
using namespace std;

// Function Prototype

int reviewGuess(int randomNumber, int guessed);

// Main function

int main()
{
	// Clear screen

	system("cls");

	// Declare variables
	bool keepPlaying = true;
	const int max = 15;
	int guess = 0, randomNum = 0, count = 1, count2 = 0, retValue = 0, randomMax = 0;

	int guessArray[max];

	// Call RandNum function to get range and random number for game
	while (keepPlaying)
	{

		const int maxRand = 1000;
		srand(time(0));
		randomNum = rand() % maxRand + 1;
		
		/*  Displays the objectives of the guessing game and allows user
		to choose their first guess to start the game.
		*/

		cout << endl;
		cout << "Welcome to the Guessing Game!"
			<< endl << endl;

		cout << "You will have 15 chances to guess"
			<< " the number in this game."
			<< endl << endl;

		cout << "Please enter a guess for a number"
			<< " between 1 and " << maxRand << ": ";
		!(cin >> guess);


		/*  Validation to make sure the user chooses a number in the
		range displayed and is not a letter or symbol.
		*/

		while (guess < 1 || guess > maxRand)
		{
			cout << "You enter a number outside of the desired range or you have"
				<< " have entered something that is not an interger.\n\n"
				<< "Please enter a guess for a number"
				<< " between 1 and " << maxRand << ": ";
			cin.clear();
			cin.ignore();
			!(cin >> guess);
		}

		/*  Starts 15 chance loop and lets the user know if the guess is
		too high or too low.  If user guess is wrong, will ask the
		user to choose another number.  Will also validate the number
		entered is within the desired range.  Uses switch with return
		value from the reviewGuess() function to display a message if
		the guess is too high, too low, or correct.
		*/

		if (guess != randomNum)
		{
			for (int i = 1; i <= max; i++)
			{
				system("cls");
				retValue = reviewGuess(randomNum, guess);
				guessArray[count2] = guess;

				switch (retValue)
				{
				case 1:
				{
					cout << endl;
					cout << "Guess is too high";
					cout << endl << endl;
					break;
				}
				case -1:
				{
					cout << endl;
					cout << "Guess is too low";
					cout << endl << endl;
					break;
				}
				case 0:
				{
					cout << endl;
					cout << randomNum << " is the correct guess." << endl;
					cout << "It took you " << count << " guesses." << endl;
					cout << "You Won!!!!!" << endl << endl;
					count = 1;
					count2 = 0;
					break;
				}
				}

				/*  If the user guesses the correct number the count will 
					reset for the new game.
				*/
				
				if (retValue == 0)
				{
					break;
				}

				/* If user maxes out the guess attempts, this message will be
				displayed
				*/
				if (count == max)
				{
					cout << endl << "Sorry YOU LOSE!!!!" << endl << endl;
					break;
				}
				
				/* Populates the guessArray[] with the user's guess and as it 
				   iterates through the loop it fills in and displays the 
				   elements of each guess in the array.
				*/
				
				guessArray[count2] = guess;
				cout << "Here is a list of the numbers you have guessed:\n\n";

				for (int i = 0; i <= count2; i++)
				{
					cout << guessArray[i] << " ";
				}
				
				
				cout << "\n\nPlease guess another number"
					<< " between 1 and " << maxRand << ": ";
				!(cin >> guess);


				/*  Validation to make sure the user chooses a number in the
				range displayed and is not a letter or symbol.  For some reason,
				this does not work right here but does in the beginning of the
				program.
				*/

				while (guess < 1 || guess > maxRand)
				{
					cout << "You enter a number outside of the desired range or you have"
						<< " have entered something that is not an interger.\n\n"
						<< "Please enter a guess for a number"
						<< " between 1 and " << maxRand << ": ";
					cin.clear();
					cin.ignore();
					!(cin >> guess);
				}
				count++;
				count2++;
			}

		}

		/* Displays if the user guess the correct number on the first try! */

		else
		{
			cout << endl;
			cout << randomNum << " is the correct guess." << endl;
			cout << "It took you " << count << " guesses." << endl;
			cout << "You Won!!!!!" << endl << endl;
		}

		/* Asks player if they want to play again.  It uses a true false
		to either continue or exit the loop. True stays in the loop and
		the player plays another game, and false to exit the game.
		*/
		
		char again;
		cout << "Would you like to play the guessing game again (y or n): ";
		cin >> again;
		if (again == 'y' || again == 'Y')
		{
			keepPlaying = true;
			system("cls");
			count = 1;
			count2 = 0;
		}
		else
		{
			keepPlaying = false;
			cout << "Thanks for playing!  Goodbye." << endl;
			system("pause");
		}

	}
	return 0;
}


/*  Function definition of reviewGuess

This function return values to be used in the switch in the
main().

*/

int reviewGuess(int randomNumber, int guessed)
{
	if (guessed > randomNumber)
	{
		return 1;
	}
	if (guessed < randomNumber)
	{
		return -1;
	}
	if (guessed == randomNumber)
	{
		return 0;
	}
}






