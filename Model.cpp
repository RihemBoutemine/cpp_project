// Dans Model.cpp (fichier d'implémentation)
#include "Model.hpp"
#include "Asteroid.hpp"
#include "missile.hpp"
#include "spaceship.hpp"
#include "flyingobject.hpp"
#include<random>
#include "framework.hpp"
#include <iostream>


Model::Model(int asteroidSize, Framework* framework){

    spaceship = new Spaceship(600, 700, 25, 35, 20, 5);
    this->framework = framework;

    for (int i = 0; i < 10; i++) {
        int x = rand() % framework->GetScreenWidth();
        int y = rand() % framework->GetScreenHeight();
        int size = rand() % asteroidSize + 30;
        int angle = rand() % 361 - 180;
        asteroids.push_back(new Asteroid(x, y, size, 3, 3,angle));
    }

    for (int i = 0; i < 10; i++) {
        int x = rand() % -(framework->GetScreenWidth());
        int y = rand() % -(framework->GetScreenHeight());
        int size = rand() % asteroidSize + 50;
        int angle = rand() % 361 - 180;
        asteroids.push_back(new Asteroid(x, y, size, 3, 3,angle));
    }

    //missiles.push_back(new Missile(400,500,50,40,90));
    //asteroids.push_back(new Asteroid(800, 500,70,40,90));

}

Model::~Model() {
    delete spaceship;
}

Spaceship *Model::GetSpaceship() const {
    return spaceship;
}

void Model::shoot() {
    if (missiles.empty()) {
        missiles.push_back(
                new Missile(spaceship->GetX(), spaceship->GetY(), 20, 20, spaceship->GetAngle()-90));
        std::cout << "Angle du missile test " << spaceship->GetAngle()  << std::endl;
    }
}

int Model::Update() {

    if (asteroids.empty()) {
        return 1;
    }
    this->spaceship->Move(framework->GetScreenWidth(), framework->GetScreenHeight(), spaceship->GetAngle());
    if (!missiles.empty()) {
        if (missiles[0]->Move(framework->GetScreenWidth(), framework->GetScreenHeight()))
            missiles.clear();
    }

    for (int i = 0; i < asteroids.size(); i++) {
        asteroids[i]->Move(framework->GetScreenWidth(), framework->GetScreenHeight());
        if (!missiles.empty()) {
            if (FlyingObject::Collide(*asteroids[i], *missiles[0])) {
                missiles.clear();
                if (asteroids[i]->GetSize() > 70) {
                    asteroids[i]->SetSize(asteroids[i]->GetSize() / 2);
                    asteroids.push_back(
                            new Asteroid(asteroids[i]->GetX(), asteroids[i]->GetY(), asteroids[i]->GetSize(), 3, 3,
                                         asteroids[i]->GetAngle() + 90));
                } else {
                    asteroids.erase(asteroids.begin() + i);
                }
            }
        }

        if (FlyingObject::Collide(*asteroids[i], *this->spaceship)) {
            if (!this->spaceship->isWarning()) {
                this->spaceship->setShieldLevel(this->spaceship->getShieldLevel() - 0.2);
                this->spaceship->resterInvinsible(3);

            } else if (this->spaceship->getShieldLevel() <= 0)
                return -1;
        }
    }
    if (this->spaceship->isWarning()) {
        this->spaceship->updateinvincible();


    }
    return 0;
}

std::vector<FlyingObject*> Model::GetFlyingObjects() {

    std::vector<FlyingObject*> flyingObjects;
    std::copy(missiles.begin(), missiles.end(), std::back_inserter(flyingObjects));
    std::copy(asteroids.begin(), asteroids.end(), std::back_inserter(flyingObjects));
    flyingObjects.push_back(spaceship);

    return flyingObjects;
}




