//
// Created by Aidan on 10/2/2022.
//
#include <iostream>
#include <string>

#ifndef M2OEP_ABONNER1_FOOD_H
#define M2OEP_ABONNER1_FOOD_H

using std::ostream, std::string;
class Food {
protected:
    string type;
    string name;

public:
    //Constructor
    Food(string type, string name);

    //Getters
    string getType();
    string getName();

    //Setters
    void setType(string type);
    void setName(string name);

    //Overload << operator to print type: name
    friend ostream& operator << (ostream& outs, const Food& meal);
    //Overload == operator to check that both the type and name of the two foods are the same
    friend bool operator == (const Food& meal, const Food& mealComp);

};


#endif //M2OEP_ABONNER1_FOOD_H
