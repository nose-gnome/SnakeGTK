//
// Created by blyth on 06/02/2022.
//

#include "../include/App.h"
App::App() {
    this->mainMenu = MainMenu::getInstance(this);
    this->game = Game::getInstance(this);

    run(*mainMenu);
//    this->mainMenu->show();
}

void App::gotoMainMenu() {gotoMainMenu(true);}
void App::gotoMainMenu(bool hideGame) {
    this->mainMenu->show();
    if(hideGame){
        this->game->hide();
    }
}

void App::gotoGame() {gotoGame(true);}
void App::gotoGame(bool hideMenu) {

    if(hideMenu){
        this->mainMenu->hide();
    }
    this->game->show();
}

Glib::RefPtr<App> App::create() {
    return Glib::RefPtr<App>(new App());
}
