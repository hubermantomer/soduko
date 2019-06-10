/*
 * MainAux.c
 *
 *  Created on: May 24, 2019
 *      Author: guyko
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Parser.h"
#include "Game.h"
#include "Solver.h"
#include "MainAux.h"

#define dashes (SIZE*3 + ROWS*2 + 1) /*the number of dashes (-) that has to be printed for the board*/


/*
 *
 */
void enterBoardSize(){
	/*
	fprintf(stdout, "Please enter board size")  to change at project
	scan = (scanf("%d %d, ROWS, COLS));
	if (scan == EOF){
		fprintf(stdout, "Exiting...\n");
		exit (0);}
	if ((fix>=0)&&(fix<numCell)){
		return numCell;}
	*/
}

/*
 *
 */
int enterNumOfFixed(){
	int numCell = (SIZE*SIZE)-1, fix, scan;
	numCell = 80;             /*delete on project*/
	while (1){
		printf("Please enter the number of cells to fill [0-%d]:\n",numCell);
		scan = (scanf("%d", &fix));
		if (scan == EOF || scan!=1 ){
			if(scan!=EOF) printf("Error: not a number\n");
			printf("Exiting...\n");
			exit (0);
		}
		if ((fix>=0)&&(fix<=numCell)){
			return fix;
		}
		else{
			printf("Error: invalid number of cells to fill (should be between 0 and %d)\n", numCell);
		}
	}
	return 0;
}

/*
 *private!!
 *prints the dashes for the rows boundaries of the board
 *(the number of dashes needed computed in the #define above)
 */
void dasheLine(){
	int i;
	for(i =0; i<dashes; i++){
		printf("-");
	}
	printf("\n");
}

/*
 *private!!
 *prints one row of the board (the 'live' field)
 *every COLS cells, prints a '|' to separate between blocks
 */
void numLine(board* board, int row){
	int col;
	printf("|");
	for(col =0; col< (SIZE); col++){
		printf(" %c", (board->cells[row][col].fix ==1) ? '.' : ' ');
		if(board->cells[row][col].live == 0){
			printf(" ");
		}
		else{
			printf("%d", board->cells[row][col].live);
		}
		if((col+1)%COLS==0){
			printf(" |");
		}
	}
	printf("\n");
}

/*
 *prints the whole board according to it's current stage
 */
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

/*
 *
 */
void terminate(board* b){
	if (feof(stdin)){
		exiting(b);
		exit(0);
	}
}

/*
 *cleans the buffer from spaces.
 *@inv: at the end of the function the
 */
void cleanBuff(){
	char c;
	while(isspace((c=getchar())));
	ungetc(c, stdin);
}

void standartError(board* b, function func){
	char* error=NULL;
	switch (func){
		case(malloc_e):
			error="malloc";
			break;
		case(fgets_e):
			error="fgets";
			break;
	}
	printf("Error: %s has failed\n", error);
	exiting(b);
}
