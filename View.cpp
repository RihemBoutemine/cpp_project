#include "view.hpp"
#include "framework.hpp"
#include <iostream>


View::View(Framework* framework) : framework(framework) {}


// cela me semble plus logique
void View::RefreshDisplay(const std::vector<FlyingObject*>& flyingObjects) {
    // Effacer l'écran

    for (const auto& obj : flyingObjects) {
        std::string typeName = obj->GetTypeName();
        std::cout << "entrée de la boucle " << std::endl;


        if (typeName == "Spaceship") {
            framework->DrawShip(obj->GetX(), obj->GetY(), obj->GetAngle(),((Spaceship*)obj)->getShieldLevel(),((Spaceship*)obj)->isWarning());
            std::cout << "Angle du ship test " << obj->GetAngle() << std::endl;
        } else if (typeName == "Missile") {
            framework->DrawMissile(obj->GetX(), obj->GetY());
            std::cout << "Missile Position: X = " << obj->GetX() << std::endl;
        } else if (typeName == "Asteroid") {
            framework->DrawAsteroid(obj->GetX(), obj->GetY(), obj->GetSize());
            std::cout << "Asteroid Position: X = " << obj->GetX() << std::endl;
        }
    }
}

View::~View() {}


