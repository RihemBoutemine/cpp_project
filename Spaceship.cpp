// Spaceship.cpp
#include "FlyingObject.hpp"
#include "spaceship.hpp"
#include "math.h"
#include <iostream>

Spaceship::Spaceship(double x, double y, double size, double angle, double xSpeed, double ySpeed)
        : FlyingObject(x, y, size, angle, xSpeed, ySpeed) {

}

double Spaceship::GetX() const {
    return x; // Implémentez la logique pour obtenir la coordonnée x
}

double Spaceship::GetY() const {
    return y; // Implémentez la logique pour obtenir la coordonnée y
}

double Spaceship::GetAngle() const {
    return angle;
}

ObjectType Spaceship::GetType() const {
    return ObjectType::Spaceship; // Ou utilisez la valeur appropriée pour Asteroid
}


void Spaceship::Rotate(double rAngle) {
    this->angle += rAngle;
    std::cout << "Angle after rotating left: " << angle << std::endl;
}

void Spaceship::Move(double screenWidth, double screenHeight, double angle) {

    std::cout << "Move - Current Angle: " << angle << std::endl;

    double angle_rad = angle * (M_PI / 180.0);

    // Adjust the speed factor to control the movement speed
    double speedFactor = 0.2; // Adjust this value as needed

    // Calculate the new positions using trigonometry
    double x = GetX() + speedFactor * xSpeed * cos(angle_rad);
    std::cout << "Move - cos(angle_rad): " << cos(angle_rad) << std::endl;

    double y = GetY() + speedFactor * ySpeed * sin(angle_rad);
    std::cout << "Move - sin(angle_rad): " << sin(angle_rad) << std::endl;

    // Update the new positions
    SetX(x);
    SetY(y);
    std::cout << "move" << std::endl;

    // Handle screen boundaries
    if (this->x >= screenWidth) {
        this->x = 0;
    }

    if (this->y >= screenHeight) {
        this->y = 0;
    }

    if (this->x < 0) {
        this->x = screenWidth;
    }

    if (this->y < 0) {
        this->y = screenHeight;
    }
}


void Spaceship::SpeedUp(double accelerationFactor, double angle) {
    // Convertir l'angle en radians
    double angle_rad = angle * (M_PI / 180.0);

    // Appliquer l'accélération dans la direction de l'angle spécifié
    this->xSpeed += accelerationFactor * cos(angle_rad);
    this->ySpeed += accelerationFactor * sin(angle_rad);
}


void Spaceship::SpeedDown(double decelerationFactor, double angle) {
    // Convertir l'angle en radians
    double angle_rad = angle * (M_PI / 180.0);

    // Appliquer l'accélération dans la direction de l'angle du vaisseau
    this->xSpeed -= decelerationFactor * cos(angle_rad);
    this->ySpeed -= decelerationFactor * sin(angle_rad);
}



std::string Spaceship::GetTypeName() {
    return "Spaceship";
}


bool Spaceship::isWarning() const {
    if (this->warning)
        return true;
    else
        return false;
}

float Spaceship::getShieldLevel() const {
    return shieldLevel;
}

void Spaceship::setShieldLevel(float shieldLevel) {
    Spaceship::shieldLevel = shieldLevel;
}

void Spaceship::resterInvinsible(int duration) {
    this->warning = true;
    this->time = std::chrono::steady_clock::now() + std::chrono::milliseconds(duration * 1000);
}

void Spaceship::updateinvincible() {
    if (this->time <= std::chrono::steady_clock::now())
        this->warning = false;
}








