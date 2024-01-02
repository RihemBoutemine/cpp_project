// Spaceship.hpp
#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include "FlyingObject.hpp"

class Spaceship : public FlyingObject {
private:
    double angle;

public:
    Spaceship(double x, double y, double size, double angle, double xSpeed, double ySpeed);

    double GetX() const override;
    double GetY() const override;
    ObjectType GetType() const override;
    double GetAngle();
    void SetAngle(double angle);
    void SpeedUp(double accelerationFactor, double angle);
    void SpeedDown(double decelerationFactor, double angle);
    void Move(double screenWidth, double screenHeight, double angle);
    void RotateLeft();
    void RotateRight();
};

#endif // SPACESHIP_HPP
