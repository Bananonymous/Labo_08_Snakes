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
    void     serpentMangeSerpent(std::vector<Serpent>& v);

private:
    int        largeur      = 200;
    int        hauteur      = 200;
    size_t     nbrSerpents  = 5;
};


#endif //LABO_08_SNAKES_TERRAIN_H
