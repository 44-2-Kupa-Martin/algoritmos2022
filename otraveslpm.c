#include <stdio.h>
double sum(double a, double b) {
    return a+b;
}
double product(double a, double b) {
    return a*b;
}
double division(double a, double b) {
    return a/b;
}
int reminder(int a, int b) {
    return a%b;
}
int main(int argc, char const *argv[])
{
    double a, b;
    printf("Enter two numbers\n");
    scanf("%lf %lf", &a, &b);
    printf("%lf\n%lf\n%lf\n%d", sum(a, b), product(a, b), division(a, b), reminder((int)a, (int)b));
    return 0;
}
