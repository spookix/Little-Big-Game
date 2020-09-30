/*
** ETNA PROJECT, 07/06/2019 by soubri_j, mendy_s, martin_m
** RectangleEntity.hh
** File description: 
**      RectangleEntity header class for LittleBigGame.
**      RectangleEntity header class to define a rectangle.
*/
#ifndef __RECTANGLE_ENTITY_HH__
#define __RECTANGLE_ENTITY_HH__
#include <SFML/Graphics.hpp>
#include "AbstractEntity.hh"
#include "Utils.hh"

class RectangleEntity : public AbstractEntity {
    private:
        sf::RectangleShape _shape;
        sf::Color _color;
        double _width;
        double _height;

    public:
        RectangleEntity();
        RectangleEntity(double, double, const sf::Color*);
        RectangleEntity(const RectangleEntity&);
        virtual ~RectangleEntity();
        RectangleEntity &operator=(const RectangleEntity&);
        virtual void Draw() override;
        virtual void Update() override;
        double GetWidth() const;
        void SetWidth(const double);
        double GetHeight() const;
        void SetHeight(const double);
        void SetColor(const sf::Color* color);
        virtual sf::Shape* GetShape() override;
        virtual sf::Color* GetColor() override;
};
#endif