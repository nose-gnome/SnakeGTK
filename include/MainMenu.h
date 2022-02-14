//
// Created by blyth on 06/02/2022.
//
#pragma once

#ifndef SNAKEGTK_MAINMENU_H
#define SNAKEGTK_MAINMENU_H
#include <gtkmm.h>

#include <MainProcess.h>
#include <iostream>

class MainMenu: public Gtk::Window{
public:

    MainMenu(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade, MainProcess * app);

    static MainMenu * getInstance(MainProcess * app);

    virtual ~MainMenu();

protected:
    void playButtPress();

private:
    MainProcess *app;
    Gtk::Button * playButton;

};

#endif //SNAKEGTK_MAINMENU_H
