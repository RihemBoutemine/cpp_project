#include "FlyingObject.hpp"
#include "missile.hpp"
#include <math.h>

// Constructeur de la classe Missile
Missile::Missile(double x, double y, double size, double speed, double angle)
        : FlyingObject(x, y, size, 0, 0), speed(speed), angle(angle) {
    this->speed = speed;
    this->angle = angle;
    // Aucun besoin d'initialiser manuellement les attributs x, y, size, xSpeed et ySpeed, car ils sont déjà initialisés dans la classe de base FlyingObject
}
double Missile::GetX() const {
    return x; // Implémentez la logique pour obtenir la coordonnée x
}

double Missile::GetY() const {
    return y; // Implémentez la logique pour obtenir la coordonnée y
}

ObjectType Missile::GetType() const {
    return ObjectType::Missile; // Ou utilisez la valeur appropriée pour Asteroid
}

// Getters
double Missile::GetSpeed() {
    return speed;
}

double Missile::GetAngle() {
    return angle;
}

// Setters
void Missile::SetSpeed(double speed) {
    this->speed = speed;
}

void Missile::SetAngle(double angle) {
    this->angle = angle;
}


// Méthode de déplacement
void Missile::Move(double screenWidth, double screenHeight) {
    // Appel de la méthode Move de la classe de base pour effectuer le déplacement
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

std::string Missile::GetTypeName() {
    return "Missile";
}
