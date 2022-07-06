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
    Match *ptr_currentMatch= makeMatch();
    bool done= false;
    while (!done)
    {
        done= nextTurn(ptr_currentMatch);
    }
    freeMatch(ptr_currentMatch);
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
bool nextTurn(Match *ptr_currentMatch) {
    if (ptr_currentMatch->mistakes == 10) {
        priv_youLost(ptr_currentMatch);
        return 1;
    }
    priv_displayState(ptr_currentMatch);
    printf("Make a guess:\n");
    label_tryAgain: ;
    char guess[65535]= {0};
    scanf("%65534s", guess);
    while (getchar() != '\n');
    if (strlen(guess) == 1) {
        //letter guess
        char letterGuess= tolower(guess[0]);
        bool valid= true;
        for (size_t i = 0; i < ptr_currentMatch->guessedLettersCounter; i++)
        {
            if (letterGuess == ptr_currentMatch->guessedLetters[i])
            {
                valid= false;
                break;
            }
        }
        if (!valid) {
            printf("You already made that guess, try again\n");
            goto label_tryAgain;
        }
        ptr_currentMatch->guessedLetters[ptr_currentMatch->guessedLettersCounter++]= letterGuess;
        bool guessNotInWord= true;
        for (size_t i = 0; i < ptr_currentMatch->wordLength; i++)
        {
            if (ptr_currentMatch->word[i] == letterGuess) {
                ptr_currentMatch->currentState[i]= letterGuess;
                guessNotInWord= false;
            }
        }
        if (guessNotInWord) ptr_currentMatch->mistakes++;
    } else {
        bool sameWord= strcmp(ptr_currentMatch->word, guess) == 0 ? true : false;
        if (sameWord)
        {
            priv_youWon(ptr_currentMatch);
            return 1;
        } else {
            ptr_currentMatch->mistakes++;
            return 0;
        }
    }
    //win condition
    if (strcmp(ptr_currentMatch->word, ptr_currentMatch->currentState) == 0) {
        priv_youWon(ptr_currentMatch);
        return 1;
    }
    return 0;
}
void priv_displayState(Match *ptr_currentMatch) {
    system("cls");
    for (size_t i = 0; i < ptr_currentMatch->wordLength; i++)
    {
        putchar(ptr_currentMatch->currentState[i]);
        putchar(' ');
    }
    putchar('\n');
    printf("Mistakes: %u\n", ptr_currentMatch->mistakes);
    printf("Guessed letters: ");
    for (size_t i = 0; i < ptr_currentMatch->guessedLettersCounter; i++)
    {
        putchar(ptr_currentMatch->guessedLetters[i]);
        putchar(' ');
    }
    putchar('\n');
    return;
}
void priv_youWon(Match *ptr_currentMatch) {
    system("cls");
    printf("You Won! The word was %s\n", ptr_currentMatch->word);
    return;
}
void priv_youLost(Match *ptr_currentMatch) {
    system("cls");
    printf("You ran out of attempts. The word was %s\n", ptr_currentMatch->word);
    return;
}
//