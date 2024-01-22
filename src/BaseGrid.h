//
// Created by blyth on 30/03/2022.
//

#ifndef SNAKEGTK_BASEGRID_H
#define SNAKEGTK_BASEGRID_H


#include <gtkmm/drawingarea.h>
#include <gtkmm/builder.h>
#include "MainProcess.h"
#include "Apple.h"

class BaseGrid: public Gtk::DrawingArea {
//    BaseGrid(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refGlade, MainProcess *app);
public:
    BaseGrid(BaseObjectType *cobject, unsigned short width=40, unsigned short height=40, unsigned short gap=20);
    std::array<int,2> convertCoordinates(std::array<int,2> values);
    int convertCoordinate(int value);

    unsigned short get_width();
    unsigned short get_height();


    virtual bool eatApple(Coordinates pos);

protected:

    unsigned short width;
    unsigned short height;
    unsigned short max_xpixels;
    unsigned short max_ypixels;
    unsigned short gap;


};



#endif //SNAKEGTK_BASEGRID_H
