#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "FlyingObject.hpp" // Assurez-vous d'inclure le fichier d'en-tête de FlyingObject

class Asteroid : public FlyingObject {
public:
    // Constructeur
    Asteroid(double x, double y, double size, double xSpeed, double ySpeed, double angle);
    double GetX() const override;
    double GetY() const override;
    double GetAngle() const;
    ObjectType GetType() const override;
    std::string GetTypeName() override;

      // Méthodes de déplacement
    void Move(double screenWidth, double screenHeight);

};

#endif // ASTEROID_HPP
