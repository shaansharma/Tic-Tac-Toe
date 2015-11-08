#include "player.h"
#include "scoreboard.h"
#include <string>
#include <iostream>
using namespace std;

void Player::makeMove(){
	//display X's/O's move
	if(id == 1){
		cout << "X's move" << endl;
	}else if(id == 2){
		cout << "O's move" << endl;
	}

	unsigned int numberOfAvailabeSpots = 0;
	for(int i = 0; i < 9; i++){
		if(sp->currentState[i] == 0){
			numberOfAvailabeSpots++;
		}
	}
	
	int moveSpot = 10;
	string moveString;
	if(numberOfAvailabeSpots > 0){
		//get move
		
		//for stdin stdin
		if(inputType == 0){
			cin >> moveString;
		}else if(inputType == 1){
			//SOMEHOW GET INPUT FROM FILESTREAM
			moveString = currentMove;
			cout << "(plays " << currentMove << ")" << endl;
		}


		moveSpot = convert2(moveString);
		
		// cout << "moveSpot = " << moveSpot << endl;
		// cout << "id = " << id << endl;

		sp->makeMove(moveSpot, id);

	}
	else{
		//*sp.endGame();
		sp->findWinner();
	}


}

int convert2(const string moveString){
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
