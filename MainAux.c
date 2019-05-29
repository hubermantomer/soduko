/*
 * MainAux.c
 *
 *  Created on: May 24, 2019
 *      Author: guyko
 */
#include <stdio.h>
#include <stdlib.h>
#include "Parser.h"
#include "Game.h"
#include "Solver.h"
#include "MainAux.h"
#include "SPBufferset.h"



void enterBoardSize(){
	/*printf("Please enter board size")  to change at project
	scan = (scanf("%d %d, ROWS, COLS));
	if (scan == EOF){
		printf ("Exiting...\n");
		exit (0);}
	if ((fix>=0)&&(fix<numCell)){
		return numCell;}

	ROWS = 3;
	COLS = 3;
	SIZE = ROWS*COLS;
	*/
}

int enterNumOfFixed(){
	int numCell = (SIZE*SIZE)-1;
	int fix, scan;
	numCell = 80;             /*delete on project*/
	while (1){
		printf("Please enter the number of cells to fill[0-%d]:\n",numCell);
		scan = (scanf("%d", &fix));
		if (scan == EOF){
			printf ("Exiting...\n");
			exit (0);}
		if ((fix>=0)&&(fix<numCell)){
			return numCell;}
		else{
			printf ("Error: invalid number of cells to fill(should be between 0 and %d)\n", numCell);}
		}
	return 0;
}


void dasheLine(){
	int dashes, i;
	dashes = SIZE*3 + ROWS*2 + 1;
	for(i =0; i<dashes; i++){
		printf("-");
	}
	printf("\n");
}

void numLine(board* board, int row){
	int col;
	printf("|");
	for(col =0; col< (SIZE); col++){
		printf(" %c%d", (board->cells[row][col].fix ==1) ? '.' : ' ', board->cells[row][col].live);
		if((col+1)%COLS==0){
			printf(" |");
		}
	}
	printf("\n");
}

void printBoard(board* board){
	int row;
	dasheLine();
	for(row=0; row<SIZE; row++){
		numLine(board, row);
		if (((row+1)%ROWS)==0){
			dasheLine();
		}
	}
}



