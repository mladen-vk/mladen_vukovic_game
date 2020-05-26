#include "Screen.h"

// Initialize the ncurses library
Screen::Screen() {
	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	// Aquire the screen dimensions
	getmaxyx(stdscr, m_height, m_width);
}

// Clear ncurses
Screen::~Screen() {
	endwin();
}

// Print a message on the screen
void Screen::add(const char *message) {
	printw(message);
}

// Get the screen height
int Screen::getHeight() {
	return m_height;
}

// Get the screen width
int Screen::getWidth() {
	return m_width;
}

// Don't wait for the user to press a key
void Screen::zerodelay() {
	nodelay(stdscr, TRUE);
}

// Wait for the user to press a key (this is the default when ncurses starts)
void Screen::delay() {
	nodelay(stdscr, FALSE);
}
