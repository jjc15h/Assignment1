#ifndef CRAZYRANDOMSWORD_H_INCLUDED
#define CRAZYRANDOMSWORD_H_INCLUDED

#include <string>
#include <stdlib.h>
#include "Weapon.h"
#include <time.h>
#include <cmath>
class CrazyRandomSword : public Weapon {
public:

    CrazyRandomSword() : Weapon("CrazyRandomSword",RANDOMHIT()) //Calls Weapon(name, hitpoints) constructor with values Common Sword and 50.0
    {
    }

    virtual ~CrazyRandomSword() {};

    virtual double hit(double armor)
    {
        double damage = hitPoints - (RANDOMARMOR(armor));
        if (damage < 0) {
            return 0;
        }
        return damage;
    };

    virtual double RANDOMARMOR (double armor)   // picks a random number between 2 and a third of the armor to negate
    {
        srand(time(NULL));
        double RandomNum;
        int MaxArmourNegation = ceil(armor * .33);

        RandomNum = rand() % MaxArmourNegation + 2;

        return RandomNum;
    }

    virtual int RANDOMHIT() //Function gives a random hit value between 7 and 100
    {
        srand(time(NULL));
        int RandomNum = rand() % 93 +7;

        return RandomNum;
    }

};
// Got cmath and Cieling from c++ website
#endif // CRAZYRANDOMSWORD_H_INCLUDED
