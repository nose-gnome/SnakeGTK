//
// Created by blyth on 14/02/2022.
//
#pragma once

#ifndef SNAKEGTK_GAME_H
#define SNAKEGTK_GAME_H

#include <MainProcess.h>
#include <gtkmm.h>
#include <Grid.h>

class Game: public Gtk::Window {
public:
    Game(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade, MainProcess * app);

    Game(_GtkWindow *pWindow, Glib::RefPtr<Gtk::Builder> refPtr);

    static Game * getInstance(MainProcess *app);

    virtual ~Game();

private:
    Grid *grid;
    MainProcess *app;

};


#endif //SNAKEGTK_GAME_H
