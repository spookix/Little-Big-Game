/*
** ETNA PROJECT, 20/05/2019 by soubri_j, mendy_s, martin_m
** AbstractEntity.hh
** File description: 
**      AbstractEntity header for LittleBigGame.
**      AbstractEntity header class that is the basis for every entity of the game.
*/
#ifndef __ABSTRACT_ENTITY_HH__
#define __ABSTRACT_ENTITY_HH__
#include <SFML/Graphics.hpp>
#include <iostream>

class AbstractEntity 
{
    private:
        sf::Vector2f _position;
        sf::Vector2f _direction;
        double _speed;
        int _id;
    
    protected:
        std::string _name;

    public:
        AbstractEntity();
        virtual ~AbstractEntity();
        virtual void Draw() = 0;
        virtual void Update() = 0;
        virtual sf::Shape* GetShape() = 0;
        virtual sf::Color* GetColor() = 0;
        sf::Vector2f GetPosition() const;
        sf::Vector2f GetDirection() const;
        double GetSpeed() const;
        void SetPosition(const float, const float);
        void SetPosition(const sf::Vector2f);
        void SetDirection(const float, const float);
        void SetDirection(const sf::Vector2f);
        void SetSpeed(const double);
        int GetId() const;
        void SetId(const int);
        std::string GetName() const;
};
#endif