#include "Car.h"
using namespace std;

int Car::row1(string square[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (square[i][j] == color) {
                return i;
            }
        }
    }
    return -1;
}

int Car::col1(string square[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (square[i][j] == color) {
                return j;
            }
        }
    }
    return -1;
}

int Car::row2(string square[][BOARD_SIZE]) {
    for (int i = BOARD_SIZE - 1; i >= 0; --i) {
        for (int j = BOARD_SIZE - 1; j >= 0; --j) {
            if (square[i][j] == color) {
                return i;
            }
        }
    }
    return -1;
}

int Car::col2(string square[][BOARD_SIZE]) {
    for (int i = BOARD_SIZE - 1; i >= 0; --i) {
        for (int j = BOARD_SIZE - 1; j >= 0; --j) {
            if (square[i][j] == color) {
                return j;
            }
        }
    }
    return -1;
}

void horizontal(string square[][BOARD_SIZE], Car vehicle[8]) {
    for (int i = 0; i < 8; ++i) {
        if (vehicle[i].row1(square) == vehicle[i].row2(square)) {
            vehicle[i].horizontal = "h";
        } else {
            vehicle[i].horizontal = "v";
        }
    }
}
