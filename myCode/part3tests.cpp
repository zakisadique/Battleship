/*
 * part3tests.cpp
 *
 *  Created on: 28-Dec-2023
 *      Author: zakisadique
 */

#include "tests.h"

#include <iostream>
#include "Board.h"
#include "ConsoleView.h"

using namespace std;

void part3tests(){

	Board board (10, 10);

	board.getOwnGrid().placeShip(Ship{GridPosition{"B1"}, GridPosition{"B4"}});
	board.getOwnGrid().placeShip(Ship{GridPosition{"D1"}, GridPosition{"D5"}});
	board.getOwnGrid().placeShip(Ship{GridPosition{"F1"}, GridPosition{"F4"}});
	board.getOwnGrid().placeShip(Ship{GridPosition{"I1"}, GridPosition{"J1"}});
	board.getOwnGrid().placeShip(Ship{GridPosition{"B9"}, GridPosition{"D9"}});
	board.getOwnGrid().placeShip(Ship{GridPosition{"C7"}, GridPosition{"E7"}});
	board.getOwnGrid().placeShip(Ship{GridPosition{"G7"}, GridPosition{"I7"}});
	board.getOwnGrid().placeShip(Ship{GridPosition{"F9"}, GridPosition{"F10"}});




	// Test takeblow
	assertTrue(board.getOwnGrid().takeBlow(GridPosition {"B1"}) ==
		Shot::Impact::HIT, "Blow should be HIT at B1");

	assertTrue(board.getOwnGrid().takeBlow(GridPosition {"B2"}) ==
		Shot::Impact::HIT, "Blow should be HIT at B2");

	assertTrue(board.getOwnGrid().takeBlow(GridPosition {"B3"}) ==
		Shot::Impact::HIT, "Blow should be HIT at B3");

	assertTrue(board.getOwnGrid().takeBlow(GridPosition {"B4"}) ==
		Shot::Impact::SUNKEN, "Blow should be SUNKEN at B4");


	assertTrue(board.getOwnGrid().takeBlow(GridPosition {"F7"}) ==
		Shot::Impact::NONE, "Blow should be HIT at F7");

	assertTrue(board.getOwnGrid().takeBlow(GridPosition {"C1"}) ==
		Shot::Impact::NONE, "Blow should be HIT at C1");

	assertTrue(board.getOwnGrid().takeBlow(GridPosition {"E1"}) ==
		Shot::Impact::NONE, "Blow should be NONE at E1");
	assertTrue(board.getOwnGrid().takeBlow(GridPosition {"I7"}) ==
		Shot::Impact::HIT, "Blow should be HIT at I7");


	// Hit Opponent
	board.getOpponentGrid().getShotResult(Shot(GridPosition{"A1"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().getShotResult(Shot(GridPosition{"A3"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().getShotResult(Shot(GridPosition{"A4"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().getShotResult(Shot(GridPosition{"A2"}),
			Shot::Impact::SUNKEN);

	board.getOpponentGrid().getShotResult(Shot(GridPosition{"A9"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().getShotResult(Shot(GridPosition{"A10"}),
			Shot::Impact::SUNKEN);

	board.getOpponentGrid().getShotResult(Shot(GridPosition{"J1"}),
			Shot::Impact::NONE);
	board.getOpponentGrid().getShotResult(Shot(GridPosition{"B2"}),
			Shot::Impact::NONE);

	board.getOpponentGrid().getShotResult(Shot(GridPosition{"I8"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().getShotResult(Shot(GridPosition{"J8"}),
			Shot::Impact::SUNKEN);

	board.getOpponentGrid().getShotResult(Shot(GridPosition{"E10"}),
			Shot::Impact::HIT);

	board.getOpponentGrid().getShotResult(Shot(GridPosition{"H1"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().getShotResult(Shot(GridPosition{"H2"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().getShotResult(Shot(GridPosition{"H3"}),
			Shot::Impact::SUNKEN);

	board.getOpponentGrid().getShotResult(Shot(GridPosition{"A6"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().getShotResult(Shot(GridPosition{"A7"}),
			Shot::Impact::SUNKEN);

	board.getOpponentGrid().getShotResult(Shot(GridPosition{"C8"}),
			Shot::Impact::HIT);

	board.getOpponentGrid().getShotResult(Shot(GridPosition{"C1"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().getShotResult(Shot(GridPosition{"E1"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().getShotResult(Shot(GridPosition{"F1"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().getShotResult(Shot(GridPosition{"D1"}),
			Shot::Impact::SUNKEN);

	board.getOpponentGrid().getShotResult(Shot(GridPosition{"A9"}),
			Shot::Impact::HIT);
	board.getOpponentGrid().getShotResult(Shot(GridPosition{"A10"}),
			Shot::Impact::SUNKEN);

	ConsoleView view (&board);
	view.print();
}



