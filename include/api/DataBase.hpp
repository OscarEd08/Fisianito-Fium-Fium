#pragma once
#include <string>
#include "DataStructures/ScoreRecordNode.hpp"
#include <tao/pq.hpp>

class DataBase
{
    std::string dbURI;

public:
    DataBase();
    void recordScore(std::string playerName, int score);
    tao::pq::result retrieveScores();
};