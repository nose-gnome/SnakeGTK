//
// Created by blyth on 14/02/2022.
//

#pragma once

#ifndef SNAKEGTK_GRID_H
#define SNAKEGTK_GRID_H


#include "MainProcess.h"
#include <gdkmm/general.h>
#include <glibmm/fileutils.h>
#include <cairomm/context.h>
#include <giomm/resource.h>
#include <stdlib.h>
#include "Coordinates.h"

#include <array>
//#include <Tile.h>
#include "Snake.h"
#include "BaseGrid.h"
#include "Apple.h"


class Grid: public BaseGrid {
public:
//    Grid();
    Grid(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refGlade, MainProcess *app, unsigned short width=40, unsigned short height=40, unsigned short gap=20);
    static Grid* getInstance(MainProcess *app);

    void changeState();
    bool eatApple(Coordinates pos);

    ~Grid();
    Snake *snake;
protected:

//    Tile chunks[7];
    Apple apple;
    virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);

private:
    void draw_apple(const Cairo::RefPtr<Cairo::Context>& cr);
    Tile * tiles[12][12];
    MainProcess *app;


    void draw_grid(const Cairo::RefPtr<Cairo::Context>& cr);
    void generateApple();


};

#endif //SNAKEGTK_GRID_H
