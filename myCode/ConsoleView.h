/*
 * ConsoleView.h
 *
 *  Created on: 24-Dec-2023
 *      Author: zakisadique
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_

#include <vector>
#include "Board.h"

/**
 * @class ConsoleView
 * @brief Represents the console view for the Battleship game.
 *
 * This class is responsible for displaying the state of the game boards in the
 * console, including the player's own grid and the opponent's grid.
 */
class ConsoleView {
private:
    Board* board; /**< Pointer to the game board. */
    std::vector<std::vector<char>> myView; /**< View of the player's own grid.*/
    std::vector<std::vector<char>> opponentView; /**< View of the
    												opponent's grid. */

    /**
     * @brief Updates the console view based on the current state of the
     * player's own grid.
     */
    void getStateOwnGrid();

    /**
     * @brief Updates the console view based on the current state of the
     * opponent's grid.
     */
    void getStateOpponentGrid();

public:
    /**
     * @brief Constructs a ConsoleView with the given game board.
     * @param board Pointer to the game board.
     */
    ConsoleView(Board* board);

    /**
     * @brief Prints the current state of both the player's own grid and the
     * opponent's grid to the console.
     */
    void print();
};

#endif /* CONSOLEVIEW_H_ */

