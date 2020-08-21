#include <iostream>
#include <fstream>
#include <string>
#include "Global.h"

using namespace std;

int score = 0;
int lives = 3;
bool right;

int FPS = 60;
int frameDelay;
Uint32 frameStart = SDL_GetTicks();
int frameTime = SDL_GetTicks() - frameStart;

void Global::saveScores(int _score) {
	string strScore = to_string(_score);
	ofstream scoreS("scores.dat", ios::app);

	while (!scoreS.eof()) {
		scoreS << strScore << endl;
		break;
	}
	
	scoreS.close();
}

void Global::readScores() {
	string strScore;
	ifstream scoreR("scores.dat", ios::in);
	
	int i = 0;
	if (scoreR.is_open()) {
		while (scoreR >> strScore) {
			cout << strScore << endl;
			scores[i] = stoi(strScore);
			i++;
		}

		scoreR.close();
	}
}