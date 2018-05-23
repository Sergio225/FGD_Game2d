#include "DAOMap.h"
#include "Map.h"
#include <vector>
#include "allegro.h"
#include "Enemy.h"

using namespace std;

/**
Para declararlo desde otra interfaz sin tener que instanciarlo
*/
DAOMap::DAOMap()
{

}

/**
Rellena todas las matrices de un mapa en concreto que contendra lo siguiente:
Vector de enemigos, matriz de Ambiente, la longitud de la matriz
*/
DAOMap::DAOMap(int difficult)
{
    /*Drawable **mapAmbient;
    vector<Enemy*> firtMapEnemies;
    /**
    Fill the matrix of animations enemy
    */
    //BITMAP ***matrixAnimationsEnemy;

    switch(difficult){

        /**
        Case 1 = Dificultad Facil
        */
        case 1: this->quantEnemies = 5;
                this->quantElementsAmbient = 3;
                for(int i = 0; i < 2; i++){
                    this->mapList.push_back(new Map(this->quantEnemies, this->quantElementsAmbient, this->numMap));
                    this->numMap++;
                    this->quantEnemies+=2;
                }
                break;

                /**
        Case 2 = Dificultad Medio
        */
        case 2: this->quantEnemies = 10;
                this->quantElementsAmbient = 3;
                for(int i = 0; i < 2; i++){
                    this->mapList.push_back(new Map(this->quantEnemies, this->quantElementsAmbient, this->numMap));
                    this->numMap++;
                }
                break;

                /**
        Case 3 = Dificultad Dificil
        */
        case 3: this->quantEnemies = 15;
                this->quantElementsAmbient = 3;
                for(int i = 0; i < 2; i++){
                    this->mapList.push_back(new Map(this->quantEnemies, this->quantElementsAmbient, this->numMap));
                    this->numMap++;
                }
                break;


        default: ;
    }
}

vector<Map*> DAOMap::getMapList()
{
    return mapList;
}

Map* DAOMap::getMap(int id)
{
    return mapList.at(id);
}


///////////////////          GETTERS & SETTERS            ////////////////////////////

int DAOMap::getDifficultGame()
{
    return this->difficultGame;
}

void DAOMap::setDifficultGame(int difficult)
{
    this->difficultGame = difficult;
}

