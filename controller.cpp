#include "controller.hpp"
#include <SDL2/SDL.h>
#include "framework.hpp"
#include <iostream>

controller::controller(int screenWidth, int screenHeight, int frameRate){
    view = new View(framework);
    framework = new Framework(screenWidth, screenHeight, frameRate, 50, 30);
    model = new Model();
}

void controller::LaunchGame() {

        int keyPressed = 0;
        while (keyPressed != SDLK_ESCAPE ) {
            framework->Update();

            std::vector<FlyingObject *> flyingObjects = model->GetFlyingObjects();
            view->RefreshDisplay(flyingObjects);

            // Ensure that GetAsteroid(), GetMissile(), and GetSpaceship() return valid pointers
            if (model->GetAsteroid()) {
                model->GetAsteroid()->Move(1920, 1080);
            }

            if (model->GetMissile()) {
                model->GetMissile()->Move(1920, 1080);
            }

            if (model->GetSpaceship()) {
                if (keyPressed == SDLK_LEFT) {
                    model->GetSpaceship()->RotateLeft();
                } else if (keyPressed == SDLK_RIGHT) {
                    model->GetSpaceship()->RotateRight();
                }

                if (keyPressed == SDLK_UP) {
                    model->GetSpaceship()->Move(1920, 1080, model->GetSpaceship()->GetAngle() - 90);
                } else if (keyPressed == SDLK_DOWN) {
                    model->GetSpaceship()->Move(1920, 1080, model->GetSpaceship()->GetAngle() + 90);
                }
            }
            keyPressed = framework->GetInput();
    }
}

controller::~controller() {
    // Release resources if necessary
    delete framework;
    delete view;
    delete model;  // Don't forget to delete the Model
    // Add other cleanup operations if necessary
}

