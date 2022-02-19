//
// Created by blyth on 14/02/2022.
//
#include <Game.h>

Game::Game(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refGlade, MainProcess *app): Gtk::Window(cobject) {
    this->app = app;
    grid = Grid::getInstance(app);


}

Game *Game::getInstance(MainProcess *app) {
    Game *result;
    app->builder->get_widget_derived("Game", result, app);
    return result;
}

Game::~Game() {

}

Game::Game(_GtkWindow *pWindow, Glib::RefPtr<Gtk::Builder> refPtr) {

}
