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

    // Display title
    string gameOverText = R"(

██╗  ██╗██╗   ██╗███╗   ██╗ ██████╗ ██████╗ ██╗   ██╗    ██╗  ██╗ ██████╗ ██╗   ██╗██████╗
██║  ██║██║   ██║████╗  ██║██╔════╝ ██╔══██╗╚██╗ ██╔╝    ██║  ██║██╔═══██╗██║   ██║██╔══██╗
███████║██║   ██║██╔██╗ ██║██║  ███╗██████╔╝ ╚████╔╝     ███████║██║   ██║██║   ██║██████╔╝
██╔══██║██║   ██║██║╚██╗██║██║   ██║██╔══██╗  ╚██╔╝      ██╔══██║██║   ██║██║   ██║██╔══██╗
██║  ██║╚██████╔╝██║ ╚████║╚██████╔╝██║  ██║   ██║       ██║  ██║╚██████╔╝╚██████╔╝██║  ██║
╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝       ╚═╝  ╚═╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝

    )";

    for (char c : gameOverText) {
        cout << c;
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(2));
    }

    this_thread::sleep_for(chrono::milliseconds(1000));

    string gameDescription = R"(

Join James, a university student on a thrilling quest through the bustling city streets, as he tackles a series of unpredictable 
challenges. Help him navigate through packed parking lots, chaotic campuses, and more — all in a race against time to satisfy his 
growling stomach!

GAME OBJECTIVE
Guide the smiley face (James) 😀 all the way to the right of the board. Simply clear the path and input your moves like so: j r 4.

HOW TO PLAY
Move the cars based on their orientation:
- Horizontally placed cars move left (l) or right (r).

CAR SIGNIFIERS
- 😀 (j) James 
- 🟥 (r) Red
- 🟧 (o) Orange
- 🟪 (p) Purple
- 🟨 (y) Yellow
- 🟫 (b) Brown
- 🔲 (w) White
- 🟩 (g) Green

COMMANDS
Input your moves in the format: Color Direction Steps
Example: 
o r 2 moves the orange car right by 2 steps.
j r 4 moves James to victory!

EXITING THE GAME    
Press q to quit anytime.

SCORING
Earn 1000 points for each game you complete!

Get ready to drive, strategize, and enjoy an adventure filled with laughter, excitement, and delicious discoveries. 

Let the urban odyssey begin!
)";

    for (char c : gameDescription) {
        cout << c;
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(10));
    }

    cout << "\n--- Press enter to continue --- \n";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (playAgain) {
        // string name;
        
        for (int level = 1; level <= LEVELS; ++level) {
        srand(time(NULL));
        string square[BOARD_SIZE][BOARD_SIZE];
        make_map(square);
        clear_screen();
        print_map(square);
        string color;
        string direction;
        int distance;
        Car vehicle[8] = {{"😀"}, {"🟥"}, {"🟧"}, {"🟪"}, {"🟨"}, {"🟫"}, {"🔲"}, {"🟩"}};
        horizontal(square, vehicle);
        auto start = high_resolution_clock::now(); // 게임 시작 시간을 기록
        int moves = 0;
        
        while (true) {
            string command;
            cout << "Input examples: j r 4 (indicating 'James right 4 boxes') or 'q' to quit)" << endl;
            cout << "Enter move command: ";
            getline(cin, command);

            if (command.empty()) {
                cout << "\nInvalid move command.\n";
                continue;
            }

            istringstream iss(command);
            iss >> color >> direction >> distance;
        
            if (color == "q") {
                cout << endl << "Exit rush hour";
                break;
            }
            
            if (color == "j" && (direction == "r" || direction == "l"|| direction == "u" || direction == "d") && distance >= 1 && distance < 5) {
                if (move_blocks(square, "😀", vehicle, direction, distance)) {
                    cout << endl;
                    clear_screen();
                    print_map(square);
                } else {
                    cout << "\nInvalid move command.\n";
                }
                
    
            } else if (color == "r" && (direction == "r" || direction == "l"|| direction == "u" || direction == "d") && distance >= 1 && distance < 5) {
                if (move_blocks(square, "🟥", vehicle, direction, distance)) {
                    cout << endl;
                    clear_screen();
                    print_map(square);
                } else {
                    cout << "\nInvalid move command.\n";
                }
                
            } else if (color == "o" && (direction == "r" || direction == "l"|| direction == "u" || direction == "d") && distance >= 1 && distance < 5) {
                
                if (move_blocks(square, "🟧", vehicle, direction, distance)) {
                    cout << endl;
                    clear_screen();
                    print_map(square);
                } else {
                    cout << "\nInvalid move command.\n";
                }
                
            } else if (color == "p" && (direction == "r" || direction == "l"|| direction == "u" || direction == "d") && distance >= 1 && distance < 5) {
                
                if (move_blocks(square, "🟪", vehicle, direction, distance)) {
                    cout << endl;
                    clear_screen();
                    print_map(square);
                } else {
                    cout << "\nInvalid move command.\n";
                }
                
            } else if (color == "y" && (direction == "r" || direction == "l"|| direction == "u" || direction == "d") && distance >= 1 && distance < 5) {
                
                if (move_blocks(square, "🟨", vehicle, direction, distance)) {
                    cout << endl;
                    clear_screen();
                    print_map(square);
                } else {
                    cout << "\nInvalid move command.\n";
                }
                
            } else if (color == "b" && (direction == "r" || direction == "l"|| direction == "u" || direction == "d") && distance >= 1 && distance < 5) {
                
                if (move_blocks(square, "🟫", vehicle, direction, distance)) {
                    cout << endl;
                    clear_screen();
                    print_map(square);
                } else {
                    cout << "\nInvalid move command.\n";
                }
                
            } else if (color == "w" && (direction == "r" || direction == "l"|| direction == "u" || direction == "d") && distance >= 1 && distance < 5) {
                
                if (move_blocks(square, "🔲", vehicle, direction, distance)) {
                    cout << endl;
                    clear_screen();
                    print_map(square);
                } else {
                    cout << "\nInvalid move command.\n";
                }
                
            } else if (color == "g" && (direction == "r" || direction == "l"|| direction == "u" || direction == "d") && distance >= 1 && distance < 5) {
                
                if (move_blocks(square, "🟩", vehicle, direction, distance)) {
                    cout << endl;
                    clear_screen();
                    print_map(square);
                } else {
                    cout << "\nInvalid move command.\n";
                }
                
            } else {
                cout << "\nInvalid move command.\n";
            }
            moves++;

            if (square[2][4] == "😀" && square[2][5] == "😀") {
                auto end = high_resolution_clock::now(); // 게임 종료 시간을 기록
                auto duration = duration_cast<seconds>(end - start);
                cout << endl << "YOU WIN!!\n" << endl;
                cout << "Time taken: " << duration.count() << " seconds." << endl; // 경과 시간 출력
                cout << "level: " << level << endl;
            double duration_count = duration.count();
            double score = calculateScore(duration_count, moves);
    cout << "Score: " << round(score) << endl;
            totalScore += score;
            char placeholder;
            cout << "\n--- Press enter to continue ---\n";
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
    
    while (true) {
    cout << "Options: \n1. Play Again\n2. Show Leaderboards\n3. Quit\nEnter option (number only): \n";
    cin >> answer;
        if (answer == "1") {
            cout << "\nGame will restart with a reset score.\n";
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
            cout << "\nThanks for playing!" << endl;
            // Display leaderboard
            cout << "Leaderboard:" << endl;
            // Sort leaderboard by total score
            sort(leaderboard.begin(), leaderboard.end(), [](const Player& a, const Player& b) {
                return a.totalScore > b.totalScore; // Sort descending
            });
            for (const auto& player : leaderboard) {
                cout << player.name << ": " << player.totalScore << endl;
                }

            // Display game over
            string gameOverText = R"(
                             _______  _______  _______  _______    _______           _______  _______
                            (  ____ \(  ___  )(       )(  ____ \  (  ___  )|\     /|(  ____ \(  ____ )
                            | (    \/| (   ) || () () || (    \/  | (   ) || )   ( || (    \/| (    )|
                            | |      | (___) || || || || (__      | |   | || |   | || (__    | (____)|
                            | | ____ |  ___  || |(_)| ||  __)     | |   | |( (   ) )|  __)   |     __)
                            | | \_  )| (   ) || |   | || (        | |   | | \ \_/ / | (      | (\ (
                            | (___) || )   ( || )   ( || (____/\  | (___) |  \   /  | (____/\| ) \ \__
                            (_______)|/     \||/     \|(_______/  (_______)   \_/   (_______/|/   \__/
                            )";

            for (char c : gameOverText) {
                cout << c;
                cout.flush();
                this_thread::sleep_for(chrono::milliseconds(20));
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
