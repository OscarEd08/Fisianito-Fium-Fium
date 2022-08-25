#include <string>
struct ScoreRecord
{
    int score;
    std::string playerName;
    ScoreRecord(std::string playerName, int score)
    {
        this->playerName = playerName;
        this->score = score;
    }
}