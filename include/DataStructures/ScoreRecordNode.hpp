#pragma once
#include <string>
class ScoreRecordNode
{
public:
    int score;
    std::string playerName;
    ScoreRecordNode *next_node = nullptr;
};
