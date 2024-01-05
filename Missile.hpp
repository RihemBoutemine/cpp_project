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
    double GetAngle() const ;
    double GetSpeed();
    ObjectType GetType() const override;
    bool Move(double width, double height);



    std::string GetTypeName() override;

private:
    double angle;
    double speed;
};

#endif // MISSILE_HPP
