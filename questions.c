
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
#include "questions.h"


// Define categories (previously in header)
char categories[NUM_CATEGORIES][MAX_LEN] = {
    "programming", 
    "algorithms", 
    "databases"
};

// Define questions array (previously in header)
question questions[NUM_QUESTIONS];

// Initializes the array of questions for the game
void initialize_game(void)
{
    // Programming Category
    strcpy(questions[0].category, "programming");
    strcpy(questions[0].question, "What is the complexity of binary search?");
    strcpy(questions[0].answer, "O(log n)");
    questions[0].value = 200;
    questions[0].answered = false;

    strcpy(questions[1].category, "programming");
    strcpy(questions[1].question, "What is the keyword to declare a constant in C?");
    strcpy(questions[1].answer, "const");
    questions[1].value = 400;
    questions[1].answered = false;

    // Algorithms Category (instead of science)
    strcpy(questions[2].category, "algorithms");
    strcpy(questions[2].question, "What sorting algorithm has an average case of O(n log n)?");
    strcpy(questions[2].answer, "Merge Sort");
    questions[2].value = 200;
    questions[2].answered = false;

    strcpy(questions[3].category, "algorithms");
    strcpy(questions[3].question, "What data structure uses LIFO?");
    strcpy(questions[3].answer, "Stack");
    questions[3].value = 400;
    questions[3].answered = false;

    // Databases Category
    strcpy(questions[4].category, "databases");
    strcpy(questions[4].question, "What does SQL stand for?");
    strcpy(questions[4].answer, "Structured Query Language");
    questions[4].value = 200;
    questions[4].answered = false;

    strcpy(questions[5].category, "databases");
    strcpy(questions[5].question, "What type of database is MongoDB?");
    strcpy(questions[5].answer, "NoSQL");
    questions[5].value = 400;
    questions[5].answered = false;
}


// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    printf("\nAvailable Categories:\n");

    for (int i = 0; i < NUM_CATEGORIES; i++) {
        printf("Category: %s\n", categories[i]);
        bool has_unanswered = false;

        for (int j = 0; j < NUM_QUESTIONS; j++) {
            if (strcmp(questions[j].category, categories[i]) == 0 && !questions[j].answered) {
                printf("  $%d - %s\n", questions[j].value, questions[j].question);
                has_unanswered = true;
                
            }
        }

        // If all questions in a category are answered, indicate it
        if (!has_unanswered) {
            printf("  (All questions answered)\n");
        }
    }
}





// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    // Iterate through the questions array to find the category and dollar value
   
for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            if (!questions[i].answered) {
                // Print the question for the category and value
                printf("Question: %s\n", questions[i].question);
                return;
            } else {
                printf("This question has already been answered.\n");
                return;
            }
        }
    }
    printf("Invalid category or value.\n");

}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            if (strcmp(questions[i].answer, answer) == 0) {
                questions[i].answered = true;  // Mark as answered only when correct
                return true;
            }
            return false; // Wrong answer, but don't mark as answered
        }
    }
    return false; // No matching question found
}


// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return questions[i].answered;  // Return true if answered
        }
    }
    return false;  // Return false if not answered
}
