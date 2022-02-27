//
// Created by blyth on 14/02/2022.
//

#include <Grid.h>


//Grid::Grid():Glib::ObjectBase("Grid"),
//prop_ustring(){
//}
Grid::Grid(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refGlade, MainProcess *app): Gtk::DrawingArea(cobject){
    this->app = app;
    this->snake = new Snake();
//
//    for (int i=0; i<7; i++) {
////        chunks[i] = Gdk::Pixbuf::create_from_file(std::string("../assets/tiles/Tile ").append(std::to_string(i)).append(".png"));
//    }
//
//    for (int i = 0; i<1; i++) {
//        const int row = (int) i/12;
//        const int column = i-(12*row);
//        tiles[column][row] = new Tile(column, row);
////        tiles[column][row]->set_size_request(chunks[0]->get_width(), chunks[1]->get_height());
////        Gdk::Cairo::set_source_pixbuf(tiles[column][row], chunks[0], 50, 50)
////        tiles[column[]]
//        this->attach(*tiles[column][row], column, row);

//    }
//    this->snake = new Snake(&tiles);
//    show_all_children();
////    show();
}

bool Grid::on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {
//    Gdk::Cairo::set_source_pixbuf(cr, *chunks, 0, 0);
//    std::cout << "drawn" << std::endl;
    draw_grid(cr);
    snake->re_draw(cr);

//    for (int i = 0; i<144; i++) {
//        const int row = (int) i/12;
//        const int column = i-(12*row);*
//        tiles[column][row] = new Tile(cr, column, row, column*50, row*50);
//    }


//    cr->stroke();
    return true;
}

void Grid::draw_grid(const Cairo::RefPtr<Cairo::Context>& cr) {
    cr->save();
    cr->set_source_rgb(0, 0, 0);
    cr->paint();
//    cr->restore();

//    cr->save();
    cr->set_source_rgb(1, 1, 1);cr->set_line_width(2.0);
    for(int i=20; i<800; i+=20){
        cr->move_to(i,0);cr->line_to(i,800);
        cr->move_to(0,i);cr->line_to(800,i);
    }
    cr->stroke();
    cr->restore();
//    cr->set_line_width(1.0);


}

Grid::~Grid() {

}

Grid *Grid::getInstance(MainProcess *app) {
    Grid *result;
    app->builder->get_widget_derived("SnakeGrid", result, app);
    return result;
}
