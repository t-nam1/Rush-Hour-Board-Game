#ifndef CAR_H
#define CAR_H

#include <string>
#include "GameLogic.h"

struct Car {
    std::string color;
    std::string horizontal;
    
    int row1(std::string square[][BOARD_SIZE]);
    int col1(std::string square[][BOARD_SIZE]);
    int row2(std::string square[][BOARD_SIZE]);
    int col2(std::string square[][BOARD_SIZE]);
};

void horizontal(std::string square[][BOARD_SIZE], Car vehicle[8]);

#endif
