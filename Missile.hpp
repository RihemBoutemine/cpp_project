// Missile.hpp
#ifndef MISSILE_HPP
#define MISSILE_HPP

#include "FlyingObject.hpp"

class Missile : public FlyingObject {
public:
    // Constructeur
    Missile(double x, double y, double size, double speed, double angle);


    double GetX() const override;
    double GetY() const override;
    ObjectType GetType() const override;
    double GetAngle() const ;
    double GetSpeed();
    void SetAngle(double angle);
    void SetSpeed(double speed);
    std::string GetTypeName() override;

    // Méthodes de déplacement
    bool Move(double width, double height);

private:
    double angle;
    double speed;
};

#endif // MISSILE_HPP
