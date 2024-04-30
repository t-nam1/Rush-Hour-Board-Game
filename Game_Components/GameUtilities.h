#ifndef GAMEUTILITIES_H
#define GAMEUTILITIES_H

#include <string>
#include <vector>
#include <string>
#include <vector>
#include <tuple>
#include "GameLogic.h"
using namespace std;


void clear_screen();
void print_map(const std::string square[][BOARD_SIZE]);
void make_map(std::string square[][BOARD_SIZE]);
tuple<int, int, int, int> available_pos(string square[][BOARD_SIZE], int rowA, int colA, int rowB, int colB, bool isFlipped);
void flipBoard(string square[][BOARD_SIZE]);
int* storeCarPositions(int rowA, int colA, int rowB, int colB);
void addCar(string square[][BOARD_SIZE], int aboveRow, int aboveCol, int belowRow, int belowCol, int color_counter);


#endif
