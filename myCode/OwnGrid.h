/*
 * OwnGrid.h
 *
 *  Created on: 24-Dec-2023
 *      Author: zakisadique
 */

#ifndef MYCODE_OWNGRID_H_
#define MYCODE_OWNGRID_H_

#include <vector>
#include <map>
#include "Ship.h"
#include "Shot.h"

/**
 * @class OwnGrid
 * @brief Represents the player's own grid in the Battleship game.
 *
 * This class manages the state of the player's own grid, including the
 * placement of ships and processing the impact of shots on the grid.
 */
class OwnGrid {
private:
    int rows; /**< The number of rows in the grid. */
    int columns; /**< The number of columns in the grid. */
    std::vector<Ship> ships; /**< Vector to store the player's ships. */
    std::map<int, int> numberShips; /**< Map to store the count of ships of
    									each length. */
    std::set<GridPosition> shotAt; /**< Set to store the positions where shots
    									have been fired. */
    std::map<GridPosition, Shot::Impact> shotResults; /**< Map to store shot
													impacts on the grid. */

public:
    /**
     * @brief Constructs an OwnGrid with the specified number of rows and
     * columns.
     * @param rows The number of rows in the grid.
     * @param columns The number of columns in the grid.
     */
    OwnGrid(int rows, int columns);

    /**
     * @brief Gets the number of columns in the grid.
     * @return The number of columns.
     */
    int getColumns() const;

    /**
     * @brief Gets the number of rows in the grid.
     * @return The number of rows.
     */
    int getRows() const;

    /**
     * @brief Gets a const reference to the vector of ships.
     * @return A const reference to the vector of ships.
     */
    const std::vector<Ship>& getShips() const;

    /**
     * @brief Attempts to place a ship on the own grid.
     *
     * This function checks if the given ship is valid and can be placed on the
     * own grid without overlapping with existing ships. If successful, it
     * updates the state of the own grid by adding the ship and decrementing
     * the ship count.
     *
     * @param ship The ship to be placed.
     * @return True if the ship is successfully placed, false otherwise.
     */
    bool placeShip(const Ship& ship);

    /**
     * @brief Processes the impact of a shot on the own grid.
     *
     * This function updates the state of the own grid based on the impact
     * of a shot, including marking the shot position and determining if a ship
     * has been hit or sunk.
     *
     * @param shot The shot fired.
     * @return The impact of the shot (e.g., NONE, HIT, SUNKEN).
     */
    Shot::Impact takeBlow(const Shot& shot);

    /**
     * @brief Gets a const reference to the set of positions where shots have
     * been fired.
     * @return A const reference to the set of shot positions.
     */
    const std::set<GridPosition>& getShotAt() const;
	const std::map<GridPosition, Shot::Impact>& getShotResults() const;
};

#endif /* MYCODE_OWNGRID_H_ */

