#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    size_t n;
    scanf("%zu", &n);
    char *test[n];
    for (size_t i = 0; i < n; i++)
    {
        char buffer[65535];
        printf("bldo labura: ");
        scanf("%65534s", buffer);
        while (getchar() != '\n');
        test[i]= malloc(sizeof(char) * strlen(buffer)+1);
        strcpy(test[i], buffer);
    }
    for (size_t i = 0; i < n; i++)
    {
        free(test[i]);
    }
    label_menu:
    n= 1;
    char a[]= {'a', 'b', '\0'};
    char *j= (&a[1])+2;
    *j= 'o';
    printf("%s %s", test, a);
    return 0;
}
