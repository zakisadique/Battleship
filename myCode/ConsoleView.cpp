/*
 * ConsoleView.cpp
 *
 *  Created on: 24-Dec-2023
 *      Author: zakisadique
 */

#include "ConsoleView.h"
#include <vector>
#include <iostream>
#include <string>

ConsoleView::ConsoleView(Board *board) : board (board){

	int rows = board->getRows();
	int columns = board->getColumns();
	myView.resize(rows, std::vector<char>(columns, '~'));
	opponentView.resize(rows, std::vector<char>(columns, '~'));
}

void ConsoleView::getStateOpponentGrid() {
    /*
     * Retrieve all shots on the opponent's grid
     */
    std::map<GridPosition, Shot::Impact> allShots =
        board->getOpponentGrid().getShots();

    /*
     * Iterate through each shot and update the opponentgrid vector
     */
    for (auto& shot : allShots) {
        if (shot.second == Shot::Impact::NONE) {
            /*
             * If the shot is a miss, mark it with '^'
             */
            opponentView[shot.first.getRow() - 'A']
                         [shot.first.getColumn() - 1] = '^';
        } else if (shot.second == Shot::Impact::HIT){
            /*
             * If the shot is a hit, mark it with '0'
             */
            opponentView[shot.first.getRow() - 'A']
                         [shot.first.getColumn() - 1] = '0';
        }
    }
    /*
     * Check for sunken ships and mark the corresponding position with
     * '#'
     */
    auto sunkenShips = board->getOpponentGrid().getSunkenShips();
    for (auto& sunkenShip : sunkenShips) {
    	std::set<GridPosition> occupiedAreaSunkenShip =
    			sunkenShip.occupiedArea();
    	for (auto& sunkPositions : occupiedAreaSunkenShip){
    		opponentView[sunkPositions.getRow() - 'A']
						[sunkPositions.getColumn() - 1] = '#';
    	}
    }
}

void ConsoleView::getStateOwnGrid() {

    std::set<GridPosition> allOccupiedArea;
    /*
     * Collect all occupied areas of the player's ships
     */
    for (auto& ship : board->getOwnGrid().getShips()) {
        std::set<GridPosition> currentShipOccupiedArea = ship.occupiedArea();
        allOccupiedArea.insert(currentShipOccupiedArea.begin(),
                                currentShipOccupiedArea.end());
    }

    /*
     * Mark player's ships in the console view
     */
    for (auto& currentPosition : allOccupiedArea) {
        myView[currentPosition.getRow() - 'A']
              [currentPosition.getColumn() - 1] = '#';
    }

    /*
     * Iterate through each shot and update the mygrid vector
     */
    std::map<GridPosition, Shot::Impact> allShots =
        board->getOwnGrid().getShotResults();

    for (auto& shot : allShots){
    	if (shot.second == Shot::Impact::NONE){
		/*
		 * If the shot is a miss, mark it with '^'
		 */
    		myView[shot.first.getRow() - 'A']
				   [shot.first.getColumn() - 1] = '^';
    	} else {
		/*
		 * If the shot is a hit or sunken, mark it with '0'
		 */
    		myView[shot.first.getRow() - 'A']
				   [shot.first.getColumn() - 1] = '0';
    	}
    }

}

void ConsoleView::print() {

    /*
     * Update the console view based on the current state of grids
     */
    getStateOwnGrid();
    getStateOpponentGrid();

    /*
     * Print the header for the player's own grid
     */
    std::cout << "----------------------" << std::endl;
    std::cout << "Own Grid" << std::endl;
    std::cout << "----------------------" << std::endl;

    /*
     * Print the column numbers (first row)
     */
    int numColumns = board->getColumns();
    std::cout << "  ";
    for (int i = 1; i <= numColumns; ++i) {
        if (i >= 10) {
            std::cout << std::to_string(i).substr(0, 1);
            std::cout << " ";
        } else {
            std::cout << "  ";
        }
    }
    std::cout << std::endl;

    /*
     * Print the rows and the state of the player's own grid
     */
    char rowNumber = 'A';
    for (int i = 0; i <= board->getRows(); ++i) {
        for (int j = 0; j <= board->getColumns(); ++j) {
            if (i == 0) {
                /*
                 * Print column number
                 */
                std::cout << (j == 0 ? "  " : std::to_string(j % 10) + " ");
            } else if (j == 0) {
                /*
                 * Print row number
                 */
                std::cout << rowNumber << " ";
                rowNumber++;
            } else {
                /*
                 * Print the state of the player's own grid
                 */
                std::cout << myView[i - 1][j - 1] << " ";
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    /*
     * Print the header for the opponent's grid
     */
    std::cout << "----------------------" << std::endl;
    std::cout << "Opponent's Grid" << std::endl;
    std::cout << "----------------------" << std::endl;

    /*
     * Print the column numbers for the opponent's grid (first row)
     */
    numColumns = board->getColumns();
    std::cout << "  ";
    for (int i = 1; i <= numColumns; ++i) {
        if (i >= 10) {
            std::cout << std::to_string(i).substr(0, 1);
            std::cout << " ";
        } else {
            std::cout << "  ";
        }
    }
    std::cout << std::endl;

    /*
     * Print the rows and the state of the opponent's grid
     */
    rowNumber = 'A';
    for (int i = 0; i <= board->getRows(); ++i) {
        for (int j = 0; j <= board->getColumns(); ++j) {
            if (i == 0) {
                /*
                 * Print column number
                 */
                std::cout << (j == 0 ? "  " : std::to_string(j % 10) + " ");
            } else if (j == 0) {
                /*
                 * Print row number
                 */
                std::cout << rowNumber << " ";
                rowNumber++;
            } else {
                /*
                 * Print the state of the opponent player's grid
                 */
                std::cout << opponentView[i - 1][j - 1] << " ";
            }
        }
        std::cout << std::endl;
    }
}
