//
// Created by blyth on 16/02/2022.
//

#include "Tile.h"

Tile::Tile(int x, int y): Gtk::DrawingArea() {
//    this->chunks = chunks;
    this->x = x;
    this->y=y;
    show();
}
bool Tile::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    this->cr = cr;
    cr->save();
    cr->rectangle(0, 0, 50, 50);
    cr->set_fill_rule(Cairo::FILL_RULE_EVEN_ODD);
    cr->fill();
    cr->set_source_rgb(1, 1, 1);
    cr->move_to(0,0);cr->line_to(50, 0);
    cr->line_to(50,50);cr->line_to(0,50);
    cr->stroke();
    return true;
}
//
//void Tile::swapTile(int tile) {
////    Gdk::Cairo::set_source_pixbuf(cr, get_chunk(tile),
//}
//Glib::RefPtr<Gdk::Pixbuf> Tile::get_chunk(int chunk) {
//    if (chunk < 0) {
//        chunk = 8 + chunk;
//    } else if (chunk >= 7) {
//        chunk = chunk - (int) round(11/chunk);
//    }
//    return *(chunks + chunk);
//}

