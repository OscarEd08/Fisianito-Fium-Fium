#include "Game/Game.hpp"
#include <iostream>
// Constructor-Destructor
Game::Game() : view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1600.0f, 800.0f))
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
    this->ground.initAttributes(0, 670, 1280.0f, 100.0f);
    this->ground.initShape();
}

// Access
const bool Game::running() const
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
    // initBullets();
    if (player.isAlive)
    {
        player.update(map.platforms, dt);
        player.checkCollisionWithObjects(map.objects);
        player.checkCollisionWithEnemies(enemy);
    }
    pollEvents();
    // enemy.checkImpactWithBullets(bulletList.bulletsList);
    //  enemy.checkCollisionWithPlatforms(map.platforms);
    bulletList.updateBullets();
    // enemy.update();
    enemy.initEnemies();
    enemy.updateManager(bulletList.bulletsList);
    enemy.removeDeadEnemies();
}

void Game::render()
{
    window->clear();
    if (player.isAlive)
    {
        player.renderOnGame(this->window);
        bulletList.renderBullets(this->window);
    }
    //   Draw game objects
    // ground.renderOnGame(this->window);
    map.renderPlatforms(this->window);
    map.renderObjects(this->window);
    // enemy.renderOnGame(this->window);
    enemy.renderEnemies(this->window);

    // renderPlatforms();
    window->display();
}
