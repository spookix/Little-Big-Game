/*
** ETNA PROJECT, 02/06/2019 by soubri_j, mendy_s, martin_m
** Scene.hh
** File description: 
**      Scene header class for LittleBigGame.
**      Scene header class that is "scene manager".
*/
#ifndef __SCENE_HH__
#define __SCENE_HH__
#include <SFML/Graphics.hpp>
#include "AbstractEntity.hh"
#include "EntityFactory.hh"
#include "TimeManager.hh"
#include "CircleEntity.hh"
#include "TextEntity.hh"
#include <math.h>
#include <list>

class Scene {
    private:
        sf::RenderWindow _window;
        sf::Text _fps;
        sf::Text _txtScore;
        sf::Text _txtLife;
        sf::Font _font;
        std::list<AbstractEntity*> _entities;
        std::list<AbstractEntity*> _toRemove;
        std::list<TextEntity*> _texts;
        sf::Vector2i _startPosition;
        EntityFactory _factory;
        bool _gameStarted = false;
        bool _gameEnded = false;
        int _currentId;
        int _lifeNumber = 3;
        int _score = 0;
        
        Scene();
        void DisplayFPS();
        void DisplayLife();
        void DisplayScore();
        void WindowCollision(AbstractEntity* entity);
        void RemoveEntities();
    
    public:
        static Scene *GetInstance();
        virtual ~Scene();
        void Update();
        void AddEntity(AbstractEntity*);
        void AddText(TextEntity*);
        void RemoveText(TextEntity*);
        void AddEntityToRemove(AbstractEntity*);
        bool GetGameStarted() const;
        bool GetGameEnded() const;
        void StartGame();
        sf::Font GetFont() const;
        sf::RenderWindow* GetWindow();
        std::list<AbstractEntity*> GetEntities();
        std::list<TextEntity*> GetTexts();
        std::list<AbstractEntity*> IsInCollision(AbstractEntity*);
};

#endif