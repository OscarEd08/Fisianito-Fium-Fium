#pragma once

#include<iostream>
#include <sstream>
#include <fstream>
#include<iostream>
#include<charconv>

struct nodo {
	int nro;
	struct nodo* sgte;
	
};

typedef struct nodo* TpList;

class Score
{

public:
	Score();

private:
	int score;
	int bscores[99];
	bool guardado;
	TpList points;

public:
	int getScore();
	void initVariables();
	void resetScore();
	void enemyScore();
	void finalScore();
	TpList initNodo(int num);//crear nodo
	void insertScore(int num);//insertar el puntaje en la lista
	void readScore();//lee scores anterioresS
	void saveScore();//guarda los puntajes
	void selection();//orderamiento por selección
	void showScore();
};