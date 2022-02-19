//
// Created by blyth on 18/02/2022.
//

#include "Snake.h"

Snake::Snake(Tile *(*tiles)[12][12]) {
    this->tiles = tiles;
//    for (int x=0;x<12;x++){
//        for (int y=0;y<12;y++) {
//            this->tiles = &tiles[12][12]
//        }
//    }
    std::cout << tiles << std::endl;
}
