// Model.hpp
#ifndef MODEL_HPP
#define MODEL_HPP

#include "flyingobject.hpp"
#include "Asteroid.hpp"
#include "missile.hpp"
#include "spaceship.hpp"
#include <vector>
#include "framework.hpp"

class Model {
public:
    Model(int asteroidSize, Framework *framework);  // Constructeur
    ~Model();
// Méthode pour obtenir les objets volants actuellement en jeu
    std::vector<FlyingObject*> GetFlyingObjects();
    Asteroid* GetAsteroid() const { return asteroid; }
    Missile* GetMissile() const { return missile; }
    Spaceship* GetSpaceship() const;
    void shoot();
    int Update();



private:
    Asteroid* asteroid;
    Missile* missile;
    Spaceship* spaceship;
    Framework* framework;
    std::vector<Missile*> missiles;
    std::vector<Asteroid*> asteroids;
    // Ajoutez d'autres attributs si nécessaire
};

#endif // MODEL_HPP
