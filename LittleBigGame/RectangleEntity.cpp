/*
** ETNA PROJECT, 07/06/2019 by soubri_j, mendy_s, martin_m
** RectangleEntity.cpp
** File description: 
**      RectangleEntity class for LittleBigGame.
**      RectangleEntity class for the game.
*/
#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "RectangleEntity.hh"

// Default constructor
RectangleEntity::RectangleEntity() {
    RectangleEntity(100.0, 5.0, &sf::Color::Green);
}

// Constructor with parameters
//      * width : Rectangle width
//      * height: Rectangle height
//      * color : Rectangle color
RectangleEntity::RectangleEntity(double width, double height, const sf::Color *color) {
    _name = "RectangleEntity";
    _width = width;
    _height = height;
    _color = *color;
    _shape = sf::RectangleShape(sf::Vector2f(_width, _height));
    _shape.setFillColor(_color);
}

// Constructor by copy
//      * copy : The rectangle to copy
RectangleEntity::RectangleEntity(const RectangleEntity& copy) {
    _name = "RectangleEntity";
    SetWidth(copy.GetWidth());
    SetHeight(copy.GetHeight());
    _color = copy._color;
    _shape = sf::RectangleShape(sf::Vector2f(_width, _height));
    _shape.setFillColor(_color);
}

// Destructor
RectangleEntity::~RectangleEntity() {
    //_shape.~RectangleShape();
    _color.~Color();
}

// Equal operator overriding
RectangleEntity& RectangleEntity::operator=(const RectangleEntity& copy) {
    SetWidth(copy.GetWidth());
    SetHeight(copy.GetHeight());
    _color = copy._color;
    return (*this);
}

// Method to get width
// Returns
//      The width of the rectangle
double RectangleEntity::GetWidth() const {
    return _width;
}

// Method to get height
// Returns
//      The height of the rectangle
double RectangleEntity::GetHeight() const {
    return _height;
}

// Method to get the shape
// Returns
//      The rectangle shape
sf::Shape* RectangleEntity::GetShape() {
    return &_shape;
}

// Method to get the color
// Returns
//      The rectangle color
sf::Color* RectangleEntity::GetColor() {
    return &_color;
}

// Method to set the width
// Parameters
//      * width : The width of the rectangle
void RectangleEntity::SetWidth(const double width) {
    _width = width;
}

// Method to set the height
// Parameters
//      height : The height of the rectangle
void RectangleEntity::SetHeight(const double height) {
    _height = height;
}

// Method to set the color
// Parameter
//      color : The color of the rectangle
void RectangleEntity::SetColor(const sf::Color* color) {
    _color = *color;
}

// Method used to draw the rectangle
void RectangleEntity::Draw() {
    _shape.setSize(sf::Vector2f(_width, _height));
    _shape.setPosition(GetPosition());
    _shape.setFillColor(*GetColor());
}

// Method Update
void RectangleEntity::Update() {

}






