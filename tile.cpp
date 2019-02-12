#include "tile.h"
#include <iostream>
using namespace std;

Tile::Tile()
{
row=1;
col=1;
content=1;
}

Tile::~Tile(){
}

void Tile::content_setter(int counter){
    content=counter;
}

void Tile::content_getter(){
    cout<<content<<" ";
}

int Tile::content_getter1(){
    return content;
}

void Tile::rowposition_setter(int i){
    row=i;
}

void Tile::colposition_setter(int j){
    col=j;
}

int Tile::colposition_getter(){
    return col;
}

int Tile::rowposition_getter(){
    return row;
}

bool Tile::ifend()
{///sprawdzenie czy pierwotne wiersz i kolumna są takie same jak aktualne
    if(new_row==row && new_col==col)
        return 1;
    else
        return 0;
}

void Tile::newrowposition_setter(int i){
    new_row=i;
}

void Tile::newcolposition_setter(int j){
    new_col=j;
}

int Tile::newcolposition_getter(){
    return new_col;
}

int Tile::newrowposition_getter(){
    return new_row;
}
