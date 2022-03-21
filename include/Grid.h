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

#include <array>
//#include <Tile.h>
#include <Snake.h>

class Grid: public Gtk::DrawingArea {
public:
//    Grid();
    Grid(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refGlade, MainProcess *app);
    static Grid* getInstance(MainProcess *app);

    void changeState();


    ~Grid();
    Snake *snake;
protected:

//    Tile chunks[7];
    virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);

private:
    Tile * tiles[12][12];
    MainProcess *app;

    void draw_grid(const Cairo::RefPtr<Cairo::Context>& cr);

};

#endif //SNAKEGTK_GRID_H
