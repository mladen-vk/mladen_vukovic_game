#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <memory>
#include <ncurses.h>
#include "Screen.h"
#include "Frame.h"
#include "Character.h"



#ifndef GAMELOOP_H
#define GAMELOOP_H

void gameLoop(Character &player, Character &monster, int ch);

#endif
