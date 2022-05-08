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
#include <Game.h>

class App: public MainProcess {
public:
    explicit App();

    void gotoMainMenu() override;
    void gotoMainMenu(bool hideGame) override;

    void gotoGame() override;
    void gotoGame(bool hideMenu) override;

    static Glib::RefPtr<App> create();



//    virtual ~App();
private:
    Game *game;
    MainMenu *mainMenu;

};


#endif //SNAKEGTK_APP_H
