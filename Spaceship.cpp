// Spaceship.cpp
#include "FlyingObject.hpp"
#include "spaceship.hpp"
#include "math.h"
#include <iostream>

Spaceship::Spaceship(double x, double y, double size, double angle, double xSpeed, double ySpeed)
        : FlyingObject(x, y, size, xSpeed, ySpeed) {

}

double Spaceship::GetX() const {
    return x; // Implémentez la logique pour obtenir la coordonnée x
}

double Spaceship::GetY() const {
    return y; // Implémentez la logique pour obtenir la coordonnée y
}

ObjectType Spaceship::GetType() const {
    return ObjectType::Spaceship; // Ou utilisez la valeur appropriée pour Asteroid
}

double Spaceship::GetAngle() {
    return angle;
}

void Spaceship::SetAngle(double angle) {
    this->angle = angle;
}


void Spaceship:: Move(double screenWidth, double screenHeight, double angle) {
    // Appel de la méthode Move de la classe de base pour effectuer le déplacement
    //FlyingObject::Move(screenWidth, screenHeight);
    // Convertir l'angle en radians
    double angle_rad = angle * (M_PI / 180.0);
    // Calculer les nouvelles positions en utilisant la trigonométrie
    double x = GetX() + xSpeed * cos(angle_rad);
    double y = GetY() + ySpeed * sin(angle_rad);

    // Mettre à jour les nouvelles positions
    SetX(x);
    SetY(y);
    std::cout << "move" << std::endl;
}

void Spaceship::SpeedUp(double accelerationFactor, double angle) {
    // Convertir l'angle en radians
    double angle_rad = angle * (M_PI / 180.0);

    // Appliquer l'accélération dans la direction de l'angle spécifié
    xSpeed += accelerationFactor * cos(angle_rad);
    ySpeed += accelerationFactor * sin(angle_rad);
}


void Spaceship::SpeedDown(double decelerationFactor, double angle) {
    // Convertir l'angle en radians
    double angle_rad = angle * (M_PI / 180.0);

    // Appliquer l'accélération dans la direction de l'angle du vaisseau
    xSpeed -= decelerationFactor * cos(angle_rad);
    ySpeed -= decelerationFactor * sin(angle_rad);
}

std::string Spaceship::GetTypeName() {
    return "Spaceship";
}
// Méthode pour faire pivoter le vaisseau vers la gauche

void Spaceship::RotateLeft() {
    angle -= 40; // Faites pivoter vers la gauche en réduisant l'angle
    std::cout << "Angle after rotating left: " << angle << std::endl;
}

// Méthode pour faire pivoter le vaisseau vers la droite
void Spaceship::RotateRight() {
    angle += 5; // Faites pivoter vers la droite en augmentant l'angle
}



