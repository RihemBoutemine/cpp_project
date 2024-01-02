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
    Model* model;       // Attribut pointeur vers le modèle
    View* view;         // Attribut pointeur vers la vue
    Framework* framework; // Attribut pointeur vers le framework
};