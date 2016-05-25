# Guessing Game

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
