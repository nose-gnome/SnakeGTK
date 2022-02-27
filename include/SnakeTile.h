//
// Created by blyth on 20/02/2022.
//

#ifndef SNAKEGTK_SNAKETILE_H
#define SNAKEGTK_SNAKETILE_H
#include <Direction.h>
#include <array>

class SnakeTile {
public:
    SnakeTile(int chunkNum, SnakeTile *(*snakeTiles)[144], std::array<int,2> coordinates, int buffer=0);
    void move();
    void move(Direction direction);
    void redraw();
    int coordinates[2];
    Direction direction;
    int pcoords[2];
protected:
    int chunkNum;

private:
    SnakeTile *(*snakeTiles)[144];
    int buffer;
};


#endif //SNAKEGTK_SNAKETILE_H
