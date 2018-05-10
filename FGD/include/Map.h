#ifndef Map_h
#define Map_h
#include <allegro.h>
#include "Enemy.h"
#include "Drawable.h"
#include <vector>

using namespace std;

class Map{

 private:

    vector<Enemy*> enemies;
    Drawable **ambientMatrix;
    int sizeOfMatrix;
    /**
    Cantidad de enemigos que habra que estara asociado al nivel del juego que sea actualmente
    */
    int quantEnemies = 2;

 protected:

 public:
    Map();
    Map(vector<Enemy*> enemies, Drawable **mapMatrix, int sizeOfMatrix);
    void setAmbientMatrix(Drawable **ambientMatrix);
    vector<Enemy*> getVectorEnemies();
    Drawable **getAmbientMatrix();
    int getSizeOfMatrix();
    //virtual ~Map();



};

#endif // Map_h
