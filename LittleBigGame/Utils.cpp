/*
** ETNA PROJECT, /05/2019 by soubri_j, mendy_s, martin_m
** Utils.cpp
** File description: 
**      Utils class for LittleBigGame.
**      Utils class that contains utility methods for the game.
*/
#include "Utils.hh"

// Method used to get a random color
// Returns : 
//      A random color
sf::Color Utils::GetRandomColor() {
    return sf::Color(rand() % 256, rand() % 256, rand() % 256);
}

Utils::Utils() {
}

Utils::~Utils() {
}