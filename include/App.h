//
// Created by blyth on 06/02/2022.
//
#pragma once

#ifndef SNAKEGTK_APP_H
#define SNAKEGTK_APP_H

#include <iostream>
#include <gtkmm.h>
#include <MainMenu.h>
#include <MainProcess.h>

class App: public MainProcess {
public:
    explicit App();

    virtual void gotoMainMenu();
    virtual void gotoMainMenu(bool hideGame);

    virtual void gotoGame();
    virtual void gotoGame(bool hideMenu);

    static Glib::RefPtr<App> create();



//    virtual ~App();
private:

    MainMenu *mainMenu;

};


#endif //SNAKEGTK_APP_H
