/*
 * Shot.h
 *
 *  Created on: 25-Dec-2023
 *      Author: zakisadique
 */

#ifndef MYCODE_SHOT_H_
#define MYCODE_SHOT_H_

#include "GridPosition.h"

/**
 * @class Shot
 * @brief Represents a shot fired in the Battleship game.
 *
 * This class defines the characteristics and behavior of a shot, including
 * the target position and the possible impact of the shot.
 */
class Shot {
private:
    GridPosition targetPosition; /**< The target position of the shot. */

public:
    /**
     * @brief Enumeration representing the possible impacts of a shot.
     */
    enum Impact {
        NONE, /**< No impact. */
        HIT, /**< The shot hit a ship. */
        SUNKEN /**< The shot resulted in a ship being sunken. */
    };

    /**
     * @brief Constructs a Shot with the specified target position.
     * @param targetPosition The target position of the shot.
     */
    Shot(GridPosition targetPosition);

    /**
     * @brief Gets the target position of the shot.
     * @return The target position.
     */
    GridPosition getTargetPosition() const;
};

#endif /* MYCODE_SHOT_H_ */

