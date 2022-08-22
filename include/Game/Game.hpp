#pragma once

#include "Player.hpp"
#include "Platform.hpp"
#include "EnemyManager.hpp"
#include "Enemy.hpp"
#include "EnemyManager.hpp"
#include "Maps.hpp"
#include "Bullets.hpp"
#include "DataStructures/EntityNode.hpp"
#include "GameTextures.hpp"
#include "GameOver.hpp"
/*Game engine class*/

class Game
{
private:
    // Variables
    // Window
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event ev;
    // View
    sf::View view;
    // Time
    float deltaTime;
    sf::Clock clock;
    //Game Over variables
    bool endGame;
    GameOver gameOver;

    // Game objects
    Player player;
    EnemyManager enemy;
    Platform ground;
    Bullets bulletList;
    Maps map;
    // Private functions
    void initVariables();
    void initWindow();
    void initEntitys();

public:
    // Constructor-Destructor
    Game();
    virtual ~Game();

    // Access
    const bool running() const;

    // Functions
    void pollEvents();
    void update(float dt);
    void render();
};