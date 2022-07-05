#include <stdio.h>
#include <limits.h>
void sort(int [], int *, int *, int *, int *, int *);
int main(int argc, char *argv[]) {
    int a, b, c, d, e;
    int arr[5];
    for (size_t i= 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, &a, &b, &c, &d, &e);
    printf("%d %d %d %d %d\n", a,b,c,d,e);
    return 0;
}
void sort(int arrIn[], int *a, int *b, int *c, int *d, int *e) {
    int min= INT_MAX;
    size_t index;
    for (size_t i = 0; i < 5; i++) {
        //find lowest number in arrIn
        for (size_t j = i; j < 5; j++) {
            if (arrIn[j] < min) {
              min= arrIn[j];
              index= j;
            }
        }
        //swap two numbers in arrIn
        arrIn[index]= arrIn[i];
        arrIn[i]= min;
        min= INT_MAX;
    }
    *a= arrIn[0];
    *b= arrIn[1];
    *c= arrIn[2];
    *d= arrIn[3];
    *e= arrIn[4];
    return;
}