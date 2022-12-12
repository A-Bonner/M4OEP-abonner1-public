//
// Created by Aidan on 10/2/2022.
//

#include "Food.h"

using namespace std;
Food::Food(string type, string name)
{
    this->type = type;
    this->name = name;
}

string Food::getType()
{
    return type;
}

string Food::getName()
{
    return name;
}

void Food::setType(string type)
{
    this->type = type;
}

void Food::setName(string name)
{
    this->name = name;
}

ostream& operator << (ostream& outs, const Food& meal)
{
    outs << meal.type + ": " + meal.name << endl;
    return outs;
}

bool operator == (const Food& meal, const Food& mealComp)
{
    return (meal.type == mealComp.type && meal.name == mealComp.name);
}