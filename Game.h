/*
 * Game.h
 *
 *  Created on: May 24, 2019
 *      Author: guyko
 */

#ifndef GAME_H_
#define GAME_H_

#include <stdlib.h>
#include <stdio.h>

#define ROWS 3
#define COLS 3
#define SIZE ROWS*COLS

typedef struct cell_t{
	int fix;  /*the initial fixed cells*/
	int player; /*             */
	int live; /*                  */
	int hint;  /*the number to desplay when calling hint" */
}cell;

typedef struct board_t{
	cell cells[ROWS][COLS];
}board;

/*
 *
 */
void updateFixed(board* board, int fixed);

/*
 *
 */
board* initBoard();


/*
 * check if z is a valid assignment to cell (x,y) in board
 * return 1 if true, 0 oterwise
 */
int isValid(board* b,int x,int y,int z);


/*
 * check if the board is full and valid
 * return 1 if true, 0 otherwise
 */
int game(board* b);











#endif /* GAME_H_ */


