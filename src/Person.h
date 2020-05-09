#ifndef PERSON_H
#define PERSON_H

#include <vector>
#include "SDL.h"
#include "GameObject.h"



class Person:public GameObject {
    public:

    Person(int grid_width, int grid_height);
    bool gotItem{false};
    private:
};
#endif