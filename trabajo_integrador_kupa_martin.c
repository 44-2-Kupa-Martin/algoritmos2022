#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <wchar.h>
#include <locale.h>
//throughout the program wprintf is used instead of printf because the length of certain characters exceeds 1 byte (e.g ñ). Thus, the necessity of wchar_t and its related functions.
void promptNumbers(size_t m, size_t n, double matrix[][n]) {
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            wprintf(L"Ingrese el numero en la %zu fila %zu columna\n", i+1, j+1);
            scanf("%lf", &matrix[i][j]);
            while (getchar() != '\n'){}
        }
    }
    return;
}
int productOfMatrices(void) {
    size_t m, n, p, l;
    wprintf(L"Recuerda que el numero de columnas de la primera matriz debe ser igual a las filas de la segunda\n");
    wprintf(L"Ingrese las dimensiones de la primera matriz\n");
    scanf("%zu %zu", &m, &n);
    while (getchar() != '\n'){}
    wprintf(L"Ingrese las dimensiones de la segunda matriz\n");
    scanf("%zu %zu", &p, &l);
    while (getchar() != '\n'){}
    if (n != p)
    {
        wprintf(L"No se puede multiplicar estas matrices.\n");
        return 0;
    }
    double matrixA[m][n], matrixB[n][l], result[m][l];
    wprintf(L"\nIngrese los numeros de la primera matriz\n");
    promptNumbers(m,n,matrixA);
    wprintf(L"\nIngrese los numeros de la segunda matriz\n");
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
            wprintf(L"%.2lf ", result[i][j]);
        }
        wprintf(L"\n");
    }
    char choice;
    wprintf(L"¿Quieres hacerlo otra vez? s/n\n");
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
    wprintf(L"Ingrese las dimensiones de las matrices (filas columnas)\n");
    scanf("%zu %zu", &m, &n);
    while (getchar() != '\n'){}
    double matrixA[m][n], matrixB[m][n];
    wprintf(L"\nIngrese los numeros de la primera matriz\n");
    promptNumbers(m,n,matrixA);
    wprintf(L"\nIngrese los numeros de la segunda matriz\n");
    promptNumbers(m,n,matrixB);
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            wprintf(L"%.2lf ", matrixA[i][j] + matrixB[i][j]);
        }
        wprintf(L"\n");
    }
    char choice;
    wprintf(L"¿Quieres hacerlo otra vez? s/n\n");
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
    unsigned int choice1;
    double det;
    label_choice1:
    wprintf(L"Cual es el tamaño de la matriz?\n\t1. 2x2\n\t2. 3x3\n");
    scanf("%u", &choice1);
    while (getchar() != '\n'){}
    switch (choice1)
    {
        case 1: {
            double matrix[2][2];
            promptNumbers(2,2,matrix);
            det= matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
            break;
        }
        case 2: {
            double matrix[3][3];
            promptNumbers(3,3,matrix);
            det=   matrix[0][0]*(matrix[1][1]*matrix[2][2] - matrix[1][2]*matrix[2][1])
                 - matrix[0][1]*(matrix[1][0]*matrix[2][2] - matrix[1][2]*matrix[2][0])
                 + matrix[0][2]*(matrix[1][0]*matrix[2][1] - matrix[1][1]*matrix[2][0])
            ;
            break;
        }
        default: {
            wprintf(L"Opcion invalida\n");
            goto label_choice1;
        }
    }
    wprintf(L"Determinante= %lf\n", det);
    char choice2;
    wprintf(L"¿Quieres hacerlo otra vez? s/n\n");
    scanf(" %c", &choice2);
    while (getchar() != '\n'){}
    if (choice2 == 's')
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
    wprintf(L"Ingrese el tamaño del vector\n");
    scanf("%zu", &n);
    while (getchar() != '\n'){}
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
        wprintf(L"Ingrese el %zu numero del array\n", i+1);
        scanf("%d", &arr[i]);
        while (getchar() != '\n'){}
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
        wprintf(L"%d ", even[i]);
    }
    for (size_t i = 0; i < oddIndex; i++)
    {
        wprintf(L"%d ", odd[i]);
    }
    wprintf(L"\n");
    char choice;
    wprintf(L"¿Quieres hacerlo otra vez? s/n\n");
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
    wprintf(L"Ingrese el año\n");
    scanf("%u", &year);
    while (getchar() != '\n'){}
    wchar_t *str;
    if (year % 6 != 0 || year % 100 == 0)
    {
        str= L"no es";
    } else {
        str= L"es";
    }
    wprintf(L"%d %ls bisiesto\n", year, str);
    char choice;
    wprintf(L"¿Quieres hacerlo otra vez? s/n\n");
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
    fwide(stdout, 1); //set stdout to wchar_t
    setlocale(LC_CTYPE, ""); //this call is necessary to correctly display certain characters, as it sets the correct encoding.
    bool done = false;
    unsigned int choice;
    while (!done) {
        wprintf(L"¿Que quieres hacer?\n\t1. Sumar dos matrices\n\t2. Multiplicar dos matrices\n\t3. Calcular la determiante (2x2)\n\t4. Ordenar vector segun paridad\n\t5. Test de año bisiesto\n\t6. Salir\n");
        scanf("%u", &choice);
        while (getchar() != '\n'){}
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
                wprintf(L"Opcion invalida\n");
                break;
            }
        }
    }
    return 0;
}
