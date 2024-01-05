// Spaceship.cpp
#include "Spaceship.hpp"
#include "math.h"
#include <iostream>

Spaceship::Spaceship(double x, double y, double size, double angle, double xSpeed, double ySpeed)
        : FlyingObject(x, y, size, angle, xSpeed, ySpeed) {
}

double Spaceship::GetX() const {
    return x;
}

double Spaceship::GetY() const {
    return y;
}

double Spaceship::GetAngle() const {
    return angle;
}

ObjectType Spaceship::GetType() const {
    return ObjectType::Spaceship;
}

void Spaceship::Rotate(double rAngle) {
    angle += rAngle;
    std::cout << "Angle after rotating left: " << angle << std::endl;
}

void Spaceship::Move(double screenWidth, double screenHeight, double angle) {
    std::cout << "Move - Current Angle: " << angle << std::endl;

    double angle_rad = angle * (M_PI / 180.0);

    // Adjust the speed factor to control the movement speed
    double speedFactor = 0.2; // Adjust this value as needed

    // Calculate the new positions using trigonometry
    double newX = GetX() + speedFactor * xSpeed * cos(angle_rad);
    double newY = GetY() + speedFactor * ySpeed * sin(angle_rad);

    // Update the new positions
    SetX(newX);
    SetY(newY);
    std::cout << "Move" << std::endl;

    // Handle screen boundaries
    if (x >= screenWidth) {
        x = 0;
    }

    if (y >= screenHeight) {
        y = 0;
    }

    if (x < 0) {
        x = screenWidth;
    }

    if (y < 0) {
        y = screenHeight;
    }
}

void Spaceship::SpeedUp(double accelerationFactor, double angle) {
    // Convertir l'angle en radians
    double angle_rad = angle * (M_PI / 180.0);

    // Appliquer l'accélération dans la direction de l'angle spécifié
    xSpeed += accelerationFactor * cos(angle_rad);
    ySpeed += accelerationFactor * sin(angle_rad);
}

void Spaceship::SpeedDown(double decelerationFactor, double angle) {
    // Convertir l'angle en radians
    double angle_rad = angle * (M_PI / 180.0);

    // Appliquer l'accélération dans la direction de l'angle du vaisseau
    xSpeed -= decelerationFactor * cos(angle_rad);
    ySpeed -= decelerationFactor * sin(angle_rad);
}

std::string Spaceship::GetTypeName() {
    return "Spaceship";
}

bool Spaceship::isWarning() const {
    return warning;
}

float Spaceship::getShieldLevel() const {
    return shieldLevel;
}

void Spaceship::setShieldLevel(float newShieldLevel) {
    shieldLevel = newShieldLevel;
}

void Spaceship::resterInvinsible(int duration) {
    warning = true;
    time = std::chrono::steady_clock::now() + std::chrono::milliseconds(duration * 1000);
}

void Spaceship::updateinvincible() {
    if (time <= std::chrono::steady_clock::now())
        warning = false;
}
