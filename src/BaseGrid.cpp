//
// Created by blyth on 30/03/2022.
//

#include "BaseGrid.h"
//BaseGrid::BaseGrid(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refGlade, MainProcess *app): Gtk::DrawingArea(cobject) {
//
//}

BaseGrid::BaseGrid(BaseObjectType *cobject): Gtk::DrawingArea(cobject) {

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

