/*
 * Ship.h
 *
 *  Created on: 24-Dec-2023
 *      Author: zakisadique
 */

#ifndef MYCODE_SHIP_H_
#define MYCODE_SHIP_H_

#include <set>
#include "GridPosition.h"

/**
 * @class Ship
 * @brief Represents a ship in the Battleship game.
 *
 * This class defines the characteristics and behavior of a ship, including its
 * bow and stern positions, validity check, length, and the calculation of its
 * occupied and blocked areas on the game grid.
 */
class Ship {
private:
    GridPosition bow; /**< The bow position of the ship. */
    GridPosition stern; /**< The stern position of the ship. */

public:
    /**
     * @brief Constructs a Ship with the specified bow and stern positions.
     * @param bow The bow position of the ship.
     * @param stern The stern position of the ship.
     */
    Ship(const GridPosition& bow, const GridPosition& stern);

    /**
     * @brief Checks if the ship is valid.
     * @return True if the ship is valid, false otherwise.
     */
    bool isValid() const;

    /**
     * @brief Gets the bow position of the ship.
     * @return The bow position.
     */
    GridPosition getBow() const;

    /**
     * @brief Gets the stern position of the ship.
     * @return The stern position.
     */
    GridPosition getStern() const;

    /**
     * @brief Gets the length of the ship.
     * @return The length of the ship.
     */
    int length() const;

	/**
	 * @brief Gets the set of grid positions occupied by the ship.
	 *
	 * This function calculates and returns a set of grid positions that are
	 * occupied by the ship, based on its bow and stern positions.
	 *
	 * @return A set of GridPosition objects representing the occupied area
	 * of the ship.
	 */
	const std::set<GridPosition> occupiedArea() const;
	/**
	 * @brief Gets the set of grid positions that are blocked by the ship.
	 *
	 * This function calculates and returns a set of grid positions that are
	 * blocked by the ship. It considers both the direct path of the ship and
	 * the surrounding cells, taking into account the neighboring cells in
	 * all eight directions.
	 *
	 * @return A set of GridPosition objects representing the blocked area
	 * of the ship.
	 */
	const std::set<GridPosition> blockedArea() const;
};

#endif /* MYCODE_SHIP_H_ */
