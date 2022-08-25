#include "Game/GameOver.hpp"

GameOver::GameOver(){

}

void GameOver::initVariables(){
    //Retry button boolean
    isRetryButtonPressed = false;
    //index
    gameOverMenuSelected = 0;

    //GAME OVER BRACKGROUND
    sp_gameOver.setTexture(texture.gameOverTexture);

   //SCORE TABLE
    gameOverButton[0].setFont(font.font_gameOver);
    gameOverButton[0].setString("Total Scores");
    gameOverButton[0].setCharacterSize(50);
    gameOverButton[0].setPosition(500,200);

    //RETRY BUTTON
    gameOverButton[1].setFont(font.font_gameOver);
    gameOverButton[1].setString("Retry");
    gameOverButton[1].setCharacterSize(50);
    gameOverButton[1].setPosition(570,500);

    //EXIT BUTTON
    gameOverButton[2].setFont(font.font_gameOver);
    gameOverButton[2].setString("Exit");
    gameOverButton[2].setCharacterSize(50);
    gameOverButton[2].setPosition(590,600);

    //FINAL SCORE
    finalScore.setFont(font.font_score);
    finalScore.setCharacterSize(40);
    finalScore.setPosition(460,100);

}

void GameOver::moveUp(){
    if(gameOverMenuSelected - 1 >= 0){
        gameOverButton[gameOverMenuSelected].setFillColor(sf::Color::White);
        gameOverMenuSelected--;
        gameOverButton[gameOverMenuSelected].setFillColor(sf::Color::Red);
    }
}

void GameOver::moveDown(){
    if(gameOverMenuSelected + 1 < 3){
        gameOverButton[gameOverMenuSelected].setFillColor(sf::Color::White);
        gameOverMenuSelected++;
        gameOverButton[gameOverMenuSelected].setFillColor(sf::Color::Red);
    }
}

void GameOver::KeyboardReleased(sf::Event ev, sf::RenderWindow *window){
    switch (ev.key.code){
        case sf::Keyboard::Up:
            moveUp();
            break;                
        case sf::Keyboard::Down:
            moveDown();
            break;
        case sf::Keyboard::Enter:
            switch (getPressedButton()){
                case 0:
                    Score().showScore();
                    break;
                case 1:
                    isRetryButtonPressed = true;
                    break;
                case 2:
                    std::cout<<"\nSalir Juego"<<std::endl;
                    window->close();
                    break;  
            }
            break;            
    }
}

void GameOver::updateScore(Score score){
    finalScore.setString("Score Final:  "+std::to_string(score.getScore()));
}


void GameOver::renderBackground(sf::RenderTarget *target){
   target->draw(sp_gameOver);
   for(int i=0; i<3; i++){
    target->draw(gameOverButton[i]);
   }
   target->draw(finalScore);
}