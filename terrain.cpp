//
// Created by Athena on 11.01.2023.
//

#include "terrain.h"
#include "serpents.h"
#include "annexe.h"
#include <vector>
#include <iostream>


using namespace std;

int Terrain::getHauteur() const {
    return hauteur;
}

int Terrain::getLargeur() const {
    return largeur;
}

size_t Terrain::getnbrSerpents() const {
    return nbrSerpents;
}



void creationSerpents(const size_t nbSerpents, const int largeurTerrain, const int hauteurTerrain, std::vector<Serpent>& vecSerpent){
    bool found = false;
    for (size_t i = 0; i < (nbSerpents); ++i) {
        int valPomme   = aleatoire(1, 10);
        int randX      = aleatoire(1, largeurTerrain);
        int randY      = aleatoire(1, hauteurTerrain);
        int randPommeX = aleatoire(1, largeurTerrain);
        int randPommeY = aleatoire(1, hauteurTerrain);

        if(i == 0)
            vecSerpent.emplace_back(int(i), randX, randY, randPommeX, randPommeY, valPomme);
        else {
            for (Serpent& serpent: vecSerpent) {
                if (serpent.getCoordX(0) == randX and serpent.getCoordY(0) == randY) {
                    i--;
                    found = true;
                }
            }
            if(!found)
                vecSerpent.emplace_back(int(i), randX, randY, randPommeX, randPommeY, valPomme);
            else
                found=false;
        }
    }
}