/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 * Updated Jeopardy Game
 * Implements all requirements:
 *  - Command line prompt for interactions.
 *  - Prompts for 4 players and sets initial score to 0.
 *  - Displays available categories and dollar values.
 *  - Prompts for the player selecting the question, validates the name.
 *  - Prompts for the category and dollar value, ensuring the question is unused.
 *  - Displays the question, then prompts for an answer starting with "what is" or "who is".
 *  - Uses tokenization to parse the answer, checks correctness, updates score,
 *    and marks the question as answered.
 *  - Repeats until all questions are answered, then shows final results ranked.
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdbool.h>
 #include "questions.h"
 #include "players.h"
 #include "jeopardy.h"
 
 #define BUFFER_LEN 256
 #define NUM_PLAYERS 4
 
 // Tokenizes the input string by space and stores tokens in the tokens array.
 void tokenize(char *input, char **tokens) {
     char *token = strtok(input, " ");
     int i = 0;
     while (token != NULL) {
         tokens[i++] = token;
         token = strtok(NULL, " ");
     }
     tokens[i] = NULL; // Terminate the tokens array
 }
 
 // Displays final results sorted by score in descending order.
 void show_results(player *players, int num_players) {
     // Bubble sort the players by score (descending)
     for (int i = 0; i < num_players - 1; i++) {
         for (int j = i + 1; j < num_players; j++) {
             if (players[i].score < players[j].score) {
                 player temp = players[i];
                 players[i] = players[j];
                 players[j] = temp;
             }
         }
     }
     printf("\nFinal Results:\n");
     for (int i = 0; i < num_players; i++) {
         printf("%s: %d points\n", players[i].name, players[i].score);
     }
 }
 
 int main(int argc, char *argv[])
 {
     player players[NUM_PLAYERS];
     char buffer[BUFFER_LEN] = {0};
 
     // Initialize the questions
     initialize_game();
 
     // --- Requirement 2: Prompt for players' names ---
     for (int i = 0; i < NUM_PLAYERS; i++) {
         printf("Enter name for player %d: ", i + 1);
         fgets(players[i].name, MAX_LEN, stdin);
         players[i].name[strcspn(players[i].name, "\n")] = '\0'; // Remove newline
         players[i].score = 0;
     }
     printf("Players initialized. Game is starting...\n");
 
     // Main game loop
     while (1) {
         // --- Requirement 3 & 9: Display remaining categories and values ---
         display_categories();
 
         // --- Requirement 4: Ask for the player selecting the question ---
         char currentPlayer[MAX_LEN];
         printf("\nEnter the name of the player selecting the question: ");
         fgets(currentPlayer, MAX_LEN, stdin);
         currentPlayer[strcspn(currentPlayer, "\n")] = '\0';
 
         // Validate the player's name.
         if (!player_exists(players, NUM_PLAYERS, currentPlayer)) {
             printf("Player not found. Please enter a valid player name.\n");
             continue;
         }
 
         // --- Requirement 5: Prompt for category and dollar value ---
         char category[MAX_LEN];
         int value;
         printf("Enter category: ");
         fgets(category, MAX_LEN, stdin);
         category[strcspn(category, "\n")] = '\0';
         printf("Enter dollar value: ");
         fgets(buffer, BUFFER_LEN, stdin);
         if (sscanf(buffer, "%d", &value) != 1) {
             printf("Invalid dollar value. Please try again.\n");
             continue;
         }
 
         // Check if the question has already been answered.
         if (already_answered(category, value)) {
             printf("This question has already been answered. Pick another.\n");
             continue;
         }
 
         // --- Requirement 6: Display the selected question ---
         display_question(category, value);
 
         // --- Requirement 7: Prompt for the answer (must start with "what is" or "who is") ---
         char answerInput[BUFFER_LEN];
         printf("Your answer (must start with 'what is' or 'who is'): ");
         fgets(answerInput, BUFFER_LEN, stdin);
         answerInput[strcspn(answerInput, "\n")] = '\0';
 
         // Tokenize the answer input.
         char *tokens[10] = {0};
         tokenize(answerInput, tokens);
         if (!tokens[0] || !tokens[1] || !tokens[2] ||
             (strcasecmp(tokens[0], "what") != 0 && strcasecmp(tokens[0], "who") != 0) ||
             strcasecmp(tokens[1], "is") != 0) {
             printf("Invalid answer format. Answer must start with 'what is' or 'who is'.\n");
             continue;
         }
         // Concatenate tokens[2] onward to form the full answer.
        char playerAnswer[MAX_LEN] = "";
        for (int i = 2; tokens[i] != NULL; i++) {
            strcat(playerAnswer, tokens[i]);
            if (tokens[i+1] != NULL) {
                strcat(playerAnswer, " ");
            }
        }
 
         // --- Requirement 8: Validate answer, update score if correct, or display correct answer ---
         if (valid_answer(category, value, playerAnswer)) {
             printf("Correct!\n");
             update_score(players, NUM_PLAYERS, currentPlayer, value);
         } else {
             const char* correctAnswer = get_correct_answer(category, value);
             printf("Incorrect. The correct answer was: %s\n", correctAnswer);
         }
 
         // Mark the question as answered so it cannot be used again.
         for (int i = 0; i < NUM_QUESTIONS; i++) {
             if (strcasecmp(questions[i].category, category) == 0 && questions[i].value == value) {
                 questions[i].answered = true;
                 break;
             }
         }
 
         // --- Requirement 9: Check if all questions have been answered ---
         bool all_answered = true;
         for (int i = 0; i < NUM_QUESTIONS; i++) {
             if (!questions[i].answered) {
                 all_answered = false;
                 break;
             }
         }
         if (all_answered) {
             printf("\nGame Over!\n");
             // --- Requirement 10: Display final results in ranked order ---
             show_results(players, NUM_PLAYERS);
             break;
         }
     }
 
     return EXIT_SUCCESS;
 }
 