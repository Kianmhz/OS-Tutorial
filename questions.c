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
#include <strings.h>  // For case-insensitive comparisons
#include <ctype.h>    // For isalnum() and tolower
#include "questions.h"

// Define the categories.
char categories[NUM_CATEGORIES][MAX_LEN] = {
    "programming", 
    "algorithms", 
    "databases",
    "operating systems", 
    "networking", 
    "web development"
};

// Define the questions array.
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

    strcpy(questions[2].category, "programming");
    strcpy(questions[2].question, "What is the time complexity of quicksort?");
    strcpy(questions[2].answer, "O(n log n)");
    questions[2].value = 600;
    questions[2].answered = false;

    strcpy(questions[3].category, "programming");
    strcpy(questions[3].question, "What is the difference between a stack and a queue?");
    strcpy(questions[3].answer, "A stack uses LIFO, while a queue uses FIFO.");
    questions[3].value = 800;
    questions[3].answered = false;

    strcpy(questions[4].category, "programming");
    strcpy(questions[4].question, "What is polymorphism in object-oriented programming?");
    strcpy(questions[4].answer, "The ability to take many forms.");
    questions[4].value = 1000;
    questions[4].answered = false;

    // Algorithms Category
    strcpy(questions[5].category, "algorithms");
    strcpy(questions[5].question, "What sorting algorithm has an average case of O(n log n)?");
    strcpy(questions[5].answer, "Merge Sort");
    questions[5].value = 200;
    questions[5].answered = false;

    strcpy(questions[6].category, "algorithms");
    strcpy(questions[6].question, "What is the time complexity of bubble sort?");
    strcpy(questions[6].answer, "O(n^2)");
    questions[6].value = 400;
    questions[6].answered = false;

    strcpy(questions[7].category, "algorithms");
    strcpy(questions[7].question, "What is a depth-first search?");
    strcpy(questions[7].answer, "A tree traversal algorithm that explores as far as possible along a branch before backtracking.");
    questions[7].value = 600;
    questions[7].answered = false;

    strcpy(questions[8].category, "algorithms");
    strcpy(questions[8].question, "What is the difference between BFS and DFS?");
    strcpy(questions[8].answer, "BFS explores nodes layer by layer, DFS explores as deep as possible.");
    questions[8].value = 800;
    questions[8].answered = false;

    strcpy(questions[9].category, "algorithms");
    strcpy(questions[9].question, "What is a greedy algorithm?");
    strcpy(questions[9].answer, "An algorithmic paradigm that makes the locally optimal choice at each stage.");
    questions[9].value = 1000;
    questions[9].answered = false;

    // Databases Category
    strcpy(questions[10].category, "databases");
    strcpy(questions[10].question, "What does SQL stand for?");
    strcpy(questions[10].answer, "Structured Query Language");
    questions[10].value = 200;
    questions[10].answered = false;

    strcpy(questions[11].category, "databases");
    strcpy(questions[11].question, "What type of database is MongoDB?");
    strcpy(questions[11].answer, "NoSQL");
    questions[11].value = 400;
    questions[11].answered = false;

    strcpy(questions[12].category, "databases");
    strcpy(questions[12].question, "What does ACID stand for in database transactions?");
    strcpy(questions[12].answer, "Atomicity, Consistency, Isolation, Durability");
    questions[12].value = 600;
    questions[12].answered = false;

    strcpy(questions[13].category, "databases");
    strcpy(questions[13].question, "What is the difference between a primary key and a foreign key?");
    strcpy(questions[13].answer, "A primary key uniquely identifies records in a table, while a foreign key links tables together.");
    questions[13].value = 800;
    questions[13].answered = false;

    strcpy(questions[14].category, "databases");
    strcpy(questions[14].question, "What is a join operation in SQL?");
    strcpy(questions[14].answer, "Combining rows from two or more tables based on a related column.");
    questions[14].value = 1000;
    questions[14].answered = false;

    // Operating Systems Category
    strcpy(questions[15].category, "operating systems");
    strcpy(questions[15].question, "What is the purpose of an operating system?");
    strcpy(questions[15].answer, "To manage hardware resources and provide services for application programs.");
    questions[15].value = 200;
    questions[15].answered = false;

    strcpy(questions[16].category, "operating systems");
    strcpy(questions[16].question, "What is a process in an operating system?");
    strcpy(questions[16].answer, "An instance of a program in execution.");
    questions[16].value = 400;
    questions[16].answered = false;

    strcpy(questions[17].category, "operating systems");
    strcpy(questions[17].question, "What is a deadlock in an operating system?");
    strcpy(questions[17].answer, "A situation where two or more processes are blocked, waiting for each other.");
    questions[17].value = 600;
    questions[17].answered = false;

    strcpy(questions[18].category, "operating systems");
    strcpy(questions[18].question, "What is a thread?");
    strcpy(questions[18].answer, "A unit of execution within a process.");
    questions[18].value = 800;
    questions[18].answered = false;

    strcpy(questions[19].category, "operating systems");
    strcpy(questions[19].question, "What is the difference between a process and a thread?");
    strcpy(questions[19].answer, "A process has its own memory space, while a thread shares memory space with other threads in the same process.");
    questions[19].value = 1000;
    questions[19].answered = false;

    // Networking Category
    strcpy(questions[20].category, "networking");
    strcpy(questions[20].question, "What does IP stand for?");
    strcpy(questions[20].answer, "Internet Protocol");
    questions[20].value = 200;
    questions[20].answered = false;

    strcpy(questions[21].category, "networking");
    strcpy(questions[21].question, "What is a DNS?");
    strcpy(questions[21].answer, "Domain Name System");
    questions[21].value = 400;
    questions[21].answered = false;

    strcpy(questions[22].category, "networking");
    strcpy(questions[22].question, "What is the purpose of a router?");
    strcpy(questions[22].answer, "To forward data packets between computer networks.");
    questions[22].value = 600;
    questions[22].answered = false;

    strcpy(questions[23].category, "networking");
    strcpy(questions[23].question, "What is the difference between TCP and UDP?");
    strcpy(questions[23].answer, "TCP is connection-oriented, while UDP is connectionless.");
    questions[23].value = 800;
    questions[23].answered = false;

    strcpy(questions[24].category, "networking");
    strcpy(questions[24].question, "What is an IP address?");
    strcpy(questions[24].answer, "A unique identifier assigned to devices on a network.");
    questions[24].value = 1000;
    questions[24].answered = false;

    // Web Development Category
    strcpy(questions[25].category, "web development");
    strcpy(questions[25].question, "What does HTML stand for?");
    strcpy(questions[25].answer, "HyperText Markup Language");
    questions[25].value = 200;
    questions[25].answered = false;

    strcpy(questions[26].category, "web development");
    strcpy(questions[26].question, "What is CSS used for?");
    strcpy(questions[26].answer, "Cascading Style Sheets, used for styling HTML content.");
    questions[26].value = 400;
    questions[26].answered = false;

    strcpy(questions[27].category, "web development");
    strcpy(questions[27].question, "What is JavaScript?");
    strcpy(questions[27].answer, "A programming language used to create interactive effects within web browsers.");
    questions[27].value = 600;
    questions[27].answered = false;

    strcpy(questions[28].category, "web development");
    strcpy(questions[28].question, "What is the purpose of a front-end framework?");
    strcpy(questions[28].answer, "To provide pre-written code to make building web interfaces faster.");
    questions[28].value = 800;
    questions[28].answered = false;

    strcpy(questions[29].category, "web development");
    strcpy(questions[29].question, "What is a REST API?");
    strcpy(questions[29].answer, "Representational State Transfer, a software architectural style for distributed systems.");
    questions[29].value = 1000;
    questions[29].answered = false;
}

void display_categories(void) {
    printf("\nAvailable Questions:\n");

    // --- Print the header row with category names ---
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        // Use a fixed width for each column (20 characters in this example)
        printf("%-20s", categories[i]);
    }
    printf("\n");

    // --- Determine the maximum number of questions in any category ---
    int maxQuestions = 0;
    int questionCount[NUM_CATEGORIES] = {0};
    for (int c = 0; c < NUM_CATEGORIES; c++) {
        for (int i = 0; i < NUM_QUESTIONS; i++) {
            if (strcasecmp(questions[i].category, categories[c]) == 0) {
                questionCount[c]++;
            }
        }
        if (questionCount[c] > maxQuestions) {
            maxQuestions = questionCount[c];
        }
    }

    // --- Allocate temporary storage for each category's question values and answered status ---
    // We use dynamic arrays (one per category) to store the question values and whether they've been answered.
    int *values[NUM_CATEGORIES];
    bool *answered[NUM_CATEGORIES];
    for (int c = 0; c < NUM_CATEGORIES; c++) {
        values[c] = malloc(questionCount[c] * sizeof(int));
        answered[c] = malloc(questionCount[c] * sizeof(bool));
        int pos = 0;
        // Collect all questions for this category.
        for (int i = 0; i < NUM_QUESTIONS; i++) {
            if (strcasecmp(questions[i].category, categories[c]) == 0) {
                values[c][pos] = questions[i].value;
                answered[c][pos] = questions[i].answered;
                pos++;
            }
        }
    }

    // --- Print the grid rows ---
    // Each row corresponds to one question (e.g., first question, second question, etc.) for each category.
    for (int row = 0; row < maxQuestions; row++) {
        for (int cat = 0; cat < NUM_CATEGORIES; cat++) {
            if (row < questionCount[cat]) {
                if (answered[cat][row]) {
                    // If the question is answered, print an "X" or other marker.
                    printf("%-20s", "X");
                } else {
                    // Otherwise, print the dollar value.
                    char buf[32];
                    sprintf(buf, "$%d", values[cat][row]);
                    printf("%-20s", buf);
                }
            } else {
                // If this category doesn't have a question in this row, print an empty column.
                printf("%-20s", " ");
            }
        }
        printf("\n");
    }

    // --- Free temporary storage ---
    for (int c = 0; c < NUM_CATEGORIES; c++) {
        free(values[c]);
        free(answered[c]);
    }
}


void display_question(char *category, int value) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcasecmp(questions[i].category, category) == 0 && questions[i].value == value) {
            if (!questions[i].answered) {
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

/**
 * THIS IS HOW WE HANDLE RANDOM SPACES AND UPPERCASES IN USER INPUT
 * Normalize a string by converting it to lowercase and removing non-alphanumeric characters.
 */
void normalize_string(char *dest, const char *src) {
    while (*src) {
        if (isalnum((unsigned char)*src)) { // Only include letters and digits.
            *dest = tolower((unsigned char)*src);
            dest++;
        }
        src++;
    }
    *dest = '\0';
}

/**
 * Returns true if the sanitized user answer matches the sanitized correct answer.
 */
bool valid_answer(char *category, int value, char *answer) {
    char norm_user[MAX_LEN];
    char norm_correct[MAX_LEN];
    
    // Normalize the user's answer.
    normalize_string(norm_user, answer);
    
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcasecmp(questions[i].category, category) == 0 && questions[i].value == value) {
            // Normalize the stored answer.
            normalize_string(norm_correct, questions[i].answer);
            if (strcmp(norm_user, norm_correct) == 0) {
                return true;
            }
            return false;
        }
    }
    return false;
}

bool already_answered(char *category, int value) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcasecmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return questions[i].answered;
        }
    }
    return false;
}

const char* get_correct_answer(char *category, int value) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcasecmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return questions[i].answer;
        }
    }
    return "Unknown";
}
