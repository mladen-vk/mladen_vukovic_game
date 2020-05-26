
#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
public:
	// Create a character
	Character(char symbol, int _row, int _col, int _armorPlates, int _healthPoints);
	// Change the character position
	void pos(int _row, int _col);
	// Get character's row (y) position
	int getRow();
	// Get character's col (x) position
	int getCol();
	// Get the symbol of the character
	char getSymbol();
	// Set armor of the character
	void setArmor(int x);
	// Set health of the character
	void setHealth(int x);
	// Get armor of the character
	int getArmor();
	// Get healt of the character
	int getHealth();
private:
	int m_row, m_col;
	int m_armorPlates, m_healthPoints;
	char m_symbol;
};

#endif
