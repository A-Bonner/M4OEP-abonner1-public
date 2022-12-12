//
// Created by Aidan on 10/2/2022.
//

#include "UniqueDietSlime.h"
UniqueDietSlime::UniqueDietSlime(string name, string diet)  : Slime(name), diet(diet)
{
}

string UniqueDietSlime::getDiet()
{
    return diet;
}

void UniqueDietSlime::setDiet(string diet)
{
    this->diet = diet;
}

int UniqueDietSlime::feed(Food meal)
{
    if(meal.getName() == diet)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
