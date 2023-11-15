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
    BaseGrid(BaseObjectType *cobject);
    std::array<int,2> convertCoordinates(std::array<int,2> values);
    int convertCoordinate(int value);


    virtual bool eatApple(Coordinates pos);


};



#endif //SNAKEGTK_BASEGRID_H
