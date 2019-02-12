#include "filled_tile.h"
#include <iostream>
using namespace std;
Filled_tile::Filled_tile(int it, int jt, int count)
{
    rowposition_setter(it);
    colposition_setter(jt);
    content_setter(count);
    newrowposition_setter(it);
    newcolposition_setter(jt);
}
Filled_tile::~Filled_tile(){
    cout<<"usunieto obiekt klasy Filled_tile";
}

void Filled_tile::who_am_i()
{
    cout<<"I am filled tile"<<endl;
}
