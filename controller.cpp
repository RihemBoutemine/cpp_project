#include "controller.hpp"
#include <SDL2/SDL.h>
#include "framework.hpp"
#include <iostream>

controller::controller(int screenWidth, int screenHeight, int frameRate){
    framework = new Framework(screenWidth, screenHeight, frameRate, 80, 30);
    view = new View(framework);
    model = new Model(70,framework);
}

void controller::LaunchGame() {

        int keyPressed = 0;
        int w = 0;
        while (keyPressed != SDLK_ESCAPE && w == 0) {
            framework->Update();
            w = model->Update();

            std::cout << "Missile Position: X = " << std::endl;
            view->RefreshDisplay(model->GetFlyingObjects());

            if (model->GetSpaceship()) {
                if (keyPressed == SDLK_LEFT) {
                    model->GetSpaceship()->Rotate(-30);//Rotate(-90); // Rotation vers la gauche
                } else if (keyPressed == SDLK_RIGHT) {
                    model->GetSpaceship()->Rotate(30); // Rotation vers la droite
                } else if (keyPressed == SDLK_UP) {
                    model->GetSpaceship()->SpeedUp(0.3,model->GetSpaceship()->GetAngle() - 90);//Move(1920, 1080, model->GetSpaceship()->GetAngle() - 90);
                } else if (keyPressed == SDLK_DOWN) {
                    model->GetSpaceship()->SpeedDown(3,model->GetSpaceship()->GetAngle() + 90); //Move(1920, 1080, model->GetSpaceship()->GetAngle() + 90);
                } else if (keyPressed == SDLK_SPACE) {
                    model->shoot();
                }
            }
            keyPressed = framework->GetInput();
        }

        if (w == 1) {
            printf("you win");
        } else if (w == -1) {
            printf("game over");
        }
}


controller::~controller() {
    delete framework;
    delete view;
    delete model;

}

