#ifndef GUI_TILE_H
#define GUI_TILE_H
#include "tile.h"
#include <QGraphicsPixmapItem>

class Gui_tile: public QGraphicsPixmapItem
{
public:
    Gui_tile();

private:
    Tile tile_;
    QGraphicsPixmapItem* imgTile;

};

#endif // GUI_TILE_H
