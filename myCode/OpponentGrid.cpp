/*
 * OpponentGrid.cpp
 *
 *  Created on: 24-Dec-2023
 *      Author: zakisadique
 */

#include "OpponentGrid.h"
#include <iostream>

OpponentGrid::OpponentGrid(int rows, int columns) : rows (rows),
	columns (columns){
}

int OpponentGrid::getRows() {
	return rows;
}

int OpponentGrid::getColumns() {
	return columns;
}

const std::map<GridPosition, Shot::Impact>& OpponentGrid::getShots() const {
	return shots;
}

const std::vector<Ship>& OpponentGrid::getSunkenShips() const {
	return sunkenShips;
}


void OpponentGrid::getShotResult(const Shot &shot, Shot::Impact impact) {

	const GridPosition& targetPosition = shot.getTargetPosition();
    /* Check if the shot target position is within the grid boundaries */
    if (targetPosition.getRow() < 'A' ||
    		targetPosition.getRow() >= 'A' + rows) {
        return;
    } else if (targetPosition.getColumn() <= 0 ||
    		targetPosition.getColumn() > columns) {
        return;
    }

    /* Update the shots map with the shot result */
    shots[targetPosition] = impact;


    /* Process sunken ship */
    if (impact == Shot::Impact::SUNKEN) {
        /* Directions for traversing neighboring positions */
        std::vector<std::pair<int, int>> traverse = {
            {-1, 0}, {0, 1},
            {1, 0}, {0, -1}
        };

        GridPosition currentPosition = targetPosition;
        GridPosition endOne = currentPosition;
        GridPosition endTwo = targetPosition;
        int directionTraveled = 0;

        auto direction = traverse.begin();
        while (direction != traverse.end()) {

        	/* Find a hit while traversing in a particular direction */
            auto foundHit = shots.find(GridPosition(currentPosition.getRow() +
							 direction->first, currentPosition.getColumn() +
							 direction->second));

            if (foundHit != shots.end() &&
            		(foundHit->second == Shot::Impact::HIT)) {
                currentPosition = GridPosition(currentPosition.getRow() +
						   direction->first, currentPosition.getColumn() +
						   direction->second);

                continue;
            } else {
            	/* if hit not found and no traversal was done, traverse in
            	 * next direction available
            	 */
                if (targetPosition == currentPosition) {
                    ++direction;
                } else {
                    /* After traversing through all the HITS, found one of the
                     * ends of the ship.
                     * Assign the ends of the sunken ship, and traverse in next
                     * direction available
                     */
                	++directionTraveled;
                	/*
                	 * Increase the count of valid direction traveled;
                	 * can be a maximum of 2, ship will only be placed either
                	 * horizontal or vertical
                	 */
                	if (directionTraveled == 1){
                		endOne = currentPosition;

                	} else if (directionTraveled == 2){
                		endTwo = currentPosition;
                	}
                	++direction;
                	currentPosition = targetPosition;

                }
            }
        }
        if (directionTraveled != 0){
        	/*
        	 * Determine Bow and Stern of the ship
        	 */

        	GridPosition bow = endOne < endTwo ?
        			endOne : endTwo;
			GridPosition stern = endOne == bow ?
					endTwo : endOne;

        	sunkenShips.push_back(Ship(bow, stern));
        }
    }
}

