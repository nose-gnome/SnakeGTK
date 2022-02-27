//
// Created by blyth on 20/02/2022.
//


#include "SnakeTile.h"

SnakeTile::SnakeTile(int chunkNum, SnakeTile *(*snakeTiles)[144], std::array<int,2> coordinates, int buffer) {
    this->chunkNum = chunkNum;
    this->snakeTiles = snakeTiles;
    this->buffer = buffer;
    for(int i=0; i < 2; i++){
        this->coordinates[i] = coordinates[i];
        this->pcoords[i] = (coordinates[i] * 20);
    }
    pcoords[1] -=10;
}

void SnakeTile::move() {
    if (chunkNum>0) {
        if(buffer>0){
//            this->coordinates[0] = (*snakeTiles[chunkNum - 1])->coordinates[0];
//            this->coordinates[1] = (*snakeTiles[chunkNum - 1])->coordinates[1];
            buffer --;

        } else {
            pcoords[0] += 1;
        }
    } else {
        pcoords[0] += 1;
    }
}
void SnakeTile::redraw() {

}