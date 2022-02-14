//
// Created by blyth on 14/02/2022.
//
#include <Game.h>

Game::Game(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refGlade, MainProcess *app) {
    this->app = app;

}

Game *Game::getInstance(MainProcess *app) {
    Game *result;
    app->builder->get_widget_derived("Game", result, app);
    return result;
}
