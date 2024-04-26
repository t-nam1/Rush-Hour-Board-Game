#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <vector>
#include <string>

struct Player {
    std::string name;
    double totalScore;
};

bool comparePlayers(const Player& a, const Player& b);
void updateLeaderboard(std::vector<Player>& leaderboard, const std::string& playerName, double score);

#endif
