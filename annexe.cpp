/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : annexe.cpp
  Nom du labo : Labo 8 - Snake
  Auteur(s)   : Auberson Kevin - Surbeck Léon
  Date        : 11.01.2023
  But         : Déclaration de la fonction aléatoire sur une range définit avec le min et le max
                et la fonction entrée utilisateur qui va obliger l'utilisateur à entrée des données conformes

  Remarque(s) : -

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#include "annexe.h"
#include <random>
#include <iostream>


using namespace std;

int aleatoire(int valMax, int valMin) {
    random_device rd;
    uniform_int_distribution d(valMin, valMax);

    return d(rd);
}

void cleanCin() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Valeur incorrecte, merci d'entrer une valeur correcte : " << endl;
}

int entreeUser(int valMin, int valMax) {
    int val;
    bool erreur;

    do {
        cout << "Veuillez entrer une valeur comprise entre : " << valMin << " et : " << valMax << " : ";
        cin >> val;

        if (val > valMax or val < valMin or cin.fail()) {
            cout << "Erreur, vous avez entre une valeur incorrecte" << endl;
            cleanCin();
            erreur = true;
        } else
            erreur = false;
    } while (erreur);
    return val;
}