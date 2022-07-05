#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct Match {
    char word[65535];
    char guessedLetters[26];
    char currentState[];
} Match;
int nextTurn(void);
Match *makeMatch(void);
int main(int argc, char const *argv[])
{
    makeMatch();
    bool done= 0;
    while (!done)
    {
        done= nextTurn();
    }
    return 0;
}
