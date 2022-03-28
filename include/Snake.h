//
// Created by blyth on 18/02/2022.
//


#ifndef SNAKEGTK_SNAKE_H
#define SNAKEGTK_SNAKE_H
#include <Tile.h>
#include <iostream>
#include <Direction.h>
#include <iostream>
#include <SnakeTile.h>
#include <SnakeBase.h>

class Snake: public SnakeBase {
public:
    Snake(int startChunks=4, Direction direction=EAST);
    Snake(std::array<int, 2> startPos, int startChunks=4, Direction direction=EAST);
    void move();
    void re_draw(const Cairo::RefPtr<Cairo::Context> &cr);

    SnakeTile *occupied[144];
    int (*head)[2];
    int (*tail)[2];

    bool setDirection(Direction direction);
    Direction getDirection();

    void getCoords();

    virtual ~Snake();
protected:

private:
    Direction *getDirectPtr(Direction direction);
    Direction directions[4] = {NORTH, EAST, SOUTH, WEST};
    Direction *facing[2];
    Direction *lastDirection;
    static int  * get_array();
//    Snake(Direction direction, const int startPos[2], int startChunks);
    int state;
    Tile *(*tiles)[12][12];
};


#endif //SNAKEGTK_SNAKE_H
