#ifndef PLAYER_H
#define PLAYER_H
#include "scoreboard.h"
#include <string>
using namespace std;

class Player{
	public:
		ScoreBoard *sp;
		int id;
		//1 = x
		//2 = o
		
		int inputType;
		//0 = stdin
		//1 = file
		
		string currentMove;

		void makeMove(); //no parameters
};

int convert2(const string);

#endif
