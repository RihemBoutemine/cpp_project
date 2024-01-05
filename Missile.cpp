#include "FlyingObject.hpp"
#include "missile.hpp"
#include <math.h>

// Constructeur de la classe Missile
Missile::Missile(double x, double y, double size, double speed, double angle)
        : FlyingObject(x, y, size, 0, 0, angle), speed(speed){

    this->xSpeed=speed * cos((M_PI * angle) / 180);
    this->ySpeed=speed * sin((M_PI * angle) / 180);

}
double Missile::GetX() const {
    return x; // Implémentez la logique pour obtenir la coordonnée x
}

double Missile::GetY() const {
    return y; // Implémentez la logique pour obtenir la coordonnée y
}

ObjectType Missile::GetType() const {
    return ObjectType::Missile; // Ou utilisez la valeur appropriée pour Asteroid
}

// Getters
double Missile::GetSpeed() {
    return speed;
}

double Missile::GetAngle() const {
    return angle;
}

// Setters
void Missile::SetSpeed(double speed) {
    this->speed = speed;
}

void Missile::SetAngle(double angle) {
    this->angle = angle;
}


bool Missile::Move(double screenWidth, double screenHeight) {
    if (this->x >= screenWidth || this->x <= 0 || this->y >= screenHeight || this->y <= 0) {
        return true;
    } else {
        double angleRad = (M_PI * angle) / 180;

        double new_xspeed= this->xSpeed+ cos(angleRad);
        double new_yspeed= this->ySpeed+ sin(angleRad);
        this->x+=new_xspeed;
        this->y+=new_yspeed;
        return false;
    }
}

std::string Missile::GetTypeName() {
    return "Missile";
}
