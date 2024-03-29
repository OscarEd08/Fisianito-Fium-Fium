#include "Game/Game.hpp"
#include <iostream>
// Constructor-Destructor
Game::Game() 
{
    initVariables();
    initEntitys();
    initWindow();
}

Game::~Game()
{
    delete this->window;
}

// Private Functions
void Game::initVariables()
{
    this->window = nullptr;
    videoMode.width = 1280;
    videoMode.height = 720;
    deltaTime = 0.0f;
    endGame = false;
}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(this->videoMode, "GAME TESTING", sf::Style::Titlebar | sf::Style::Close);
    this->window->setKeyRepeatEnabled(true);
    this->window->setFramerateLimit(60);
}

void Game::initEntitys()
{

    player.initShape();
    map.initPlatforms();
    map.initObjects();
    map.initBackground();
    map.initHearts();
    map.initLifeBar();
    map.initTextScore();
    gameOver.initVariables();
}

// Access
bool Game::running()
{
    return this->window->isOpen();
}

// Functions
void Game::pollEvents()
{
    deltaTime = clock.restart().asSeconds();
    while (window->pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            window->close();
            break;

        case sf::Event::KeyPressed:
            if (ev.key.code == sf::Keyboard::Escape)
                window->close();
            break;

        case sf::Event::KeyReleased:
        {   
            gameOver.KeyboardReleased(ev,this->window);
            if (ev.key.code == sf::Keyboard::F)
                bulletList.shotBullet(player);
            else
                player.movementDirection = Directions::Static;
            player.isJumping = false;
            break;
        }
        }
    }
}

void Game::update(float dt)
{   
    pollEvents();
    //Update player
    if (player.isAlive)
    {
        //Collision with platforms
        player.update(map.platforms, dt);
        //Collision with traps
        player.checkCollisionWithObjects(map.objects);
        //Collision with enemies
        enemy.checkCollisionWithPlayer(player);
        player.changeColorWhenCollideWithEnemy();
        player.checkCollisionWithHearts(map.hearts,&score);
        //Enemy & Bullets update
        bulletList.updateBullets();
        enemy.initEnemies();
        enemy.updateManager(bulletList.bulletsList);
        enemy.removeDeadEnemies(&score);
        map.updateLifeBar(player);
        map.updateTextScore(score);
    }
    //Playes is not alived
    else{
        //Lose
        if(!gameOver.isRetryButtonPressed){
            gameOver.updateScore(score);
            score.finalScore();
            endGame = true;
        }
        //Retry
        else{
            endGame = false;
            player.resetPlayer();
            score.resetScore();
            enemy.resetEnemies();
            map.resetHears();
            gameOver.isRetryButtonPressed = false;
        }
    
    }
}

void Game::render()
{
    window->clear();
    if(!endGame){
        //   Draw game objects
        map.renderBackground(this->window);
        map.renderPlatforms(this->window);
        map.renderObjects(this->window);
        map.renderHearts(this->window);
        map.renderLifeBar(this->window);
        map.renderTextScore(this->window);
        if (player.isAlive)
        {
            player.renderOnGame(this->window);
            bulletList.renderBullets(this->window);
        }
        enemy.renderEnemies(this->window);
    }
    // Draw GameOver Screen
    else{
        gameOver.renderBackground(this->window);
    }

    window->display();
}
