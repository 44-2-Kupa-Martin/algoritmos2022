#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    size_t n;
    scanf("%zu", &n);
    char *strArr[n];
    for (size_t i = 0; i < n; i++)
    {
        char buffer[65535];
        printf("bldo labura: ");
        scanf("%65534s", buffer);
        while (getchar() != '\n');
        strArr[i]= malloc(sizeof(char) * strlen(buffer)+1);
        strcpy(strArr[i], buffer);
    }
    for (size_t i = 0; i < n; i++)
    {
        printf("%s", strArr[i]);
        free(strArr[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            if (strcmp(tolower(strArr[i]), tolower(strArr[j])) < 0) {
                
            }
        }
    }
    
    return 0;
}
