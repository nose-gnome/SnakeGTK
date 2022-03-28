//
// Created by blyth on 18/02/2022.
//

#include "Snake.h"

Snake::Snake(int startChunks, Direction direction): Snake({4,6}, startChunks, direction){

}

Snake::Snake(std::array<int, 2> startPos, int startChunks, Direction direction): SnakeBase() {
    this->facing[0]=getDirectPtr(direction);this->facing[1]=nullptr;
    lastDirection=NULL;
    for(int i=0;i<startChunks;i++){
//        int coords[2];
        std::array<int,2> coords;
        switch(direction) {
            case NORTH:
                coords[0] = startPos[0];
                coords[1] = startPos[1]-i;
                break;
            case EAST:
                coords[0] = startPos[0] - i;
                coords[1]=startPos[1];
                break;
            case SOUTH:
                coords[0]=startPos[0];coords[1]=startPos[1]+i;
                break;
            case WEST:
                coords[0]=startPos[0]+1;coords[i]=startPos[1];
        }
        occupied[i] = new SnakeTile(this, EAST, i,occupied, coords);
    }
    for(int i=startChunks;i<144;i++){
        occupied[i]=nullptr;
    }

//    for()
}

void Snake::getCoords() {
//    return;
    printf("--------\n");
    for(int i=0;occupied[i]!= nullptr;i++){
        printf("[%d, %d]\n",div(occupied[i]->pcoords[0], 20).quot, div(occupied[i]->pcoords[1], 20).quot);
    }

    return;
}

bool Snake::setDirection(Direction direction){
    Direction *directionPtr = getDirectPtr(direction);
    std::cout << direction << std::endl;

    if ((this->lastDirection == directionPtr) || (this->lastDirection == getDirectPtr((Direction)((int)direction*-1)))) {
        return false;
    } else if (this->facing[0] == nullptr){
        facing[0]=getDirectPtr(direction);
        return true;
    }
    else{
        this->facing[1] = getDirectPtr(direction);
        return true;
    }
}

Direction Snake::getDirection() {
    if (facing[0] == nullptr){
        return *lastDirection;
    } else {
        Direction* out = facing[0];
        facing[0]=facing[1];
        facing[1]=nullptr;
        lastDirection = out;
        return *out;
    }
}

Direction * Snake::getDirectPtr(Direction direction) {
    int out;
    switch(direction){
        case NORTH:
            out = 0;break;
//            return (Direction *) directions[0];
        case EAST:
            out = 1;break;
//            return (Direction *) directions[1];
        case SOUTH:
            out = 2;break;
//            return (Direction *) directions[2];
        case WEST:
            out = 3;break;
//            return (Direction *) directions[3];
    }
    return directions+out;
    


}

//
//int *Snake::get_array() {
//    const int ray[2] = {3,6};
//    return const_cast<int *>(ray);
//}

void Snake::re_draw(const Cairo::RefPtr<Cairo::Context> &cr) {
    cr->save();
//    const int size = *(&occupied+1)-occupied-1;
    cr->move_to(occupied[0]->pcoords[0],occupied[0]->pcoords[1]);
//    const int size = sizeof(occupied)/sizeof(occupied[0]);
    cr->set_source_rgb(0,1,0);
    cr->set_line_width(15);
    int length;
    for(int i=0;occupied[i]!=nullptr;i++){
        if(occupied[i]== nullptr){
            length = i-1;
            break;
        }
        occupied[i]->redraw(cr);
//        cr->line_to(occupied[i]->pcoords[0],occupied[i]->pcoords[1]);
    }
    for(int i=0;occupied[i]!=nullptr;i++){
        occupied[i]->move();
    }
    cr->stroke();
    cr->restore();
//    getCoords();
}

Snake::~Snake(){}
