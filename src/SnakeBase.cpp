//
// Created by blyth on 27/02/2022.
//

#include "SnakeBase.h"


SnakeBase::~SnakeBase() {

}

SnakeBase::SnakeBase() {

}

void SnakeBase::move() {

}

void SnakeBase::re_draw(const Cairo::RefPtr <Cairo::Context> &cr) {

}

bool SnakeBase::setDirection(Direction direction) {

}


Direction SnakeBase::getDirection() {
    return EAST;
}