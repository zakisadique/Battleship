/*
 * GridPosition.h
 *
 *  Created on: 24-Dec-2023
 *      Author: zakisadique
 */

#ifndef MYCODE_GRIDPOSITION_H_
#define MYCODE_GRIDPOSITION_H_

#include <string>

/**
 * @class GridPosition
 * @brief Represents a position on a grid with a row and column.
 *
 * This class provides functionality to handle grid positions, including
 * validation, conversion to string, and comparison operations.
 */
class GridPosition {
private:
    char row; /**< The row of the grid position. */
    int column; /**< The column of the grid position. */

public:
    /**
     * @brief Constructs a GridPosition with the given row and column.
     * @param row The row of the grid position.
     * @param column The column of the grid position.
     */
    GridPosition(char row, int column);

    /**
     * @brief Constructs a GridPosition from a string representation.
     * @param position The string representation of the grid position.
     */
    GridPosition(std::string position);

    /**
     * @brief Checks if the grid position is valid.
     * @return True if the grid position is valid, false otherwise.
     */
    bool isValid() const;

    /**
     * @brief Gets the row of the grid position.
     * @return The row.
     */
    char getRow() const;

    /**
     * @brief Gets the column of the grid position.
     * @return The column.
     */
    int getColumn() const;

    /**
     * @brief Converts the grid position to a string.
     * @return The string representation of the grid position.
     */
    operator std::string() const;

    /**
     * @brief Checks if two grid positions are equal.
     * @param other The other GridPosition to compare.
     * @return True if the grid positions are equal, false otherwise.
     */
    bool operator==(const GridPosition &other) const;

    /**
     * @brief Checks if one grid position is less than another.
     * @param other The other GridPosition to compare.
     * @return True if this grid position is less than the other, false
     * otherwise.
     */
    bool operator<(const GridPosition &other) const;
};

#endif /* MYCODE_GRIDPOSITION_H_ */

