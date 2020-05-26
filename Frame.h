#include <ncurses.h>
#include <vector>
#include <string>
#include "Character.h"

#ifndef FRAME_H
#define FRAME_H

class Frame {
public:
	// Get the window
	WINDOW *getWin();
	// Get the sub window
	WINDOW *getSubWin();
	// Initialize a window
	Frame(int nr_rows, int nr_cols, int _row, int _col, Frame *_subFrame = nullptr);
	~Frame();
	// Get the height of the window
	int getHeight();
	// Get the width of the window
	int getWidth();
	// Get the row (y) position of the window
	int getRow();
	// Get the row (y) position of the window
	int getCol();
	// Refresh the window
	void refresh();
	// Add a character to the window
	void add(Character &x);
	// Define the "erase" character, use an empty character for cleaning a cell or a
	// visible character for showing the trace of a game character	
	void erase(Character &x);
	// Add a character at a specific position to the window
	void add(Character &x, int _row, int _col);
	// Check if the target position is free
	bool targetPosition(Character &x, int _row, int _col);
	// Print the map
	void printMap(std::vector<std::string> &v);
	// Print inventory
	void printInventory(Character &x);
	// Print the legend
	void printLegend();
	
private:
	// Frame dimensions
	int m_height, m_width;
	// Frame position
	int m_row, m_col;
	// Pointer to an ncurses WINDOW
	WINDOW *m_win;
	// Pointer to an sub frame
	Frame *m_subFrame;
};

#endif
