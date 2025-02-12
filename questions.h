/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#ifndef QUESTIONS_H_
#define QUESTIONS_H_

#include <stdbool.h>

#define MAX_LEN 256
#define NUM_CATEGORIES 6
#define NUM_QUESTIONS 30

// List of categories (defined in questions.c)
extern char categories[NUM_CATEGORIES][MAX_LEN];

// Question struct for each question.
typedef struct {
    char category[MAX_LEN];
    char question[MAX_LEN];
    char answer[MAX_LEN];
    int value;
    bool answered;
} question;

// Array of questions (to be initialized in questions.c)
extern question questions[NUM_QUESTIONS];

// Initializes the array of questions for the game.
extern void initialize_game(void);

// Displays each of the remaining categories and the dollar values for unanswered questions.
extern void display_categories(void);

// Displays the question for the given category and dollar value.
extern void display_question(char *category, int value);

// Returns true if the provided answer is correct for the given category and dollar value.
extern bool valid_answer(char *category, int value, char *answer);

// Returns true if the question has already been answered.
extern bool already_answered(char *category, int value);

// Helper: Returns the correct answer for the given category and value.
extern const char* get_correct_answer(char *category, int value);

#endif /* QUESTIONS_H_ */

