#include "Enemy.h"
#include <allegro.h>
#include <Drawable.h>
#include <Sword.h>
#include <iostream>
#include "Timer.h"

Enemy::Enemy(){}

Enemy::Enemy(BITMAP ***animations, int health, int damage, double speed, int shield, int x, int y, int height, int width):
            Character(animations, health, damage, speed, shield, x, y, height, width) {
    genWalkCollision();
    this->collisionRadius = 15;
    this->detectionRadius = 150;

}

Enemy::~Enemy()
{
    for(int i = 0; i < 12; i++){
        for (int j = 0; j < 4; j++){
            delete this->animations[i][j];
        }
        delete this->animations[i];
    }
    delete[] this->animations;
}

void Enemy::update()
{
/*
Se podria hacer un switch pero no lo hago por tema de que quiero mirar el rollo de "estado" de un NPC al crearlo
*/

    /**
    Randomiza una direccion del 0 al 3
    0 = UP
    1 = RIGHT
    2 = DOWN
    3 = LEFT
    */
    if(this->timeNextRandomize % 200 == 0){
        this->direction = rand()%4;
    }


    /**
    Posiciones anteriores por tema colisiones
    */
    int ax = this->x;
    int ay = this->y;

    if(this->direction == 0)
    {
        this->walkUP();
    }
    if(this->direction == 1)
    {
        this->walkRIGHT();
    }
    if(this->direction == 2)
    {
        this->walkDOWN();
    }
    if(this->direction == 3)
    {
        this->walkLEFT();
    }
    // TODO CAMBIAR A FUNCION
    if ( this->x < 0 ){ this->x = ax; this->changeDirectionIfCol = true;}
    if ( this->x+this->width > 800 ) {this->x = ax; this->changeDirectionIfCol = true;}
    if ( this->y < 0 ) {this->y = ay; this->changeDirectionIfCol = true;}
    if ( this->y+this->height > 600 ) {this->y = ay; this->changeDirectionIfCol = true;}

    if(this->changeDirectionIfCol)
    {
        this->direction = rand()%4;
        this->changeDirectionIfCol = false;
    }

    this->timeNextRandomize++;

}

void Enemy::genWalkCollision() {
    this->walkCollision[0] = 39;
    this->walkCollision[1] = 49;
}

bool Enemy::detectionRadiusEnemy(Drawable *drawable)
{
    //Si es menor esta dentro del radio
    if (distance(drawable) < (this->detectionRadius) ){
        return true;
    }
    return false;
}

void Enemy::setDirectionEnemy(int direction)
{
    this->direction = direction;
}

Weapon *Enemy::randomizeDrop() {
    Weapon *object = 0;
    //randomize object
    //rand()%4;
    //int objectType = rand()%4;//
    int objectType = 0;
    switch (objectType){
        case 0://sword
            int damage = (rand()%50)+50;
            int attackDistance = (rand()%40)+20;
            BITMAP *imageOfObject = load_bitmap("src\\Resources\\Inventory\\sword.bmp",NULL);
            Weapon *newSword = new Weapon(attackDistance, damage,imageOfObject, 46,40);
            object = newSword;
            break;
    }

    return object;
}

int Enemy::getDetectionRadius() {
    return detectionRadius;
}

void Enemy::setDetectionRadius(int detectionRadius) {
    Enemy::detectionRadius = detectionRadius;
}

void Enemy::dieAnim(){
    activeBitmap[0] = direction + 8;
    if (Timer::getTime()-10 > timeLastAnim) {
        timeLastAnim = Timer::getTime();
        if (activeBitmap[1] < 3) {
            activeBitmap[1]++;
        }
    }
}
