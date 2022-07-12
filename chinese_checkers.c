#define UP 0
#define DOWN 1
#define UP_LEFT 2
#define UP_RIGHT 3
#define DOWN_LEFT 4
#define DOWN_RIGHT 5
#include <stdio.h>
#include <stdlib.h>
void propagate(int (*ptr_board)[14][14], size_t x, size_t y, int direction, int length, void (*callback)(int *, void *), void *callbackArg) {
    int (*board)[14]= *ptr_board;
    switch (direction) {
        case UP_LEFT: {
            for (size_t i= 0; i < length ; i++) {
                for (size_t j= 0; j < length-i; j++) {
                    callback(&board[x-i][y-j], callbackArg);
                }
            }
            break;
        }
        case UP_RIGHT: {
            for (size_t i= 0; i < length ; i++) {
                for (size_t j= 0; j < length-i; j++) {
                    callback(&board[x-i][y+j], callbackArg);
                }
            }
            break;
        }
        case DOWN_LEFT: {
            for (size_t i= 0; i < length ; i++) {
                for (size_t j= 0; j < length-i; j++) {
                    callback(&board[x+i][y-j], callbackArg);
                }
            }
            break;
        }
        case DOWN_RIGHT: {
            for (size_t i= 0; i < length ; i++) {
                for (size_t j= 0; j < length-i; j++) {
                    callback(&board[x+i][y+j], callbackArg);
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

int main(int argc, char const *argv[]) {
    int board[14][14]= {0};

    return 0;
}