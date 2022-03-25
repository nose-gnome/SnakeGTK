//
// Created by blyth on 20/02/2022.
//


#include "SnakeTile.h"

SnakeTile::SnakeTile(SnakeBase *parent, Direction direction, int chunkNum, SnakeTile *snakeTiles[144], std::array<int,2> coordinates, int buffer) {
    snake = parent;
    this->chunkNum = chunkNum;
    this->direction =direction;
    this->prevDirection = direction;
    this->snakeTiles = snakeTiles;
    this->buffer = buffer;
    for(int i=0; i < 2; i++){
        this->coordinates[i] = coordinates[i];
        this->pcoords[i] = (coordinates[i] * 20);
    }
    pcoords[1] -=10;
}

void SnakeTile::move() {
    float whole, fractional;
    float decCoord = (float) pcoords[getCoord()] /20;
    fractional = std::modf(decCoord, &whole);
    if (chunkNum>0) {
        if(buffer>0){
//            this->coordinates[0] = (*snakeTiles[chunkNum - 1])->coordinates[0];
//            this->coordinates[1] = (*snakeTiles[chunkNum - 1])->coordinates[1];
            buffer --;

        } else {

            if (fractional == 0.5) {
                const int index = chunkNum-1;
                SnakeTile *nextChunk = *(snakeTiles+index);

                if (nextChunk->direction != direction) {
                    changeDirection(nextChunk->direction);
                }
            }

            move(this->direction);

        }
    } else {
        if (fractional == 0.5){
            changeDirection(this->snake->getDirection());

        }
//            std::cout << fractional << std::endl;
        move(this->direction);
    }
}

void SnakeTile::changeDirection(Direction direction1) {
    this->prevDirection = this->direction;
    this->direction = direction1;
}

int SnakeTile::getCoord(){
    int out;
    switch(direction){
        case EAST:
        case WEST:
            out = 0;break;
        case NORTH:
        case SOUTH:
            out=1;break;
    }
    return out;
}

void SnakeTile::move(Direction direction1) {
    const int *new_val = mod_coord(direction1);
    pcoords[0] = *new_val;
    pcoords[1] = *(new_val+1);
}

int *SnakeTile::mod_coord(Direction direction1){
    return mod_coord(direction1, this->distance);
}

int *SnakeTile::mod_coord(Direction direction1, int amount) {
    static int out[2] = {pcoords[0], pcoords[1]};
    switch (direction1){
        case NORTH:
            out[1] = pcoords[1] - amount;
            break;
        case EAST:
            out[0] = pcoords[0] + amount;
            break;
        case SOUTH:
            out[1] = pcoords[1] + amount;
            break;
        case WEST:
            out[0] = pcoords[0] - amount;
    }
    return out;
}

void SnakeTile::redraw(const Cairo::RefPtr<Cairo::Context> &cr) {
    cr->line_to(pcoords[0],pcoords[1]);
    if (direction != prevDirection)cr->line_to((int) (pcoords[0]/20*20),(int) (pcoords[0]/20)*20);
//        int whole[2] = {(int)(float) pcoords[0]/20, (int)(float) pcoords[1]/20, };
//        float whole[2], fractional[2];
//        fractional[0] = std::modf((float) pcoords[0] /20, &whole[0]);
//        fractional[1] = std::modf((float) pcoords[1] /20, &whole[1]);


//    }
//    const int *mod = mod_coord(direction, -19);
//    std::cout << *mod << "|" << *(mod+1) << std::endl;
//    cr->line_to(*mod, *(mod+1));
}
