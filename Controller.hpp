#pragma once

#include "Model.hpp"
#include "view.hpp"
#include "framework.hpp"
#include "flyingobject.hpp"
#include "Asteroid.hpp"
#include "missile.hpp"
#include "spaceship.hpp"

class Controller {
public:
    // Constructeur
    Controller(int fps, int shipSize, int missileSize);
    // Destructeur
    ~Controller();
    // Méthode pour lancer le jeu
    void LaunchGame();

public:
    Framework* framework;
    View* view;
    Model* model;
};