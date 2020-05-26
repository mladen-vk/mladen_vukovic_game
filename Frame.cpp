#include "Frame.h"
#include <vector>
#include <string>

// Initialize a main window (no parent)
Frame::Frame(int nr_rows, int nr_cols, int _row, int _col, Frame *_subFrame) : m_height(nr_rows), 
					m_width(nr_cols), m_row(_row), m_col(_col), m_subFrame(_subFrame) {
	m_win = newwin(nr_rows, nr_cols, _row, _col);
	box(m_win, '#', '#');
	wrefresh(m_win);
}

// Delete window
Frame::~Frame() {
	delwin(m_win);
}

// Add a character to the window
void Frame::add(Character &x) {
	mvwaddch(m_win, x.getRow(), x.getCol(), x.getSymbol());
	wrefresh(m_win);
}

// Define the "erase" character, use an empty character for cleaning a cell or a
// visible character for showing the trace of a game character
void Frame::erase(Character &x) {
	mvwaddch(m_win, x.getRow(), x.getCol(), ' ');
}

// Check if the target position is free
bool Frame::targetPosition(Character &x, int _row, int _col) {
	// Get the element at the target position:
	char target = mvwinch(m_win, _row, _col);
	// If the target position is watter, mountain or tree stop the character to go through it
	if (target == '~' || target == '#' || target == 'T') {
		return FALSE;
	}
	// If the target position is a monster don't let the character to go through it (for now)
	if (target == 'M' || target == 'P') {
		x.setArmor(-5);
		x.setHealth(-5);
		// Print only stats for the player
		if(x.getSymbol() == 'P')
			m_subFrame -> printInventory(x);
		if(x.getArmor() + x.getHealth() <= 0)
			if(x.getSymbol() == 'P'){
				std::vector<std::string> v{{"                                               "},
				   {"                                               "},
				   {"                                               "},
				   {"                                               "},
				   {"                                               "},
				   {"                                               "},
				   {"                                               "},
				   {"                                               "},
				   {"                  GAME OVER                    "},
				   {"                                               "},
				   {"                                               "},
				   {"                                               "},
				   {"                                               "},
				   {"                                               "},
				   {"                                               "},
				   {"                                               "},
				   {"                                               "},
				   {"                                               "},};
				printMap(v);
			}
		return FALSE;
	}
	// If the target position is an armor plate add five points to the armor
	if (target == 'a') {
		x.setArmor(5);
		// Print only stats for the player
		if(x.getSymbol() == 'P')
			m_subFrame -> printInventory(x);
		return TRUE;
	}

	// If the target position is a health add five points to the healt
	if (target == 'h') {
		x.setHealth(5);
		// Print only stats for the player
		if(x.getSymbol() == 'P')
			m_subFrame -> printInventory(x);
		return TRUE;
	}
	return TRUE;
}

// Add a character at a specific position to the window
void Frame::add(Character &x, int _row, int _col) {
	if((_row >= 1 && _row < m_height - 1) && (_col >= 1 && _col < m_width - 1)) {
		if( !targetPosition(x, _row, _col) ) return;
		erase(x);
		mvwaddch(m_win, _row, _col, x.getSymbol());
		wrefresh(m_win);
		x.pos(_row, _col);	
	}
}

// Get the window
WINDOW* Frame::getWin() {
	return m_win;
}

// Get the height of the window
int Frame::getHeight() {
	return m_height;
}

// Get the width of the window
int Frame::getWidth() {
	return m_width;
}

// Get the row (y) position of the window
int Frame::getRow() {
	return m_row;
}

// Get the row (y) position of the window
int Frame::getCol() {
	return m_col;
}

// Print the map
void Frame::printMap(std::vector<std::string> &v) {
	int i = getRow();
	for(auto &s : v){
		mvwprintw(m_win, ++i, 1, s.c_str());
		wrefresh(m_win);
	}
}

// Print inventory
void Frame::printInventory(Character &x) {
	mvwprintw(m_win, 1, 2, "Inventory:");
	mvwprintw(m_win, 3, 2, "Armor Plates: %i", x.getArmor());
	mvwprintw(m_win, 4, 2, "Health Points: %i", x.getHealth());
	wrefresh(m_win);
}
// Print the legend
void Frame::printLegend() {
	mvwprintw(m_win, 1, 2, "Legend:");
	mvwprintw(m_win, 3, 2, "P - Player");
	mvwprintw(m_win, 4, 2, "a - Armor Plates");
	mvwprintw(m_win, 5, 2, "h - Healt Points");
	mvwprintw(m_win, 6, 2, "T - Tree");
	mvwprintw(m_win, 7, 2, "# - Mountain");
	mvwprintw(m_win, 8, 2, "~ - Watter");
	mvwprintw(m_win, 9, 2, "M - Monster/Enemy");
	mvwprintw(m_win, 11, 2, "Mladen Vukovic - Playrix");
	wrefresh(m_win);	
}
