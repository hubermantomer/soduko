/*
 * Parser.c
 *
 *  Created on: May 24, 2019
 *      Author: guyko
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Game.h"
#include "Solver.h"
#include "MainAux.h"


/*
 * private!!!
 * prints invalid command error.
 */
void inValidCmd(){
	printf("Error: invalid command\n");
}

/*
 *private!!!
 *being called after the game is solved. allows only "exit" & "restart" commands
 */
void parsingSolved(board* b){
	char str[20];
	char *curr, *check;
	while(1){
		check = fgets(str, 20, stdin);
		if ((check == NULL) && (*str != EOF)){
			standartError(b, fgets_e);
		}
		terminate(b);
		curr = strtok(str, " \t\r\n");
		if (strcmp(curr, "restart") == 0){
			restart(b);
			return;
		}
		else if (strcmp(curr, "exit") == 0){
			exiting(b);
		}
		else {
			inValidCmd();
		}
	}
	restart(b);
}

/*
 * gets a command from the player and decide which function to choose
 */
void parsing(board* b){
	int cnt=0;
	char str[1024];
	char *curr, *cmd=0, *x=0, *y=0, *z=0;
	cleanBuff();
	terminate(b);
	fgets(str, 1024, stdin);
	curr = strtok(str, " \t\r\n");
	while(curr){
		if (cnt==0) cmd=curr;
		if (cnt==1) x=curr;
		if (cnt==2) y=curr;
		if (cnt==3){
			z=curr;
			cnt++;
			break;
		}
		curr=strtok(0, " \t\r\n");
		cnt++;
	}
	if (strcmp(cmd, "set")==0){   /*check if the command is 'set'*/
		if (cnt<4 || !x || !y || !z){
			inValidCmd();
		}
		else{
			set(b, atoi(y), atoi(x), atoi(z));
		}
	}
	else if (strcmp(cmd, "hint") == 0){ /*check if the command is 'hint'*/
		if (cnt<3 || !x || !y){
			inValidCmd();
		}
		else{
			giveHint(b, atoi(y), atoi(x));
		}
	}
	else if (strcmp(cmd, "validate") == 0){ /*check if the command is 'validate'*/
		validate(b);
	}
	else if (strcmp(cmd, "restart") == 0){ /*check if the command is 'restart'*/
		restart(b);
	}
	else if (strcmp(cmd, "exit") == 0){ /*check if the command is 'exit'*/
		exiting(b);
	}
	else { /*None of the below. thus, print invalid command error*/
		inValidCmd();
	}
	terminate(b);
	return;
}

