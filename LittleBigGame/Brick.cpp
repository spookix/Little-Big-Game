/*
** ETNA PROJECT, 12/06/2019 by soubri_j, mendy_s, martin_m
** Brick.cpp
** File description: 
**      Brick class for LittleBigGame.
**      Brick class to define the brick element of the game.
*/
#include "Brick.hh"

// Destructor
Brick::~Brick() {

}

// Default constructor
Brick::Brick() {
    Brick(1);
}

// Constructor taking lifePoint in parameter
// Params :
//      * lifePoint : Life point number of the brick
Brick::Brick(const double lifePoint) : RectangleEntity(50.0, 25.0, &sf::Color::Red) {
    _name = "Brick";
    _lifePoint = lifePoint;
}

// Constructor taking multiple parameters
// Params :
//      * lifePoint : Life point number of the brick
//      * width : Width of the brick
//      * height : Height of the brick
//      * position : Position of the brick
//      * color : The color of the brick
Brick::Brick(const int lifePoint, const double width, const double height, const sf::Vector2f position, const sf::Color* color) 
       : RectangleEntity(width, height, color) {
    _name = "Brick";
    _lifePoint = lifePoint;
    SetPosition(position);
}

// Method used to manage collision with the ball
void Brick::Collision() {
    _lifePoint--;
}

// Update method overriding
// We check collision with other entities and if lifepoint less than zero with remove
//  the brick from the Scene.
void Brick::Update() {
    if (_lifePoint <=0) {
        Scene::GetInstance()->AddEntityToRemove(this);
    }
}

// Draw overriding method : We draw the brick if it has lifepoint
void Brick::Draw() {
    if (_lifePoint > 0) {
        RectangleEntity::Draw();
    }
}
