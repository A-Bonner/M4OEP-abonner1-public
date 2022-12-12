//
// Created by Aidan on 10/2/2022.
//
#include "Food.h"
#include <string>

#ifndef M2OEP_ABONNER1_SLIME_H
#define M2OEP_ABONNER1_SLIME_H

using std::string;
class Slime {
protected:
    string name;
public:
    //Constructor
    Slime(string name);

    //Getter
    string getName();

    //Setter
    void setName(string name);

    //Virtual method tht returns 0 if the meal given is not in the Slime's diet, 1 if it is, and 2 if it is the Slime's favorite food
    virtual int feed(Food meal) = 0;


};


#endif //M2OEP_ABONNER1_SLIME_H
