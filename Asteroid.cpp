// Asteroid.cpp
#include "Asteroid.hpp"

Asteroid::Asteroid(double x, double y, double size, double xSpeed, double ySpeed, double angle)
        : FlyingObject(x, y, size, xSpeed, ySpeed, angle) {
}

double Asteroid::GetX() const {
    return x;
}

double Asteroid::GetY() const {
    return y;
}

double Asteroid::GetAngle() const {
    return angle;
}

ObjectType Asteroid::GetType() const {
    return ObjectType::Asteroid;
}

void Asteroid::Move(double screenWidth, double screenHeight) {
    double angleRad = (M_PI * angle) / 180;

    // Calcul des nouvelles vitesses en fonction de l'angle
    double new_xspeed = xSpeed + cos(angleRad);
    double new_yspeed = ySpeed + sin(angleRad);

    // Mise à jour des positions en fonction des nouvelles vitesses
    x += new_xspeed;
    y += new_yspeed;

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
