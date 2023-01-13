//
// Created by Athena on 11.01.2023.
//

#include "terrain.h"
#include "serpents.h"
#include "annexe.h"
#include <vector>
#include <iostream>
#include <algorithm>


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

void Terrain::serpentMangeSerpent(vector<Serpent>& v) {
    for (Serpent &serpent: v) {
        int teteX = serpent.getCoordX(0);
        int teteY = serpent.getCoordX(1);

        for (Serpent &serpent2: v) {
            int serpTete2X = serpent2.getCoordX(0);
            int serpTete2Y = serpent2.getCoordX(1);

            if(serpTete2X == teteX and serpTete2Y == teteY){


            }

            for (vector<int> &coords: serpent2.getSerpent()) {
                if(teteX == coords.at(0) and teteY == coords.at(1) and serpent.getSerpentID() != serpent2.getSerpentID()){
                    serpent.serpentGrow(serpent2.couperSerpent(coords.at(0),coords.at(1)));
                }

            }
        }


    }
}