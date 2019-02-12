#ifndef BLANK_TILE_H
#define BLANK_TILE_H
#include "tile.h"
using namespace std;
///dziedzieczenie po klasie Tile
class Blank_tile: public Tile
{
public:
    Blank_tile (int it, int jt, int count);
    ~Blank_tile();
    void who_am_i();
    //void find_blank(Gameboard tablica);
  //  void move(Gameboard tablica);


};

#endif // BLANK_TILE_H
