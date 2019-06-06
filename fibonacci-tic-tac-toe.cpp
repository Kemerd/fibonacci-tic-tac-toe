// Saw a question asking to implement Tic-Tac-Toe in C++.
//
// Was wondering to myself if there was a super quick and easy to way to check for victory.
//
// At first I was thinking of assigning different prime numbers to every value of the board,
//
// But from my experimenting, you can actually use the Fibonacci sequence to obtain a unique
// victory number every time. So you can try every permutation of the board, and unless
// you obtain a winning 3-in-a-row, you won't obtain any of these numbers:
// 1, 16, 24, 30, 39, 63, 105, 2184
//
// This is if you assign the board the sequence as follow:
// 1  | 2  | 3
// 5  | 8  | 13
// 21 | 34 | 55
//
// So let's make a C++ implementation of it!
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

// I think you could probably dynamically generate unique win-conditions for a board of size n,
// just increasing the amount of Fibonnaci numbers you use, but this is untested.
int iWinConditions[8] = { 6, 105, 440, 504, 520, 544, 2145, 39270 };

int score[2] = { 0, 0 };
int currentSelect[2] = { 0, 0 };
int iMoves = 0;

bool validMove = false;
string winner = "";

string key;

// Make the scoring template we will refer to.
int iBoardTemplate[3][3] = {
	{ 1, 2, 3	 },
	{ 5, 8, 13	 },
	{ 21, 34, 55 }
};

// Make the board we will be modifying.
string iBoardOwners[3][3] = {
	{ "A1", "A2", "A3"	},
	{ "B1", "B2", "B3"	},
	{ "C1", "C2", "C3" }
};

// A function for printing our board.
void printboard()
{
	cout << " \n";
	cout << "       |      |      \n";
	cout << "   " + iBoardOwners[0][0] + "  |  " + iBoardOwners[0][1] + "  |  " + iBoardOwners[0][2] + "  \n";
	cout << " ______|______|______\n";
	cout << "       |      |      \n";
	cout << "   " + iBoardOwners[1][0] + "  |  " + iBoardOwners[1][1] + "  |  " + iBoardOwners[1][2] + "  \n";
	cout << " ______|______|______\n";
	cout << "       |      |      \n";
	cout << "   " + iBoardOwners[2][0] + "  |  " + iBoardOwners[2][1] + "  |  " + iBoardOwners[2][2] + "  \n";
	cout << "       |      |      \n";
	cout << " \n";
}

// A function for when one of our players needs to make a move.
void player_move(int iPlayer) {
	cout << "Player " + to_string(iPlayer) + ", enter your move!\n";
	cin >> key;
	// String cleaning is built in to how it handles valid moves.
	cout << "Move was " + key + ".\n";

	// Loop through our board and find out if our selection is valid.
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// Also, whatever you do do not put in OO or XX. I just wanted to test the Fibbonaci part, 
			// The implementation in terms of the bugs of this program suck.
			if ( key == iBoardOwners[i][j] ) {
				validMove = true;
				currentSelect[0] = i;
				currentSelect[1] = j;
			}
		}
	}
	
	// After finding a spot on our board, claim it and check for victory.
	if (validMove) {
		// Player 1
		if (iPlayer == 1) {
			iBoardOwners[currentSelect[0]][currentSelect[1]] = "XX";
		}
		// Player 2
		else {
			iBoardOwners[currentSelect[0]][currentSelect[1]] = "OO";
		}

		// Set our score to the value assigned to the board.
		if (score[iPlayer - 1] != 0) {
			score[iPlayer - 1] = score[iPlayer - 1] * iBoardTemplate[currentSelect[0]][currentSelect[1]];
		}
		else {
			score[iPlayer - 1] = iBoardTemplate[currentSelect[0]][currentSelect[1]];
		}

		//cout << "The score for Player " + to_string(iPlayer) + " is " + to_string(score[iPlayer - 1]) + ".";

		// Check if there is a winner. If not, print the board and move onto the next move.
		for (int i = 0; i < 8; i++)
		{
			if (score[iPlayer - 1] == iWinConditions[i]) {
				cout << "Should call";
				winner = "Player " + to_string(iPlayer);
			}
		}
		printboard();
	}
	else {
		cout << "This is an invalid move! \n";
		player_move(iPlayer);
	}
}

// pls forgiv i wrote this in an hour
int main()
{
	cout << "Hello, welcome to Fibonacci tic-tac-toe!\n";
	cout << "Here is your board!\n";
	printboard();
	while (winner == "") {
		player_move(1);
		if (winner == "") {
			player_move(2);
		}
	}
	cout << "Congratulations! " + winner + " is the winner!";
}



