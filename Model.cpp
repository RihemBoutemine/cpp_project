// Dans Model.cpp (fichier d'implémentation)
#include "Model.hpp"
#include "asteroid.hpp"
#include "missile.hpp"
#include "spaceship.hpp"
#include "flyingobject.hpp"

// Constructeur de la classe Model
Model::Model() {
    // Initialiser les objets du modèle (vous devrez peut-être ajuster les paramètres)
    asteroid = new Asteroid(960, 540, 60, 5, 5);
    missile = new Missile(250, 150, 60, 5, 45);
    spaceship = new Spaceship(60, 140, 5, 90, 7, 7);
}

std::vector<FlyingObject*> Model::GetFlyingObjects() {
    std::vector<FlyingObject*> flyingObjects;

    flyingObjects.push_back(asteroid);
    flyingObjects.push_back(missile);
    flyingObjects.push_back(spaceship);

    return flyingObjects;
}

Model::~Model() {
    // Libérer la mémoire allouée dynamiquement
    delete asteroid;
    delete missile;
    delete spaceship;
}

/*
void FlyingObject::Move(double screenWidth, double screenHeight) {
    // Déplacer l'objet en utilisant xSpeed et ySpeed
    //x += xSpeed;
    //y += ySpeed;
}

// Méthodes pour les actions du joueur
void Asteroid::Move(double screenWidth, double screenHeight) {
    FlyingObject::Move(screenWidth, screenHeight);

    // Si l'astéroïde sort des limites de l'écran, le faire réapparaître de l'autre côté
    if (GetX() < 0) {
        SetX(screenWidth);
    } else if (GetX() > screenWidth) {
        SetX(0);
    }
    if (GetY() < 0) {
        SetY(screenHeight);
    } else if (GetY() > screenHeight) {
        SetY(0);
    }
}

void Missile::Move(double screenWidth, double screenHeight) {
    FlyingObject::Move(screenWidth, screenHeight);

    // Convertir l'angle en radians
    double angle_rad = angle * (M_PI / 180.0);

    // Calculer les nouvelles positions en utilisant la trigonométrie
    double newX = GetX() + speed * cos(angle_rad);
    double newY = GetY() + speed * sin(angle_rad);

    // Mettre à jour les nouvelles positions
    SetX(newX);
    SetY(newY);

    // Vérifier si le missile est sorti de l'écran
    if (GetX() < 0 || GetX() >= screenWidth || GetY() < 0 || GetY() >= screenHeight) {
        // Le missile est sorti de l'écran, réinitialiser sa position par exemple
        SetX(screenWidth / 2);
        SetY(screenHeight / 2);
    }
}

void Spaceship::Move(double screenWidth, double screenHeight, double angle) {
    FlyingObject::Move(screenWidth, screenHeight);
    // Convertir l'angle en radians
    double angle_rad = angle * (M_PI / 180.0);
    // Calculer les nouvelles positions en utilisant la trigonométrie
    double newX = GetX() + xSpeed * cos(angle_rad);
    double newY = GetY() + ySpeed * sin(angle_rad);

    // Mettre à jour les nouvelles positions
    SetX(newX);
    SetY(newY);
}

void Spaceship::RotateLeft() {
    angle -= 5; // Faites pivoter vers la gauche en réduisant l'angle
}

void Spaceship::RotateRight() {
    angle += 5; // Faites pivoter vers la droite en augmentant l'angle
}

bool Model::Collide(const FlyingObject& o1, const FlyingObject& o2) {
    double distance = sqrt(pow(o2.GetX() - o1.GetX(), 2) + pow(o2.GetY() - o1.GetY(), 2));
    double rayonSpheres = ((o1.GetSize()) / 2) + ((o2.GetSize()) / 2);

    if (distance < rayonSpheres) {
        return true;
    } else {
        return false;
    }
}
*/


