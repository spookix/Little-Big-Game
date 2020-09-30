/*
** ETNA PROJECT, 20/05/2019 by soubri_j, mendy_s, martin_m
** TimeManager.cpp
** File description: 
**      TimeManager class for LittleBigGame.
**      TimeManager class that is the time manager.
*/
#include "TimeManager.hh"

// Default constructor
TimeManager::TimeManager() {
}

// Destructor
TimeManager::~TimeManager() {
}

// Get unique instance of TimeManager
// Return :
//      A unique instance of TimeManager
TimeManager& TimeManager::GetInstance()
{
    static TimeManager _instance;
    return _instance;
}

// Start method. Initialize the timer.
void TimeManager::Start() {
    _lastStart = std::chrono::system_clock::now();
    _updateStart = std::chrono::system_clock::now();
    _update = std::chrono::system_clock::now();
}

// Update method. Save the "date" of update call
void TimeManager::Update() {
    _updateStart = _update;
    _update = std::chrono::system_clock::now();
}

// Get elapsed time between 2 ticks.
// Returns :
//      The number of milliseconds elapsed between 2 ticks
unsigned int TimeManager::GetElapsedTime() const {
    std::chrono::duration<double> elapsedTime = _update - _updateStart;
    return (elapsedTime.count() * 1000);
}

// Get time elapsed between last tick and the timer start
// Returns :
//      The number of milliseconds elapsed between last tick and timer start
unsigned int TimeManager::GetStartedTime() const {
    std::chrono::duration<double> startedTime = _update - _lastStart;
    return (startedTime.count() * 1000);
}