//
// Created by Aidan on 10/2/2022.
//
#include "Slime.h"

#ifndef M2OEP_ABONNER1_NOFAVORITESLIME_H
#define M2OEP_ABONNER1_NOFAVORITESLIME_H


class EverythingSlime: public Slime {
public:
    //Constructor
    EverythingSlime(string name);

    //feed method
    //Everything slimes will eat all non-unique-type foods, but will only ever generate 1 plort
    int feed(Food meal);
};


#endif //M2OEP_ABONNER1_NOFAVORITESLIME_H
