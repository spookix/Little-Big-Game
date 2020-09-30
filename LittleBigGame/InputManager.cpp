/*
** ETNA PROJECT, 02/06/2019 by soubri_j, mendy_s, martin_m
** InputManager.cpp
** File description: 
**      InputManager class for LittleBigGame.
**      InputManger class that is the input manager.
*/
#include "InputManager.hh"
#include "CircleEntity.hh"
#include "Scene.hh"
#include "TimeManager.hh"

// Default constructor
InputManager::InputManager() {
}

// Destructor
InputManager::~InputManager() {
}

// Method used to get unique instance of InputManager
// Returns
//      A unique instance of InputManager
InputManager& InputManager::GetInstance() {
    static InputManager _instance;
    return _instance;
}

// Method used to check keyboard events
void InputManager::KeyboardManagement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        Scene::GetInstance()->GetWindow()->close();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        Scene::GetInstance()->StartGame();
    }
}

// Method used to manage all inputs
void InputManager::ManageUserInputs() {
    KeyboardManagement();
}

// Method used to know if player press left
bool InputManager::IsLeftPressed() {
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q));
}

// Method used to know if player press right
bool InputManager::IsRightPressed() {
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D));
}