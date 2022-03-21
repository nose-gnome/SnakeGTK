//
// Created by blyth on 20/02/2022.
//

#ifndef SNAKEGTK_SNAKETILE_H
#define SNAKEGTK_SNAKETILE_H
#include <Direction.h>
#include <array>
#include <SnakeBase.h>
#include <iostream>
#include <cmath>
#include <limits>

class SnakeTile {
public:
    SnakeTile(SnakeBase *parent, Direction direction, int chunkNum, SnakeTile *snakeTiles[144], std::array<int,2> coordinates, int buffer=0);
    void move();
    void redraw(const Cairo::RefPtr<Cairo::Context> &cr);
    int coordinates[2];
    Direction direction;
    Direction prevDirection;
    int pcoords[2];
protected:
    int chunkNum;

private:
    int getCoord();
    SnakeBase *snake;
    SnakeTile **snakeTiles;
    void changeDirection(Direction direction1);
    int buffer;
    void move(Direction direction1);
    int *mod_coord(Direction direction1);
    int *mod_coord(Direction direction1, int amount);

    const int distance = 2;
};


#endif //SNAKEGTK_SNAKETILE_H
