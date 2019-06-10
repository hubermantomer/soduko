/*
 * Game.c
 *
 *  Created on: May 24, 2019
 *      Author: guyko
 */

#include <stdlib.h>
#include <stdio.h>
#include "Parser.h"
#include "Parser.h"
#include "Solver.h"
#include "Game.h"
#include "MainAux.h"


/*
 *
 */
board* cleanBoard(board* b){
	int i, j;
	for (i=0;i<SIZE;i++){
		for (j=0;j<SIZE;j++){
			b->cells[i][j].fix =0;
			b->cells[i][j].player =0;
			b->cells[i][j].live =0;
			b->cells[i][j].hint =0;
			b->cells[i][j].row =i;
			b->cells[i][j].col =j;
		}
	}
	return b;
}

/*
 * initializing a new board
 * fixing all cells to 0
 * @ret: pointer to the board
 */
board* initBoard(){
	board* b = (board*) malloc(sizeof(board));
	if (b==NULL){
		standartError(b, malloc_e);
	}
	return b;
}

/*
 * mark (@param: fixed) randomized cells to be fixed (can't change them during the game)
 */
void updateFixed(board* b, int fixed){
	int x, y, i, j;
	while (fixed > 0){
		y = rand()%SIZE;
		x = rand()%SIZE;
		if(b->cells[x][y].fix == 0){
			b->cells[x][y].fix = 1;
			fixed--;
		}
	}
	for (i=0;i<SIZE;i++){
		for (j=0;j<SIZE;j++){
			if (b->cells[i][j].fix==1){
				b->cells[i][j].live = b->cells[i][j].hint;
			}
		}
	}
}

/*
 *@inv: all cells in (@param: b) are valid
 *@chck if all the cells in the board are full.
 *because of the @inv, if everything full, return 1(true)
 *otherwise, the game is not over yet. return 0(false)
 */
int gameOver(board* b){
	int i,j;
	for (i=0;i<SIZE;i++){
		for (j=0;j<SIZE;j++){
			if (b->cells[i][j].live==0){
				return 0;
			}
		}
	}
	return 1;
}

/*
 * Validate that the current state of the board is solvable
 * update hints to the new solution
 */
void validate(board* b){
	if(backtrack(b, &(b->cells[0][0]), detB)){
		printf("Validation passed: board is solvable\n");
	} else {
		printf("Validation failed: board is unsolvable\n");
	}
	return;
}

/*
 * @inv: 1 <= x,y <= SIZE (integers)
 * give a hint for cell (x,y) in b
 */
void giveHint(board* b, int x, int y){
	printf("Hint: set cell to %d\n", b->cells[x-1][y-1].hint);
	return;
}

/*
 * @inv: 1 <= x,y <= SIZE, 0<= z <= 9 (integers)
 * assignment the number z to cell (x,y) in b
 */
void set(board* b, int x, int y, int z){
	if(b->cells[x-1][y-1].fix == 1){ /*check if the cell has already been filled by the program at initialization*/
		printf("Error: cell is fixed\n");
		return;
	}
	if (z!=0){
		if(isValidCell(b,x-1,y-1,z,play)==0){ /*check if the number exists in one of its neighbors*/
			printf("Error: value is invalid\n");
			return;
		}
	}
	b->cells[x-1][y-1].live = z;
	printBoard(b);
	if (gameOver(b)==1){
		printf("Puzzle solved successfully\n");
		parsingSolved(b);
	}
	return;
}

/*
 * start a new game.
 * frees the board from before and create a new one
 */
void restart(board* b){
	letsPlay(b);
	return;
}

/*
 * exiting the game
 */
void exiting(board* b){
	printf("Exiting...\n");
	free(b);
	/*-------------------free everything that needed------------------*/
	exit(0);
}


/*
 *combining everything together.
 *init board, fill it, fix values and call the commands.
 */
void letsPlay(board* b){
	int numFixed;
	b = cleanBoard(b);
	backtrack(b, &(b->cells[0][0]), randB);
	numFixed = enterNumOfFixed();
	updateFixed(b, numFixed);
	printBoard(b);
	while(1){
		parsing(b);
	}
}


