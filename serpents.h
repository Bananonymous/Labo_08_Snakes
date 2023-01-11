/*
 -------------------------------------------------------------------------------------------------------------------
  Fichier     : snakes.h
  Nom du labo : Labo 8 - Snake
  Auteur(s)   : Auberson Kevin - Surbeck Léon
  Date        : 11.01.2023
  But         :

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
 -------------------------------------------------------------------------------------------------------------------
*/

#ifndef LABO_08_SNAKES_SERPENTS_H
#define LABO_08_SNAKES_SERPENTS_H


#include <vector>

class Serpent {
public:
    Serpent          (int IDInput, int X, int Y, int pommeX, int pommeY, int valPomme);
    int  getPommeX()      const;
    int  getPommeY()      const;
    int  getSerpentID()   const;
    int  getCoordX();
    int  getCoordY();
    void moveSnake();

private:
    int  ID;
    int  pommeX;
    int  pommeY;
    int  valPomme;
    std::vector<std::vector<int>> snake;

};


#endif //LABO_08_SNAKES_SERPENTS_H
