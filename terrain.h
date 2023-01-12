//
// Created by Athena on 11.01.2023.
//

#ifndef LABO_08_SNAKES_TERRAIN_H
#define LABO_08_SNAKES_TERRAIN_H

#include <vector>
#include "serpents.h"



void creationSerpents(size_t nbSerpents, int largeurTerrain, int hauteurTerrain, std::vector<Serpent>& vecSerpent);

class Terrain {

public:
    int      getLargeur()      const;
    int      getHauteur()      const;
    size_t   getnbrSerpents()  const;

private:
    int        largeur      = 200;
    int        hauteur      = 200;
    size_t     nbrSerpents  = 2;
};


#endif //LABO_08_SNAKES_TERRAIN_H
