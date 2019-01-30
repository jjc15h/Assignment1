#ifndef CRAZYRANDOMSWORD_H_INCLUDED
#define CRAZYRANDOMSWORD_H_INCLUDED

#include <string>
#include <stdlib.h>
#include "Weapon.h"
#include <time.h>
#include <cmath>

/*
NOTE: I did have to look up on the cplusplus website to figure out how to get random numbers.
Doing this I was able to figure out that I needed to include the cmath and time.h libraries.
*/

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
#endif // CRAZYRANDOMSWORD_H_INCLUDED
