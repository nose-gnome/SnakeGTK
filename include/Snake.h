//
// Created by blyth on 18/02/2022.
//

#ifndef SNAKEGTK_SNAKE_H
#define SNAKEGTK_SNAKE_H
#include <Tile.h>
#include <iostream>

class Snake {
public:
    Snake(Tile *(*tiles)[12][12]);

protected:

private:
    Tile *(*tiles)[12][12];
};


#endif //SNAKEGTK_SNAKE_H
