#include <ncurses.h>
#include "gameloop.h"
#include "Screen.h"
#include "Frame.h"
#include "Character.h"
#include <cmath>
#include <stdlib.h>     
#include <time.h> 

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
	Character monster('M', 1, 48, 15, 15);

	// Start the game loop
	gameLoop(player, monster, ch);

	return 0;
}
