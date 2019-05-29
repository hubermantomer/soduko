/*
 * Game.c
 *
 *  Created on: May 24, 2019
 *      Author: guyko
 */


#include "Parser.h"
#include "Parser.h"
#include "Solver.h"
#include "Game.h"
#include "MainAux.h"
#include "SPBufferset.h"

#include <stdlib.h>
#include <stdio.h>

/*
 *
 */
board* initBoard(){
	int i, j;
	/*int fixed;*/
	board* b = (board*) malloc(sizeof(board*));
	/*backtrackRand(b);*/
	/*fixed = enterNumOfFixed();*/
	/*updateFixed(b, fixed);*/
	for (i=0;i<SIZE;i++){
		for (j=0;j<SIZE;j++){
			b->cells[i][j].fix =0;
			b->cells[i][j].player =0;
			b->cells[i][j].live =0;
			b->cells[i][j].hint =0;
		}
	}
	printBoard(b);
	return b;
}

/*
 *
 */
void updateFixed(board* b, int fixed){
	int x, y;
	while (fixed > 0){
		x = rand()%SIZE;
		y = rand()%SIZE;
		if(b->cells[x][y].fix == 0){
			b->cells[x][y].fix = 1;
			b->cells[x][y].live = b->cells[x][y].hint;
			fixed--;
		}
	}
}

/*
 *
 */
int isValid(board* b,int x,int y,int z){

}

/*
 *
 */
int gameOver(board* b){

}

