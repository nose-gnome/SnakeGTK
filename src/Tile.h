//
// Created by blyth on 16/02/2022.
//

#ifndef SNAKEGTK_TILE_H
#define SNAKEGTK_TILE_H
#include <gtkmm/drawingarea.h>
#include <gtkmm/builder.h>
#include <cairo.h>

class Tile {
public:
    Tile(Cairo::RefPtr<Cairo::Context>& cr, int x, int y);

    int x;
    int y;


    void swapTile(int tile);
protected:
//    virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
private:
    Cairo::RefPtr<Cairo::Context> cr;
    int locX;int locY;
//    const Glib::RefPtr<Gdk::Pixbuf> *chunks;

//    Glib::RefPtr<Gdk::Pixbuf> get_chunk(int chunk);


};


#endif //SNAKEGTK_TILE_H
