//
// Created by Aidan on 10/2/2022.
//

#include "FavoriteSlime.h"
#include "Food.h"
#include <string>

using namespace std;

FavoriteSlime::FavoriteSlime(string name, string type, string foodName) : Slime(name), favorite(type, name)
{
}

FavoriteSlime::FavoriteSlime(string name, Food favorite) : Slime(name), favorite(favorite)
{
}

string FavoriteSlime::getDiet()
{
    return favorite.getType();
}
string FavoriteSlime::getFavoriteName()
{
    return favorite.getName();
}
Food FavoriteSlime::getFavorite()
{
    return favorite;
}

void FavoriteSlime::setFavorite(string type, string name)
{
    favorite = Food(type, name);
}
void FavoriteSlime::setFavorite(Food favorite)
{
    this->favorite = favorite;
}

int FavoriteSlime::feed(Food meal)
{
    if(meal == favorite)
    {
        return 2;
    }
    else if(meal.getType() == favorite.getType())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}