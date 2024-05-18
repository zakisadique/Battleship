/** @mainpage Battleship Board Implementation
 * Battleship is a strategy type guessing game for two players. It is played on
 * ruled grids (paper or board) on which each player's fleet of warships are
 * marked. The locations of the fleets are concealed from the other player.
 * Players alternate turns calling shots at the other player's ships, and the
 * objective of the game is to destroy the opposing player's fleet.
 *
 *	The goal for the initial version of the program is to replace the sheet of
 *	paper, i.e. a player can use the program to arrange his ships, keep track
 *	of the opponent's shots, and keep track of the results of his own shots.
 */


/*
 * main.cpp
 *
 *  Created on: 24-Dec-2023
 *      Author: zakisadique
 */

#include "tests.h"

/**
 * @brief The main entry point of the program.
 *
 * This function calls various test functions to validate different parts of the
 * program.
 *
 * @return 0 upon successful execution.
 */
int main() {

    part1tests();
    part2tests();
    part3tests();

    return 0;
}




