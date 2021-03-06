#ifndef Weapon_h
#define Weapon_h

#include "Object.h"
#include <allegro.h>


class Weapon : public Object {


    protected:
        int attackDistance;
        int damage;
    public:
        Weapon();

    Weapon(int attackDistance, int damage, BITMAP *imageOfObject, int width, int height);

    void setAttackDistance(int attackDistance);

    int getDamage();

    void setDamage(int damage);

    int getAttackDistance();

};

#endif // Weapon_h
