//
// Created by blyth on 06/02/2022.
//

#include "../include/MainMenu.h"

MainMenu::MainMenu(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refGlade, MainProcess * app)
        : Gtk::Window(cobject) {
    this->app = app;
    app->builder->get_widget<Gtk::Button>("play", playButton);
//    app->builder->get_widget("play", this->playButton);
//    this->playButton->signal_clicked().connect(MainMenu::playButtPress(this));

//    this->playButton = app->builder->get_object("play");
    playButton->signal_clicked().connect(sigc::mem_fun(this, &MainMenu::playButtPress));

}

void MainMenu::playButtPress() {
//    app->gotoGame();
}

MainMenu *MainMenu::getInstance(MainProcess * app) {
    std::cout << "In instance" << std::endl;
    MainMenu * result;

    app->builder->get_widget_derived("Main Menu", result, app);
//    auto window = Gtk::Builder::get_widget_derived<MainMenu>(app->builder, "Main Menu")
//     pDialog = Gtk::Builder::get_widget_derived<DerivedDialog>(builder, "DialogDerived");

    return result;
}

MainMenu::~MainMenu() {

}
