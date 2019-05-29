/*
 * main.c
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
#include <time.h>

int main(/*int argc, char** argv*/){

	/*board* b;*/

	SP_BUFF_SET();

	/*enterBoardSize();*/


	/*
	 * Initializing randomization
	 */
	/*
	if (argc > 1){
		srand(atoi(argv[1]));
	} else {
		srand(time(NULL));
	}
	*/

	initBoard();

	return 0;
}



