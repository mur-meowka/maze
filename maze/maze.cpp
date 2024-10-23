// maze.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const int ROW = 10;
const int COL = 10;

void draw_map(char map[ROW][COL]) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			wcout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int position[2] = { 0,4 };
	char map[ROW][COL] = {
		{'#','#','#','#',' ','#','#','#','#','#'},
		{'#','#',' ',' ',' ','#',' ',' ',' ','#'},
		{'#',' ',' ','#','#','#',' ','#',' ','#'},
		{'#','#',' ',' ',' ',' ',' ','#','&','#'},
		{'#','#','#','#',' ','#',' ','#','#','#'},
		{'#','#','#','#','#','#',' ','#','#','#'},
		{'#',' ',' ',' ','#','#',' ',' ','#','#'},
		{'#',' ','#',' ',' ','#','#',' ','#','#'},
		{'#',' ','#','#',' ',' ',' ',' ',' ','#'},
		{'#',' ','#','#','#','#','#','#','#','#'},
	};

	bool in_game = true;
	while (in_game) {
		system("cls");
		map[position[0]][position[1]] = '🐱';
		draw_map(map);
		cout << "use w,a,s,d to move!\n";
		char move;
		cin >> move;
		int new_position[2] = { position[0], position[1] };
		if (move == 'w') {
			new_position[0]--;
		}
		else if (move == 's') {
			new_position[0]++;
		}
		else if (move == 'a') {
			new_position[1]--;
		}
		else if (move == 'd') {
			new_position[1]++;
		}

		if (new_position[0]<0 || new_position[0]> ROW || new_position[1]<0 || new_position[1]> COL) {
			continue;
		}
		if (map[new_position[0]][new_position[1]] == ' ') {
			map[position[0]][position[1]] = ' ';
			position[0] = new_position[0];
			position[1] = new_position[1];
		}
		if (map[new_position[0]][new_position[1]] == '&') {
			map[position[0]][position[1]] = ' ';
			position[0] = new_position[0];
			position[1] = new_position[1];
			in_game = false;
		}
		
	}
	cout << "you won";
}