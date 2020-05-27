#include "gameloop.h"

void moveMonster(std::shared_ptr<Frame> gameMap, Character &monster, Character &player) {
	
	//Monster moves randomly
	srand (time(NULL) * 1000);

	switch (rand() % 4 + 1) {
		case 1:
			gameMap->add(monster, player, monster.getRow(), monster.getCol() - 1);
		break;
		case 2:
			gameMap->add(monster, player, monster.getRow() - 1, monster.getCol());
		break;
		case 3:
			gameMap->add(monster, player, monster.getRow() + 1, monster.getCol());
		break;
		case 4:
			gameMap->add(monster, player, monster.getRow(), monster.getCol() + 1);
		break;
	}                  
}

void gameLoop(Character &player, Character &monster, int ch) {
	
	// Check if the user wishes to play the game
	if(ch == 'q' || ch =='Q') return;

	// This is how map is going to look a like
	std::vector<std::string> v{{"   TTTTTTT~~~~~              ####              "},
				   {"      TTTT  ~~~~    TTTTT     ######           "},
				   {"         TTT                                   "},
				   {"                            h    a    h        "},
				   {"                                               "},
				   {"       a             ~~                        "},
				   {"                  ~~~~~~~                      "},
				   {"         a    a       ~~~~~~~~~  a   ######    "},
				   {"                  ~~~~~~~~                     "},
				   {"               h       h                       "},
				   {"                                               "},
				   {"     a   TTT                      a      h  h  "},
				   {"   TTTTTTT       a                             "},
				   {"      TTTT              ######      a          "},
				   {"               h                        a      "},
				   {"                                               "},
				   {"                  #######                      "},
				   {"            ####################               "},};

	//Create four independent ncurses windows
        std::shared_ptr<Frame> inventory = std::make_shared<Frame>(7, 29, 0, 51);
	inventory->printInventory(player);

	std::shared_ptr<Frame> gameMap = std::make_shared<Frame>(20, 50, 0, 0, inventory.get());
	gameMap->printMap(v);

	std::shared_ptr<Frame> legend = std::make_shared<Frame>(13, 29, 7, 51);
	legend->printLegend();

	std::shared_ptr<Frame> interface = std::make_shared<Frame>(4, 80, 20, 0);


	// Show the main character on the screen
	gameMap->add(player);

	// Show the monsters on the screen
	gameMap->add(monster);

	while(1) {
		ch = getch();
		// Main character movements
		if(ch == KEY_LEFT || ch == 'a' || ch =='A') {
			gameMap->add(player, monster, player.getRow(), player.getCol() - 1);
			// Monster random movements
			moveMonster(gameMap, monster, player);
		}
		else if(ch == KEY_RIGHT || ch == 'd' || ch =='D') {
			gameMap->add(player, monster, player.getRow(), player.getCol() + 1);
			// Monster movements
        		moveMonster(gameMap, monster, player);
		}
		else if(ch == KEY_UP || ch == 'w' || ch =='W') {
			gameMap->add(player, monster, player.getRow() - 1, player.getCol());
			// Monster movements
        		moveMonster(gameMap, monster, player);     
		}
		else if(ch == KEY_DOWN || ch == 's' || ch =='S') {
			gameMap->add(player, monster, player.getRow() + 1, player.getCol());
			// Monster movements
        		moveMonster(gameMap, monster, player);            
		}
		else if(ch == 'q' || ch == 'Q') {
			break;
		}
	}

		
}
