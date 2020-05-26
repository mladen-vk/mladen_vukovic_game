#include <ncurses.h>
#include "gameloop.h"
#include "Screen.h"
#include "Frame.h"
#include "Character.h"
#include <cmath>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

/*void gameLoop(Character &player, Character &monster1, Character &monster2, int ch) {
	// Check if the user wishes to play the game
	if(ch == 'q' || ch =='Q') return;

	std::vector<std::string> v{{"   TTTTTTT~~~~~                       ####     "},
				   {"      TTTT  ~~~~    TTTTT            ######    "},
				   {"         TTT                                   "},
				   {"                                               "},
				   {"                                               "},
				   {"                     ~~                        "},
				   {"                  ~~~~~~~                      "},
				   {"         a    a       ~~~~~~~~~      ######    "},
				   {"                  ~~~~~~~~                     "},
				   {"               h       h                       "},
				   {"                                               "},
				   {"         TTT                                   "},
				   {"   TTTTTTT                                     "},
				   {"      TTTT              ######                 "},
				   {"                                               "},
				   {"                                               "},
				   {"                  #######                      "},
				   {"            ####################               "},};

	//Create four independent ncurses windows
	Frame inventory(7, 29, 0, 51);
	inventory.printInventory(player);

	Frame gameMap(20, 50, 0, 0, &inventory);
	gameMap.printMap(v);

	Frame legend(13, 29, 7, 51);
	legend.printLegend();

	Frame interface(4, 80, 20, 0);

	// Show the main character on the screen
	gameMap.add(player);

	// Show the monsters on the screen
	gameMap.add(monster1);
	gameMap.add(monster2);


	while(1) {
		ch = getch();
		srand (time(NULL));
		// Main character movements
		if(ch == KEY_LEFT || ch == 'a' || ch =='A') {
			gameMap.add(player, player.getRow(), player.getCol() - 1);
			// Monster movements
			
			switch (rand() % 4 + 1) {
				case 1:
					gameMap.add(monster1, monster1.getRow(), monster1.getCol() - 1);
					gameMap.add(monster2, monster2.getRow(), monster2.getCol() + 1);
				break;
				case 2:
					gameMap.add(monster1, monster1.getRow() - 1, monster1.getCol());
					gameMap.add(monster2, monster2.getRow() + 1, monster2.getCol());
				break;
				case 3:
					gameMap.add(monster1, monster1.getRow() + 1, monster1.getCol());
					gameMap.add(monster2, monster2.getRow() - 1, monster2.getCol());
				break;
				case 4:
					gameMap.add(monster1, monster1.getRow(), monster1.getCol() + 1);
					gameMap.add(monster2, monster2.getRow(), monster2.getCol() - 1);
				break;
			}              
		}
		else if(ch == KEY_RIGHT || ch == 'd' || ch =='D') {
			gameMap.add(player, player.getRow(), player.getCol() + 1);
			// Monster movements
        		switch (rand() % 4 + 1) {
				case 1:
					gameMap.add(monster1, monster1.getRow(), monster1.getCol() - 1);
					gameMap.add(monster2, monster2.getRow(), monster2.getCol() + 1);
				break;
				case 2:
					gameMap.add(monster1, monster1.getRow() - 1, monster1.getCol());
					gameMap.add(monster2, monster2.getRow() + 1, monster2.getCol());
				break;
				case 3:
					gameMap.add(monster1, monster1.getRow() + 1, monster1.getCol());
					gameMap.add(monster2, monster2.getRow() - 1, monster2.getCol());
				break;
				case 4:
					gameMap.add(monster1, monster1.getRow(), monster1.getCol() + 1);
					gameMap.add(monster2, monster2.getRow(), monster2.getCol() - 1);
				break;
			}              
		}
		else if(ch == KEY_UP || ch == 'w' || ch =='W') {
			gameMap.add(player, player.getRow() - 1, player.getCol());
			// Monster movements
        		switch (rand() % 4 + 1) {
				case 1:
					gameMap.add(monster1, monster1.getRow(), monster1.getCol() - 1);
					gameMap.add(monster2, monster2.getRow(), monster2.getCol() + 1);
				break;
				case 2:
					gameMap.add(monster1, monster1.getRow() - 1, monster1.getCol());
					gameMap.add(monster2, monster2.getRow() + 1, monster2.getCol());
				break;
				case 3:
					gameMap.add(monster1, monster1.getRow() + 1, monster1.getCol());
					gameMap.add(monster2, monster2.getRow() - 1, monster2.getCol());
				break;
				case 4:
					gameMap.add(monster1, monster1.getRow(), monster1.getCol() + 1);
					gameMap.add(monster2, monster2.getRow(), monster2.getCol() - 1);
				break;
			}               
		}
		else if(ch == KEY_DOWN || ch == 's' || ch =='S') {
			gameMap.add(player, player.getRow() + 1, player.getCol());
			// Monster movements
        		switch (rand() % 4 + 1) {
				case 1:
					gameMap.add(monster1, monster1.getRow(), monster1.getCol() - 1);
					gameMap.add(monster2, monster2.getRow(), monster2.getCol() + 1);
				break;
				case 2:
					gameMap.add(monster1, monster1.getRow() - 1, monster1.getCol());
					gameMap.add(monster2, monster2.getRow() + 1, monster2.getCol());
				break;
				case 3:
					gameMap.add(monster1, monster1.getRow() + 1, monster1.getCol());
					gameMap.add(monster2, monster2.getRow() - 1, monster2.getCol());
				break;
				case 4:
					gameMap.add(monster1, monster1.getRow(), monster1.getCol() + 1);
					gameMap.add(monster2, monster2.getRow(), monster2.getCol() - 1);
				break;
			}               
		}
		else if(ch == 'q' || ch == 'Q') {
			break;
		}
	}

		
}*/

// Entry function for game
int main() {

	// Initialize ncurses
	Screen scr;

	// Print a welcome message on screen
	scr.add("Welcome to the game.\nPress any key to start.\nIf you want to quit press \"q\" or \"Q\"");

	// Wait until the user press a key
	int ch = getch();

	// Initialize the main character
	Character player('P', 1, 1, 10, 10);

	// Initialize a monster
	Character monster('M', 1, 48, 20, 20);

	// Start the game loop
	gameLoop(player, monster, ch);

	return 0;
}
