//
// Created by blyth on 20/02/2022.
//

#ifndef SNAKEGTK_SNAKETILE_H
#define SNAKEGTK_SNAKETILE_H
#include <Direction.h>
#include <array>
#include <SnakeBase.h>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <Coordinates.h>

class SnakeTile {
public:
    SnakeTile(SnakeBase *parent, Direction direction, int chunkNum, SnakeTile *snakeTiles[1600], std::array<int,2> coordinates, int buffer=0);
    void move();

    void redraw(const Cairo::RefPtr<Cairo::Context> &cr);
    int coordinates[2];
    Direction direction;
    Direction prevDirection;
    int pcoords[2];
    int buffer;

protected:
    int chunkNum;

private:
    int getCoord();
    int getCoord(Direction direction1);
    SnakeTile * nextChunk;;
    SnakeBase *snake;
    SnakeTile **snakeTiles;
    void changeDirection(Direction direction1);
    void move(Direction direction1);
    Coordinates mod_coord(Direction direction1);
    Coordinates  mod_coord(Direction direction1, int amount);

    const int distance = 5;
};


#endif //SNAKEGTK_SNAKETILE_H
