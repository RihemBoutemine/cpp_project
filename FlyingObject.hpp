#ifndef FLYINGOBJECT_HPP
#define FLYINGOBJECT_HPP

#include <cmath>
#include <string>

enum class ObjectType {
    Asteroid,
    Missile,
    Spaceship
};
class FlyingObject {
public:
    // Constructeur
    FlyingObject(double x, double y, double size, double xSpeed, double ySpeed);
    virtual ~FlyingObject() = default;
    virtual double GetX() const = 0;
    virtual double GetY() const = 0;
    virtual ObjectType GetType() const = 0;

    // Getters
    double GetX();
    double GetY();
    double GetXSpeed();
    double GetYSpeed();
    double GetSize() const;
    double GetAngle();

    // Setters
    void SetX(double x);
    void SetY(double y);
    void SetXSpeed(double xSpeed);
    void SetYSpeed(double ySpeed);
    void SetSize(double size);
    void SetAngle(double Angle);


    // Méthodes de déplacement
    void Move(double screenWidth, double screenHeight);
    bool Collide(const FlyingObject& o1, const FlyingObject& o2);
    virtual std::string GetTypeName();

protected:
    double x;
    double y;
    double size;
    double xSpeed;
    double ySpeed;
    double Angle;
};

// Définition de la fonction Collide en dehors de la classe (comme inline)
inline bool FlyingObject::Collide(const FlyingObject& o1, const FlyingObject& o2) {
    double distance = sqrt(pow(o2.GetX() - o1.GetX(), 2) + pow(o2.GetY() - o1.GetY(), 2));
    double rayonSpheres = ((o1.GetSize()) / 2) + ((o2.GetSize()) / 2);

    if (distance < rayonSpheres) {
        return true;
    } else {
        return false;
    }
}
#endif // SDLTEST_FLYINGOBJECT_HPP


