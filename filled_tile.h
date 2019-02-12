#ifndef FILLED_TILE_H
#define FILLED_TILE_H
using namespace std;
#include "tile.h"
///dziedziczenie po klasie Tile
class Filled_tile: public Tile
{
public:
    Filled_tile (int i, int j, int count);
    ~Filled_tile();
    void who_am_i();

};
#endif // FILLED_TILE_H
