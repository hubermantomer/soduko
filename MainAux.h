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
/*
 * asks for the number of rows and cols for building the board
 * not necessary for this project
 */
void enterBoardSize();

/*
 * asks for number of fixed cells
 */
int enterNumOfFixed();

/*
 *
 */
void printBoard(board* board);


#endif /* MAINAUX_H_ */
