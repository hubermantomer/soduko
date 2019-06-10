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
/**
 * Game Summary:
 *
 * A module that run the game from the start till the end.
 * This module encapsulates the Sudoku puzzle game and the Sudoku board.
 *
 *cleanBoard- clean the board and intilaized all data after finish/intilsation of a game
 *initBoard- allocate memory for the board game
 *updateFixed- randomly create the fix cell according to the player demand
 *gameOver- check if the board is full so the game is over
 *validate- Validate that the current state of the board is solvable, can be called by "validate"
 *giveHint- give an hint to the player according the cell he chose, can be called by "hint x y"
 *set- set the require cell if legal to the number chosen by the player, can be called by "set x y z"
 *restart- start the game from the beginning with a new board, can be called by "restart"
 *exiting- exit from the app at any time by writing "exit"
 *letsPlay- this function encapsulates the Sudoku puzzle game and the Sudoku board.
 *
 */


#define ROWS 3
#define COLS 3
#define SIZE (ROWS*COLS)

/*
 *
 */
typedef struct cell_t{
	int fix;      /*the initial fixed cells*/
	int player; /*             */
	int live; /*                  */
	int hint;  /*the number to desplay when calling hint" */
	int row;
	int col;
}cell;

/*
 *
 */
typedef struct board_t{
	cell cells[SIZE][SIZE];
}board;

/*
 * initializing a new board
 * fixing all cells to 0
 * @ret: pointer to the board
 */
board* initBoard();

/*
 * mark (@param: fixed) randomized cells to be fixed (can't change them during the game)
 */
void updateFixed(board* b, int fixed);

/*
 *@inv: all cells in (@param: b) are valid
 *@chck if all the cells in the board are full.
 *because of the @inv, if everything full, return 1(true)
 *otherwise, the game is not over yet. return 0(false)
 */
int gameOver(board* b);

/*
 *
 */
void validate(board* b);

/*
 *
 */
void giveHint(board* b, int x, int y);

/*
 *
 */
void set(board* b, int x, int y, int z);


/*
 *
 */
void restart(board* b);

/*
 *
 */
void exiting(board* b);


/*
 *combining everything together.
 *init board, fill it, fix values and call the commands.
 */
void letsPlay(board* b);


#endif /* GAME_H_ */


