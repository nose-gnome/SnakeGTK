//
// Created by blyth on 14/02/2022.
//

#include <Grid.h>
#include <random>


//Grid::Grid():Glib::ObjectBase("Grid"),
//prop_ustring(){
//}
Grid::Grid(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refGlade, MainProcess *app): Gtk::DrawingArea(cobject){
    this->app = app;
    generateApple();

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
    draw_apple(cr);
    snake->re_draw(cr);

//    for (int i = 0; i<144; i++) {
//        const int row = (int) i/12;
//        const int column = i-(12*row);*
//        tiles[column][row] = new Tile(cr, column, row, column*50, row*50);
//    }


//    cr->stroke();
    return true;
}
void Grid::draw_apple(const Cairo::RefPtr<Cairo::Context>& cr) {
    cr->save();
    cr->set_source_rgb(255,0,0);cr->set_line_width(12);
//    Coordinates ne = {apple.x*20-10, apple.y*20+4};
//    Coordinates nn = {apple.x*20-10,apple.y*20+16};
//    cr->move_to(apple.x*10, apple.y*10); cr->line_to(apple.x*10, apple.y*10+5);
//    cr->move_to(ne.x, ne.y); cr->line_to(nn.x, nn.y);
    cr->move_to(apple.p.x, apple.p.y);cr->line_to(apple.p2.x,apple.p2.y);
    cr->stroke();
    cr->restore();
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

bool Grid::eatApple() {
    return false;
}

bool Grid::generateApple() {

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1,40); // define the range
    const Coordinates tmp = {
            distr(gen),
            distr(gen)
    };
    apple = {
            tmp,
            tmp.x*20-10,tmp.y*10+4,
            tmp.x*20-10,tmp.y*10+16,

    };
    return true;

}
