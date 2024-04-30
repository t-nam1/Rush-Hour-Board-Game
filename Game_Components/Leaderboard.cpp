#include "Leaderboard.h"
#include <algorithm>
using namespace std;

bool comparePlayers(const Player& a, const Player& b) {
    return a.totalScore > b.totalScore;
}

void updateLeaderboard(vector<Player>& leaderboard, const string& playerName, double score) {
    bool found = false;
    for (auto& player : leaderboard) {
        if (player.name == playerName) {
            found = true;
            if (player.totalScore < score) {
                player.totalScore = score;
            }
            break;
        }
    }
    if (!found) {
        Player newPlayer;
        newPlayer.name = playerName;
        newPlayer.totalScore = score;
        leaderboard.push_back(newPlayer);
    }
}
