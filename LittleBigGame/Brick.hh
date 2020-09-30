/*
** ETNA PROJECT, 12/06/2019 by soubri_j, mendy_s, martin_m
** Brick.hh
** File description: 
**      Brick header class for LittleBigGame.
**      Brick header class to define the brick element of the game.
*/
#ifndef __BRICK_HH__
#define __BRICK_HH__
#include <SFML/Graphics.hpp>
#include "AbstractEntity.hh"
#include "RectangleEntity.hh"
#include "Scene.hh"

class Brick : public RectangleEntity {
    private:
        int _lifePoint;

        virtual ~Brick();

    public:
        Brick();
        Brick(const double);
        Brick(const int, const double, const double, const sf::Vector2f, const sf::Color*);
        void Update() override;
        void Draw() override;
        void Collision();
};
#endif