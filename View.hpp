
#ifndef VIEW_HPP
#define VIEW_HPP

#include <vector>
#include "framework.hpp"
#include "flyingobject.hpp"
#include "Asteroid.hpp"
#include "missile.hpp"
#include "spaceship.hpp"

// Dans View.hpp
class View {
public:
    View(Framework* framework);  // Constructeur

    // Méthode pour rafraîchir l'affichage
    ~View();

    void RefreshDisplay(const std::vector<FlyingObject*>& flyingObjects);

private:
    Framework* framework; // Utilisez 'f' au lieu de 'framework'
    Asteroid* asteroid;
    Missile* missile;
    Spaceship* spaceship;
};



#endif // VIEW_HPP



