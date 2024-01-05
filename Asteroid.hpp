// Asteroid.hpp
#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "FlyingObject.hpp"

class Asteroid : public FlyingObject {
public:
    // Constructeur
    Asteroid(double x, double y, double size, double xSpeed, double ySpeed, double angle);

    // Méthodes d'accès
    double GetX() const override;
    double GetY() const override;
    double GetAngle() const;
    ObjectType GetType() const override;
    std::string GetTypeName() override;
    void Move(double screenWidth, double screenHeight);
};

#endif // ASTEROID_HPP
