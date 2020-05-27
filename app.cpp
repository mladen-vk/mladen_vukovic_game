#include "gameloop.h"
#include "Screen.h"
#include "Frame.h"
#include "Character.h"
#include <ncurses.h>
#include <memory>
#include <cmath>
#include <stdlib.h>     
#include <time.h> 

// Entry function for the game
int main() {

	// Initialize ncurses
	std::unique_ptr<Screen> scr(new Screen());

	// Print a welcome message on screen
	scr->add("Welcome to the game.\nPress any key to start.\nIf you want to quit press \"q\" or \"Q\"");

	// Wait until the user press a key
	int ch = getch();

	// Initialize the main character
	std::shared_ptr<Character> player = std::make_shared<Character>('P', 1, 1, 10, 10);

	// Initialize a monster
	std::shared_ptr<Character> monster = std::make_shared<Character>('M', 1, 48, 15, 15);

	// Start the game loop
	gameLoop(*player, *monster, ch);

	return 0;
}
