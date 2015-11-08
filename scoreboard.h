#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <string>
using namespace std;

class ScoreBoard{
	public:
		int xwins;
		int owins;

		int currentState[9];
		// 0 == unoccupied
		// 1 == x occupied
		// 2 == o occupied

		ScoreBoard();

		void makeMove(const int moveSpot, const int id); 
		void startGame();
		bool isOccupied(const string place); // only for file input
		//void endGame();

		bool findWinner();
		bool checkBoardFull();
		void clear();

		bool checkWin(const int currentState[], const int id);
};

int convert(const string moveString);

#endif
