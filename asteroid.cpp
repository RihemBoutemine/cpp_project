// Dans le fichier Asteroid.cpp

#include "FlyingObject.hpp"
#include "Asteroid.hpp"


// Constructeur de la classe Asteroid
Asteroid::Asteroid(double x, double y, double size, double xSpeed, double ySpeed, double angle)
        : FlyingObject(x, y, size, xSpeed, ySpeed, angle) {

}

double Asteroid::GetX() const {
    return x; // Implémentez la logique pour obtenir la coordonnée x
}

double Asteroid::GetY() const {
    return y; // Implémentez la logique pour obtenir la coordonnée y
}

double Asteroid::GetAngle() const {
    return angle;
}

ObjectType Asteroid::GetType() const {
    return ObjectType::Asteroid; // Ou utilisez la valeur appropriée pour Asteroid
}

// Redéfinition de la méthode Move pour gérer la réentrée
void Asteroid::Move(double screenWidth, double screenHeight) {

    double angleRad = (M_PI * angle) / 180;

    double new_xspeed= xSpeed+ cos(angleRad);
    double new_yspeed= ySpeed+ sin(angleRad);
    x+=new_xspeed;
    y+=new_yspeed;


    // Si l'astéroïde sort des limites de l'écran, le faire réapparaître de l'autre côté
    if (x < 0) {
        x = screenWidth;
    } else if (x > screenWidth) {
        x = 0;
    }
    if (y < 0) {
        y = screenHeight;
    } else if (y > screenHeight) {
        y = 0;
    }
}

std::string Asteroid::GetTypeName() {
    return "Asteroid";
}
