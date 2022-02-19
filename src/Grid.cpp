//
// Created by blyth on 14/02/2022.
//

#include <Grid.h>


//Grid::Grid():Glib::ObjectBase("Grid"),
//prop_ustring(){
//}
Grid::Grid(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refGlade, MainProcess *app): Gtk::Grid(cobject){
    this->app = app;
//
//    for (int i=0; i<7; i++) {
////        chunks[i] = Gdk::Pixbuf::create_from_file(std::string("../assets/tiles/Tile ").append(std::to_string(i)).append(".png"));
//    }
//
    for (int i = 0; i<1; i++) {
        const int row = (int) i/12;
        const int column = i-(12*row);
        tiles[column][row] = new Tile(column, row);
//        tiles[column][row]->set_size_request(chunks[0]->get_width(), chunks[1]->get_height());
//        Gdk::Cairo::set_source_pixbuf(tiles[column][row], chunks[0], 50, 50)
//        tiles[column[]]
        this->attach(*tiles[column][row], column, row);

    }
    this->snake = new Snake(&tiles);
//    show_all_children();
////    show();
}

//bool Grid::on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {
////    Gdk::Cairo::set_source_pixbuf(cr, *chunks, 0, 0);
//
//    cr->set_source_rgb(1, 1, 1);
//    for (int i = 0; i<144; i++) {
//        const int row = (int) i/12;
//        const int column = i-(12*row);
////        tiles[column][row] = new Tile(cr, chunks, column, row, column*50, row*50);
//    }
//    cr->paint();
//    return true;
//}

Grid::~Grid() {

}

Grid *Grid::getInstance(MainProcess *app) {
    Grid *result;
    app->builder->get_widget_derived("SnakeGrid", result, app);
    return result;
}
