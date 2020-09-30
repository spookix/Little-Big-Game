/*
** ETNA PROJECT, 02/06/2019 by soubri_j, mendy_s, martin_m
** InputManager.hh
** File description: 
**      InputManager header class for LittleBigGame.
**      InputManger header class that is the input manager.
*/
#ifndef __INPUT_MANAGER_HH__
#define __INPUT_MANAGER_HH__
#include <SFML/Graphics.hpp>
#include "CircleEntity.hh"
#include "Scene.hh"
#include "TimeManager.hh"

class InputManager {
    private:
        bool _buttonRightWasPressed = false;
        bool _buttonLeftWasPressed = false;
        sf::Vector2i _startPosition;
    
    public:
        static InputManager& GetInstance();
        void ManageUserInputs();
        bool IsLeftPressed();
        bool IsRightPressed();

    private:
        InputManager();
        virtual ~InputManager();
        void KeyboardManagement();
};
#endif