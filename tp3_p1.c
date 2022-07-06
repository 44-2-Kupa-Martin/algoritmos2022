#include <stdio.h>

void carga (int n, int Vector[]);
void imprimir (int n, int Vector[]);

int main()
{
    int n=5;
   	int V[n];
    carga (n,V);
    imprimir (n,V);
   	printf("\n");
    //prints the array
  	for (int i=0; i<n; i++){
        printf("%5d",V[i]);
    }
    return 0;
}
//initializes the array
void carga (int n, int Vector[]){
   	int i;
   	for (i=0; i<n; i++) {
       printf("ingrese el valor de la posicion %d: ",i);
       scanf("%d",&Vector[i]);
  	}
}
void imprimir (int n, int Vector[]){
  	for (int i=0; i<n; i++){
      	printf("\n %5d",Vector[i]);
    }
   	printf("\n");
}




int ej2() {
    int x, *y;
    x=10;
    y=&x; //y points to x
    printf("%d %d %d",y,*y,&y ); //x's memory address, 10, y's memory address
    return 0;
}
