#include "scoreboard.h"
//#include "player.h"
#include <iostream>
#include <string>
using namespace std;

ScoreBoard::ScoreBoard() : xwins(0), owins(0){
	for(int i = 0; i < 9; i++){
		currentState[i] = 0;
	}
}

void ScoreBoard::makeMove(const int moveSpot, const int id){
	currentState[moveSpot] = id;

	// for(int i = 0; i < 9; i++){
	// 	cout << currentState[i];
	// }
	// cout << endl;

}

bool ScoreBoard::findWinner(){
	//check all possible winning combinations for x
	if(checkWin(currentState, 1)){
		xwins++;
		cout << "X wins" << endl;
		cout << "Score is" << endl;
		cout << "X " << xwins << endl;
		cout << "O " << owins << endl;
		return true;
	}else if(checkWin(currentState,2)){
		owins++;
		cout << "O wins" << endl;
		cout << "Score is" << endl;
		cout << "X " << xwins << endl;
		cout << "O " << owins << endl;
		return true;
	}else if(checkBoardFull()){
		cout << "Draw" << endl;
		cout << "Score is" << endl;
		cout << "X " << xwins << endl;
		cout << "O " << owins << endl;
		return true;
	}
	return false;
}

//check if the player with specified id wins
bool ScoreBoard::checkWin(const int currentState[], const int id){
	if((currentState[0] == id) && (currentState[1] == id) && (currentState[2] == id)){
		return true;
	}else if((currentState[3] == id) && (currentState[4] == id) && (currentState[5] == id)){
		return true;
	}else if((currentState[6] == id) && (currentState[7] == id) && (currentState[8] == id)){
		return true;
	}else if((currentState[1] == id) && (currentState[4] == id) && (currentState[7] == id)){
		return true;
	}else if((currentState[0] == id) && (currentState[3] == id) && (currentState[6] == id)){
		return true;
	}else if((currentState[2] == id) && (currentState[5] == id) && (currentState[8] == id)){
		return true;
	}else if((currentState[0] == id) && (currentState[4] == id) && (currentState[8] == id)){
		return true;
	}else if((currentState[2] == id) && (currentState[4] == id) && (currentState[6] == id)){
		return true;
	}else{
		return false;
	}
}

//check if board is full
bool ScoreBoard::checkBoardFull(){
	bool boardFull = true;
	for(int i = 0; i < 9; i++){
		if(currentState[i] == 0){
			boardFull = false;
			return boardFull;
		}
	}
	return boardFull;
}

void ScoreBoard::clear(){
	for(int i = 0; i < 9; i++){
		currentState[i] = 0;
	}
}

void ScoreBoard::startGame(){
	for(int i = 0; i < 9; i++){
		currentState[i] = 0;
	}
}

bool ScoreBoard::isOccupied(const string place){
	int toCheck = convert(place);
	if(currentState[toCheck] == 0){
		return false;
	}else{
		return true;
	}
}

int convert(const string moveString){
	if(moveString == "NW") return 0;
	else if(moveString == "N") return 1;
	else if(moveString == "NE") return 2;
	else if(moveString == "W") return 3;
	else if(moveString == "C") return 4;
	else if(moveString == "E") return 5;
	else if(moveString == "SW") return 6;
	else if(moveString == "S") return 7;
	else if(moveString == "SE") return 8;
}
