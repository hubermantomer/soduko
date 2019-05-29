/*
 * Parser.c
 *
 *  Created on: May 24, 2019
 *      Author: guyko
 */

#include <stdlib.h>
#include <stdio.h>

/*
 * @inv: 1 <= z,x,y <= SIZE (integers)
 * assignment the number z to cell (x,y) in b
 */
void set(board* b, int x, int y, int z){
	if(b->cells[x-1][y-1].fix == 1){
		printf("Error: cell is fixed\n");
	}
	else if (isValid(b,x,y,z)==0){
		printf("Error: value is invalid\n");
	}
	b->cells[x-1][y-1].live = z;
	printBoard(b);
	if (gameOver(b)==1){
		printf("Puzzle solved successfully");
	}
	return;
}

/*
 * @inv: 1 <= x,y <= SIZE (integers)
 * give a hint for cell (x,y) in b
 */
void hint(board* b, int x, int y){
	printf("Hint: set cell to%d\n", b->cells[x-1][y-1].hint);
}

/*
 *
 */
void validate(){
	backtrackDet(board* board);

}
