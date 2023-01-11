#include <iostream>
#include <cstdlib>
#include <SDL.h>
#include "UI.h"
#include "terrain.h"
#include "serpents.h"

using namespace std;

int main(int argc, char* argv[]) {
    // Ces arguments sont nécessaire au bon fonctionnement de SDL sur Windows,
    // grâce aux 2 lignes suivantes les warning sont ignorés
    (void)argc;
    (void)argv;


//    int SCREEN_WIDTH  = entreeUser(50, 1200);
//    int SCREEN_HEIGTH = entreeUser(50, 800);
//    int NBRE_VALUES   = entreeUser(2 , 1000);
    int SCREEN_WIDTH  = 500;
    int SCREEN_HEIGTH = 400;
    int NBRE_VALUES   = 40;
    const int SDL_DELAY = 100;

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Event event;
    bool appIsRunning = true;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGTH, SDL_WINDOW_SHOWN, &window, &renderer);
    if (window == nullptr or renderer == nullptr) {
        cout << "SDL not ready ... quitting" << endl;
    }
    SDL_RenderSetScale(renderer, (float) SCREEN_WIDTH / (float) NBRE_VALUES,
                       (float) SCREEN_HEIGTH / (float) NBRE_VALUES);



    Terrain terrain;

    int largeurTerrain  = terrain.getLargeur();
    int hauteurTerrain  = terrain.getHauteur();

    size_t nbSerpents   = terrain.getnbrSerpents();

    vector<Serpent> vecSerpent;

    creationSerpents(nbSerpents,largeurTerrain,hauteurTerrain,vecSerpent);

    while (appIsRunning) {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) {
            appIsRunning = false;
            break;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);


        for (Serpent serpent : vecSerpent){
            {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawLine(renderer, serpent.getCoordX(), serpent.getCoordY(), 100, 100);

                SDL_RenderPresent(renderer);
                SDL_Delay(SDL_DELAY);
                }

        }

        appIsRunning = false;
    }


    cout << "press ENTER to quit ...";
    cin.ignore();

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return EXIT_SUCCESS;
}