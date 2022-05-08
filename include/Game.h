//
// Created by blyth on 14/02/2022.
//
#pragma once

#ifndef SNAKEGTK_GAME_H
#define SNAKEGTK_GAME_H

#include <MainProcess.h>
#include <gtkmm.h>
#include <Grid.h>
#include <Direction.h>

class Game: public Gtk::Window {
public:
    Game(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade, MainProcess * app);

    Game(_GtkWindow *pWindow, Glib::RefPtr<Gtk::Builder> refPtr);

    int score = 0;

    void hide();
    void show();

    static Game * getInstance(MainProcess *app);

    virtual ~Game();


private:
    bool on_key_press_event(GdkEventKey* event) override;

    bool on_timeout();
    bool visible = false;
    Grid *grid;
    MainProcess *app;

    bool paused = false;

};


#endif //SNAKEGTK_GAME_H
