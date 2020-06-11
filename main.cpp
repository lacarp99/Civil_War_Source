#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int turn = 1;

char sourceXPos;
char sourceYPos;
char destinationXPos;
char destinationYPos;

int gameMap[49] = {
	0, 1, 0, 1, 0, 1, 0,
	0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0,
	0, 1, 0, 1, 0, 1, 0

};

int letterToNumber(char sY) {
	int intSY = 0;
	switch(sY) {
		case 'a':
			intSY = 0;
			break;
		case 'b':
			intSY = 1;
			break;
		case 'c':
			intSY = 2;
			break;
		case 'd':
			intSY = 3;
			break;
		case 'e':
			intSY = 4;
			break;
		case 'f':
			intSY = 5;
			break;
		case 'g':
			intSY = 6;
			break;
	}
	return intSY;
}

void parseInput(char sX, char sY, char dX, char dY) {
	int intSX = letterToNumber(sY);
	int intSY = letterToNumber(sX);
	int intDX = letterToNumber(dY);
	int intDY = letterToNumber(dX);
	int tempUnit = gameMap[intDX+(intDY*7)];
	gameMap[intDX+(intDY*7)] = gameMap[intSX+(intSY*7)];
	gameMap[intSX+(intSY*7)] = tempUnit;
}

void drawMapToConsole() {
	char layout[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	cout << "   a  b  c  d  e  f  g" << endl;
	for (int i=0; i < 49; i++) {
		if (i % 7 == 0) {
			if (i != 0) {
				cout << endl;
			}
			cout << layout[i/7] << "  ";
		}
		
		cout << gameMap[i] << "  ";
	}
	cout<<endl;
}

int main() {
	cout << "Welcome to the American Civil War. This is a local 2 player game, so grab a friend and begin!" << endl;
	cout << "Press ENTER to continue . . .";
	cin.get();
#ifdef WIN32 || _WIN32
	system("cls");
#endif
#ifdef __UNIX__
	system("clear");
#endif
	while (true) {
#ifdef WIN32 || _WIN32
		system("cls");
#endif
#ifdef __UNIX__
		system("clear");
#endif
		if (turn == 1) {
			turn = 0;
			cout << "Confederate player your move." << endl;
		}
		else
		{
			turn = 1;
			cout << "Union player your move." << endl;
		}
		drawMapToConsole();
		cout << "X Position of Source [A-G]: ";
		cin >> sourceXPos;
		cout << "Y Position of Source [A-G]: ";
		cin >> sourceYPos;
		cout << "X Position of Destination [A-G]: ";
		cin >> destinationXPos;
		cout << "Y Position of Destination [A-G]: ";
		cin >> destinationYPos;

		parseInput(sourceXPos, sourceYPos, destinationXPos, destinationYPos);
	}

	return 0;	
}