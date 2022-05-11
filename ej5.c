#include <stdio.h>

int main(void)
{
    unsigned int n;
    printf("Enter a number\n");
    scanf("%u", &n);
    if (n < 0)
    {
        printf("Invalid input\n");
        return 0;
    }
    long long unsigned int result= 1;
    for (size_t i = n; i >= 1; i--)
    {
        result= result*i;
    }
    printf("%llu", result);
    return 0;
}
