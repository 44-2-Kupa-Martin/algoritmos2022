#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
void promptNumbers(size_t m, size_t n, double matrix[][n]) {
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            printf("Ingrese el numero en la %zu fila %zu columna\n", i+1, j+1);
            scanf("%lf", &matrix[i][j]);
        }
    }
    return;
}
int productOfMatrices(void) {
    size_t m, n, p, l;
    printf("Recuerda que el numero de columnas de la primera matriz debe ser igual a las filas de la segunda\n");
    printf("Ingrese las dimensiones de la primera matriz\n");
    scanf("%zu %zu", &m, &n);
    printf("Ingrese las dimensiones de la segunda matriz\n");
    scanf("%zu %zu", &p, &l);
    if (n != p)
    {
        printf("No se puede multiplicar estas matrices.\n");
        return 0;
    }
    double matrixA[m][n], matrixB[n][l], result[m][l];
    printf("\nIngrese los numeros de la primera matriz\n");
    promptNumbers(m,n,matrixA);
    printf("\nIngrese los numeros de la segunda matriz\n");
    promptNumbers(n,l,matrixB);
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < l; j++)
        {
            double sum= 0;
            for (size_t z = 0; z < n; z++)
            {
                sum += matrixA[i][z] * matrixB[z][j];
            }
            result[i][j] = sum;
        }
    }
    //output
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < l; j++)
        {
            printf("%.2lf ", result[i][j]);
        }
        printf("\n");
    }
    char choice;
    printf("¿Quieres hacerlo otra vez? s/n\n");
    scanf(" %c", &choice);
    while (getchar() != '\n'){}
    if (choice == 's')
    {
        return 0;
    } else {
        return 1;
    }
    return 0;
}
int sumOfMatrices(void) {
    size_t m, n; 
    printf("Ingrese las dimensiones de las matrices (filas columnas)\n");
    scanf("%zu %zu", &m, &n);
    double matrixA[m][n], matrixB[m][n];
    printf("\nIngrese los numeros de la primera matriz\n");
    promptNumbers(m,n,matrixA);
    printf("\nIngrese los numeros de la segunda matriz\n");
    promptNumbers(m,n,matrixB);
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            printf("%.2lf ", matrixA[i][j] + matrixB[i][j]);
        }
        printf("\n");
    }
    char choice;
    printf("¿Quieres hacerlo otra vez? s/n\n");
    scanf(" %c", &choice);
    while (getchar() != '\n'){}
    if (choice == 's')
    {
        return 0;
    } else {
        return 1;
    }
}
int detOfMatrix(void) {
    double matrix[2][2];
    promptNumbers(2,2,matrix);
    double det= matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
    printf("Determinante= %lf\n", det);
    char choice;
    printf("¿Quieres hacerlo otra vez? s/n\n");
    scanf(" %c", &choice);
    while (getchar() != '\n'){}
    if (choice == 's')
    {
        return 0;
    } else {
        return 1;
    }
    return 0;
}
void sortEven(size_t n, int arrIn[]) {
    int min= INT_MAX;
    size_t index;
    for (size_t i = 0; i < n; i++) {
        //find lowest number in arrIn
        for (size_t j = i; j < n; j++) {
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
    return;
}
void sortOdd(size_t n, int arrIn[]) {
    int max= INT_MIN;
    size_t index;
    for (size_t i = 0; i < n; i++) {
        //find highest number in arrIn
        for (size_t j = i; j < n; j++) {
            if (arrIn[j] > max) {
              max= arrIn[j];
              index= j;
            }
        }
        //swap two numbers in arrIn
        arrIn[index]= arrIn[i];
        arrIn[i]= max;
        max= INT_MIN;
    }
    return;
}
int orderVector(void) {
    size_t n;
    printf("Ingrese el tamaño del vector\n");
    scanf("%zu", &n);
    int arr[n], even[n], odd[n];
    //initialize
    for (size_t i = 0; i < n; i++)
    {
        even[i]= INT_MAX;
        odd[i]= INT_MIN;
    }
    size_t evenIndex= 0, oddIndex= 0;
    //input
    for (size_t i = 0; i < n; i++)
    {
        printf("Ingrese el %zu numero del array\n", i+1);
        scanf("%d", &arr[i]);
    }
    //filter by parity
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even[evenIndex]= arr[i];
            evenIndex++;
        } else {
            odd[oddIndex]= arr[i];
            oddIndex++;
        }
    }
    //sort
    sortEven(evenIndex, even);
    sortOdd(oddIndex, odd);
    //output
    for (size_t i = 0; i < evenIndex; i++)
    {
        printf("%d ", even[i]);
    }
    for (size_t i = 0; i < oddIndex; i++)
    {
        printf("%d ", odd[i]);
    }
    printf("\n");
    char choice;
    printf("¿Quieres hacerlo otra vez? s/n\n");
    scanf(" %c", &choice);
    while (getchar() != '\n'){}
    if (choice == 's')
    {
        return 0;
    } else {
        return 1;
    }
    return 0;
}
int checkLeap(void) {
    unsigned int year;
    printf("Ingrese el año\n");
    scanf("%u", &year);
    char *str;
    if (year % 6 != 0 || year % 100 == 0)
    {
        str= "no es";
    } else {
        str= "es";
    }
    printf("%d %s bisiesto\n", year, str);
    char choice;
    printf("¿Quieres hacerlo otra vez? s/n\n");
    scanf(" %c", &choice);
    while (getchar() != '\n'){}
    if (choice == 's')
    {
        return 0;
    } else {
        return 1;
    }
}
int main(int argc, char const *argv[])
{
    bool done = false;
    unsigned int choice;
    while (!done) {
        printf("¿Que quieres hacer?\n\t1. Sumar dos matrices\n\t2. Multiplicar dos matrices\n\t3. Calcular la determiante (2x2)\n\t4. Ordenar vector segun paridad\n\t5. Test de año bisiesto\n\t6. Salir\n");
        scanf("%u", &choice);
        switch (choice) {
            case 1: {
                bool functionDone= false;
                while (!functionDone)
                {
                    functionDone= sumOfMatrices();
                }                
                break;
            }
            case 2: {
                bool functionDone= false;
                while (!functionDone)
                {
                    functionDone= productOfMatrices();
                }                
                break;
            }
            case 3: {
                bool functionDone= false;
                while (!functionDone)
                {
                    functionDone= detOfMatrix();
                }                
                break;
            }
            case 4: {
                bool functionDone= false;
                while (!functionDone)
                {
                    functionDone= orderVector();
                }                
                break;
            }
            case 5: {
                bool functionDone= false;
                while (!functionDone)
                {
                    functionDone= checkLeap();
                }                
                break;
            }
            case 6: {
                done= true;
                break;
            }
            default: {
                printf("Opcion invalida\n");
                break;
            }
        }
    }
    return 0;
}
