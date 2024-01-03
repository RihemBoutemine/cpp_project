#pragma once

#include "Model.hpp"
#include "view.hpp"
#include "framework.hpp"
#include "flyingobject.hpp"
#include "asteroid.hpp"
#include "missile.hpp"
#include "spaceship.hpp"

class controller {
public:
    // Constructeur
    controller(int fps, int shipSize, int missileSize);
    // Destructeur
    ~controller();
    // Méthode pour lancer le jeu
    void LaunchGame();

public:
    Framework* framework;
    View* view;
    Model* model;
};