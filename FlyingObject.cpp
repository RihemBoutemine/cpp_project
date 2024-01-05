#include "FlyingObject.hpp"
#include <cmath>

FlyingObject::FlyingObject(double x, double y, double size, double xSpeed, double ySpeed, double angle) {
    this->x = x;
    this->y = y;
    this->size = size;
    this->xSpeed = xSpeed;
    this->ySpeed = ySpeed;
    this->angle = angle;
}

double FlyingObject::GetX() {
    return x;
}

double FlyingObject::GetY() {
    return y;
}

double FlyingObject::GetAngle(){
    return angle;
}

double FlyingObject::GetXSpeed() {
    return xSpeed;
}

double FlyingObject::GetYSpeed() {
    return ySpeed;
}

double FlyingObject::GetSize() const {
    return size;
}

void FlyingObject::SetX(double x) {
    this->x = x;
}

void FlyingObject::SetY(double y) {
    this->y = y;
}

void FlyingObject::SetXSpeed(double xSpeed) {
    this->xSpeed = xSpeed;
}

void FlyingObject::SetYSpeed(double ySpeed) {
    this->ySpeed = ySpeed;
}

void FlyingObject::SetSize(double size) {
    this->size = size;
}


// Méthode de déplacement avec réentrée
void FlyingObject::Move(double screenWidth, double screenHeight) {
    // Déplacer l'objet en utilisant xSpeed et ySpeed
    x += xSpeed;
    y += ySpeed;
}

std::string FlyingObject::GetTypeName() {
    return {};
}


bool Collide(const FlyingObject& o1, const FlyingObject& o2) {
    double distance = sqrt(pow(o2.GetX() - o1.GetX(), 2) + pow(o2.GetY() - o1.GetY(), 2));
    double rayonSpheres = ((o1.GetSize()) / 2) + ((o2.GetSize()) / 2);

    if (distance < rayonSpheres) {
        return true;
    } else {
        return false;
    }

}

