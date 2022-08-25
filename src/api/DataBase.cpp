#include "api/DataBase.hpp"
#include <iostream>
DataBase::DataBase()
{
    dbURI = "host=localhost port=5432 dbname=fisianito password=german1213 user=postgres";
}

void DataBase::recordScore(std::string playerName, int score)
{
    const auto conn = tao::pq::connection::create(dbURI);
    conn->prepare("insert_score", "INSERT INTO Scores (playername, score) VALUES ($1, $2)");
    conn->execute("insert_score", playerName, score);
}

tao::pq::result DataBase::retrieveScores()
{
    ScoreRecordNode *scoresList = nullptr;
    ScoreRecordNode *head = nullptr;
    const auto conn = tao::pq::connection::create(dbURI);
    const auto scores = conn->execute("SELECT * FROM Scores");
    return scores;
}