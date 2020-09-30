/*
** ETNA PROJECT, 20/05/2019 by soubri_j, mendy_s, martin_m
** EntityFactory.cpp
** File description: 
**      EntityFactory class for LittleBigGame.
**      EntityFactory class that is the factory for every entity type of the game.
*/
#include "EntityFactory.hh"

// Create method : Create the entity of the type passed in parameter
// Params :
//      toCreate : A string containing the entity type to create
// Returns :
//      The created entity if type found, NULL otherwise
AbstractEntity* EntityFactory::Create(const std::string& toCreate) {
    if (toCreate.compare("CircleEntity") == 0) {
        return new CircleEntity();
    } else {
        return NULL;
    }
}