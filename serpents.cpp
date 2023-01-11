/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : snakes.cpp
  Nom du labo : Labo 8 - Snake
  Auteur(s)   : Auberson Kevin - Surbeck Léon
  Date        : 11.01.2023
  But         :

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#include "serpents.h"

using namespace std;

Serpent::Serpent(int IDInput, int X, int Y, int pommeX, int pommeY, int valPomme) {
    ID     = IDInput;
    snake = {{X,Y}};
    this->pommeX = pommeX;
    this->pommeY = pommeY;
}

int Serpent::getSerpentID() const {
    return this->ID;
}

int Serpent::getPommeX() const {
    return this->pommeX;
}

int Serpent::getPommeY() const {
    return this->pommeY;
}

int Serpent::getCoordY() {
    return snake[0][1];
}

int Serpent::getCoordX() {
    return snake[0][0];
}

void Serpent::moveSnake(){
        if(abs(pommeX - getCoordX()) > abs(pommeY - getCoordY())){
            snake[0][0] -= 1;
        }else{
            snake[0][1] += 1;
        }

        if(abs(getCoordX() - pommeX) > abs(getCoordY() - pommeY)){
            snake[0][0] -= 1;
        }else{
            snake[0][1] += 1;
        }

}

