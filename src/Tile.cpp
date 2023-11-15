//
// Created by blyth on 16/02/2022.
//

#include "Tile.h"

Tile::Tile(Cairo::RefPtr<Cairo::Context>& cr, int x, int y) {
//    this->chunks = chunks;
    this->x=x;this->y=y;
    this->locX=50*x;this->locY=50*y;
    this->cr=cr;
    swapTile(0);
//    show();

}
//bool Tile::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
//    this->cr = cr;
//    cr->save();
//    cr->rectangle(0, 0, 50, 50);
//    cr->set_fill_rule(Cairo::FILL_RULE_EVEN_ODD);
//    cr->fill();
//    cr->set_source_rgb(1, 1, 1);
//    cr->move_to(0,0);cr->line_to(50, 0);
//    cr->line_to(50,50);cr->line_to(0,50);
//    cr->stroke();
//    return true;
//}
//
void Tile::swapTile(int tile) {
    cr->paint();
    cr->set_source_rgb(1, 1, 1);
    cr->move_to(0,0);cr->line_to(50, 0);
    cr->line_to(50,50);cr->line_to(0,50);
    cr->stroke();
}
//Glib::RefPtr<Gdk::Pixbuf> Tile::get_chunk(int chunk) {
//    if (chunk < 0) {
//        chunk = 8 + chunk;
//    } else if (chunk >= 7) {
//        chunk = chunk - (int) round(11/chunk);
//    }
//    return *(chunks + chunk);
//}

