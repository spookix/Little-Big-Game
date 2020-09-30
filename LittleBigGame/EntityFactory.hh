/*
** ETNA PROJECT, 20/05/2019 by soubri_j, mendy_s, martin_m
** EntityFactory.hh
** File description: 
**      EntityFactory header class for LittleBigGame.
**      EntityFactory header class that is the factory for every entity type of the game.
*/
#ifndef __ENTITY_FACTORY_HH__
#define __ENTITY_FACTORY_HH__
#include <iostream>
#include "AbstractEntity.hh"
#include "CircleEntity.hh"

class EntityFactory {
    public:
        static AbstractEntity* Create(const std::string&);
};

#endif