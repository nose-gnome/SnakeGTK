//
// Created by blyth on 14/02/2022.
//

#pragma once

#ifndef SNAKEGTK_GRID_H
#define SNAKEGTK_GRID_H


#include <MainProcess.h>
#include <gdkmm/general.h>
#include <glibmm/fileutils.h>
#include <cairomm/context.h>
#include <giomm/resource.h>

#include <iostream>
#include <Tile.h>
#include <Snake.h>

class Grid: public Gtk::Grid {
public:
//    Grid();
    Grid(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refGlade, MainProcess *app);
    static Grid* getInstance(MainProcess *app);

    void changeState();

    ~Grid();

protected:
    Snake *snake;
//    Tile chunks[7];
//    virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);

private:
    Tile * tiles[12][12];
    MainProcess *app;

};

#endif //SNAKEGTK_GRID_H
