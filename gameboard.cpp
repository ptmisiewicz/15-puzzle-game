#include "gameboard.h"
#include "game.h"
#include "ctime"
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
using namespace std;


Gameboard::Gameboard(Game obiekt)
{
    vector<vector<std::shared_ptr<Tile>>> board1;
    board=board1;
    int k=0;
    ///uzupełnianie wektora wektorów pełniącego rolę planszy puzzli
    for(int i = 0; i < obiekt.boardsize; ++i){
        vector<std::shared_ptr<Tile>> temp;
        for(int j = 0; j < obiekt.boardsize1; ++j){
            if(k==0){
                auto blank_tile=std::make_shared<Blank_tile>(i,j,k);
                temp.push_back(blank_tile); ///< pierwszy puzzel jest pusty
                brow=i;
                bcol=j;
            }
            else{
                auto filled_tile=std::make_shared<Filled_tile>(i,j,k);
                temp.push_back(filled_tile); ///< kolejne puzzle są wypełnione
            }
            k++;


        }
        board.push_back(temp);
    }
    ifrand=1; ///< ustalenie zmiennej ifrand przed losowaniem na 1
    movesleft=0; ///< ustalenie zmiennej odpowiadającej za ilość puzzli źle ustawionych na 0
}

Gameboard::~Gameboard(){
}

void Gameboard::print(Game obiekt){
    for(int i=0;i<obiekt.boardsize;++i){
        for(int j=0;j<obiekt.boardsize1;++j){
            board[i][j]->content_getter();
        }
        cout<<endl;
    }
}

void Gameboard::find_blank()
{
for(int i=0;i<board.size();i++){
    for (int j=0;j<board[0].size();j++){
        if(board[i][j]->content_getter1()==0){
            /// zapisanie kolumny i wiersza pustego puzzla
            brow=i;
            bcol=j;
        }
    }
}
}

int Gameboard::brow_getter(){
  return brow;
}

int Gameboard::bcol_getter(){
  return bcol;
}

void Gameboard::swap_tiles(int u, int i, int o, int p){
    if ((o>=0 && o<board.size()) && (p>=0 && p<board[0].size())){
    emit move_gui(u,i,o,p);
    std::swap(board[u][i],board[o][p]); ///<zamiana pól w wektorze wektorów miejscami
    /// zapamiętanie nowych pozycji klocków
    board[u][i]->newrowposition_setter(u);
    board[u][i]->newcolposition_setter(i);
    board[o][p]->newrowposition_setter(o);
    board[o][p]->newcolposition_setter(p);



    }
    ///jeśli wprowadzony ruch jest niepoprawny następuje komunikat o potrzebie wprowadzenie ruchu ponownie
    else {
    if (ifrand==0){
        cout<<"Ruch niepoprawny. Wprowadz ruch ponownie"<<endl;
        emit wrong_move();
             }
        }

    }


void Gameboard::direction(Gameboard::Next_move list, int u, int i, int &o, int &p){
    ///zapisanie położeń puzzla, który ma zostać zamieniony z pustym puzzlem w oparciu o wybrany ruch oraz położenie pustego puzzla
    switch (list) {
            case Next_move::Up:
                    {
                            o=u-1;
                            p=i;
                            break;
                    }
            case Next_move::Down:
                    {
                            o=u+1;
                            p=i;
                            break;
                    }
            case Next_move::Left:
                    {
                            p=i-1;
                            o=u;
                            break;
                    }
            case Next_move::Right:
                    {
                            p=i+1;
                            o=u;
                            break;
                    }
    }

}

Gameboard::Next_move Gameboard::move_insert(){

    ifrand=0; ///< zmienna ifrand ustawiona na 0, bo ruch nie jest losowany
    cout<<"podaj jaki ruch chcesz wykonac"<<endl;
    cin>>echoice;
    Gameboard::Next_move ch;
    ch = (Gameboard::Next_move) echoice; ///<konwersja zmiennej char na enum class
    return ch;
}


void Gameboard::move(Gameboard::Next_move k){
    find_blank(); ///<znajdowanie pustego puzzla
    int erow = brow_getter();
    int ecol = bcol_getter();
    int a;
    int b;
    direction(k, erow,ecol,a,b);///<ustalenie położenia klocka, z którym zamiana nastąpi
    swap_tiles(erow,ecol,a,b); ///< zamiana klocków
    /// sprawdzenie czy wszystkie klocki są na swojej pozycji o ile ruch został wykonany przez gracza, a nie przez system losujący
    if (ifrand==0){
        if (end()==1){
            emit game_passed();
        }
    }
}


void Gameboard::randomize(){
srand((unsigned int)time(0)); ///<ustawienie punktu startowego do generowania serii pseudolosowych liczb całkowitych
for (int cntr = 0; cntr < 1000000; ++cntr) {
    int random = (rand() % 4); ///<ustalenie przedziału liczb od 0 do 3
    /// w zależności od losowania następuje ruch w określonym kierunku
    switch (random) {
        case 0:
            {
                move(Gameboard::Next_move::Up);
                break;
            }
        case 1:
            {
                move(Gameboard::Next_move::Down);
                break;
            }
        case 2:
            {
                move(Gameboard::Next_move::Left);
                break;
            }
        case 3:
            {
                move(Gameboard::Next_move::Right);
                break;
            }
    }
}
}

bool Gameboard::end()
{   /// sprawdzenie ile puzzli jest na niewłaściwym miejscu
    for(int i=0;i<board.size();i++){
        for (int j=0;j<board[0].size();j++){
            if(board[i][j]->ifend()==0){
                movesleft++;

            }

        }
}
    qDebug()<<movesleft<<" pol znajduje sie na niewlasciwej pozycji";
    ///jeśli wszystkie pola są ustawione właściwie metoda zwraca wartość 1
    if (movesleft==0){
        board[0][0]->who_am_i();
        board[0][1]->who_am_i();
        return 1;
    }


    movesleft=0;
    /// w innym wypadku metoda zwraca 0
    return 0;
}

void Gameboard::get_move(Dialog *dial)
{   /// funkcja przechwytująca sygnały z wciśnięcia klawiszy w okienku
    connect(dial->getPic()->getView(),SIGNAL(chose_a()),this,SLOT(rchose_a()));
    connect(dial->getPic()->getView(),SIGNAL(chose_w()),this,SLOT(rchose_w()));
    connect(dial->getPic()->getView(),SIGNAL(chose_s()),this,SLOT(rchose_s()));
    connect(dial->getPic()->getView(),SIGNAL(chose_d()),this,SLOT(rchose_d()));
}

void Gameboard::rchose_w()
{   /// określenie, że ruch jest wykonywany przez gracza oraz wywołanie metody move z przesunięciem pustego puzzla do góry
    ifrand=0;
    move(Gameboard::Next_move::Up);
}

void Gameboard::rchose_s()
{   /// określenie, że ruch jest wykonywany przez gracza oraz wywołanie metody move z przesunięciem pustego puzzla do dołu
    ifrand=0;
    move(Gameboard::Next_move::Down);
}

void Gameboard::rchose_a()
{   /// określenie, że ruch jest wykonywany przez gracza oraz wywołanie metody move z przesunięciem pustego puzzla w lewo
    ifrand=0;
    move(Gameboard::Next_move::Left);
}

void Gameboard::rchose_d()
{   /// określenie, że ruch jest wykonywany przez gracza oraz wywołanie metody move z przesunięciem pustego puzzla w prawo
    ifrand=0;
    move(Gameboard::Next_move::Right);
}
