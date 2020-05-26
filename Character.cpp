#include "Character.h"

// Create a character
Character::Character(char _symbol, int _row, int _col, int _armorPlates, int _healthPoints) : m_symbol(_symbol), m_row(_row), 
			m_col(_col), m_armorPlates(_armorPlates), m_healthPoints(_healthPoints) {}

// Change the character position
void Character::pos(int _row, int _col) {
	m_row = _row;
	m_col = _col;
}

// Get character's row (y) position
int Character::getRow() {
	return m_row;
}

// Get character's col (x) position
int Character::getCol() {
	return m_col;
}

// Get the symbol of the character
char Character::getSymbol() {
	return m_symbol;
}

// Set armor of the character
void Character::setArmor(int x) {
	m_armorPlates += x;
}

// Set health of the character
void Character::setHealth(int x) {
	m_healthPoints += x;
}

// Get armor of the character
int Character::getArmor() {
	return m_armorPlates;
}

// Get health of the character
int Character::getHealth() {
	return m_healthPoints;
}
