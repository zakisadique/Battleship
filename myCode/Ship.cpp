/*
 * Ship.cpp
 *
 *  Created on: 24-Dec-2023
 *      Author: zakisadique
 */
#include <iostream>
#include <vector>
#include <string>
#include "Ship.h"

Ship::Ship(const GridPosition& bow, const GridPosition& stern) : bow (bow),
	stern (stern){

	if (!isValid()){
		this -> bow = GridPosition("@0");
		this -> stern = GridPosition("@0");
	}
}

bool Ship::isValid() const {

	return ((bow.getRow() == stern.getRow() ||
		bow.getColumn() == stern.getColumn()) &&
		(this->length() >= 2 && this->length() <= 5));

}

int Ship::length() const{

	int length = 0;

		if (bow.getRow() == stern.getRow()){
			length = std::abs(stern.getColumn() - bow.getColumn()) + 1;

		} else if (bow.getColumn() == stern.getColumn()){
			length = std::abs(stern.getRow() - bow.getRow()) + 1;
		}

	return length;
}

GridPosition Ship::getBow() const {

	return bow;
}

GridPosition Ship::getStern() const {

	return stern;
}


const std::set<GridPosition> Ship::occupiedArea() const {

    std::set<GridPosition> occupied;

    /* Compare bow and stern and assign a multiplier (1 for left to right and
     * up to down, -1 for right to left and down to up)*/
    int multiplier = bow < stern ? 1 : -1;

    /* Assign bow and stern */
    GridPosition currentPosition = bow;
    GridPosition endPosition = stern;

    /* Initialise changeRow and changeColumn assuming the ship is oriented
     * horizontally */
    int changeRow = multiplier * 0;
    int changeColumn = multiplier * 1;

    /* Adjust changeRow and changeColumn if the ship is oriented vertically */
    if (bow.getColumn() == stern.getColumn()) {
        changeRow = multiplier * 1;
        changeColumn = multiplier * 0;
    }

    occupied.insert(currentPosition);

    /* Populate the set with grid positions along the ship's path */
    while (static_cast<std::string>(currentPosition) !=
           static_cast<std::string>(endPosition)) {

        currentPosition = GridPosition(currentPosition.getRow() + changeRow,
                                    currentPosition.getColumn() + changeColumn);
        occupied.insert(currentPosition);
    }

    return occupied;
}



const std::set<GridPosition> Ship::blockedArea() const {
    std::set<GridPosition> blocked;

    /* Define the eight possible directions to traverse around each ship cell */
    std::vector<std::pair<int, int>> traverse = {
        {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
        {1, 0}, {1, -1}, {0, -1}, {-1, -1}
    };

    /* Get the occupied area of the ship */
    std::set<GridPosition> occupiedArea = this->occupiedArea();

    /* Iterate through each cell in the ship's occupied area */
    for (auto& iterCell : occupiedArea) {
        /* Iterate through each direction around the current cell */
        for (auto& iterDirection : traverse) {
            /* Calculate the position of the cell in the current direction */
            GridPosition currentCell(iterCell.getRow() + iterDirection.first,
								 iterCell.getColumn() + iterDirection.second);

            /* Check if the calculated position is valid and insert it into the
             * blocked set */
            if (currentCell.isValid()) {
                blocked.insert(currentCell);
            }
        }

        /* Insert the current cell itself into the blocked set */
        blocked.insert(GridPosition(iterCell.getRow(), iterCell.getColumn()));
    }

    return blocked;
}
