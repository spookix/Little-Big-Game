/*
** ETNA PROJECT, 10/06/2019 by soubri_j, mendy_s, martin_m
** Ball.hh
** File description: 
**      Ball header class for LittleBigGame.
**      Ball header class to define the ball of the game.
*/
#ifndef __BALL_HH__
#define __BALL_HH__
#include <SFML/Graphics.hpp>
#include "AbstractEntity.hh"
#include "CircleEntity.hh"
#include "Brick.hh"
#include "Scene.hh"

class Ball : public CircleEntity {
    private:
        virtual ~Ball();
        void Collision();

    public:
        Ball();
        Ball(double, double, const sf::Vector2f, const sf::Color*);
        Ball(double, double, const sf::Vector2f, const sf::Vector2f, const sf::Color*);
        void Update() override;
};
#endif