/*WINTER 2016*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>

char* getUserChoice() {
    /* Prompt the user "Enter rock, paper, or scissors: " and return
       the string they enter */
    char* userInput = (char*) malloc(9); 

    printf("Enter rock, paper or scissors: ");
    scanf("%s", userInput);

    return userInput;
}

char* getComputerChoice() {
    srand(time(NULL));
    /* get a pseudo-random integer between 0 and 2 (inclusive) */
    int randChoice = rand() % 3;

    /* If randChoice is 0, return "rock"; if randChoice is 1, 
     return "paper", and if randChoice is 2, return "scissors". */

    char* compChoice = NULL;
    if (randChoice == 0) {
        compChoice = "rock";
    }
    if (randChoice == 1) {
        compChoice = "paper";
    }
    if (randChoice == 2) {
        compChoice = "scissors";
    }

    return compChoice;
}

char* compare(char* choice1, char* choice2) 
{
    /* Implement the logic of the game here. If choice1 and choice2
     are equal, the result should be "This game is a tie."
    
     Make sure to use strcmp for string comparison.
     */
    char* result = NULL;

     if (strcmp(choice1, choice2) == 0) {
        result = "This game is a tie.";
        return result;
     }
     if (strcmp(choice1, "rock") == 0) {
        if (strcmp(choice2, "paper") == 0) {
            result = "Paper wins.";
        }
        else {
            result = "Rock wins.";
        }
     }
     if (strcmp(choice1, "paper") == 0) {
        if (strcmp(choice2, "scissors") == 0) {
            result = "Scissors wins.";
        }
        else {
            result = "Paper wins.";
        }
     }
     if (strcmp(choice1, "scissors") == 0) {
        if (strcmp(choice2, "rock") == 0) {
            result = "Rock wins.";
        }
        else {
            result = "Scissors wins.";
        }
     }

     return result;
}

int main(int argc, char** argv) 
{
    char *userChoice = NULL, *computerChoice = NULL, *outcome = NULL;

    userChoice = getUserChoice();

    if (strcmp(userChoice, "rock") == 0 || strcmp(userChoice, "paper") == 0 || strcmp(userChoice, 
        "scissors") == 0) {
        computerChoice = getComputerChoice();

        outcome = compare(userChoice, computerChoice);

        printf("You picked %s.\n", userChoice);
        printf("Computer picked %s.\n", computerChoice);
        printf("%s\n", outcome);
    }
    else {
        printf("Invalid user choice, you must enter rock, paper or scissors.\n");
        free(userChoice);
        return 0;
    }

    free(userChoice);

    return 0;
}