//
// Created by blyth on 07/02/2022.
//

#ifndef SNAKEGTK_MAINPROCESS_H
#define SNAKEGTK_MAINPROCESS_H
#include <gtkmm.h>

class MainProcess: public Gtk::Application {
protected:
    MainProcess();
public:
    static Glib::RefPtr<MainProcess> create();


    void gotoMainMenu();
    void gotoMainMenu(bool hideGame);

    void gotoGame();
    void gotoGame(bool hideMenu);

    Glib::RefPtr<Gtk::Builder> builder;

protected:
    // Ovveride default signal handlers
//    void on_activate() override;
//    void on_open(const Gio::Application::type_vec_files& files,
//                 const Glib::ustring& hint) override;

private:

//    void on_hide_window(Gtk::Window* window);
};


#endif //SNAKEGTK_MAINPROCESS_H
