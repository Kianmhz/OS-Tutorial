/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#include "players.h"  // needed for the player type

#define MAX_LEN 256

// Processes the answer from the user (e.g., "what is" or "who is")
// and tokenizes it into words.
extern void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score,
// ranked from first to last place.
extern void show_results(player *players, int num_players);
//Ending the code function to move on
#endif /* JEOPARDY_H_ */

