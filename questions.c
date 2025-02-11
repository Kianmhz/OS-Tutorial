
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
    "databases",
    "operating systems", 
    "networking", 
    "web development"
};

// Define questions array (previously in header)
question questions[NUM_QUESTIONS];

// Initializes the array of questions for the game
void initialize_game(void)
{
    // Programming Category
    strcpy(questions[0].category, "programming");
    strcpy(questions[0].question, "What is the complexity of binary search?");
    strcpy(questions[0].answer, "O(logpron)");
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
