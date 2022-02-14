//
// Created by blyth on 06/02/2022.
//

#include "../include/App.h"
App::App() {
    this->mainMenu = MainMenu::getInstance(this);

    run(*mainMenu);
//    this->mainMenu->show();
}

void App::gotoMainMenu() {gotoMainMenu(true);}
void App::gotoMainMenu(bool hideGame) {
    this->mainMenu->show();
    if(hideGame){

    }
}

void App::gotoGame() {gotoGame(true);}
void App::gotoGame(bool hideMenu) {

}

Glib::RefPtr<App> App::create() {
    return Glib::RefPtr<App>(new App());
}
