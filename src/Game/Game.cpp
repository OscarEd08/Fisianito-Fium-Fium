#include "Game/Game.hpp"

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
    // initObjects();
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
            player.movementDirection = Directions::Down;
            player.isJumping = false;
            break;
        }
        }
    }
}

void Game::update()
{
    pollEvents();
    //Player
    player.update(map.platforms);
    player.checkCollisionWithObjects(map.objects);
    //Enemy
    enemy.initEnemies();
    enemy.updateManager();
}

void Game::render()
{
    window->clear();
    //Draw game objects
    player.renderOnGame(this->window);
    map.renderPlatforms(this->window);
    map.renderObjects(this->window);
    enemy.renderEnemies(this->window);
    window->display();
}
