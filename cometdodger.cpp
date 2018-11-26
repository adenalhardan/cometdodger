#include <iostream>

using namespace std;

bool CheckGame(int);
void CreateAsterisk(void);
void MoveAsterisk(void);
int ProcessInput(char, int);
void DisplayScreen(void);
char GetInput(void);

char map[9];

const char LEFT_CONTROL = 'a';
const char RIGHT_CONTROL = 'd';

int main() {
	bool game;
	char input;
	int position;
	
	game = true;
	position = 1;
	
	map[0] = map[1] = map[2] = ' ';
	map[3] = map[4] = map[5] = ' ';
	map[6] = ' ';
	map[7] = '/';
	map[8] = ' ';
	
	CreateAsterisk();
	
	while (game) {
		DisplayScreen();
		input = GetInput();
		position = ProcessInput(input, position);
		game = CheckGame(position);
		MoveAsterisk();
		CreateAsterisk();
	}
	
	DisplayScreen();
	cout << "Game Over!" << endl;
}     

bool CheckGame(int position) {
	if (position == 0 && map[3] == '*')
		return(false);
	if (position == 1 && map[4] == '*')
		return(false);
	if (position == 2 && map[5] == '*')
		return(false);
		
	return(true);
}

void MoveAsterisk() {
	for(int i = 8; i >= 0; i--) {
		if(map[i] == '*'){
			map[i] = ' ';
			
			if (i < 6)
				map[i + 3] = '*';
		}
	}
}

void CreateAsterisk() {
	int flag = 0;
	
	srand(time(0));
	
	int random = rand() % 100 + 1;
	if (random > 50) {
		map[0] = '*';
		flag++;
	}
	
	random = rand() % 100 + 1;
	if (random > 50) {
		map[1] = '*';
		flag++;
	}
	
	random = rand() % 100 + 1;
	if (random > 50) {
		map[2] = '*';
		flag++;
	}
	
	if (flag == 3) {
		random = rand() % 99 + 1;
		
		if (random < 33) 
			map[0] = ' ';
		
		if (random < 66) 
			map[1] = ' ';	
			
		if (random < 99) 
			map[2] = ' ';	
	}
}

int ProcessInput(char input, int position) {
	switch (position) {
		case 0:
			switch(input) {
				case RIGHT_CONTROL:
					map[6] = ' ';
					map[7] = '/';
					position = 1;
			}
		break;
		
		case 1:
			switch(input) {
				case LEFT_CONTROL:
					map[7] = ' ';
					map[6] = '/';
					position = 0;
				break;
				case RIGHT_CONTROL:
					map[7] = ' ';
					map[8] = '/';
					position = 2;
			}
		break;
		
		case 2:
			switch(input) {
				case LEFT_CONTROL:
					map[8] = ' ';
					map[7] = '/';
					position = 1;
				break;
			}
	}
	
	return(position);
}

void DisplayScreen() {
	cout << " _ _ _ _" << endl;                                                                          
	cout << "| " << map[0] << " " << map[1] << " " << map[2] << " |" << endl;   
	cout << "| " << map[3] << " " << map[4] << " " << map[5] << " |" << endl;   
	cout << "| " << map[6] << " " << map[7] << " " << map[8] << " |" << endl;  
	cout << " ‾ ‾ ‾ ‾" << endl;          
}

char GetInput() {
	char input;
	
	cout << "> ";
	cin >> input;
	
	for(int i = 0; i < 58; i++)
		cout << "\b";
	
	return(input);
}
