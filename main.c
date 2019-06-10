/*
 * main.c
 *
 *  Created on: May 24, 2019
 *      Author: guyko
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Game.h"

int main(int argc, char** argv){
	board* b;               /*declare on a board, this board will stay as long as the player play the game*/

	/*Initialising randomisation*/
	if (argc > 1){
		srand(atoi(argv[1]));
	} else {
		srand(time(NULL));
	}

	b = initBoard();      /*Initialised the structer of the board*/

	/*start a game*/
	letsPlay(b);
	return 0;
}



