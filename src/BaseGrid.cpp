//
// Created by blyth on 30/03/2022.
//

#include "BaseGrid.h"
//BaseGrid::BaseGrid(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refGlade, MainProcess *app): Gtk::DrawingArea(cobject) {
//
//}

BaseGrid::BaseGrid(BaseObjectType *cobject, unsigned short width, unsigned short height, unsigned short gap): Gtk::DrawingArea(cobject) {
    this->width = width;
    this->height = height;
    this->gap = gap;
    this->max_xpixels = width*gap;
    this->max_ypixels = height*gap;
}

bool BaseGrid::eatApple(Coordinates pos) {return false;}
std::array<int, 2> BaseGrid::convertCoordinates(std::array<int, 2> values)
{
    return {convertCoordinate(values[0]), convertCoordinate(values[1])};
}

int BaseGrid::convertCoordinate(int value)
{
    return div(value, 20).quot;
}

unsigned short BaseGrid::get_width() {
    return this->width;
}

unsigned short BaseGrid::get_height() {
    return this->height;
}

