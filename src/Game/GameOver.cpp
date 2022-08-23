#include "Game/GameOver.hpp"

GameOver::GameOver(){

}

void GameOver::initVariables(){
    //Buttons
    isExitButtonSelected = false;
    isExitButtonPressed = false;
    isRetryButtonSelected = true;
    isRetryButtonPressed = false;
    //GAME OVER BRACKGROUND
    sp_gameOver.setTexture(texture.gameOverTexture);
    //GAME OVER TEXT
    //gameOverTitle.setString("Game Over");

    //RETRY BUTTON
    retryButton.setFont(font.font_gameOver);
    retryButton.setString("Retry");
    retryButton.setCharacterSize(50);
    retryButton.setPosition(550,500);
    //EXIT BUTTON
    exitButton.setFont(font.font_gameOver);
    exitButton.setString("Exit");
    exitButton.setCharacterSize(50);
    exitButton.setPosition(550,600);

}

void GameOver::updateInput(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if(!isRetryButtonSelected){
            isRetryButtonSelected = true;
            isExitButtonSelected = false;
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        if (!isExitButtonSelected){
            isRetryButtonSelected = false;
            isExitButtonSelected = true;
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){

        if (isRetryButtonSelected)
            isRetryButtonPressed = true;                
        else{
            isExitButtonPressed = true;
        }
    }
}

void GameOver::update(sf::RenderWindow *window){
    updateInput();
    if (isRetryButtonSelected){
        retryButton.setFillColor(sf::Color::Red);
        exitButton.setFillColor(sf::Color::White);
    }
    else{
        exitButton.setFillColor(sf::Color::Red);
        retryButton.setFillColor(sf::Color::White);
    }

    if (isRetryButtonPressed){

    }
    else if(isExitButtonPressed){
        window->close();
    }
}


void GameOver::renderBackground(sf::RenderTarget *target){
    target->draw(sp_gameOver);
    target->draw(exitButton);
    target->draw(retryButton);
}