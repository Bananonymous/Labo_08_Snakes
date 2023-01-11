//
// Created by Athena on 11.01.2023.
//

#include "annexe.h"
#include <random>
#include <iostream>


using namespace std;

int aleatoire(int valMin, int valMax){
    random_device rd;
    uniform_int_distribution d(valMin, valMax);

    return d(rd);
}

void cleanCin(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Value incorrect, please enter a correct one : " << endl;
}

int entreeUser(int valMin, int valMax){
    int val;
    bool erreur;

    do {
        cout << "Veuillez entrer une valeur comprise entre : " << valMin << " et : " << valMax << " : ";
        cin >> val;
        if(val > valMax or val < valMin or cin.fail()){
            cout << "Erreur, vous avez entre une valeur incorrecte" << endl;
            cleanCin();
            erreur=true;
        }
        else
            erreur=false;
    }while(erreur);
    return val;
}