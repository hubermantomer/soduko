/*
 * MainAux.h
 *
 *  Created on: May 24, 2019
 *      Author: guyko
 */

#ifndef MAINAUX_H_
#define MAINAUX_H_

#include <stdlib.h>
#include <stdio.h>

/**
 * MainAux Summary:
 *
 * A module that include All auxiliary functions, those are functions that use by other modules.
 *
 *enterBoardSize- FOR PROJEC USE, collect from the player the size of board he is interes in.
 *enterNumOfFixed- collect from the player the number of cell that will be given on the starting board.
 *dasheLine- for internal use, printing the board lines
 *numLine- for internal use, printing the board lines
 *printBoard- for internal use, printig the board
 *terminate- check if there is no more information from the player and exit from the app
 *cleanBuff- clean the buffer from a not needed chars
 *standartEror- throw errors of running problems and exit
 *
 */


/*
 *
 */
typedef enum function_t{
	malloc_e,
	fgets_e
}function;

/*
 *!!not needed for this HW. only for the project!!
 *asks for the size of the board (in this HW it will be the default -3x3)
 */
void enterBoardSize();

/*
 *asks for the the number of fixed cells (e.g. the number of cells that will be filled)
 *if the given number isn't between 0 to 80, prints an error and asks again
 *WARNING- if entering an EOF char, the run will be terminated
 */
int enterNumOfFixed();

/*
 *prints the whole board according to it's current stage
 */
void printBoard(board* board);

/*
 *private function! do not use!!
 *(terminating the program if gets EOF)
 */
void terminate(board* b);

/*
 *
 */
void cleanBuff();

/*
 *
 */
void standartError(board* b, function func);


#endif /* MAINAUX_H_ */
