/*
 * Solver.h
 *
 *  Created on: May 24, 2019
 *      Author: guyko
 */

#ifndef SOLVER_H_
#define SOLVER_H_

#include <stdlib.h>
#include <stdio.h>
#include "Game.h"

/**
 * Solver Summary:
 *
 *A module that parse user commands
 *
 *findNextAvailbaleCell- find the next cell that is empty for board build
 *isValidCell-check if the input of the user is legal according to row, column and block
 *backtrackRec- a recursive function how solves the board
 *backtrack- an envelope function that call backtrackRec
 */


/*
 *
 */
typedef enum backOrPlay_t{ /*for checking cell's validity - decide what field to look at*/
	back,
	play
}backOrPlay;

/*
 *
 */
typedef enum boardType_t{ /*decide which backtrack to call*/
	randB,
	detB
}boardType;

/*
 *
 */
int isValidCell(board* b, int row, int col, int num, backOrPlay mode);

/*
 *
 */
int backtrack(board* b, cell* curCell,boardType type);


#endif /* SOLVER_H_ */
