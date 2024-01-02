#include "view.hpp"
#include "framework.hpp"
#include <iostream>


View::View(Framework* framework) : framework(framework) {}
View::~View() {}

// cela me semble plus logique
void View::RefreshDisplay(const std::vector<FlyingObject*>& flyingObjects) {
    // Effacer l'écran
    //framework->Update();

    for (const auto& obj : flyingObjects) {
        std::string typeName = obj->GetTypeName();

        if (typeName == "Missile")
            // Afficher le missile
            framework->DrawMissile(obj->GetX(), obj->GetY());
        else if (typeName == "Asteroid")
            // Afficher l'astéroïde
            framework->DrawAsteroid(obj->GetX(), obj->GetY(), obj->GetSize());
    }
}


    // Parcourir la liste des objets volants et les afficher
    /*for (const FlyingObject* obj : flyingObjects) {
        const Asteroid* asteroid = dynamic_cast<const Asteroid*>(obj);
        const Missile* missile = dynamic_cast<const Missile*>(obj);

        // Si l'objet est un Asteroid, dessiner l'asteroid
        if (asteroid) {
            framework->DrawAsteroid(asteroid->GetX(), asteroid->GetY(), asteroid->GetSize());
        }
            // Si l'objet est un Missile, dessiner le missile
        else if (missile) {
            framework->DrawMissile(missile->GetX(), missile->GetY());
        }
    }
}
*/
/*
void View::RefreshDisplay(const std::vector<FlyingObject*>& flyingObjects) {
    // Effacer l'écran
    framework->Update();

    // Parcourir la liste des objets volants et les afficher
    for (const FlyingObject* obj : flyingObjects) {

        framework->DrawAsteroid(obj->GetX(), obj->GetY(), obj->GetSize());
        framework->DrawMissile(obj->GetX(), obj->GetY());
        //framework->DrawShip(obj->GetX(), obj->GetY(), obj->GetAngle(), 0, false);
    }
}
*/
