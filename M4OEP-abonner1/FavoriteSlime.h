//
// Created by Aidan on 10/2/2022.
//
#include "Slime.h"
#include <string>

#ifndef M2OEP_ABONNER1_FAVORITESLIME_H
#define M2OEP_ABONNER1_FAVORITESLIME_H

using std::string;
class FavoriteSlime: public Slime {
private:
    Food favorite;

public:
    //Constructor
    FavoriteSlime(string name, string type, string foodName);
    //Alternate constructor that directly accepts a favorite food
    FavoriteSlime(string name, Food favorite);

    //Getters
    string getDiet();
    string getFavoriteName();
    Food getFavorite();

    //Setters
    void setFavorite(string type, string name);
    void setFavorite(Food favorite);

    //Feed method
    //Slimes with a favorite food will only accept food of that type
    //They will generate 1 plort when fed any food of that type, and 2 when fed their favorite
    int feed(Food meal);

};


#endif //M2OEP_ABONNER1_FAVORITESLIME_H
