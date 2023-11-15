//
// Created by blyth on 06/02/2022.
//

#include "App.h"
App::App() {
    this->mainMenu = MainMenu::getInstance(this);
    this->game = Game::getInstance(this);
    gotoMainMenu(false);
    run(*mainMenu);
//    this->mainMenu->show();
}

void App::gotoMainMenu() {gotoMainMenu(true);}
void App::gotoMainMenu(bool hideGame) {
    if(hideGame){
        this->hold();
        this->game->hide();
        this->remove_window(*game);
        this->add_window(*mainMenu);
        this->release();
    }
    this->mainMenu->show();

}

void App::gotoGame() {gotoGame(true);}
void App::gotoGame(bool hideMenu) {


    if(hideMenu){
        this->hold();
        this->mainMenu->hide();
        this->remove_window(*mainMenu);
        delete mainMenu;
        this->add_window(*game);
        release();
    }
    this->game->show();


}

Glib::RefPtr<App> App::create() {
    return Glib::RefPtr<App>(new App());
}
