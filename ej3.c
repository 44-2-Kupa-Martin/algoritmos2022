#include <stdio.h>
#include <float.h>

int main(void) {
	printf("Ingrese 3 numeros\n");
	char operand;
	double arrIn[3];
	scanf("%lf %lf %lf", &arrIn[0], &arrIn[1], &arrIn[2]);
	printf("Que operacion desea realizar (+, *, /)\n");
	scanf(" %c", &operand);
	switch(operand) {
		case '+': ;
			printf("%f\n", arrIn[0]+arrIn[1]+arrIn[2]);
			break;
		case '*': ;
			printf("%f\n", arrIn[0]*arrIn[1]*arrIn[2]);
			break;
		case '/': ;
			double min= DBL_MAX;
			double max= DBL_MIN;
			for (size_t i= 0; i < 3; i++) {
				if (arrIn[i] < min) {
					min= arrIn[i];
				}
				if (arrIn[i] > max) {
					max= arrIn[i];
				}
			}
			if (min == 0) {
				printf("Minimum value can't be zero\n");
			} else {
				printf("%f\n", max/min);
			}
			break;
		default:
			printf("Invalid operand\n");
	}
	return 0;
}