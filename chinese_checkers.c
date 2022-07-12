#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define UP_LEFT 4
#define UP_RIGHT 5
#define DOWN_LEFT 6
#define DOWN_RIGHT 7
#include <stdio.h>
#include <stdlib.h>
void propagate(int (*ptr_board)[19][15], size_t x, size_t y, int direction, int length, void (*callback)(int *, void *), void *callbackArg) {
    int (*board)[15]= *ptr_board;
    switch (direction) {
        case UP: {
            for (size_t i= 0; i < length; i++) {
                for (size_t j= 0; j <= i; j++) {
                    (*callback)(&board[x-i][y+j], callbackArg);
                }
            }
            break;
        }
        case DOWN: {
            for (size_t i= 0; i < length; i++) {
                for (size_t j= 0; j <= i; j++) {
                    (*callback)(&board[x+i][y-j], callbackArg);
                }
            }
            break;
        }
        case LEFT: {
            for (size_t i= 0; i < length; i++) {
                for (size_t j= 0; j <= length-i; j++) {
                    (*callback)(&board[x-j+i][y-i], callbackArg);
                }
            }
            break;
        }
        case RIGHT: {
            for (size_t i= 0; i < length; i++) {
                for (size_t j= 0; j < length-i; j++) {
                    (*callback)(&board[x+j-i][y+i], callbackArg);
                }
            }
            break;
        }
        case UP_LEFT: {
            for (size_t i= 0; i < length ; i++) {
                for (size_t j= 0; j < length-i; j++) {
                    (*callback)(&board[x-i][y-j], callbackArg);
                }
            }
            break;
        }
        case UP_RIGHT: {
            for (size_t i= 0; i < length ; i++) {
                for (size_t j= 0; j < length-i; j++) {
                    (*callback)(&board[x-i][y+j], callbackArg);
                }
            }
            break;
        }
        case DOWN_LEFT: {
            for (size_t i= 0; i < length ; i++) {
                for (size_t j= 0; j < length-i; j++) {
                    (*callback)(&board[x+i][y-j], callbackArg);
                }
            }
            break;
        }
        case DOWN_RIGHT: {
            for (size_t i= 0; i < length ; i++) {
                for (size_t j= 0; j < length-i; j++) {
                    (*callback)(&board[x+i][y+j], callbackArg);
                }
            }
            break;
        }
        default: {
            break;
        }
    }
    return;
}
void printBoard(int (*ptr_board)[19][15]) {
    for (size_t i= 0; i < 19; i++) {
        for (size_t j= 0; j < 15; j++) {
            printf("%2d ", (*ptr_board)[i][j]);
        }
        printf("\n");
    }
    return;
}
void setNumber(int *ptr_boardNumber, void *ptr_number) {
    *ptr_boardNumber= *((int *)ptr_number);
    return;
}
int main(int argc, char const *argv[]) {
    int board[19][15]= {0};
    int red= 1, white= 2, yellow= 3, green= 4, black= 5, blue=6;//bruh
    propagate(&board, 1, 9, DOWN, 4, &setNumber, &red);//
    propagate(&board, 8, 10, UP, 4, &setNumber, &white);//
    propagate(&board, 9, 10, DOWN, 4, &setNumber, &yellow);//
    propagate(&board, 16, 3, UP, 4, &setNumber, &green);//?
    propagate(&board, 9, 2, DOWN, 4, &setNumber, &black);
    propagate(&board, 8, 2, UP, 4, &setNumber, &blue);
    printBoard(&board);
    return 0;
}