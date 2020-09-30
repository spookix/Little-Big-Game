/*
** ETNA PROJECT, 05/05/2019 by soubri_j, mendy_s, martin_m
** main.cpp
** File description: 
**      This file contains main method
*/
#include "Scene.hh"
#include "InputManager.hh"
#include "Breaker.hh"
#include "Ball.hh"
#include "Brick.hh"
#include "TextEntity.hh"
#include <SFML/Window.hpp>
#include <iostream>

void InitializeBricks() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 10; ++j) {
            Brick* brick = new Brick(5, 60.0, 30.0, sf::Vector2f(75 + j * 60 +  j * 1, 75 + i * 30 + i * 1), &sf::Color::Red);
            Scene::GetInstance()->AddEntity(brick);
        }
    }
}

int main()
{
    TextEntity* toDisplay = new TextEntity("Press Space to start the game");
    Breaker* ballBreaker = new Breaker(100.0, 20.0, &sf::Color::Green);
    sf::Vector2u screenSize = Scene::GetInstance()->GetWindow()->getSize();
    Ball* ball;
    sf::Font font;
    bool gameStarted = false;

    font = Scene::GetInstance()->GetFont();
    toDisplay->GetText()->setString("Press Space to start the game");
    toDisplay->GetText()->setColor(sf::Color::White);
    toDisplay->GetText()->setFont(font);
    toDisplay->GetText()->setCharacterSize(32);
    toDisplay->GetText()->setPosition((screenSize.x - toDisplay->GetText()->getGlobalBounds().width) / 2,
                (screenSize.y - toDisplay->GetText()->getGlobalBounds().height) / 2); 
    Scene::GetInstance()->AddText(toDisplay);
    ballBreaker->SetSpeed(10);
    ballBreaker->SetPosition(sf::Vector2f((screenSize.x - ballBreaker->GetWidth()) / 2, screenSize.y - ballBreaker->GetHeight() - 40));
    ball = new Ball(10.0, 3.0, sf::Vector2f(1,2), 
        sf::Vector2f(screenSize.x / 2, ballBreaker->GetPosition().y - 25), 
        &sf::Color::Blue);
    
    // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
    while (Scene::GetInstance()->GetWindow()->isOpen())
    {
        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (Scene::GetInstance()->GetWindow()->pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed) {
                Scene::GetInstance()->GetWindow()->close();
            }
        }
        if (!Scene::GetInstance()->GetGameEnded()) {
            if (Scene::GetInstance()->GetGameStarted() && !gameStarted) {
                gameStarted = true;
                Scene::GetInstance()->RemoveText(toDisplay);
                Scene::GetInstance()->AddEntity(ballBreaker);
                Scene::GetInstance()->AddEntity(ball);
                InitializeBricks();
            }
        } else {
            toDisplay->GetText()->setString("Game Over");
            toDisplay->GetText()->setPosition(sf::Vector2f((screenSize.x - toDisplay->GetText()->getGlobalBounds().width) / 2,
                (screenSize.y - toDisplay->GetText()->getGlobalBounds().height) / 2));
            Scene::GetInstance()->AddText(toDisplay);
        }
        InputManager::GetInstance().ManageUserInputs();
        Scene::GetInstance()->Update();
    }



    return 0;
}