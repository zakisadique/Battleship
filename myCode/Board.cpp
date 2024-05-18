/*
 * Board.cpp
 *
 *  Created on: 24-Dec-2023
 *      Author: zakisadique
 */

#include "Board.h"

Board::Board(int rows, int columns) : ownGrid(OwnGrid(rows, columns)),
	opponentGrid (OpponentGrid(rows, columns)), rows (rows), columns (columns){
}

int Board::getRows() const {
	return rows;
}

int Board::getColumns() const {
	return columns;
}

OwnGrid& Board::getOwnGrid() {
	return ownGrid;
}

OpponentGrid& Board::getOpponentGrid() {
	return opponentGrid;
}
