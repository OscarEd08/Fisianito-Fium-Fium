#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <charconv>
#include "ScoreWindow.hpp"
#include "api/DataBase.hpp"
#include "DataStructures/ScoreRecordNode.hpp"
/*
struct nodo {
	int nro;
	struct nodo* sgte;

};
*/
// typedef struct nodo* TpList;

class Score
{

public:
	Score();

private:
	int score;
	std::string playerName;
	bool guardado;
	DataBase db;

	// TpList points;

public:
	ScoreRecordNode *points;
	ScoreWindow scoreWindow;
	int getScore();
	void setPlayerName(std::string name);
	void initVariables();
	void resetScore();
	void enemyScore();
	void finalScore();
	void orderScoreList();
	ScoreRecordNode *createNode(std::string playerName, int num); // crear nodo
	void insertScore(ScoreRecordNode *node);					  // insertar el puntaje en la lista
	void readScore();											  // lee scores anterioresS
	void saveScore();											  // guarda los puntajes
	void selection();											  // orderamiento por selección
	void windowLogic();
	void displayScoreWindow();
};