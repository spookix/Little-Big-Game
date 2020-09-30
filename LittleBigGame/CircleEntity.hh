/*
** ETNA PROJECT, 20/05/2019 by soubri_j, mendy_s, martin_m
** CircleEntity.hh
** File description: 
**      CircleEntity header class for LittleBigGame.
**      CircleEntity header class to define a circle.
*/
#ifndef __CIRCLE_ENTITY_HH__
#define __CIRCLE_ENTITY_HH__
#include <SFML/Graphics.hpp>
#include "AbstractEntity.hh"
#include "Utils.hh"

class CircleEntity : public AbstractEntity {
    private:
        sf::CircleShape _shape;
        sf::Color _color;
        double _rayon;

    public:
        CircleEntity();
        CircleEntity(const double, const double, const sf::Vector2f, const sf::Color*);
        CircleEntity(const CircleEntity&);
        virtual ~CircleEntity();
        CircleEntity &operator=(const CircleEntity&);
        virtual void Draw() override;
        virtual void Update() override;
        double GetRayon() const;
        void SetRayon(const double);
        virtual sf::Shape* GetShape() override;
        virtual sf::Color* GetColor() override;
};
#endif