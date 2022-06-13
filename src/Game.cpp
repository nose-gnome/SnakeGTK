//
// Created by blyth on 14/02/2022.
//
#include <Game.h>

Game::Game(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refGlade, MainProcess *app): Gtk::Window(cobject) {
//    this->signal_key_press_event().connect(sigc::mem_fun(*this, &Game::on_key_press));
    add_events(Gdk::KEY_PRESS_MASK);
    this->app = app;
    grid = Grid::getInstance(app);
    Glib::signal_timeout().connect(sigc::mem_fun(*this, &Game::on_timeout), 25);
//    Glib::signal_timeout(sigc::mem_fun(this, &Game::on_timeout), 1000);
}

Game *Game::getInstance(MainProcess *app) {
    Game *result;
    app->builder->get_widget_derived("Game", result, app);
    return result;
}
void Game::hide() {
    visible=false;
    this->Gtk::Window::hide();
}
bool Game::on_key_press_event(GdkEventKey *event) {
    Direction direction;
    switch (event->keyval) {
        case GDK_KEY_w:
        case GDK_KEY_W:
        case GDK_KEY_Up:
            direction = NORTH;
            break;
        case GDK_KEY_d:
        case GDK_KEY_D:
        case GDK_KEY_Right:
            direction = EAST;
            break;
        case GDK_KEY_s:
        case GDK_KEY_S:
        case GDK_KEY_Down:
            direction = SOUTH;
            break;
        case GDK_KEY_a:
        case GDK_KEY_A:
        case GDK_KEY_Left:
            direction = WEST;
            break;

        case GDK_KEY_slash:
            grid->snake->getCoords();
            return false;
            break;

        case GDK_KEY_Pause:
        case GDK_KEY_Escape:
            this->paused = !paused;
            return false;

        case GDK_KEY_Delete:
        case GDK_KEY_F3:
            this->app->gotoMainMenu();
            this->paused = true;
            return false;
//        case GDK_KEY_comma:
//            grid->eatApple();
//            return false;
//            break;

        default:
            return false;
    }

    grid->snake->setDirection(direction);
//    printf("Turned\n");
    return true;
}

void Game::show() {
    visible=true;
    this->Gtk::Window::show();
}


Game::~Game() {

}

Game::Game(_GtkWindow *pWindow, Glib::RefPtr<Gtk::Builder> refPtr) {

}

bool Game::on_timeout() {
    auto win = get_window();
    if (visible && !paused) {
        if (win) {}

        {
            Gdk::Rectangle r(0, 0, get_allocation().get_width(),
                             get_allocation().get_height());
            win->invalidate_rect(r, false);
        }

    }
    return true;
}

