/*
** ETNA PROJECT, 02/06/2019 by soubri_j, mendy_s, martin_m
** TextEntity.cpp
** File description: 
**      TextEntity class for LittleBigGame.
**      TextEntity class to define a text to display.
*/
#include "TextEntity.hh"
#include "Scene.hh"

// Default constructor
TextEntity::TextEntity(const std::string& text) {
    _text.setString(text);
}

// Destructor
TextEntity::~TextEntity() {

}

// Constructor by copy
TextEntity::TextEntity(TextEntity& toCopy) {
    _text = *toCopy.GetText();
}

// Equal operator definition
TextEntity& TextEntity::operator=(TextEntity &toCopy) {
    _text = *toCopy.GetText();
}

// Method used to set text
// Params :
//      text : The text to set
void TextEntity::SetText(const sf::Text* text) {
    _text = *text;
}

// Method used to get text
// Returns
//      The text
sf::Text* TextEntity::GetText() {
    return &_text;
}