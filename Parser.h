/*
 * Parser.h
 *
 *  Created on: May 24, 2019
 *      Author: guyko
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdlib.h>
#include <stdio.h>
#include "Game.h"
#include "MainAux.h"


/**
 * Parser Summary:
 *
 * A module that parse user commands
 *
 *inValidCmd- throw an error to the player if is command was not okay
 *parsingSolved- after finish the game, let the player the option to "exit" or to "restart"
 *parsing- parse the user command and move to the right action
 *
 */

/*
 *
 */
void parsingSolved(board* b);


/*
 * gets a command from the player and decide which function to choose
 */
void parsing(board* b);


#endif /* PARSER_H_ */
