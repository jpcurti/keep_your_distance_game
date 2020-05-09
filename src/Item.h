#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include "SDL.h"
#include "GameObject.h"



class Item:public GameObject {
    public:

    Item(int grid_width, int grid_height);
    void ResetPosition() override;
    bool consumed{false};
    private:
    
    
};
#endif