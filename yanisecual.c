#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void promptNumbers(size_t rows, size_t columns, double array2d[][columns]) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            printf("Input number in %zuth row %zuth column\n", i+1, j+1);
            scanf("%lf", &array2d[i][j]);
        }
    }
    return;
}
int numberRoutine(void) {
    double a, b;
    unsigned int choice;
    printf("What do you want to do?\n\t1. Addition\n\t2. Product\n\t3. Division\n\t4. Go back\n");
    scanf("%u", &choice);
    switch (choice) {
        case 1: { // sum
            printf("Input two numbers (e.g 4 5)\n");
            scanf("%lf %lf", &a, &b);
            printf("\nResult: %lf\n\n", a+b);
            return 0;
        }
        case 2: { // multiply
            printf("Input two numbers (e.g 4 5)\n");
            scanf("%lf %lf", &a, &b);
            printf("\nResult: %lf\n\n", a*b);
            return 0;
        }
        case 3: { // divide
            printf("Input two numbers (e.g 4 5)\n");
            scanf("%lf %lf", &a, &b);
            b == 0 ? printf("Cannot divide by zero\n") : printf("\nResult: %lf\n\n", a/b);
            return 0;
        }
        case 4: { // go back
            return 1;
        }
        default: { // err
            printf("Invalid input\n");
            return 0;
        }
    }
    return 0;
}
int vectorRoutine(void) {
    unsigned int choice;
    printf("What do you want to do?\n\t1. Subtract\n\t2. Check primes\n\t3. Check parity\n\t4. Go back\n");
    scanf("%u", &choice);
    switch (choice) {
        case 1: { //subtract
            size_t len;
            printf("Input the length of the vectors (e.g 5). They will be of equal length\n");
            scanf("%zu", &len);
            double vectorA[len], vectorB[len];
            //input a
            for (size_t i = 0; i < len; i++) {
                printf("Input the %zuth number of the first vector\n", i+1);
                scanf("%lf", &vectorA[i]);
            }
            //input b
            for (size_t i = 0; i < len; i++) {
                printf("Input the %zuth number of the second vector\n", i+1);
                scanf("%lf", &vectorB[i]);
            }
            for (size_t i = 0; i < len; i++) {
                printf("%zuth Result: %lf\n", i+1, vectorA[i] - vectorB[i]); 
            }
            return 0;
        }
        case 2: { //check primes
            size_t len;
            printf("Input the length of the vector (e.g 5)\n");
            scanf("%zu", &len);
            long long unsigned int vector[len];
            //input
            for (size_t i = 0; i < len; i++) {
                printf("Input the %zuth number of the vector. The number must be a positive integer (i.e, not zero)\n", i+1);
                scanf("%llu", &vector[i]);
            }
            //check prime
            for (size_t i = 0; i < len; i++) {
                bool isPrime= true;
                for (long long unsigned int j = vector[i]-1; j > 1; j--) {
                    if (vector[i] % j == 0) {
                        isPrime= false;
                        break;
                    }
                }
                printf(isPrime ? "%llu is a prime\n" : "%llu is not a prime\n", vector[i]);
            }
            return 0;
        }
        case 3: { //check parity
            size_t len;
            printf("Input the length of the vector (e.g 5)\n");
            scanf("%zu", &len);
            long long int vector[len];
            //input
            for (size_t i = 0; i < len; i++) {
                printf("Input the %zuth number of the vector. The number must be an integer\n", i+1);
                scanf("%lld", &vector[i]);
            }
            for (size_t i = 0; i < len; i++) {
                printf("%lld is %s\n", vector[i], vector[i] % 2 == 0 ? "even" : "odd");
            }
            return 0;
        }
        case 4: { //go back
            return 1;
        }
        default: { //err
            printf("Invalid input\n");
            return 0;
        }
    }
    return 0;
}
int matrixRoutine(void) {
    unsigned int choice;
    printf("What do you want to do?\n\t1. Addition\n\t2. Product\n\t3. Go back\n");
    scanf("%u", &choice);
    switch (choice) {
        case 1: { //addition
            size_t m, n;
            printf("Input the dimensions of the matrices (rows columns). Their dimensions will be the same\n");
            scanf("%zu %zu", &m, &n);
            double matrixA[m][n];
            double matrixB[m][n];
            printf("\nInput numbers of the first matrix\n");
            promptNumbers(m, n, matrixA);
            printf("\nInput numbers of the second matrix\n");
            promptNumbers(m, n, matrixB);
            //output
            printf("Result:\n");
            for (size_t i = 0; i < m; i++) {
                for (size_t j = 0; j < n; j++) {
                    printf("%lf ", matrixA[i][j] + matrixB[i][j]);
                }
                printf("\n");
            }
            return 0;
        }
        case 2: { //multiplication
            size_t m, n, l, p;
            printf("Input the dimensions of the first matrix (rows columns)\n");
            scanf("%zu %zu", &m, &n);
            printf("Input the dimensions of the second matrix (rows columns)\n");
            scanf("%zu %zu", &l, &p);
            if (n!=l) {
                printf("The first matrix's columns must equal the second matrix's rows\n");
                return 0;
            }
            double matrixA[m][n];
            double matrixB[n][p];
            printf("\nInput numbers of the first matrix\n");
            promptNumbers(m, n, matrixA);
            printf("\nInput numbers of the second matrix\n");
            promptNumbers(m, n, matrixB);
            printf("Result:\n");
            for (size_t i = 0; i < m; i++) {
                for (size_t j = 0; j < p; j++) {
                    double sum= 0;
                    for (size_t k = 0; k < n; k++) {
                        sum += matrixA[i][k]*matrixB[k][j];
                    }
                    printf("%lf ", sum);
                }
                printf("\n");
            }
            return 0;
        }
        case 3: { //go back
            return 1;
        }
        default: {
            printf("Invalid input\n");
            return 0;
        }
    }
    return 0;
}
int main(int argc, char *argv[]) {
    bool done= false;
    while (!done) {
        system("cls");
        unsigned int choice;
        printf("Do you want to work with?\n\t1. Numbers\n\t2. Vectors\n\t3. Matrices\n\t4. Exit\n");
        scanf("%u", &choice);
        switch (choice) {
            case 1: {
                bool numberRoutineDone= false;
                while (!numberRoutineDone) {
                    numberRoutineDone= numberRoutine();
                }
                break;
            }
            case 2: {
                bool vectorRoutineDone= false;
                while (!vectorRoutineDone) {
                    vectorRoutineDone= vectorRoutine();
                }
                break;
            }
            case 3: {
                bool matrixRoutineDone= false;
                while (!matrixRoutineDone) {
                    matrixRoutineDone= matrixRoutine();
                }
                break;
            }
            case 4: {
                done= true;
                break;
            }
            default: {
                printf("Invalid input\n");
                break;
            }
        }
    }
    system("cls");
    return 0;
}