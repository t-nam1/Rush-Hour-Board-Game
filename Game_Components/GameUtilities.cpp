#include "GameUtilities.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void clear_screen() {
    cout << "\033[H\033[2J";
}

void print_map(const string square[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << square[i][j];
        }
        cout << endl;
    }
}

// Function to add a car to the square
void addCar(string square[][BOARD_SIZE], int aboveRow, int aboveCol, int belowRow, int belowCol, int color_counter){
    string colors[] = {"🟥", "🟪", "🟨", "🟫", "🔲", "🟩"};
    string vehicle = colors[color_counter];
    square[aboveRow][aboveCol] = vehicle;
    square[belowRow][belowCol] = vehicle;
}

// Function to store car positions in an array
int* storeCarPositions(int rowA, int colA, int rowB, int colB) {
    int* positions = new int[4];
    positions[0] = rowA;
    positions[1] = colA;
    positions[2] = rowB;
    positions[3] = colB;
    return positions;
}

tuple<int, int, int, int> available_pos(string square[][BOARD_SIZE], int rowA, int colA, int rowB, int colB, bool isFlipped) {
    vector<std::tuple<int, int, int, int>> pairs;

    

    for (int c = 0; c < BOARD_SIZE; ++c) {
        // Ensure that rowA - 1 is valid before accessing it
        if (rowA == 0) {
        ; // do nothing
        }
        else {
            if ((!isFlipped && square[rowA][c] == "🟦" && square[rowA - 1][c] == "🟦") ||
                (isFlipped && c != colA && c != colB && c != 2 && square[rowA][c] == "🟦" && square[rowA - 1][c] == "🟦")) {
                pairs.emplace_back(rowA, c, rowA - 1, c);
            }
        }

        // Ensure that rowB + 1 is valid before accessing it
        if (rowB >= BOARD_SIZE - 1) {
            continue;
        } 
        else {        
            if ((!isFlipped && square[rowB][c] == "🟦" && square[rowB + 1][c] == "🟦") ||
                (isFlipped && c != colA && c != colB && c != 2 && square[rowB][c] == "🟦" && square[rowB + 1][c] == "🟦")) {
                pairs.emplace_back(rowB, c, rowB + 1, c);
            }
        }
    }


    if (pairs.empty()) {
        if (isFlipped)  { flipBoard(square); }
        return make_tuple(-1, -1, -1, -1); // No available positions found
    }

    // Randomly select a set of available positions
    int randomIndex = rand() % pairs.size();
    return pairs[randomIndex];
}

void flipBoard(string square[][BOARD_SIZE]) {
    string temp[BOARD_SIZE][BOARD_SIZE];

    // Copy the contents of the original square array to a temporary array
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            temp[i][j] = square[i][j];
        }
    }

    // Flip the rows and columns in the temporary array
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            square[j][i] = temp[i][j];
        }
    }
}

void make_map(string square[][BOARD_SIZE]) {
    bool isFlipped = false;
    int color_counter = 0;
    // Fill the array with white spaces
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            square[i][j] = "🟦";
        }
    }

    // Set specific positions to red color
    square[2][0] = "😀"; // Smiley face emoji
    square[2][1] = "😀"; 

    // Ensure that at least 2 cars are blocking the red car
    square[2][2] = "🟧";
    square[3][2] = "🟧";
    //square[4][2] = "🟧";

    // Generate the first car
    int* carPositions = storeCarPositions(2, 0, 2, 1);



    // Generate subsequent cars
    int NUM_CARS = 6;
    for (int i = 0; i < NUM_CARS; ++i) {
        // flipBoard(square); // Flip the board before generating the next car
        int rowA = carPositions[0];
        int colA = carPositions[1];
        int rowB = carPositions[2];
        int colB = carPositions[3];

        auto positions = available_pos(square, rowA, colA, rowB, colB, isFlipped);
        int aboveRow = std::get<0>(positions);
        int aboveCol = std::get<1>(positions);
        int belowRow = std::get<2>(positions);
        int belowCol = std::get<3>(positions);

        if (aboveRow == -1 && aboveCol == -1 && belowRow == -1 && belowCol == -1) {
            break; // Exit the loop
        }
        addCar(square, aboveRow, aboveCol, belowRow, belowCol, color_counter);
        delete[] carPositions; // Free the memory of the previous car positions
        
        carPositions = storeCarPositions(aboveCol, aboveRow, belowCol, belowRow); //Must also flip coords
        flipBoard(square);
        isFlipped = !isFlipped;
        ++color_counter;
    }

    delete[] carPositions;
}