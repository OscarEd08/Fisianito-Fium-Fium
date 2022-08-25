#include "Game/Score.hpp"
Score::Score()
{

	initVariables();
}

void Score::initVariables()
{
	score = 0;
	guardado = false;
	points = NULL;
}

void Score::enemyScore()
{
	score += 5;
}

void Score::resetScore()
{
	score = 0;
	guardado = false;
}

void Score::finalScore()
{

	if (guardado == false)
	{
		saveScore();
		guardado = true;
	}
}

int Score::getScore()
{
	return this->score;
}

ScoreRecordNode *Score::createNode(std::string playerName, int num)
{
	ScoreRecordNode *nuevo = new ScoreRecordNode();
	nuevo->playerName = playerName;
	nuevo->score = num;
	return nuevo;
}
void Score::insertScore(ScoreRecordNode *node)
{
	if (!points)
	{
		points = node;
		return;
	}
	ScoreRecordNode *head = points;
	while (head->next_node)
		head = head->next_node;
	head->next_node = node;
}

void Score::readScore()
{
	auto scoreTable = db.retrieveScores();
	for (const auto &row : scoreTable)
	{
		std::string playerName = row["playername"].as<std::string>();
		int score = row["score"].as<int>();
		insertScore(createNode(playerName, score));
	}
}

void Score::setPlayerName(std::string name)
{
	playerName = name;
}
void Score::saveScore()
{
	db.recordScore(playerName, score);
}

void Score::orderScoreList()
{
}
void Score::selection()
{
	ScoreRecordNode *actual;
	ScoreRecordNode *siguiente;
	int tempScore;
	std::string tempName;
	actual = points;
	int minimo;
	ScoreRecordNode *min = points;

	while (actual->next_node != NULL)
	{
		minimo = actual->score;
		min = actual;
		siguiente = actual->next_node;

		while (siguiente != NULL)
		{

			if (siguiente->score > minimo)
			{
				minimo = siguiente->score;
				min = siguiente;
			}

			siguiente = siguiente->next_node;
		}

		tempScore = actual->score;
		tempName = actual->playerName;
		actual->score = min->score;
		actual->playerName = min->playerName;
		min->score = tempScore;
		min->playerName = tempName;
		actual = actual->next_node;
	}
}

void Score::displayScoreWindow()
{
	scoreWindow.renderBackground();
}

void Score::windowLogic()
{
	// Ver puntuaciones
	scoreWindow.initVariables();
	sf::VideoMode videoMode;
	videoMode.width = 1280;
	videoMode.height = 720;
	scoreWindow.window = new sf::RenderWindow(videoMode, "Scores");
	do
	{
		while (scoreWindow.window->pollEvent(scoreWindow.scoreEV))
		{
			switch (scoreWindow.scoreEV.type)
			{
			case sf::Event::Closed:
				scoreWindow.window->close();
				break;
			case sf::Event::KeyPressed:
			{

				if (scoreWindow.scoreEV.key.code == sf::Keyboard::Escape)
				{

					scoreWindow.window->close();
					break;
				}
			}
			}
		}
		displayScoreWindow();
	} while (scoreWindow.window->isOpen());
}
