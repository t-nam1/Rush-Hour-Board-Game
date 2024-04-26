#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <chrono>
#include <thread>
#include <algorithm>
#include "Car.h"
#include "GameLogic.h"
#include "GameUtilities.h"
#include "Leaderboard.h"

using namespace std;
using namespace std::chrono;

const int LEVELS = 10;

int main() {
    bool playAgain = true;
    int totalScore = 0;
    vector<Player> leaderboard;
    clear_screen();
    cout << "we'll add a nice title here ~" << endl;

    // Pause for 3 seconds 
    this_thread::sleep_for(chrono::milliseconds(3000));
    clear_screen();

    while (playAgain) {
        // string name;
        
        for (int level = 1; level <= LEVELS; ++level) {
        srand(time(NULL));
        string square[BOARD_SIZE][BOARD_SIZE];
        make_map(square);
        print_map(square);
        string color;
        string direction;
        int distance;
        Car vehicle[8] = {{"🟥"}, {"🔶"}, {"🟧"}, {"🟪"}, {"🟨"}, {"🟫"}, {"❎"}, {"🟩"}};
        horizontal(square, vehicle);
        auto start = high_resolution_clock::now(); // 게임 시작 시간을 기록
        int moves = 0;
        
        while (true) {
            string command;
            cout << "Enter move command (e.g., red r 2, or 'exit' to quit): ";
            getline(cin, command);
        
            istringstream iss(command);
            iss >> color >> direction >> distance;
        
            if (color == "exit") {
                cout << endl << "Exit rush hour";
                break;
            }
            
            if (color == "red" && (direction == "r" || direction == "l"|| direction == "u" || direction == "d") && distance >= 1 && distance < 5) {
                if (move_blocks(square, "🟥", vehicle, direction, distance)) {
                    cout << endl;
                    // Print the updated map
                    print_map(square);
                } else {
                    cout << "Invalid move command." << endl;
                }
                
    
            } else if (color == "diamond" && (direction == "r" || direction == "l"|| direction == "u" || direction == "d") && distance >= 1 && distance < 5) {
                if (move_blocks(square, "🔶", vehicle, direction, distance)) {
                    cout << endl;
                    // Print the updated map
                    print_map(square);
                } else {
                    cout << "Invalid move command." << endl;
                }
                
            } else if (color == "orange" && (direction == "r" || direction == "l"|| direction == "u" || direction == "d") && distance >= 1 && distance < 5) {
                
                if (move_blocks(square, "🟧", vehicle, direction, distance)) {
                    cout << endl;
                    // Print the updated map
                    print_map(square);
                } else {
                    cout << "Invalid move command." << endl;
                }
                
            } else if (color == "purple" && (direction == "r" || direction == "l"|| direction == "u" || direction == "d") && distance >= 1 && distance < 5) {
                
                if (move_blocks(square, "🟪", vehicle, direction, distance)) {
                    cout << endl;
                    // Print the updated map
                    print_map(square);
                } else {
                    cout << "Invalid move command." << endl;
                }
                
            } else if (color == "yellow" && (direction == "r" || direction == "l"|| direction == "u" || direction == "d") && distance >= 1 && distance < 5) {
                
                if (move_blocks(square, "🟨", vehicle, direction, distance)) {
                    cout << endl;
                    // Print the updated map
                    print_map(square);
                } else {
                    cout << "Invalid move command." << endl;
                }
                
            } else if (color == "brown" && (direction == "r" || direction == "l"|| direction == "u" || direction == "d") && distance >= 1 && distance < 5) {
                
                if (move_blocks(square, "🟫", vehicle, direction, distance)) {
                    cout << endl;
                    // Print the updated map
                    print_map(square);
                } else {
                    cout << "Invalid move command." << endl;
                }
                
            } else if (color == "x" && (direction == "r" || direction == "l"|| direction == "u" || direction == "d") && distance >= 1 && distance < 5) {
                
                if (move_blocks(square, "❎", vehicle, direction, distance)) {
                    cout << endl;
                    // Print the updated map
                    print_map(square);
                } else {
                    cout << "Invalid move command." << endl;
                }
                
            } else if (color == "green" && (direction == "r" || direction == "l"|| direction == "u" || direction == "d") && distance >= 1 && distance < 5) {
                
                if (move_blocks(square, "🟩", vehicle, direction, distance)) {
                    cout << endl;
                    // Print the updated map
                    print_map(square);
                } else {
                    cout << "Invalid move command. Problem" << endl;
                }
                
            } else {
                cout << "Invalid move command." << endl;
            }
            moves++;

            if (square[2][4] == "🟥" && square[2][5] == "🟥") {
                auto end = high_resolution_clock::now(); // 게임 종료 시간을 기록
                auto duration = duration_cast<seconds>(end - start);
                cout << endl << "YOU WIN!!" << endl;
                cout << "Time taken: " << duration.count() << " seconds." << endl; // 경과 시간 출력
                cout << "level: " << level << endl;
            double duration_count = duration.count();
            double score = calculateScore(duration_count, moves);
    cout << "Score: " << round(score) << endl;
            totalScore += score;
            char placeholder;
            cout << "--- Press enter to continue --- ";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
                
            }
        }
            
    
}

        string playerName;
        cout << "Enter your name: ";
        getline(cin, playerName);
    
        // Check if player already exists in the leaderboard
        bool found = false;
        for (auto& player : leaderboard) {
            if (player.name == playerName) {
                found = true;
                // Update the score if the current score is higher
                if (player.totalScore < totalScore) {
                    player.totalScore = totalScore;
                }
                break;
            }
        }

    // If player does not exist, add them to the leaderboard
    if (!found) {
        Player currentPlayer;
        currentPlayer.name = playerName;
        currentPlayer.totalScore = totalScore;
        leaderboard.push_back(currentPlayer);
        }
    // }

    string answer;
    
    while (true) {;
    cout << "Options: \n1. Play Again\n2. Show Leaderboards\n3. Quit\nEnter option (number only):  ";
    getline(cin, answer);
        if (answer == "1") {
            cout << "Game will restart with a reset score.\n";
            totalScore = 0;
            break; 
        } 
        
        else if (answer == "2") {
            // Display leaderboard
            cout << "\nLeaderboard:" << endl;
            // Sort leaderboard by total score
            sort(leaderboard.begin(), leaderboard.end(), [](const Player& a, const Player& b) {
                return a.totalScore > b.totalScore; // Sort descending
            });
            for (const auto& player : leaderboard) {
                cout << player.name << ": " << player.totalScore << endl;
            }
            cout << endl;
            continue;
        } 
        
        else if (answer == "3") {
            cout << "Thanks for playing!" << endl;
            // Display leaderboard
            cout << "Leaderboard:" << endl;
            // Sort leaderboard by total score
            sort(leaderboard.begin(), leaderboard.end(), [](const Player& a, const Player& b) {
                return a.totalScore > b.totalScore; // Sort descending
            });
            for (const auto& player : leaderboard) {
                cout << player.name << ": " << player.totalScore << endl;
                }
            playAgain = false; // Set to false to exit the loop and end the program.
            break;
            } 
        
        else {
            cout << "Invalid input, please try again.\n\n";
            break;
            }
        }
        if (playAgain == false) {
            break;
        }
    }
   return 0;
}
