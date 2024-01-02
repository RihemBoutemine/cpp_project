// Model.hpp
#ifndef MODEL_HPP
#define MODEL_HPP

#include "flyingobject.hpp"
#include "asteroid.hpp"
#include "missile.hpp"
#include "spaceship.hpp"
#include <vector>

class Model {
public:
    Model();  // Constructeur
    ~Model();
/*
    // Méthodes pour les actions du joueur
    void AsteroidMove(double screenWidth, double screenHeight);
    void MissileMove(double screenWidth, double screenHeight);
    void SpaceshipMove(double screenWidth, double screenHeight, double angle);
    void SpaceshipRotateLeft();
    void SpaceshipRotateRight();
    void FlyingObjectMove();

    // Méthode de collision statique
    static bool Collide(const FlyingObject& o1, const FlyingObject& o2);
*/

// Méthode pour obtenir les objets volants actuellement en jeu
    std::vector<FlyingObject*> GetFlyingObjects();
public:
    Asteroid* GetAsteroid() const { return asteroid; }
    Missile* GetMissile() const { return missile; }
    Spaceship* GetSpaceship() const { return spaceship; }

private:
    Asteroid* asteroid;
    Missile* missile;
    Spaceship* spaceship;
    // Ajoutez d'autres attributs si nécessaire
};

#endif // MODEL_HPP
