#define N 10
#include <stdio.h>
//these functions will only accept int (*)[10]. Passing, for example, a 11x11 matrix will result in a compiler error.
void leer_matriz(int A[N][N], int filas, int columnas);
void escribir_matriz(int A[N][N], int filas, int columnas);
void multiplicar(int A[N][N], int B[N][N], int C[N][N], int m, int n, int p);
int main ()  {
 int m, n, p;
 //not a VLA, N is a macro.
 int A[N][N], B[N][N], C[N][N];
 	printf("\n Datos de la Matriz A: \n");  
    printf("Filas: ");  		scanf("%d", &m);
 	printf("Columnas: "); 	scanf("%d", &n);
    //might write out of bounds
    leer_matriz(A, m, n);
 	printf("\n Datos de la Matriz B: \n");
    printf("Columnas: ");	 	scanf("%d", &p);
    //might write out of bounds
    leer_matriz(B, n, p);
    printf("\n Matriz A:\n");  escribir_matriz(A, m, n);
    printf("\n Matriz B: \n");  escribir_matriz(B, n, p);
    //might write out of bounds
    multiplicar(A, B, C, m, n, p); 
    printf("\n Matriz AxB: \n");   escribir_matriz(C, m, p);
}
//mismatched definitions. 
void leer_matriz(int A[N][N], int filas, int columnas) {
 	int i, j;
 for (i=0; i<filas; i++)  {
  		for (j=0; j<columnas; j++)  {
   			printf("Ingresa la entrada [%d][%d]: ", i+1, j+1);
   			scanf("%d", &A[i][j]);
 		}
 	}
}
//mismatched definitions. 
void escribir_matriz(int A[N][N], int filas, int columnas)
{
 int i, j;
 for (i=0; i< filas; i++)  {
  		for (j=0; j<columnas; j++)   {
   			printf("\t%d", A[i][j]);
 		 }
  		printf("\n");
 }
}
void multiplicar (int A[N][N], int B[N][N], int C[N][N], int m, int n, int p) {
 	int i, j, k;
 //missing brackets
 	for(i=0; i< m; i++)
  		for(k=0; k< p; k++)
   			C[i][k]=0;
   
 		for (i=0; i< m; i++)
 			for (j=0; j< n; j++)
  				 for (k=0; k< p; k++)
   					 C[i][k] = C[i][k] + A[i][j]*B[j][k];
}