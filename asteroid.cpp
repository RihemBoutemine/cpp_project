// Dans le fichier Asteroid.cpp

#include "FlyingObject.hpp"
#include "Asteroid.hpp"


// Constructeur de la classe Asteroid
Asteroid::Asteroid(double x, double y, double size, double xSpeed, double ySpeed)
        : FlyingObject(x, y, size, xSpeed, ySpeed) {

}

double Asteroid::GetX() const {
    return x; // Implémentez la logique pour obtenir la coordonnée x
}

double Asteroid::GetY() const {
    return y; // Implémentez la logique pour obtenir la coordonnée y
}

ObjectType Asteroid::GetType() const {
    return ObjectType::Asteroid; // Ou utilisez la valeur appropriée pour Asteroid
}

// Redéfinition de la méthode Move pour gérer la réentrée
void Asteroid::Move(double screenWidth, double screenHeight) {
    // Appel de la méthode Move de la classe de base pour effectuer le déplacement
    FlyingObject::Move(screenWidth, screenHeight);

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
