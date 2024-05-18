/*
 * part1tests.cpp
 *
 *  Created on: 15.11.2019
 *      Author: mnl
 */

#include "tests.h"

#include <iostream>
#include "Board.h"
#include "ConsoleView.h"

using namespace std;


void assertTrue(bool condition, string failedMessage) {
	if (!condition) {
		cout << failedMessage << endl;
	}
}


void part1tests(){

	// Test GridPosition constructor
	assertTrue(GridPosition{'A', 1}.isValid(), "A1 not considered valid");
	assertTrue(!GridPosition{'A', -1}.isValid(), "A-1 considered valid");
	assertTrue(!GridPosition{'@', 1}.isValid(), "@1 considered valid");

	GridPosition fromRowCol{'A', 1};
	GridPosition fromString{"A1"};
	assertTrue(fromRowCol.getRow() == fromString.getRow()
		&& fromRowCol.getColumn() == fromString.getColumn(),
		"different constructors return different objects");

	// Test getters and cast to string
	GridPosition pos1 = GridPosition{'B', 13};
	assertTrue(pos1.getRow() == 'B',
		"GridPosition::GridPosition doesn't set row properly.");
	assertTrue(pos1.getColumn() == 13,
		"GridPosition::GridPosition doesn't set column properly.");
	assertTrue((string)pos1 == "B13", "Conversion to string fails.");



	// Test comparison
	assertTrue(!(GridPosition{"A1"} < GridPosition{"A1"}),
			"Same positions considered different by '<'");
	assertTrue(GridPosition{"A1"} < GridPosition{"B1"},
			"Position with bigger row not considered greater");
	assertTrue(GridPosition{"A1"} < GridPosition{"A2"},
			"Position with bigger column not considered greater");
	assertTrue(GridPosition{"C21"} == GridPosition{"C21"},
			"Equal positions not considered equal.");

	assertTrue(GridPosition{"A2"} < GridPosition{"B5"},
			"Equal positions not considered equal.");





	// Test Ship Constructor
	assertTrue(!Ship{GridPosition{"B2"}, GridPosition{"C3"}}.isValid(),
			"Can create non-aligned ship.");
	assertTrue(!Ship{GridPosition{"B2"}, GridPosition{"B2"}}.isValid(),
			"Can create ship of size 1.");
	assertTrue(!Ship{GridPosition{"B2"}, GridPosition{"B7"}}.isValid(),
			"Can create ship of size 6.");

	// Test Length
	assertTrue(Ship{GridPosition{"B2"}, GridPosition{"B4"}}.length() == 3,
			"Length is not 3");
	assertTrue(Ship{GridPosition{"B2"}, GridPosition{"E2"}}.length() == 4,
			"Length is not 4");

	// Test isValid
	assertTrue(Ship{GridPosition{"B2"}, GridPosition{"B4"}}.isValid(),
				"Ship is valid");
	assertTrue(Ship{GridPosition{"B8"}, GridPosition{"B12"}}.isValid(),
				"Ship is not valid");
	assertTrue(Ship{GridPosition{"A1"}, GridPosition{"A3"}}.getBow() ==
			GridPosition{"A1"},
				"Ship's bow is not A1");
	assertTrue(!((string)Ship{GridPosition{"A1"}, GridPosition{"A3"}}.getBow()
			!= (string)GridPosition{"A1"}),
				"Ship's bow is not A1");


	// Occupied area
	assertTrue(Ship{GridPosition{"B2"}, GridPosition{"E2"}}.occupiedArea()
			== set<GridPosition>{GridPosition{"B2"}, GridPosition{"C2"},
		GridPosition{"D2"}, GridPosition{"E2"}},
		"Occupied area not correct");

	assertTrue(Ship{GridPosition{"A1"}, GridPosition{"A5"}}.occupiedArea()
			== set<GridPosition>{GridPosition{"A1"}, GridPosition{"A2"},
		GridPosition{"A3"}, GridPosition{"A4"}, GridPosition{"A5"}},
		"Occupied area not correct");

	assertTrue(Ship{GridPosition{"E2"}, GridPosition{"B2"}}.occupiedArea()
			== set<GridPosition>{GridPosition{"B2"}, GridPosition{"C2"},
		GridPosition{"D2"}, GridPosition{"E2"}},
		"Occupied area not correct");

}



