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
#include "annexe.h"
#include <algorithm>
#include <iostream>

using namespace std;

Serpent::Serpent(int IDInput, int X, int Y, int pommeX, int pommeY, int valPomme) {
    ID     = IDInput;
    serpent.resize(10,{X, Y});
    this->pommeX = pommeX;
    this->pommeY = pommeY;
    this->valPomme = valPomme;
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

int Serpent::getCoordY(size_t i) {
    std::cout << serpent[5][1] << endl;
    return serpent[i][1];
}

int Serpent::getCoordX(size_t i) {
    return serpent[i][0];
}

bool Serpent::pommeTrouvee(){
    if(pommeX == getCoordX(0) and pommeY == getCoordY(0)){
        surPomme = true;
        size_t taille = serpent.size();
        serpent.resize(taille+valPomme, serpent.back());


    }
    return surPomme;
}

void Serpent::newPomme(int newPommeX,int newPommeY, int newPommeVal){
    pommeX   = newPommeX;
    pommeY   = newPommeY;
    valPomme = newPommeVal;
    surPomme = false;
}

vector<vector<int>> Serpent::getSerpent() {
    return serpent;
}

void Serpent::deplacerSerpent(){

    if(abs(pommeX - getCoordX(0)) > abs(pommeY - getCoordY(0))){
        vector<int> temp;

        temp = serpent.front();

        shift_right(serpent.begin(), serpent.end(),1);

        serpent.front() = temp;

        if(pommeX > getCoordX(0))
            serpent.front()[0] += 1;
        else
            serpent.front()[0] -= 1;
    }else{
        if(pommeY > getCoordY(0))
            serpent.front()[1] += 1;
        else
            serpent.front()[1] -= 1;
    }

}






