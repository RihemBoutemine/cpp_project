#include "Controller.hpp"
#include "framework.hpp"
#include <iostream>


int main(int argc, char* argv[]) {

    Controller gameController(1920, 1080, 30);
    gameController.LaunchGame();

    return 0;
}




/*

#include <iostream>
#include <chrono>
#include <thread>
#include "framework.hpp"
#include "asteroid.hpp"
#include "missile.hpp"
#include "spaceship.hpp"
#include <cmath>

int main(int argc, char* argv[]) {
    Framework *f = new Framework(1920, 1080, 30, 50, 30);
    Asteroid *asteroid = new Asteroid(960, 540, 60, 5, 5);
    Missile *missile = new Missile(250, 150, 60, 5, 45);
    Spaceship *spaceship = new Spaceship(60, 140, 5, 0, 7, 7);

    while (true) {
        int keyPressed = f->GetInput();

        // Vérifier si la touche Escape est pressée
        if (keyPressed == SDLK_ESCAPE) {
            break; // Sortir de la boucle si la touche Escape est pressée
        }

        f->DrawAsteroid(asteroid->GetX(), asteroid->GetY(), asteroid->GetSize());
        asteroid->Move(1920, 1080);


        f->DrawMissile(missile->GetX(), missile->GetY());
        missile->Move(1920, 1080);

        // Déplacer le vaisseau en fonction de sa vitesse
        //spaceship->Move(1920, 1080, spaceship->GetAngle());

        // Dessiner le vaisseau
        f->DrawShip(spaceship->GetX(), spaceship->GetY(), spaceship->GetAngle(), 0, false);

        // Gérer l'accélération et la décélération en fonction des touches
        if (keyPressed == SDLK_LEFT) {
            spaceship->RotateLeft();

        } else if (keyPressed == SDLK_RIGHT) {
            spaceship->RotateRight();

        }
        if (keyPressed == SDLK_UP ) {
            spaceship->Move(1920, 1080, spaceship->GetAngle()-90);

        } else if (keyPressed == SDLK_DOWN) {
            spaceship->Move(1920, 1080, spaceship->GetAngle()+90);

        }

        // Gérer les collisions
        if (FlyingObject::Collide(*missile, *asteroid)) {
             //delete asteroid;
            // Réinitialisez les objets si nécessaire
            // asteroid = new Asteroid(100, 300, 60, 3, 3);
        }

        // Mettre à jour l'affichage
        f->Update();
    }
// Libérer la mémoire
    delete f;
    return 0;
}

 */