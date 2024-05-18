/*
 * OpponentGrid.h
 *
 *  Created on: 24-Dec-2023
 *      Author: zakisadique
 */

#ifndef MYCODE_OPPONENTGRID_H_
#define MYCODE_OPPONENTGRID_H_

#include <vector>
#include <map>
#include "Ship.h"
#include "Shot.h"

/**
 * @class OpponentGrid
 * @brief Represents the opponent's grid in the Battleship game.
 *
 * This class manages the state of the opponent's grid, including shot impacts
 * and information about sunken ships.
 */
class OpponentGrid {
private:
    int rows; /**< The number of rows in the grid. */
    int columns; /**< The number of columns in the grid. */

    std::map<GridPosition, Shot::Impact> shots; /**< Map to store shot impacts
													on the grid. */
    std::vector<Ship> sunkenShips; /**< Vector to store information about
										sunken ships. */

public:
    /**
     * @brief Constructs an OpponentGrid with the specified number of rows and
     * columns.
     * @param rows The number of rows in the grid.
     * @param columns The number of columns in the grid.
     */
    OpponentGrid(int rows, int columns);

    /**
     * @brief Gets the number of rows in the grid.
     * @return The number of rows.
     */
    int getRows();

    /**
     * @brief Gets the number of columns in the grid.
     * @return The number of columns.
     */
    int getColumns();

    /**
     * @brief Updates the opponent's grid based on the result of a shot.
     *
     * This function handles the impact of a shot on the opponent's grid,
     * storing the state of the shots and tracking sunken ships.
     *
     * @param shot The shot fired.
     * @param impact The impact of the shot (e.g., NONE, HIT, SUNKEN).
     */
    void getShotResult(const Shot& shot, Shot::Impact impact);

    /**
     * @brief Gets a const reference to the vector of sunken ships.
     * @return A const reference to the vector of sunken ships.
     */
    const std::vector<Ship>& getSunkenShips() const;

    /**
     * @brief Gets a const reference to the map of shots on the grid.
     * @return A const reference to the map of shots on the grid.
     */
    const std::map<GridPosition, Shot::Impact>& getShots() const;
};

#endif /* MYCODE_OPPONENTGRID_H_ */

