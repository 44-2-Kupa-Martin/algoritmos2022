#include <stdio.h>
#include <float.h>

int main(void) {
  printf("enter array size\n");
  int n;
  scanf("%d", &n);
  double arrIn[n], arrOut[n];
  double min= DBL_MAX;
  size_t index;
  //input numbers into arrIn
  for (size_t i = 0; i < n; i++) {
    printf("enter %d st number\n", i+1);
    scanf("%lf", &arrIn[i]);
  }
  for (size_t j = 0; j < n; j++) {
    //find lowest number in arrIn
    for (size_t i = 0; i < n; i++) {
      if (arrIn[i] < min) {
        min= arrIn[i];
        index= i;
      }
    }
    //update arrOut and prepare arrIn to loop again
    arrOut[j]= min;
    arrIn[index]= DBL_MAX;
    min= DBL_MAX;
  }
  for (size_t i = 0; i < n; i++) {
    printf("\n%f\n", arrOut[i]);
  }
  return 0;
}
