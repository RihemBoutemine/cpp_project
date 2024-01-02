#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "FlyingObject.hpp" // Assurez-vous d'inclure le fichier d'en-tête de FlyingObject

class Asteroid : public FlyingObject {
public:
    // Constructeur
    Asteroid(double x, double y, double size, double xSpeed, double ySpeed);
    double GetX() const override;
    double GetY() const override;
    ObjectType GetType() const override;

      // Méthodes de déplacement
    void Move(double screenWidth, double screenHeight);

};

#endif // ASTEROID_HPP
