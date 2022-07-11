#define FLUSH_INPUT() while (getchar() != '\n')
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// https://stackoverflow.com/questions/6567742/passing-an-array-as-an-argument-to-a-function-in-c
// https://stackoverflow.com/questions/2828648/how-to-pass-a-multidimensional-array-to-a-function-in-c-and-c

// Function Prototypes
void printMatrix(size_t, size_t, double[][*]);
void promptNumbers(size_t, size_t, double[][*]);
double (*sumOfMatrices(size_t, size_t, double[][*], double[][*]))[];
double (*productOfMatrices(size_t, size_t, size_t, double[][*], double[][*]))[];
double (*transposeMatrix(size_t, size_t, double[][*]))[];
double determinantOf3x3(double (*)[3][3]);
void determinantOf2x2(void);
//

// Main
int main(int argc, char const *argv[])
{
    bool done= false;
    while (!done) {
        label_menu: ;
        unsigned choice;
        printf("What do you want to do?\n\t1. Sum\n\t2. Product\n\t3. Transpose\n\t4. Determinant\n\t5. Exit\n");
        scanf("%u", &choice);
        FLUSH_INPUT();
        switch (choice) {
            case 1: {
                size_t m, n, l, p;
                printf("Input the dimensions of the first matrix\n");
                scanf("%zu %zu", &m, &n);
                FLUSH_INPUT();
                printf("Input the dimensions of the second matrix\n");
                scanf("%zu %zu", &l, &p);
                FLUSH_INPUT();
                bool sameDimensions= (m == l) && (n == p); 
                if (!sameDimensions) {
                    printf("In order to add matrices, they must have the same dimensions\n");
                    break;
                }
                double matrixA[m][n];
                double matrixB[l][p];
                printf("Input the numbers in the first matrix\n");
                promptNumbers(m, n, matrixA);
                printf("Input the numbers in the second matrix\n");
                promptNumbers(l, p, matrixB);
                double (*sumResult)[n]= sumOfMatrices(m, n, matrixA, matrixB);
                printf("\n");
                printMatrix(m, n, sumResult);
                printf("\n");
                free(sumResult);
                break;
            }
            case 2: {
                size_t m, n, l, p;
                printf("Input the dimensions of the first matrix\n");
                scanf("%zu %zu", &m, &n);
                FLUSH_INPUT();
                printf("Input the dimensions of the second matrix\n");
                scanf("%zu %zu", &l, &p);
                FLUSH_INPUT();
                if (n != l) {
                    printf("In order to multiply matrices, the first matrix's columns must match the second matrix's rows\n");
                    break;
                }
                double matrixA[m][n];
                double matrixB[l][p];
                printf("Input the numbers in the first matrix\n");
                promptNumbers(m, n, matrixA);
                printf("Input the numbers in the second matrix\n");
                promptNumbers(l, p, matrixB);
                double (*productResult)[p]= productOfMatrices(m, n, p, matrixA, matrixB);
                printf("\n");
                printMatrix(m, p, productResult);
                printf("\n");
                free(productResult);
                break;
            }
            case 3: {
                size_t m, n;
                printf("Input the dimensions of the matrix\n");
                scanf("%zu %zu", &m, &n);
                FLUSH_INPUT();
                double matrix[m][n];
                promptNumbers(m, n, matrix);
                double (*transposedMatrix)[m]= transposeMatrix(m, n, matrix);
                printMatrix(n, m, transposedMatrix);
                free(transposedMatrix);
                break;
            }
            case 4: {
                unsigned detChoice;
                printf("What dimensions?\n\t1. 2x2\n\t2. 3x3\n\t3. Go back\n");
                label_detChoice:
                scanf("%u", &detChoice);
                FLUSH_INPUT();
                double determinant;
                switch (detChoice) {
                    case 1: {
                        determinantOf2x2();
                        break;
                    }
                    case 2: {
                        double matrixA[3][3];
                        promptNumbers(3, 3, matrixA);
                        determinant= determinantOf3x3(&matrixA);
                        break;
                    }
                    case 3: {
                        goto label_menu;
                    }
                    default: {
                        printf("Invalid input try again\n");
                        goto label_detChoice;
                    }
                }
                printf("Determinant: %lf\n", determinant);
                break;
            }
            case 5: {
                done= true;
                break;
            }
            default: {
                printf("Invalid input try again\n");
                goto label_menu;
            }
        }
    }
    return 0;
}
//

// Function Definitions

/*
|| \Objective:
||     This function prints the values of a 2d matrix of doubles
|| \Params:
||     rows: the rows of the matrix
||     columns: the columns of the matrix
||     matrix: a 2d array of doubles
|| \Return:
||     N/A
*/
void printMatrix(size_t rows, size_t columns, double matrix[][columns]) {
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
    return;
}

/*
|| \Objective:
||     This function writes to a 2d matrix of doubles
|| \Params:
||     rows: the rows of the matrix
||     columns: the columns of the matrix
||     matrix: a 2d array of doubles
|| \Return:
||     N/A
*/
void promptNumbers(size_t rows, size_t columns, double matrix[][columns]) {
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("Input the number in the %zuth row, %zuth column\n", i+1, j+1);
            scanf("%lf", &matrix[i][j]);
            FLUSH_INPUT();
        }
    }
    return;
}

/*
|| \Objective:
||      This function takes two matrices of doubles and returns their sum. The matrices must have the same dimensions.
|| \Params: 
||      rows: the rows of the matrices
||      columns: the columns of the matrices
||      matrixA: a 2d array of doubles
||      matrixB: a 2d array of doubles
|| \Return:
||      This function returns a pointer to a dynamically allocated 2d matrix of doubles, whose dimensions are equal to that of the arguments' matrices, and contains the result of the operation. The pointer must be freed.
|| \Resources:
||      https://stackoverflow.com/questions/10794825/how-to-return-a-two-dimensional-pointer-in-c
*/
double (*sumOfMatrices(size_t rows, size_t columns, double matrixA[][columns], double matrixB[][columns]))[] {
    double (*result)[columns]= malloc(rows * sizeof *result); // result's data type is pointer to double[column]
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            result[i][j]= matrixA[i][j] + matrixB[i][j]; // the array subscripting operator '[]' automatically dereferences whatever result + i points to.
        }
    }
    return result;
}

/*
|| \Objective:
||     This function takes two matrices of doubles and returns their product. The first matrix's columns must equal the second matrix's rows.
|| \Params: 
||      m: the rows of the first matrix
||      n: the common dimension
||      p: the columns of the second matrix
||      matrixA: a 2d array of doubles
||      matrixB: a 2d array of doubles
|| \Return:
||      This function returns a pointer to a dynamically allocated 2d matrix of doubles whose rows equal the first matrix's, its columns equal the second matrix's, and contains the result of the operation. The pointer must be freed.
|| \Resources:
||      https://stackoverflow.com/questions/10794825/how-to-return-a-two-dimensional-pointer-in-c
*/
double (*productOfMatrices(size_t m, size_t n, size_t p, double matrixA[][n], double matrixB[][p]))[] {
    double (*result)[p]= malloc(m * sizeof *result);
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < p; j++)
        {
            double sum= 0;
            for (size_t k = 0; k < n; k++)
            {
                sum+= matrixA[i][k]*matrixB[k][j];
            }
            result[i][j]= sum;
        }
    }
    return result;
}

/*
|| \Objective: 
||     Compute the transposed of a matrix
|| \Params:
||     rows: the rows of the matrix
||     columns: the columns of the matrix
||     matrix: a 2d array of doubles
|| \Return:
||     This function returns a pointer to a dynamically allocated 2d matrix of doubles, whose rows equal the arguments' matrix columns, its columns equal the arguments' matrix rows, and contains the result of the operation. The pointer must be freed.
*/
double (*transposeMatrix(size_t rows, size_t columns, double matrix[][columns]))[] {
    double (*results)[rows]= malloc(columns * sizeof *results);
    for (size_t i = 0; i < columns; i++)
    {
        for (size_t j = 0; j < rows; j++)
        {
            results[i][j]= matrix[j][i];
        }
    }
    return results;
}

/*
|| \Objective:
||     This function computes the determinant of a 3x3 matrix of doubles.
|| \Params:
||     ptr_cubeMatrix: A pointer to a 3x3 matrix of doubles. (*)[3][3] is used instead of (*)[3] (i.e the decay of double[][3]) in order to enforce a 3x3 array.
|| \Return:
||     The determinant of the matrix as a double.
*/
double determinantOf3x3(double (*ptr_cubeMatrix)[3][3]) {
    double (*cubeMatrix)[3]= *ptr_cubeMatrix;
    return    cubeMatrix[0][0]*(cubeMatrix[1][1]*cubeMatrix[2][2] - cubeMatrix[1][2]*cubeMatrix[2][1])
            - cubeMatrix[0][1]*(cubeMatrix[1][0]*cubeMatrix[2][2] - cubeMatrix[1][2]*cubeMatrix[2][0])
            + cubeMatrix[0][2]*(cubeMatrix[1][0]*cubeMatrix[2][1] - cubeMatrix[1][1]*cubeMatrix[2][0])
    ;
}

/*
*/
void determinantOf2x2(void) {
    return;
}
//