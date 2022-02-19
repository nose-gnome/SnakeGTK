//
// Created by blyth on 07/02/2022.
//

#include <MainProcess.h>
#include <gtkmm.h>
#include <iostream>

MainProcess::MainProcess(): Gtk::Application("uk.co.nosegnome.games.gtksnake", Gio::ApplicationFlags::APPLICATION_FLAGS_NONE){
//    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("../forms/SnakeGTK.glade");
    this->hold();
    builder = Gtk::Builder::create();
    builder->add_from_file("../forms/SnakeGTK.glade");
}

void MainProcess::gotoMainMenu() {

}

void MainProcess::gotoMainMenu(bool hideGame) {

}

void MainProcess::gotoGame() {

}

void MainProcess::gotoGame(bool hideMenu) {

}

Glib::RefPtr<MainProcess> MainProcess::create() {
    return Glib::RefPtr<MainProcess>(new MainProcess());
}


