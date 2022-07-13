#define FLUSH_INPUT() while (getchar() != '\n')
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    size_t n;
    printf("How many words do you want to sort?\n");
    scanf("%zu", &n);
    char *strArr[n];
    char *loweredArr[n];
    for (size_t i = 0; i < n; i++)
    {
        char buffer[65535];
        printf("%zust word: ", i+1);
        scanf("%65534s", buffer);
        FLUSH_INPUT();
        size_t buffLen= strlen(buffer)+1;
        strArr[i]= malloc(sizeof(char) * buffLen);
        loweredArr[i]= malloc(sizeof(char) * buffLen);
        strcpy(strArr[i], buffer);
        for (size_t i = 0; i < buffLen; i++)
        {
            buffer[i]= tolower(buffer[i]);
        }
        strcpy(loweredArr[i], buffer);
    }
    for (size_t i = 0; i < n; i++) {
        char *min= "\x7F"; //string containing last ascii char
        size_t index;
        for (size_t j = i; j < n; j++) {
            if (strcmp(min, loweredArr[j]) > 0)
            {
                min= loweredArr[j];
                index= j;
            }
        }
        char *temp1= loweredArr[i];
        char *temp2= strArr[i];
        loweredArr[i]= loweredArr[index];
        strArr[i]= strArr[index];
        loweredArr[index]= temp1;
        strArr[index]= temp2;
    }
    for (size_t i = 0; i < n; i++)
    {
        printf("%s\n", strArr[i]);
        free(loweredArr[i]);
        free(strArr[i]);
    }
    return 0;
}
