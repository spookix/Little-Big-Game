/*
** ETNA PROJECT, 02/06/2019 by soubri_j, mendy_s, martin_m
** Scene.cpp
** File description: 
**      Scene class for LittleBigGame.
**      Scene class that is the "scene manager".
*/
#include "Scene.hh"

// Default constructor
Scene::Scene() {
    _currentId = 0;
    _window.create(sf::VideoMode(800,600), "Default windows");
    _window.setFramerateLimit(60);
    _font.loadFromFile("arial.ttf");
    _txtLife.setFont(_font);
    _txtLife.setCharacterSize(32);
    _txtLife.setColor(sf::Color::White);
    _txtLife.setPosition(sf::Vector2f(_window.getSize().x / 2 - 50, 0));
    _txtScore.setFont(_font);
    _txtScore.setCharacterSize(32);
    _txtScore.setColor(sf::Color::White);
    _txtScore.setPosition(sf::Vector2f(_window.getSize().x - 150, 0));
    _fps.setFont(_font);
    _fps.setCharacterSize(32);
    _fps.setColor(sf::Color::Red);
    TimeManager::GetInstance().Start();
}

// Desctructor
Scene::~Scene() {
    _window.~RenderWindow();
}

// Method used to get unique instance of Scene
// Returns
//      A unique instance of Scene
Scene* Scene::GetInstance() {
    static Scene scene;
    return &scene;
}

// Method used to get all entities
// Returns
//      All entities stored by the Scene
std::list<AbstractEntity*> Scene::GetEntities() {
    return _entities;
}

// Method used to get all texts
// Returns
//      All texts stored by the scene
std::list<TextEntity*> Scene::GetTexts() {
    return _texts;
}

// Method used to get the font loaded by the scene
// Returns
//      The font loaded by the scene
sf::Font Scene::GetFont() const {
    return _font;
}

// Update override method : Calls Update method of all entities stored by the Scene
void Scene::Update() {
    std::list<AbstractEntity*>::iterator it = _entities.begin();
    std::list<TextEntity*>::iterator it2;
    
    TimeManager::GetInstance().Update();
    while (it != _entities.end()) {
        WindowCollision(*it);
        (*it)->Update();
        it++;
    }
    RemoveEntities();
    it = _entities.begin();
    _window.clear();
    DisplayFPS();
    DisplayScore();
    DisplayLife();
    while (it != _entities.end()) {
        (*it)->Draw();
        _window.draw((*(*it)->GetShape()));
        it++;
    }
    it2 = _texts.begin();
    while (it2 != _texts.end()) {
        _window.draw(*(*it2)->GetText());
        it2++;
    }
    _window.display();
}

// Method used to manage collision between window and objects
// Params :
//      * entity : The object to check collision with
void Scene::WindowCollision(AbstractEntity* entity) {
    if (entity != NULL && entity->GetShape() != NULL) {
        sf::FloatRect boundingBox = (entity)->GetShape()->getGlobalBounds(); 
        if (boundingBox.top <= 0 || boundingBox.top + boundingBox.height >= _window.getSize().y) {
            (entity)->SetDirection((entity)->GetDirection().x, (entity)->GetDirection().y * -1);
            if (boundingBox.top + boundingBox.height >= _window.getSize().y) {
                _lifeNumber--;
                if (_lifeNumber <= 0) {
                    _gameEnded = true;
                }
            }
        }
        if (boundingBox.left <= 0 || boundingBox.left + boundingBox.width >= _window.getSize().x) {
            (entity)->SetDirection((entity)->GetDirection().x * - 1, (entity)->GetDirection().y);
        }
        if (entity->GetPosition().y <= 0) {
            entity->SetPosition(entity->GetPosition().x, 0);
        }
        if (entity->GetPosition().x <= 0) {
            entity->SetPosition(0, entity->GetPosition().y);
        }
    }
}

// Method used to know if an entity of the scene is in collision with one or more entities
// Params : 
//      * entity : THe entity to check
// Returns
//      A list of entites in collision with entity
std::list<AbstractEntity*> Scene::IsInCollision(AbstractEntity* entity) {
    std::list<AbstractEntity*>::iterator it = _entities.begin();
    std::list<AbstractEntity*> collisionList;

    sf::FloatRect b1 = entity->GetShape()->getGlobalBounds();
    while (it != _entities.end()) {
        if ((*it)->GetId() != entity->GetId()) {
            sf::FloatRect b2 = (*it)->GetShape()->getGlobalBounds();
            if (b2.top > 0 && b2.left > 0) {
                if (b1.intersects(b2)) {
                    collisionList.push_back(*it);
                }
            }
        }
        ++it;
    }
    
    return collisionList;
}

// Method used to display FPS on the screen
void Scene::DisplayFPS() {
    std::string textToDisplay;

    int ms = TimeManager::GetInstance().GetElapsedTime();
    int fps = 0;
    if (ms <= 0) {
        ms = 1;
    }
    fps = 1000 / ms;
    textToDisplay = std::to_string(fps);
    textToDisplay += " FPS";
    _fps.setString(textToDisplay);
    _window.draw(_fps);
}

void Scene::DisplayScore() {
    _txtScore.setString("Score : " + std::to_string(_score));
    _window.draw(_txtScore);
}

void Scene::DisplayLife() {
    _txtLife.setString("Life : " + std::to_string(_lifeNumber));
    _window.draw(_txtLife);
}

// Method used to add entity to entities stored by the Scene
// Params :
//      * toAdd : The entity to store
void Scene::AddEntity(AbstractEntity* toAdd) {
    toAdd->SetId(++_currentId);
    _entities.push_back(toAdd);
}

// Method used to remove an entity stored by the Scene
// Params :
//      * toRemove : The entity to remove
void Scene::AddEntityToRemove(AbstractEntity* toRemove) {
    _toRemove.push_back(toRemove);
}

// Removes all entities to remove from the Scene
void Scene::RemoveEntities() {
    std::list<AbstractEntity*>::iterator it = _toRemove.begin();

    while (it != _toRemove.end()) {
        _entities.remove(*it);
        _score += _lifeNumber;
        ++it;
    }
    _toRemove.clear();
}

// Method used to add text to texts stored by the scene
// Params :
//      * toAdd : Text to add
void Scene::AddText(TextEntity* toAdd) {
    _texts.push_back(toAdd);
}

// Method used to remove text from texts stored by the Scene
// Params :
//      * toRemove : The text to remove
void Scene::RemoveText(TextEntity* toRemove) {
    _texts.remove(toRemove);
}

// Method used to know if the game is started or not
// Returns
//      true if game has started, false otherwise
bool Scene::GetGameStarted() const {
    return _gameStarted;
}

// Method used to knwo if the game has ended or not
// Returns
//      true if game has ended, false otherwise
bool Scene::GetGameEnded() const {
    return _gameEnded;
}

// Method used to start the game
void Scene::StartGame() {
    _gameStarted = true;
}

// Method used to get the window managed by the Scene
// Returns :
//      * A pointer on the window managed by the scene
sf::RenderWindow* Scene::GetWindow() {
    return &_window;
}