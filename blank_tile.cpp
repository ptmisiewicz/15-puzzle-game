#include "blank_tile.h"
#include <iostream>
Blank_tile::Blank_tile(int it, int jt, int count)
{
rowposition_setter(it);
colposition_setter(jt);
content_setter(count);
newrowposition_setter(it);
newcolposition_setter(jt);
}

Blank_tile::~Blank_tile(){
    cout<<"usunieto obiekt klasy Blank_tile";
}

void Blank_tile::who_am_i()
{
    cout<<"I am blank tile"<<endl;
}

/*void Blank_tile::move(Gameboard tablica){
    tablica.find_blank();
    int erow = tablica.brow_getter();
    int ecol = tablica.bcol_getter();
    int a;
    int b;
    char echoice;
    Gameboard::Next_move choice;
    cout<<"podaj jaki ruch chcesz wykonac"<<endl;
    cin>>echoice;
    choice= (Gameboard::Next_move) echoice;
    tablica.direction(choice, erow,ecol,a,b);
    tablica.board_setter(erow,ecol,a,b);

}
Tile::find_blank(Gameboard tablica)
{
for(int i=0;i<tablica.board.size();i++){
    for (int j=0;j<tablica.board.size();j++){
        if(tablica.board[i][j]=0){
            erow=i;
            ecol=j;
        }
    }
}
}

void Tile::move_blank(Next_move obiekt, Gameboard tablica){
    find_blank(tablica);
    switch (obiekt) {
            case Up:
                    {
                            erow=erow+1;
                            break;
                    }
            case Down:
                    {
                            erow=erow-1;
                            break;
                    }
            case Left:
                    {
                            ecol=ecol+1;
                            break;
                    }
            case Right:
                    {
                            ecol=ecol-1;
                            break;
                    }
    }
    col=ecol;
    row=erow;
    tablica[erow][ecol]=0;

}
*/
