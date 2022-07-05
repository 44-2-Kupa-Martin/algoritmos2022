#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
// Typedef and structs:
typedef struct Match {
    char *word; //null terminated string
    size_t wordLength;
    char guessedLetters[94]; //null terminated string
    size_t guessedLettersCounter;
    unsigned int mistakes;
    char *currentState; //null terminated string
} Match;
//

// Function Prototypes:
Match *makeMatch(void);
size_t priv_promptWord(char *);
void freeMatch(Match *);
bool nextTurn(Match *);
void priv_displayState(Match *);
void priv_youWon(Match *);
void priv_youLost(Match *);
//


// Main
int main(int argc, char const *argv[])
{
    Match *currentMatch= makeMatch();
    bool done= false;
    while (!done)
    {
        done= nextTurn(currentMatch);
    }
    freeMatch(currentMatch);
    return 0;
}
//


// Function definitions 
Match *makeMatch(void) {
    Match *m= malloc(sizeof *m);
    m->guessedLettersCounter= 0;
    m->mistakes= 0;
    for (size_t i = 0; i < 94; i++)
    {
        m->guessedLetters[i]= '\0';
    }
    char temp[65535];
    m->wordLength= priv_promptWord(temp);
    m->word= malloc(m->wordLength * sizeof(char));
    m->currentState= malloc(m->wordLength * sizeof(char));
    for (size_t i = 0; i < m->wordLength; i++)
    {
        m->word[i]= tolower(temp[i]);
        m->currentState[i]= '_';
    }
    m->currentState[m->wordLength -1]= '\0';
    return m;
}
size_t priv_promptWord(char arr[]) {
    printf("Enter the word\n");
    scanf("%65534s", arr);
    system("cls");
    while (getchar() != '\n');
    return strlen(arr)+1;
}
void freeMatch(Match *m) {
    free(m->word);
    free(m->currentState);
    free(m);
    return;
}
bool nextTurn(Match *currentMatch) {
    if (currentMatch->mistakes == 10) {
        priv_youLost(currentMatch);
        return 1;
    }
    priv_displayState(currentMatch);
    printf("Make a guess:\n\t1. Guess a letter\n\t2. Guess a word\n");
    unsigned choice;
    label_choice:
    scanf("%u", &choice);
    while (getchar() != '\n');
    switch (choice) {
    case 1: {
        //letter guess
        printf("Guess a letter\n");
        label_tryAgain: ;
        char letterGuess= tolower(getchar());
        while (getchar() != '\n');
        bool valid= true;
        for (size_t i = 0; i < currentMatch->guessedLettersCounter; i++)
        {
            if (letterGuess == currentMatch->guessedLetters[i])
            {
                valid= false;
                break;
            }
        }
        if (!valid) {
            printf("You already made that guess, try again\n");
            goto label_tryAgain;
        }
        currentMatch->guessedLetters[currentMatch->guessedLettersCounter++]= letterGuess;
        bool guessNotInWord= true;
        for (size_t i = 0; i < currentMatch->wordLength; i++)
        {
            if (currentMatch->word[i] == letterGuess) {
                currentMatch->currentState[i]= letterGuess;
                guessNotInWord= false;
            }
        }
        if (guessNotInWord) currentMatch->mistakes++;
        break;
    }
    case 2: {
        char wordGuess[65535]= {0};
        printf("Guess a word\n");
        scanf("%65534s", wordGuess);
        bool sameWord= strcmp(currentMatch->word, wordGuess) == 0 ? true : false;
        if (sameWord)
        {
            priv_youWon(currentMatch);
            return 1;
        } else {
            currentMatch->mistakes++;
            return 0;
        }
        break;
    }
    default:
        printf("Invalid choice, try again\n");
        goto label_choice;
    }
    //win condition
    if (strcmp(currentMatch->word, currentMatch->currentState) == 0) {
        priv_youWon(currentMatch);
        return 1;
    }
    return 0;
}
void priv_displayState(Match *currentMatch) {
    system("cls");
    for (size_t i = 0; i < currentMatch->wordLength; i++)
    {
        putchar(currentMatch->currentState[i]);
        putchar(' ');
    }
    putchar('\n');
    printf("Mistakes: %u\n", currentMatch->mistakes);
    printf("Guessed letters: ");
    for (size_t i = 0; i < currentMatch->guessedLettersCounter; i++)
    {
        putchar(currentMatch->guessedLetters[i]);
        putchar(' ');
    }
    putchar('\n');
    return;
}
void priv_youWon(Match *currentMatch) {
    system("cls");
    printf("You Won! The word was %s\n", currentMatch->word);
    return;
}
void priv_youLost(Match *currentMatch) {
    system("cls");
    printf("You ran out of attempts. The word was %s\n", currentMatch->word);
    return;
}
//