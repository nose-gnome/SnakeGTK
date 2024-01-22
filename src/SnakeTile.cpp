//
// Created by blyth on 20/02/2022.
//


#include "SnakeTile.h"

SnakeTile::SnakeTile(SnakeBase *parent, Direction direction, int chunkNum, SnakeTile *snakeTiles[144], std::array<int,2> coordinates, int buffer) {
    snake = parent;
    if (chunkNum >0)nextChunk=*(snakeTiles+(chunkNum-1));
    this->chunkNum = chunkNum;
    this->direction =direction;
    this->prevDirection = direction;
    this->snakeTiles = snakeTiles;
    this->buffer = buffer;
    if (this->buffer >0){
        for (int i=0; i<2; i++){
            this->coordinates[i] = coordinates[i] /20;
            this->pcoords[i] = coordinates[i];
        }
        switch (direction) {
            case NORTH:
                pcoords[1] +=10;
                break;
            case SOUTH:
                pcoords[1] -=10;
                break;
            case EAST:
                pcoords[0] -=10;
                break;
            case WEST:
                pcoords[0] +=10;
                break;
        }
    } else {
        for (int i = 0; i < 2; i++) {
            this->coordinates[i] = coordinates[i];
            this->pcoords[i] = (coordinates[i] * 20);

        }
        this->pcoords[1] -=10;


    }

}

void SnakeTile::move() {
    double fractional = div(pcoords[getCoord()], 20).rem;
    bool do_move = true;
//    float decCoord = (float) pcoords[getCoord()] /20;
//    fractional = std::modf(decCoord, &whole);
    if (chunkNum>0) {
        if  (!this->snake->moving) {
            return;
        }

        if (fractional == 10 ) {
//                if ((nextChunk->prevDirection == direction)) {
//                }
            changeDirection((Direction)nextChunk->prevDirection);
            const int check = 3;
            if (chunkNum >= check){
                //printf("here\n");
            }
            if(prevDirection!=direction){
                //printf("\n");
            }

        }
        if(buffer>0){
//            this->coordinates[0] = (*snakeTiles[chunkNum - 1])->coordinates[0];
//            this->coordinates[1] = (*snakeTiles[chunkNum - 1])->coordinates[1];
            buffer --;

        } else {
//            if ((fractional == 0.5) && (getCoord() == nextChunk->getCoord()) && ()) changeDirection(nextChunk->direction);
//            if (fractional == 0.4) changeDirection(nextChunk->direction);


            move(this->direction);

        }
    } else {
        if (fractional == 10){
            this->snake->eatApple();
            changeDirection(this->snake->getDirection());
            if (!this->snake->next_safe()){
                do_move=false;
            }

        }

        //            std::cout << fractional << std::endl;
        if (do_move) {
            move(this->direction);
        }
    }
}

void SnakeTile::changeDirection(Direction direction1) {
//    float decCoord = (float) pcoords[getCoord()] /20;

    this->prevDirection = this->direction;
    //printf("%d\n", div(pcoords[getCoord()], 20).rem);
    this->direction = direction1;
}

int SnakeTile::getCoord() {
    return getCoord(direction);
}
int SnakeTile::getCoord(Direction direction1){
    int out;
    switch(direction1){
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
    const Coordinates new_val = mod_coord(direction1);
    pcoords[0] = new_val.x;
    pcoords[1] = new_val.y;
}

Coordinates SnakeTile::mod_coord(Direction direction1){
    return mod_coord(direction1, this->distance);
}

Coordinates SnakeTile::mod_coord(Direction direction1, int amount) {

    Coordinates out = {pcoords[0], pcoords[1]};
    switch (direction1){
        case NORTH:
            out.y = pcoords[1] - amount;
            break;
        case EAST:
            out.x = pcoords[0] + amount;
            break;
        case SOUTH:
            out.y = pcoords[1] + amount;
            break;
        case WEST:
            out.x = pcoords[0] - amount;
    }
    return out;
}

void SnakeTile::redraw(const Cairo::RefPtr<Cairo::Context> &cr) {
//    if (chunkNum == 0){
//        //printf("here\n");
//    }

//    double whole, fractional;
//    double decCoord =(double) pcoords[getCoord()] /20;
//    fractional = std::modf(decCoord, &whole);
    int fractional = div(pcoords[pcoords[getCoord()]], 20).rem;
    cr->line_to(pcoords[0],pcoords[1]);
    if ((direction != prevDirection)) {
//        cr->line_to((int) (pcoords[0] / 20 * 20), (int) (pcoords[1] / 20) * 20);
    }

//        int whole[2] = {(int)(float) pcoords[0]/20, (int)(float) pcoords[1]/20, };
//        float whole[2], fractional[2];
//        fractional[0] = std::modf((float) pcoords[0] /20, &whole[0]);
//        fractional[1] = std::modf((float) pcoords[1] /20, &whole[1]);


//    }
//    const int *mod = mod_coord(direction, -19);
//    std::cout << *mod << "|" << *(mod+1) << std::endl;
//    cr->line_to(*mod, *(mod+1));
}

Coordinates SnakeTile::getCoordinates()
{
    return {div(pcoords[0], 20).quot, div(pcoords[1], 20).quot};
}
