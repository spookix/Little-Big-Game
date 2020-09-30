/*
** ETNA PROJECT, /05/2019 by soubri_j, mendy_s, martin_m
** Utils.hh
** File description: 
**      Utils header file for class that contains utility methods for the game.
*/
#ifndef __UTILS_HH__
#define __UTILS_HH__
#include <SFML/Graphics.hpp>

class Utils {
    public:
        static sf::Color GetRandomColor();

    private:
        Utils();
        virtual ~Utils();
};

#endif