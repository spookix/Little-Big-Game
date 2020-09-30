/*
** ETNA PROJECT, 20/05/2019 by soubri_j, mendy_s, martin_m
** AbstractEntity.cpp
** File description: 
**      AbstractEntity class for LittleBigGame.
**      Abstract class that is the basis for every entity of the game.
*/
#include "AbstractEntity.hh"

// Default constructor for abstract entity class
AbstractEntity::AbstractEntity()
{
    _position.x = 0;
    _position.y = 0;
    _direction.x = -1;
    _direction.y = -1;
    _speed = 1;
    _name = "AbstractEntity";
}

// Empty virtual method Draw
void AbstractEntity::Draw()
{
}

// Empty virtual method Update
void AbstractEntity::Update()
{
}

// Empty virtual method GetShape
sf::Shape* AbstractEntity::GetShape() {
}

// Empty virtual method GetColor
sf::Color* AbstractEntity::GetColor() { 
}

// Default destructor
AbstractEntity::~AbstractEntity()
{
}

// Method GetDirection
// Returns :
//      The direction
sf::Vector2f AbstractEntity::GetDirection() const {
    return _direction;
}

// Method GetPosition
// Returns :
//      The position
sf::Vector2f AbstractEntity::GetPosition() const {
    return _position;
}

// Method GetSpeed
// Returns :
//      The speed
double AbstractEntity::GetSpeed() const {
    return _speed;
}

// Method SetPosition
// Modify the position of the entity
// Params :
//      x : x position
//      y : y position
void AbstractEntity::SetPosition(const float x, const float y) {
    _position.x = x;
    _position.y = y;
}

// Method SetPosition
// Modify the position of the entity
// Params :
//      copy : A vector to copy
void AbstractEntity::SetPosition(const sf::Vector2f copy) {
    _position.x = copy.x;
    _position.y = copy.y;
}

// Method SetDirection
// Modify the direction of the entity
// Params :
//      x : x direction
//      y : y direction
void AbstractEntity::SetDirection(const float x, const float y) {
    _direction.x = x;
    _direction.y = y;
}

// Method SetDirection
// Modify the direction of the entity
// Params :
//      copy : A vector to copy
void AbstractEntity::SetDirection(const sf::Vector2f copy) {
    _direction.x = copy.x;
    _direction.y = copy.y;
}

// Method SetSpeed
// Modify the speed of the entity
// Params :
//      speed : The speed
void AbstractEntity::SetSpeed(const double speed) {
    _speed = speed;
}

// Method used to get the entity id
// Returns
//      The entity id
int AbstractEntity::GetId() const {
    return _id;
}

// Method used to set the entity id
// Params : 
//      id : The id of the entity
void AbstractEntity::SetId(const int id) {
    _id = id;
}

// Method used to get classname
// Returns
//      The classname
std::string AbstractEntity::GetName() const {
    return _name;
}