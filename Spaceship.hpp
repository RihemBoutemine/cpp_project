// Spaceship.hpp
#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include "FlyingObject.hpp"
#include <cmath>
#include <string>
#include <chrono>

class Spaceship : public FlyingObject {

protected:

    float shieldLevel=1.0;
    bool warning=false;
    std::chrono::steady_clock::time_point time;

public:
    Spaceship(double x, double y, double size, double angle, double xSpeed, double ySpeed);

    double GetX() const override;
    double GetY() const override;
    double GetAngle() const override;
    float getShieldLevel() const;
    bool isWarning() const;
    ObjectType GetType() const override;


    void SpeedUp(double accelerationFactor, double angle);
    void SpeedDown(double decelerationFactor, double angle);
    void Rotate(double rAngle);
    void Move(double screenWidth, double screenHeight, double angle);
    void setShieldLevel(float shieldLevel);
    void resterInvinsible(int duration);
    void updateinvincible();








    std::string GetTypeName() override;
};

#endif // SPACESHIP_HPP
