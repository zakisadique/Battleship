/*
 * OwnGrid.cpp
 *
 *  Created on: 24-Dec-2023
 *      Author: zakisadique
 */

#include "OwnGrid.h"
#include <algorithm>
#include <iostream>

OwnGrid::OwnGrid(int rows, int columns) : rows(rows), columns (columns){
	numberShips = {
		{5, 1},
		{4, 2},
		{3, 3},
		{2, 4}
	};
}

int OwnGrid::getColumns() const {
	return columns;
}

int OwnGrid::getRows() const {
	return rows;
}

const std::vector<Ship>& OwnGrid::getShips() const {
	return ships;
}


bool OwnGrid::placeShip(const Ship& ship) {

    /* Check if the ship is valid */
    if (!ship.isValid()) {
        return false;
    }

    /* Check if there are available ships of the given length */
    if (numberShips[ship.length()] < 1) {
        return false;
    }

    /* Check if the ship's positions are within the grid boundaries */
    if ((ship.getBow().getRow() < 'A' || ship.getBow().getRow() >= 'A' + rows)
    		|| (ship.getStern().getRow() < 'A' || ship.getStern().getRow() >=
    				'A' + rows)) {
        return false;
    } else if ((ship.getBow().getColumn() <= 0 || ship.getBow().getColumn() >
    				columns) ||
               (ship.getStern().getColumn() <= 0 || ship.getStern().getColumn()
				   > columns)) {
        return false;
    }

    /* Get blocked areas from all placed ships */
    std::set<GridPosition> allBlockedArea;
    for (const auto& ship : ships) {
        std::set<GridPosition> currentShipBlockedArea = ship.blockedArea();
        allBlockedArea.insert(currentShipBlockedArea.begin(),
        		currentShipBlockedArea.end());
    }
    /* Check for overlapping with existing ships */
    std::set<GridPosition> intersection;
    for (const auto& element : ship.occupiedArea()) {
        if (allBlockedArea.find(element) != allBlockedArea.end()) {
            intersection.insert(element);
        }
    }
    /* If the ship overlaps, return false */
    if (!intersection.empty()) {
        return false;
    }

    /* Place the ship on the own grid */
    ships.push_back(ship);
    --numberShips[ship.length()];

    return true;
}

Shot::Impact OwnGrid::takeBlow(const Shot &shot) {
    Shot::Impact impact = Shot::Impact::NONE;

    /* Check if the shot target position is within the grid boundaries */
    if (shot.getTargetPosition().getRow() < 'A' || shot.getTargetPosition().
    		getRow() >= 'A' + rows) {
        return impact;
    } else if (shot.getTargetPosition().getColumn() <= 0 ||
    		shot.getTargetPosition().getColumn() > columns) {
        return impact;
    }

    /* Mark the shot position */
    shotAt.insert(shot.getTargetPosition());

    /* Check if the shot hits any ship */
    for (auto currShip : ships) {
        std::set<GridPosition> currOccupied = currShip.occupiedArea();

        if (currOccupied.find(shot.getTargetPosition()) != currOccupied.end()) {

            impact = Shot::Impact::HIT;

            std::set<GridPosition> intersection;

            /* Check for intersection with previously shot positions */
            for (const auto& element : currOccupied) {
                if (shotAt.find(element) != shotAt.end()) {
                    intersection.insert(element);
                }
            }

            /* Check if the ship is completely sunk */
            if (static_cast<int>(intersection.size()) == currShip.length()) {
                impact = Shot::Impact::SUNKEN;
            }
        }
        /* Break if a ship has been hit or sunk */
        if (impact != Shot::Impact::NONE) {
            break;
        }
    }
    shotResults[shot.getTargetPosition()] = impact;
    return impact;
}

const std::map<GridPosition, Shot::Impact>& OwnGrid::getShotResults() const
{
	return shotResults;
}

const std::set<GridPosition>& OwnGrid::getShotAt() const {
	return shotAt;
}
