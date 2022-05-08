//
// Created by blyth on 06/02/2022.
//

#include "../include/App.h"
App::App() {
//    this->mainMenu = MainMenu::getInstance(this);
//    this->game = Game::getInstance(this);
    gotoMainMenu(false);
    run(*mainMenu);
//    this->mainMenu->show();
}

void App::gotoMainMenu() {gotoMainMenu(true);}
void App::gotoMainMenu(bool hideGame) {
    this->mainMenu = MainMenu::getInstance(this);
    if(hideGame){
        this->hold();
        this->game->hide();
        this->remove_window(*mainMenu);
        this->add_window(*mainMenu);
        this->release();
    }
    this->mainMenu->show();

}

void App::gotoGame() {gotoGame(true);}
void App::gotoGame(bool hideMenu) {
    this->game = Game::getInstance(this);


    if(hideMenu){
        this->hold();
        this->mainMenu->hide();
        this->remove_window(*game);
        delete mainMenu;
        this->add_window(*game);
        release();
    }
    this->game->show();


}

Glib::RefPtr<App> App::create() {
    return Glib::RefPtr<App>(new App());
}
