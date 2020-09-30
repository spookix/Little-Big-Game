/*
** ETNA PROJECT, 20/05/2019 by soubri_j, mendy_s, martin_m
** CircleEntity.cpp
** File description: 
**      CircleEntity class for LittleBigGame.
**      CircleEntity class for the game.
*/
#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "CircleEntity.hh"

// Default constructor
CircleEntity::CircleEntity() {
    _name = "CircleEntity";
    srand(time(NULL));
    this->_color = Utils::GetRandomColor();
    int randX = (rand() % 2);
    int randY = (rand() % 2);
    this->SetDirection((rand() % 100 + 1)/100.0 * randX, (rand() % 100 + 1)/100.0 * randY);
    this->_shape = sf::CircleShape(10.0);
}

// Constructor
// Params :
//      rayon : Circle rayon
//      speed : Speed of the circle
//      direction : Direction of the circle
//      color : The color of the circle
CircleEntity::CircleEntity(const double rayon, const double speed, const sf::Vector2f direction, const sf::Color* color) {
    _name = "CircleEntity";
    this->_color = *color;
    SetSpeed(speed);
    SetDirection(direction);
    this->_rayon = rayon;
    this->_shape = sf::CircleShape(this->_rayon);
}

// Copy constructor
// Params :
//      copie : CircleEntity to copy
CircleEntity::CircleEntity(const CircleEntity& copie) {
    _name = "CircleEntity";
    srand(time(NULL));
    this->_color = Utils::GetRandomColor();

    SetPosition(copie.GetPosition());
    SetDirection(copie.GetDirection());
    SetSpeed(copie.GetSpeed());
    _shape = sf::CircleShape(_rayon);
}

// Destructor
CircleEntity::~CircleEntity() {
    //_shape.~CircleShape();
    _color.~Color();
}

CircleEntity & CircleEntity::operator=(const CircleEntity& copie) {
    SetPosition(copie.GetPosition());
    SetDirection(copie.GetDirection());
    SetSpeed(copie.GetSpeed());
    return (*this);
}

void CircleEntity::Draw() {
    _shape.setRadius(_rayon);
    _shape.setPosition(sf::Vector2f(GetPosition().x - _rayon/2, GetPosition().y - _rayon/2));
    _shape.setFillColor(*GetColor());
}

void CircleEntity::Update() {
    SetPosition(GetPosition().x + GetDirection().x * GetSpeed(), 
                GetPosition().y + GetDirection().y * GetSpeed());
}

double CircleEntity::GetRayon() const {
    return _rayon;
}

void CircleEntity::SetRayon(const double rayon) {
    _rayon = rayon;
}

sf::Shape* CircleEntity::GetShape() {
    return &(this->_shape);
}

sf::Color* CircleEntity::GetColor() {
    return &(this->_color);
}