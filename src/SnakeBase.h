//
// Created by blyth on 27/02/2022.
//

#ifndef SNAKEGTK_SNAKEBASE_H
#define SNAKEGTK_SNAKEBASE_H


#include <cairomm/refptr.h>
#include <cairomm/context.h>
#include "Direction.h"

class SnakeBase {
public:
    SnakeBase();
    void move();

    virtual void re_draw(const Cairo::RefPtr<Cairo::Context> &cr);


    virtual bool setDirection(Direction direction);

    bool moving = true;

    virtual Direction getDirection();

    virtual bool next_safe();

    virtual ~SnakeBase();

    virtual void eatApple();

};


#endif //SNAKEGTK_SNAKEBASE_H
