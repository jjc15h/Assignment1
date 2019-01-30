#include <string>
#include "Weapon.h"

#ifndef SIMPLEHAMMER_H_INCLUDED
#define SIMPLEHAMMER_H_INCLUDED


class SimpleHammer : public Weapon {
public:

    SimpleHammer() : Weapon("SimpleHammer",25.0) //Calls Weapon(name, hit points) constructor with values Simple Hammer and 25
    {
    }

    virtual ~SimpleHammer() {};

    virtual double hit(double armor)    // Couldn't get the .cpp file for the hammer to work for some reason so it's defined here.
    {
        double damage = 0;
        if (armor < 30)    //If armor is less than 30 then the weapons hits as if there was no armor
            damage = hitPoints;
        else
        {
            damage = hitPoints - (armor - 29);  // If the armor is above 29 then it subtracts 1 hit point from every armor number above 29.
        }

        if(damage < 0)
            return 0;

        return damage;
    };

};

#endif // SIMPLEHAMMER_H_INCLUDED
