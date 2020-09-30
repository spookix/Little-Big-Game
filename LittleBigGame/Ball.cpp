/*
** ETNA PROJECT, 10/06/2019 by soubri_j, mendy_s, martin_m
** Ball.cpp
** File description: 
**      Ball class for LittleBigGame.
**      Ball class to define the ball of the game.
*/
#include "Ball.hh"

Ball::Ball() : CircleEntity(5.0, 5.0, sf::Vector2f(1, 2), &sf::Color::Blue) {
    _name = "Ball";
}

Ball::Ball(const double rayon, const double speed, const sf::Vector2f direction, const sf::Color* color) : 
        CircleEntity(rayon, speed, direction, color) {
    _name = "Ball";
    SetPosition(sf::Vector2f(200,200));
}

Ball::Ball(const double rayon, const double speed, const sf::Vector2f direction, const sf::Vector2f position, const sf::Color* color) : 
        CircleEntity(rayon, speed, direction, color) {
    _name = "Ball";
    SetPosition(position);
}

Ball::~Ball() {
}

void Ball::Update() {
    SetPosition(GetPosition().x + GetDirection().x * GetSpeed(), 
                GetPosition().y + GetDirection().y * GetSpeed());
    Collision();
}

void Ball::Collision() {
    std::list<AbstractEntity*> inCollision = Scene::GetInstance()->IsInCollision(this);
    std::list<AbstractEntity*>::iterator it = inCollision.begin();

    sf::FloatRect b1 = GetShape()->getGlobalBounds();
    while (it != inCollision.end()) {
        sf::FloatRect b2 = (*it)->GetShape()->getGlobalBounds();
        if ((b1.top + b1.height >= b2.top && b1.top + b1.height <= b2.top + b2.height && b1.left + b1.width >= b2.left && b1.left <= b2.left + b2.width) || 
            (b1.top <= b2.top + b2.height && b1.top >= b2.top && b1.left + b1.width >= b2.left && b1.left <= b2.left + b2.width)) {
            SetDirection(GetDirection().x, GetDirection().y * -1);
            if (b1.top + b1.height >= b2.top && b1.top + b1.height < b2.top + b2.height && b1.left + b1.width >= b2.left && b1.left <= b2.left + b2.width) {
                SetPosition(GetPosition().x, b2.top - b1.height - 1);
            } else {
                SetPosition(GetPosition().x, b2.top + b2.height + 1);
            }
        } else if ((b1.left <= b2.left + b2.width && b1.left > b2.left && b1.top + b1.height >= b2.top 
            && b1.top + b1.height < b2.top + b2.height) || 
            (b1.left + b1.width >= b2.left && b1.left + b1.width < b2.left + b2.width 
            && b1.top + b1.height >= b2.top && b1.top + b1.height < b2.top + b2.height)) {
            SetDirection(GetDirection().x * -1, GetDirection().y);
            if (b1.left <= b2.left + b2.width && b1.left > b2.left && b1.top + b1.height >= b2.top 
            && b1.top + b1.height < b2.top + b2.height) {
                SetPosition(b2.left + b2.width + 1, GetPosition().y);
            } else {
                SetPosition(b2.left - b1.width - 1, GetPosition().y);
            }
        }
        
        if ((*it)->GetName() == "Brick") {
            Brick* brick = (Brick*) (*it);
            brick->Collision();
        }
        ++it;
    }   
}