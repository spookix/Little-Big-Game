/*
** ETNA PROJECT, 07/06/2019 by soubri_j, mendy_s, martin_m
** Breaker.hh
** File description: 
**      Breaker header class for LittleBigGame.
**      Brealer header class to define the breaker used to send the ball.
*/
#ifndef __BREAKER_HH__
#define __BREAKER_HH__
#include <SFML/Graphics.hpp>
#include "RectangleEntity.hh"
#include "InputManager.hh"
#include "Utils.hh"

class Breaker : public RectangleEntity {
    private:
        virtual ~Breaker();
        void Collision();

    public:
        Breaker();
        Breaker(double, double, const sf::Color*);
        virtual void Update() override;
};
#endif