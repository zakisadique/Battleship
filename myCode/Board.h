/*
 * Board.h
 *
 *  Created on: 24-Dec-2023
 *      Author: zakisadique
 */

#ifndef MYCODE_BOARD_H_
#define MYCODE_BOARD_H_

#include "OwnGrid.h"
#include "OpponentGrid.h"

/**
 * @class Board
 * @brief Represents the game board consisting of the player's own grid and the
 * opponent's grid.
 */
class Board {
private:
    OwnGrid ownGrid; /**< The player's own grid. */
    OpponentGrid opponentGrid; /**< The opponent's grid. */
    int rows; /**< Number of rows. */
    int columns; /**< Number of columns. */

public:
    /**
     * @brief Constructs a Board with the specified number of rows and columns.
     * @param rows The number of rows in the board.
     * @param columns The number of columns in the board.
     */
    Board(int rows, int columns);

    /**
     * @brief Gets the number of rows in the board.
     * @return The number of rows.
     */
    int getRows() const;

    /**
     * @brief Gets the number of columns in the board.
     * @return The number of columns.
     */
    int getColumns() const;

    /**
     * @brief Gets a reference to the opponent's grid.
     * @return A reference to the opponent's grid.
     */
    OpponentGrid& getOpponentGrid();

    /**
     * @brief Gets a reference to the player's own grid.
     * @return A reference to the player's own grid.
     */
    OwnGrid& getOwnGrid();
};

#endif /* MYCODE_BOARD_H_ */

