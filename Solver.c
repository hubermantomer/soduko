/*
 * Solver.c
 *
 *  Created on: May 24, 2019
 *      Author: guyko
 */

#include "Parser.h"
#include "Game.h"
#include "Solver.h"
#include "MainAux.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * find the next cell that is free
 */
cell* findNextAvailbaleCell(board* b, cell* curCell){
	while (curCell->player != 0){
		if ((curCell->row +1==SIZE)&&(curCell->col +1 ==SIZE)){    /*check if we reach to the end of the matrix*/
			return NULL;
		}
		if (curCell->col+1==SIZE){                      /*check if we reach to the end of  row*/
			curCell = &b->cells[curCell->row+1][0];
		}
		else{
			curCell = &b->cells[curCell->row][curCell->col+1];
		}

	}
	return curCell;
}

/*
 *
 */
int isValidCell(board* b, int row, int col, int num, backOrPlay mode){
	int i,j, row_n, col_n;
	int r=0, c=0, block=0;
	for (i=0; i<SIZE; i++){
		if (mode == back){
			r = b->cells[row][i].player;
			c = b->cells[i][col].player;
		}
		else if (mode == play){
			r = b->cells[row][i].live;
			c = b->cells[i][col].live;
		}
		if(i!=col && r == num){  /*check if the row is legal*/
			return 0;
		}
		if(i!=row &&  c == num){   /*check if the col is legal*/
			return 0;
		}
	}
	col_n = col-col%COLS;
	row_n = row-row%ROWS;
	for (i=row_n;i<row_n+ROWS;i++){
		for (j=col_n;j<col_n+COLS;j++){
			if (mode == back){
				block = b->cells[i][j].player;
			}
			else if (mode == play){
				block = b->cells[i][j].live;
			}
			if(i!=row && j!=col && block == num){   /*check if the block is legal*/
				return 0;
			}
		}
	}
	return 1;
}

int backtrackRec(board* b, cell* curCell,boardType type){
	int numOfElements=0, e, g , randNum, randNumIndex, k;
	int* elementsArr=NULL;
	if (type == randB){
		elementsArr = (int*) malloc(SIZE*sizeof(int));
		if (elementsArr==NULL){
			standartError(b, malloc_e);
		}
	}
	curCell = findNextAvailbaleCell(b, curCell);
	if (curCell==NULL){
		if(type == randB){
			free(elementsArr);
		}
		return 1;
	}
	if(type == randB){
		for(e=1; e<SIZE+1; e++){
			if (isValidCell(b, curCell->row, curCell->col, e, back)==1){
				elementsArr[numOfElements]= e;
				numOfElements++;
			}
		}
		while(numOfElements>0){
			randNumIndex = 0;
			if (numOfElements>1){
				randNumIndex = rand()%(numOfElements);
			}
			randNum = elementsArr[randNumIndex];
			b->cells[curCell->row][curCell->col].player =randNum;
			if(backtrackRec(b, curCell, type)==1){
				free(elementsArr);
				return 1;
			}
			else{
				numOfElements--;
				for(g=randNumIndex; g<numOfElements; g++){
					elementsArr[g] = elementsArr[g+1];
				}
				continue;
			}

		}
	}
	else if(type == detB){
		for (k=1; k<SIZE+1;k++){
			if(isValidCell(b,curCell->row, curCell->col,k, back)==0){
				continue;
			}
			b->cells[curCell->row][curCell->col].player =k;
			if(backtrackRec(b, curCell, type)==0){
				continue;
			}
			else{
				return 1;
			}
		}
	}
	curCell->player =0;
	if (type == randB)free(elementsArr);
	return 0;
}

int backtrack(board* b, cell* curCell,boardType type){
	int tmp, i, j;
	if (type == detB){
		for (i=0;i<SIZE;i++){
			for (j=0;j<SIZE;j++){
				b->cells[i][j].player = b->cells[i][j].live;
			}
		}
	}
	tmp = backtrackRec(b, curCell, type);
	if (tmp ==1) {
		int i, j;
		for (i=0;i<SIZE;i++){
			for (j=0;j<SIZE;j++){
				b->cells[i][j].hint = b->cells[i][j].player;
			}
		}
	}
	return tmp;
}

