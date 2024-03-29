//
// Created by blyth on 18/02/2022.
//

#include "Snake.h"

Snake::Snake(BaseGrid *grid, int startChunks, Direction direction): Snake(grid, {3,3}, startChunks, direction){

}

Snake::Snake(BaseGrid *grid, std::array<int, 2> startPos, int startChunks, Direction direction): SnakeBase() {
    this->parent = grid;
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
                coords[0]=startPos[0];
                coords[1]=startPos[1]+i;
                break;
            case WEST:
                coords[0]=startPos[0]+i;
                coords[i]=startPos[1];
        }
        occupied[i] = new SnakeTile(this, EAST, i,occupied, coords);
    }
    length = startChunks -1;
    for(int i=startChunks;i<144;i++){
        occupied[i]=nullptr;
    }

//    for()
}

void Snake::getCoords() {
//    return;
    printf("--------\n");
    for(int i=0;occupied[i]!= nullptr;i++){
        const Coordinates coords = occupied[i]->getCoordinates();
//        printf("[%d, %d]\n",div(occupied[i]->pcoords[0], 20).quot, div(occupied[i]->pcoords[1], 20).quot);
        printf("[%d, %d]\n",coords.x, coords.y);
    }

    return;
}

bool Snake::setDirection(Direction direction){
    Direction *directionPtr = getDirectPtr(direction);
//    std::cout << direction << std::endl;

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

//    int length;
    for(int i=0;occupied[i]!=nullptr;i++){
        occupied[i]->redraw(cr);
        occupied[i]->move();

//        cr->line_to(occupied[i]->pcoords[0],occupied[i]->pcoords[1]);
    }
//    for(int i=0;occupied[i]!=nullptr;i++){
//        occupied[i]->move();
//    }
    cr->stroke();
    cr->restore();
//    getCoords();
}

Snake::~Snake(){}

void Snake::grow(int size) {
    std::array<int,2> coords = {
            occupied[length]->pcoords[0],
            occupied[length]->pcoords[1]

    };
//    this->getCoords();

//    std::cout << parent->convertCoordinate(coords[0]) << ", " << parent->convertCoordinate(coords[1]) << std::endl;
    occupied[length+1] = new SnakeTile(this, occupied[length]->direction, length+1, occupied, coords, occupied[length]->buffer +2);
    length ++;
}
void Snake::shrink(int size)
{
    occupied[length] = NULL;
    length --;
}

void Snake::eatApple() {
    Coordinates coords = {
            occupied[0]->pcoords[0]/20,
            occupied[0]->pcoords[1]/20

    };
    if (this->parent->eatApple(coords)) {
        this->grow();
    }
}

bool Snake::next_safe() {
    bool safe = true;
    Coordinates coords = occupied[0]->getCoordinates();
    Direction direction = occupied[0]->direction;

    switch (direction) {
        case NORTH:
            if (coords.y<=0) {
                safe = false;
            } else {
                coords.y--;
            }
            break;
        case EAST:
            if (coords.x>=(this->parent->get_width()-1)) {
                safe = false;
            } else {
                coords.x ++;
            }
            break;
        case SOUTH:
            if (coords.y >= (this->parent->get_height()-1)) {
                safe = false;
            } else {
                coords.y++;
            }

            break;
        case WEST:
            if (coords.x<=0) {
                safe = false;
            } else {
                coords.x --;
            }

            break;
    }
    if (safe) {
        for(int i=1;occupied[i]!=nullptr;i++) {
            Coordinates coords2 = occupied[i]->getCoordinates();
            if ((coords2.x == coords.x) && (coords2.y== coords.y)) {
                safe = false;
                break;
            }
        }
    }

    moving = safe;
    return safe;
}

bool Snake::check_body() {
    return false;
}
