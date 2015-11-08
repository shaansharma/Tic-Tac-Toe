#include "scoreboard.h"
#include "player.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){

	ScoreBoard score;

	Player x;
	x.sp = &score;
	x.id = 1;

	Player o;
	o.sp = &score;
	o.id = 2;

	string game;
	string input1;
	string input2;
//	string game = "game";
	int gameNumber = 0;

	string nextMove;

	while(1){
		cin >> game;
		if(game == "quit") return 0;
		cin >> input1;
		cin >> input2;
		if(game == "game"){
			if((input1 == "stdin") && (input2 == "stdin")){
				score.startGame();
				while(1){
					//STDIN STDIN
					x.inputType = 0;
					o.inputType = 0;

					//check if anyone has won the game
					if(score.findWinner()) break;

					if(gameNumber % 2 == 0){
						//cout << "X's move" << endl; //this is now part of player class
						x.makeMove();
						if(score.findWinner()) break;
						//cout << "O's move" << endl;
						o.makeMove();
					}
					else{
						//cout << "O's move" << endl;
						o.makeMove();
						if(score.findWinner()) break;
						//cout << "X's move" << endl;
						x.makeMove();
					}
				}
				gameNumber++;
				score.clear();

			  }else if((input1 == "stdin") && (input2 != "stdin")){
			 	//STDIN FILE
			 	ifstream file2(input2.c_str());
			 	x.inputType = 0;
			 	o.inputType = 1;

			 	//start game
			 	score.startGame();
			 	
			 	//game being played
			 	while(1){
			 		//check if anyone has won the game
			 		if(score.findWinner()) break;

			 		if(gameNumber % 2 == 0){
			 			x.makeMove();

			 			if(score.findWinner()) break;
			 			
			 			file2 >> nextMove;
			 			while(score.isOccupied(nextMove)){
			 				file2 >> nextMove;
			 			}
			 			o.currentMove = nextMove;
			 			o.makeMove();
			 		}
			 		else{
			 			file2 >> nextMove;
			 			while(score.isOccupied(nextMove)){
			 				file2 >> nextMove;
			 			}
			 			o.currentMove = nextMove;
			 			o.makeMove();

			 			if(score.findWinner()) break;

			 			x.makeMove();
			 		}
			 	}
			 	gameNumber++;
			 	score.clear();
			 	o.currentMove = "";
			 	nextMove = "";

			 }else if((input1 != "stdin") && (input2 == "stdin")){
			 	//FILE STDIN
			 	ifstream file1(input1.c_str());
			 	x.inputType = 1;
			 	o.inputType = 0;

			 	//start game
			 	score.startGame();

			 	//game being played
			 	while(1){
			 		//check if anyone has won the game
			 		if(score.findWinner()) break;

			 		if(gameNumber % 2 == 0){
			 			file1 >> nextMove;
			 			while(score.isOccupied(nextMove)){
			 				file1 >> nextMove;
			 			}
			 			x.currentMove = nextMove;
			 			x.makeMove();

			 			if(score.findWinner()) break;
			 			o.makeMove();
			 		}
			 		else{
			 			o.makeMove();

			 			if(score.findWinner()) break;

			 			file1 >> nextMove;
			 			while(score.isOccupied(nextMove)){
			 				file1 >> nextMove;
			 			}
			 			x.currentMove = nextMove;
			 			x.makeMove();
			 		}
			 	}
			 	gameNumber++;
			 	score.clear();
			 	x.currentMove = "";
			 	nextMove = "";

			 }else if((input1 != "stdin") && (input2 != "stdin")){
			 	//FILE FILE
			 	ifstream file1(input1.c_str());
			 	ifstream file2(input2.c_str());
			 	x.inputType = 1;
			 	o.inputType = 1;

			 	//start game
			 	score.startGame();

			 	//game being played
			 	while(1){
			 		//check to see if anyone has won the game
			 		if(score.findWinner()) break;

			 		if(gameNumber % 2 == 0){
			 			file1 >> nextMove;
			 			while(score.isOccupied(nextMove)){
			 				file1 >> nextMove;
			 			}
			 			x.currentMove = nextMove;
			 			x.makeMove();

			 			if(score.findWinner()) break;

			 			file2 >> nextMove;
			 			while(score.isOccupied(nextMove)){
			 				file2 >> nextMove;
			 			}
			 			o.currentMove = nextMove;
			 			o.makeMove();

			 		}else{
			 			file2 >> nextMove;
			 			while(score.isOccupied(nextMove)){
			 				file2 >> nextMove;
			 			}
			 			o.currentMove = nextMove;
			 			o.makeMove();
			 			
			 			if(score.findWinner()) break;
			 			
			 			file1 >> nextMove;
			 			while(score.isOccupied(nextMove)){
			 				file1 >> nextMove;
			 			}
			 			x.currentMove = nextMove;
			 			x.makeMove();

			 		}
			 	}
			 	gameNumber++;
			 	score.clear();
			 	x.currentMove = "";
			 	o.currentMove = "";
			 	nextMove = "";

			 }
		}
	}
	return 0;
}
