#include "GameLogic.h"
#include "Car.h"
#include <cmath>
using namespace std;

bool move_blocks(string square[][BOARD_SIZE], const char* color, Car vehicle[8], const string direction, int distance) {
    
    int index;
    for (int a = 0; a < 8; ++a) {
        if (vehicle[a].color == color) {
            index = a;
            break;
        }
    }
    // cout << "index is : " << index << endl;
    
    if (vehicle[index].horizontal == "h") {
        if (direction == "r") {
            if (vehicle[index].col1(square) + distance < BOARD_SIZE && (square[vehicle[index].row1(square)][vehicle[index].col1(square) + distance] == "🟦" || 
            square[vehicle[index].row1(square)][vehicle[index].col1(square) + distance] == vehicle[index].color) && vehicle[index].col2(square) + distance < BOARD_SIZE && (square[vehicle[index].row2(square)][vehicle[index].col2(square) + distance] == "🟦" || 
            square[vehicle[index].row2(square)][vehicle[index].col2(square) + distance] == vehicle[index].color)) {
                
                // To prevent the cars from jumping over other cars 
                if (distance == 3 || distance == 4) {
                    if (square[vehicle[index].row2(square)][vehicle[index].col2(square) + 1] != "🟦" || square[vehicle[index].row2(square)][vehicle[index].col2(square) + 2] != "🟦") {
                        
                        return false;
                    }
                }
                
                int temp_row1 = vehicle[index].row1(square);
                int temp_col1 = vehicle[index].col1(square) + distance;
                int temp_row2 = vehicle[index].row2(square);
                int temp_col2 = vehicle[index].col2(square) + distance;
                
                square[vehicle[index].row1(square)][vehicle[index].col1(square)] = "🟦";
                square[vehicle[index].row2(square)][vehicle[index].col2(square)] = "🟦";
                square[temp_row1][temp_col1] = vehicle[index].color;
                square[temp_row2][temp_col2] = vehicle[index].color;
                
                // cout << endl << "right";
                return true;
            } 
        } else if (direction == "l") {
            if (vehicle[index].col1(square) - distance >= 0 && (square[vehicle[index].row1(square)][vehicle[index].col1(square) - distance] == "🟦" || square[vehicle[index].row1(square)][vehicle[index].col1(square) - distance] == vehicle[index].color) && vehicle[index].col2(square) - distance >= 0 && (square[vehicle[index].row2(square)][vehicle[index].col2(square) - distance] == "🟦" || square[vehicle[index].row2(square)][vehicle[index].col2(square) - distance] == vehicle[index].color)) {
                
                // To prevent the cars from jumping over other cars 
                if (distance == 3 || distance == 4) {
                    if (square[vehicle[index].row1(square)][vehicle[index].col1(square) - 1] != "🟦" || square[vehicle[index].row1(square)][vehicle[index].col1(square) - 2] != "🟦") {
                        
                        return false;
                    }
                }
                
                int temp_row1 = vehicle[index].row1(square);
                int temp_col1 = vehicle[index].col1(square) - distance;
                int temp_row2 = vehicle[index].row2(square);
                int temp_col2 = vehicle[index].col2(square) - distance;
                
                square[vehicle[index].row1(square)][vehicle[index].col1(square)] = "🟦";
                square[vehicle[index].row2(square)][vehicle[index].col2(square)] = "🟦";
                square[temp_row1][temp_col1] = vehicle[index].color;
                square[temp_row2][temp_col2] = vehicle[index].color;
                
                // cout << endl << "left";
                return true;
            } 
        } else {
            return false;
        }
        
    } else if (vehicle[index].horizontal == "v") {
        if (direction == "d") {
            if (vehicle[index].row1(square) + distance < BOARD_SIZE && (square[vehicle[index].row1(square) + distance][vehicle[index].col1(square)] == "🟦" || 
            square[vehicle[index].row1(square) + distance][vehicle[index].col1(square)] == vehicle[index].color) && vehicle[index].row2(square) + distance < BOARD_SIZE && (square[vehicle[index].row2(square) + distance][vehicle[index].col2(square)] == "🟦" || 
            square[vehicle[index].row2(square) + distance][vehicle[index].col2(square)] == vehicle[index].color)) {
                
                // To prevent the cars from jumping over other cars 
                if (distance == 3 || distance == 4) {
                    if (square[vehicle[index].row2(square) + 1][vehicle[index].col2(square)] != "🟦" || square[vehicle[index].row2(square) + 2][vehicle[index].col2(square)] != "🟦") {
                        
                        return false;
                    }
                }
                
                int temp_row1 = vehicle[index].row1(square) + distance;
                int temp_col1 = vehicle[index].col1(square);
                int temp_row2 = vehicle[index].row2(square) + distance;
                int temp_col2 = vehicle[index].col2(square);
                
                square[vehicle[index].row1(square)][vehicle[index].col1(square)] = "🟦";
                square[vehicle[index].row2(square)][vehicle[index].col2(square)] = "🟦";
                square[temp_row1][temp_col1] = vehicle[index].color;
                square[temp_row2][temp_col2] = vehicle[index].color;
                
                // cout << endl << "down";
                return true;
            } 
        } else if (direction == "u") {
            if (vehicle[index].row1(square) - distance >= 0 && (square[vehicle[index].row1(square) - distance][vehicle[index].col1(square)] == "🟦" || square[vehicle[index].row1(square) - distance][vehicle[index].col1(square)] == vehicle[index].color) && vehicle[index].row2(square) - distance >= 0 && (square[vehicle[index].row2(square) - distance][vehicle[index].col2(square)] == "🟦" || square[vehicle[index].row2(square) - distance][vehicle[index].col2(square)] == vehicle[index].color)) {
                
                // To prevent the cars from jumping over other cars 
                if (distance == 3 || distance == 4) {
                    if (square[vehicle[index].row1(square) - 1][vehicle[index].col1(square)] != "🟦" || square[vehicle[index].row1(square) - 2][vehicle[index].col1(square)] != "🟦") {
                        
                        return false;
                    }
                }
                
                int temp_row1 = vehicle[index].row1(square) - distance;
                int temp_col1 = vehicle[index].col1(square);
                int temp_row2 = vehicle[index].row2(square) - distance;
                int temp_col2 = vehicle[index].col2(square);
                
                square[vehicle[index].row1(square)][vehicle[index].col1(square)] = "🟦";
                square[vehicle[index].row2(square)][vehicle[index].col2(square)] = "🟦";
                square[temp_row1][temp_col1] = vehicle[index].color;
                square[temp_row2][temp_col2] = vehicle[index].color;
                
                // cout << endl << "up";
                return true;
            } 
        } else {
            return false;
        }
    }
    return false;
}


double calculateScore(double duration, int moves) {
    double x = (duration / 40.0) * (moves / 5);
    return 0.5 / sqrt(0.5 * pow(x, 3) + 0.25) * 1000;
}

