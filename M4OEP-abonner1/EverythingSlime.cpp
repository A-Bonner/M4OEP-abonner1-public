//
// Created by Aidan on 10/2/2022.
//

#include "EverythingSlime.h"
#include <string>

using namespace std;
EverythingSlime::EverythingSlime(string name) : Slime(name)
{
}

int EverythingSlime::feed(Food meal)
{
    if(meal.getType() == "Unique" || meal.getType() == "Nothing" || meal.getType() == "Everything")
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
