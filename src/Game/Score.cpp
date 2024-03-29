#include "Game/Score.hpp"

Score::Score(){
	initVariables();
}

void Score::initVariables(){
	score = 0;
	guardado = false;
	points=NULL;
}

void Score::enemyScore(){
    score+=5;
}

void Score::resetScore(){
	score = 0;
	guardado = false;
}

void Score::finalScore(){
    
    if(guardado==false){
        readScore();
        selection();
        saveScore();
        guardado=true;
        
    }    
}

int Score::getScore(){
	return this->score;
}

TpList Score::initNodo(int num){
    TpList nuevo = NULL;
	nuevo = new(struct nodo);
	nuevo->nro = num;
	nuevo->sgte = NULL;
	return nuevo;
}
void Score::insertScore(int num){
    TpList q = initNodo(num);
	if ( points!= NULL)
		q->sgte = points;
	points = q;
}
void Score::readScore(){    
    std::string line;
    std::ifstream text("records.txt");
    int num;
    insertScore(score);
	if (text.fail()) {
		return;
	}
	while (!text.eof()){
		std::getline(text, line);
        if(line=="")
            break;
        std::from_chars(line.c_str(),line.c_str()+line.length(),num);
        insertScore(num);
	}
	text.close();
}

void Score::saveScore(){
    std::ofstream text;
	text.open("records.txt", std::ios::out);
	while (points != NULL) {
		text << points->nro<<std::endl;
		points = points->sgte;
	}
	text.close();
}
void Score::selection(){
    	TpList actual, siguiente;   int t;
		actual = points; int minimo;
		TpList min = points;

		while (actual->sgte != NULL) {
			minimo = actual->nro;
			min = actual;
			siguiente = actual->sgte;

			while (siguiente != NULL) {

				if (siguiente->nro > minimo) {
					minimo = siguiente->nro;
					min = siguiente;
				}

				siguiente = siguiente->sgte;
			}

			t = actual->nro;
			actual->nro = min->nro;
			min->nro = t;

			actual = actual->sgte;
		}
}