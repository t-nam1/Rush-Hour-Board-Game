#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <string>
#include <tuple>
#include <cmath>
#include <string>

const int BOARD_SIZE = 6;

struct Car; // Forward declaration

bool move_blocks(std::string square[][BOARD_SIZE], const char* color, Car vehicle[8], const std::string direction, int distance);
double calculateScore(double duration, int moves);


#endif



