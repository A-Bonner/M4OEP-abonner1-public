//
// Created by Aidan on 10/2/2022.
//
#include "Slime.h"

#ifndef M2OEP_ABONNER1_UNIQUEDIETSLIME_H
#define M2OEP_ABONNER1_UNIQUEDIETSLIME_H


class UniqueDietSlime: public Slime {
private:
    string diet;

public:
    //Constructor
    UniqueDietSlime(string name, string diet);

    //Getter
    string getDiet();

    //Setter
    void setDiet(string diet);

    //Feed method
    //Slimes with unique diets will only eat a specific, unique food
    //They will only generate one plort when fed that food
    int feed(Food meal);
};


#endif //M2OEP_ABONNER1_UNIQUEDIETSLIME_H
