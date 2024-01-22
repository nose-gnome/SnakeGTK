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
    return true;

}


Direction SnakeBase::getDirection() {
    return EAST;
}

void SnakeBase::eatApple() {

}

bool SnakeBase::next_safe() {
}
