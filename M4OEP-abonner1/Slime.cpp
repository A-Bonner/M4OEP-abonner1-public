//
// Created by Aidan on 10/2/2022.
//

#include "Slime.h"
#include <string>

using namespace std;
Slime::Slime(string name)
{
    this->name = name;
}

string Slime::getName()
{
    return name;
}

void Slime::setName(string name)
{
    this->name = name;
}