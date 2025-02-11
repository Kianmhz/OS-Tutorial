/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens) {
    char *token = strtok(input, " "); // tokenize by space
    int i = 0;
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
}

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players) {
    // Sort the players by score (descending)
    for (int i = 0; i < num_players - 1; i++) {
        for (int j = i + 1; j < num_players; j++) {
            if (players[i].score < players[j].score) {
                player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
  // Display results
    printf("\nFinal Results:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d points\n", players[i].name, players[i].score);
    }
}


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
   for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter name for player %d: ", i + 1);
        fgets(players[i].name, MAX_LEN, stdin);
        players[i].name[strcspn(players[i].name, "\n")] = '\0'; // remove new line
        players[i].score = 0; // Initialize score to 0
    } 
    // initialize each of the players in the array
    printf("Players initialized. Moving to game start...\n");


    // Perform an infinite loop getting command input from users until game ends
   while (1) {
        display_categories(); // Show available categories and questions

        // Ask player to choose a category and value
        char category[MAX_LEN];
        int value;
        printf("\nEnter category and value (e.g., Programming 200): ");
        scanf("%s %d", category, &value);

        // Check if the question has already been answered
        if (already_answered(category, value)) {
            printf("This question has already been answered. Pick another.\n");
            continue;
        }

        // Display the chosen question
        display_question(category, value);

        // Get player's answer
        char answer[MAX_LEN];
        printf("\nYour answer: ");
        scanf(" %[^\n]", answer); // Read full line as answer

        // Validate answer
        if (valid_answer(category, value, answer)) {
            printf("Correct!\n");
            // Assign points to player (for now, first player gets points)
            players[0].score += value; // TODO: Implement turns
        } else {
            printf("Incorrect.\n");
        }

        // Mark question as answered
        for (int i = 0; i < NUM_QUESTIONS; i++) {
            if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
                questions[i].answered = true;
                break;
            }
        }

        // Check if all questions are answered
        bool all_answered = true;
        for (int i = 0; i < NUM_QUESTIONS; i++) {
            if (!questions[i].answered) {
                all_answered = false;
                break;
            }
        }
        if (all_answered) {
            printf("\nGame Over!\n");
            show_results(players, NUM_PLAYERS);
            break;
        }
    }

    return EXIT_SUCCESS;
}
