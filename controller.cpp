#include "controller.hpp"
#include <SDL2/SDL.h>
#include "framework.hpp"
#include <iostream>

controller::controller(int screenWidth, int screenHeight, int frameRate){
    framework = new Framework(screenWidth, screenHeight, frameRate, 50, 30);
    view = new View(framework);
    model = new Model(framework);
}

void controller::LaunchGame() {

        int keyPressed = 0;
        int w = 0;
        while (keyPressed != SDLK_ESCAPE && w == 0) {
            framework->Update();
            w = model->Update();

            std::cout << "Missile Position: X = " << std::endl;
            view->RefreshDisplay(model->GetFlyingObjects());

            // Ensure that GetAsteroid(), GetMissile(), and GetSpaceship() return valid pointers
            /*if (model->GetAsteroid()) {
                model->GetAsteroid()->Move(1920, 1080);
            }

            if (model->GetMissile()) {
                model->GetMissile()->Move(1920, 1080);
            }*/

            if (model->GetSpaceship()) {
                if (keyPressed == SDLK_LEFT) {
                    model->GetSpaceship()->RotateLeft();
                } else if (keyPressed == SDLK_RIGHT) {
                    model->GetSpaceship()->RotateRight();
                } else if (keyPressed == SDLK_UP) {
                    model->GetSpaceship()->Move(1920, 1080, model->GetSpaceship()->GetAngle() - 90);
                } else if (keyPressed == SDLK_DOWN) {
                    model->GetSpaceship()->Move(1920, 1080, model->GetSpaceship()->GetAngle() + 90);
                }
            }
            keyPressed = framework->GetInput();
    }
}

controller::~controller() {
    delete framework;
    delete view;
    delete model;

}

