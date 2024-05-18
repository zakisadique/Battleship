/*
 * Shot.cpp
 *
 *  Created on: 25-Dec-2023
 *      Author: zakisadique
 */

#include "Shot.h"


Shot::Shot(GridPosition targetPoistion) : targetPosition (targetPoistion){
}

GridPosition Shot::getTargetPosition() const {
	return targetPosition;
}


