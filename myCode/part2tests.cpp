/*
 * part2tests.cpp
 *
 *  Created on: 26-Dec-2023
 *      Author: zakisadique
 */

#include "tests.h"

#include <iostream>
#include "Board.h"
#include "ConsoleView.h"

using namespace std;




void part2tests(){

	//blocked area
	assertTrue(Ship{GridPosition{"B2"}, GridPosition{"B4"}}.blockedArea()
	    == set<GridPosition>{
	        GridPosition{"A1"}, GridPosition{"B1"}, GridPosition{"C1"},
	        GridPosition{"A2"}, GridPosition{"B2"}, GridPosition{"C2"},
	        GridPosition{"A3"}, GridPosition{"B3"}, GridPosition{"C3"},
	        GridPosition{"A4"}, GridPosition{"B4"}, GridPosition{"C4"},
	        GridPosition{"A5"}, GridPosition{"B5"}, GridPosition{"C5"},
	    },
	    "Blocked area not correct");

	//	Test OwnGrid constructor, getRows, GetColumns
	assertTrue(OwnGrid{10, 10}.getRows() == 10, "Row is not 10");
	assertTrue(!(OwnGrid{10, 10}.getRows() != 10), "Row should be 10");
	assertTrue(OwnGrid{10, 10}.getColumns() == 10, "Column is not 10");
	assertTrue(!(OwnGrid{10, 10}.getColumns() != 10), "Column should be 10");

	// Test Place Ships
	OwnGrid grid (10, 10);
	assertTrue(grid.placeShip(Ship(GridPosition("A1"), GridPosition("A5"))),
			"Ship should be placed A1-A5");
	assertTrue(!grid.placeShip(Ship(GridPosition("@3"), GridPosition("A5"))),
			"Ship should be not be placed @3-A5");
	assertTrue(!grid.placeShip(Ship(GridPosition("I1"), GridPosition("I5"))),
					"Ship should not be placed I1-I5");

	assertTrue(!grid.placeShip(Ship(GridPosition("B4"), GridPosition("B5"))),
				"Ship should not be placed B4-B5");

	assertTrue(!grid.placeShip(Ship(GridPosition("A6"), GridPosition("A7"))),
				"Ship should not be placed A6-A7");

	assertTrue(grid.placeShip(Ship(GridPosition("A7"), GridPosition("A8"))),
					"Ship should not be placed A7-A8");

	assertTrue(!grid.placeShip(Ship(GridPosition("@1"), GridPosition("@3"))),
					"Ship should not be placed @1-@3");

	assertTrue(!grid.placeShip(Ship(GridPosition("K1"), GridPosition("K4"))),
						"Ship should not be placed K1-K4");

}

