//
// Created by blyth on 18/02/2022.
//

#include "Snake.h"

Snake::Snake(int startChunks, Direction direction): Snake({4,6}, startChunks, direction){

}
Snake::Snake(std::array<int, 2> startPos, int startChunks, Direction direction) {
    this->facing=direction;
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
        occupied[i] = new SnakeTile(i,(&occupied), coords);
    }

//    for()
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
    const int size = sizeof(occupied)/sizeof(occupied[0]);
    cr->set_source_rgb(0,1,0);
    cr->set_line_width(15);
    int length;
    for(int i=1;i<size;i++){
        if(occupied[i]== nullptr){
            length = i-1;
            break;
        }
        cr->line_to(occupied[i]->pcoords[0],occupied[i]->pcoords[1]);
    }
    for(int i=length;i>-1;i--){
        occupied[i]->move();
    }
    cr->stroke();
    cr->restore();
}
