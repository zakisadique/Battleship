/*
 * GridPosition.cpp
 *
 *  Created on: 24-Dec-2023
 *      Author: zakisadique
 */

#include "GridPosition.h"
#include <iostream>
#include <cctype>

GridPosition::GridPosition(char row, int column) {
	this->row = row;
	this->column = column;

	if (!isValid()) {
		this->row = ' ';
		this->column = -1;
	}
}

GridPosition::GridPosition(std::string position) {

	if (position.length() > 3) {
		this->row = ' ';
		this->column = -1;
	} else {
		row = std::toupper(position[0]);
		column = std::stoi(position.substr(1));

		if (!isValid()) {
			this->row = ' ';
			this->column = -1;
		}
	}

}

bool GridPosition::isValid() const {

	return (std::isalpha(row) && column > 0);
}

char GridPosition::getRow() const {
	return row;
}

int GridPosition::getColumn() const {
	return column;
}

GridPosition::operator std::string() const {
	return (std::string(1, row) + std::to_string(column));
}

bool GridPosition::operator==(const GridPosition &other) const {
	return (other.row == this -> row && other.column == this -> column);
}

bool GridPosition::operator<(const GridPosition &other) const {
	if (this -> row < other.row) {
		return true;
	} else if (this -> row == other.row && this -> column < other.column) {
		return true;
	}
	return false;
}
