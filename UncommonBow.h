#ifndef UNCOMMONBOW_H_INCLUDED
#define UNCOMMONBOW_H_INCLUDED

#include <string>
#include <time.h>
#include <cmath>
#include "Weapon.h"

class UncommonBow : public Weapon {
public:

    UncommonBow() : Weapon("UncommonBow",40.0) //Calls Weapon(name, hit points) constructor with values Simple Hammer and 25
    {
    }

    virtual ~UncommonBow() {};

    virtual double hit(double armor)    // Couldn't get the .cpp file for the hammer to work for some reason so it's defined here.
    {
        return hitchance(armor);
    };


    virtual double hitchance(double armor)
    {
        srand(time(NULL));
        double RandomNum = rand() % 4;

        if (RandomNum == 0) //25% chance to miss and deal 0 damage
            return 0;
        else if (RandomNum == 1 || RandomNum == 2) // 50% chance to graze
        {
            if (armor > 35)         //if it grazes and the armor is greater than 35 then it will hit for 25% of damage
                return (40*.25);
            else                    //if it grazes and the armor is less than 35 then it will hit or 50% of  damage
                return (40*.50);
        }
        else                        // 25% chance to pierce and hit for 80% of damage
            return (40*.80);

    }

};


#endif // UNCOMMONBOW_H_INCLUDED
