/*
** ETNA PROJECT, 07/06/2019 by soubri_j, mendy_s, martin_m
** Breaker.cpp
** File description: 
**      Breaker class for LittleBigGame.
**      Brealer class to define the breaker used to send the ball.
*/
#include "Breaker.hh"

// Default constructor
Breaker::Breaker() {
    Breaker(100.0, 5.0, &sf::Color::Green);
}

Breaker::Breaker(double width, double height, const sf::Color* color) : RectangleEntity(width, height, color) {

}

// Destructor
Breaker::~Breaker() {
    
}

// Method to update breaker
void Breaker::Update() {
    if (InputManager::GetInstance().IsLeftPressed()) {
        SetPosition(sf::Vector2f(GetPosition().x - GetSpeed(), GetPosition().y));
        if (GetPosition().x <= 0) 
        {
            SetPosition(0, GetPosition().y);
        }
    }
    if (InputManager::GetInstance().IsRightPressed()) {
        SetPosition(sf::Vector2f(GetPosition().x + GetSpeed(), GetPosition().y));
        if (GetPosition().x + GetWidth() >= Scene::GetInstance()->GetWindow()->getSize().x) {
            SetPosition(Scene::GetInstance()->GetWindow()->getSize().x - GetWidth(), GetPosition().y);
        }
    }
}

