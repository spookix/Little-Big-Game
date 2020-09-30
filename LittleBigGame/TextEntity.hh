/*
** ETNA PROJECT, 02/06/2019 by soubri_j, mendy_s, martin_m
** TextEntity.hh
** File description: 
**      TextEntity header class for LittleBigGame.
**      TextEntity header class to define a text to display.
*/
#ifndef __TEXT_ENTITY_HH__
#define __TEXT_ENTITY_HH__
#include <SFML/Graphics.hpp>
#include "Utils.hh"

class TextEntity {
    private:
        sf::Text _text;
        
    public:
        TextEntity(const std::string&);
        TextEntity(TextEntity&);
        virtual ~TextEntity();
        TextEntity &operator=(TextEntity&);
        sf::Text* GetText();
        void SetText(const sf::Text*);
};

#endif