#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "game.h"
#include "blank_tile.h"
#include "filled_tile.h"
#include "tile.h"
#include "dialog.h"
#include <vector>
#include <memory>
#include <QObject>
using namespace std;
class Tile;
class Dialog;
class Gameboard: public QObject
{
    Q_OBJECT
private:
    vector<vector<std::shared_ptr<Tile> > > board; ///< wektor wektorów inteligentych wskaźników na obiekty klasy Tile
    int brow; ///< wiersz, w którym znajduje się pusty klocek
    int bcol; ///< kolumna, w której znajduje się pusty klocek
    bool ifrand; ///< zmienna, przechowująca informację czy ruch wykonany był przez użytkownika czy wylosowany przez komputer
    int movesleft; ///< ilość klocków, które znajdują się na niewłaściwej pozycji
    char echoice; ///< zmienna, służąca do podawania kierunku ruchu klocka
public:
    /// konstruktor
    Gameboard(Game obiekt);
    /// destruktor
    ~Gameboard();
    /// drukowanie obrazu gry
    void print (Game obiekt);
    /// znajdowanie pustego puzzla
    void find_blank();
    /// getter wiersza, w którym znajduje się pusty puzzel
    int brow_getter();
    /// getter kolumny, w której znajduje się pusty puzzel
    int bcol_getter();
    /// przesunięcie pustego puzzla
    void swap_tiles(int u, int i, int o, int p);
    /// wybór ruchu ze zbioru możliwości
    enum class Next_move{Up = 'w',
                         Down = 's',
                         Left = 'a',
                         Right = 'd'};
    ///ustalanie położenia puzzla, który zostanie zamieniony z pustym puzzlem
    void direction(Gameboard::Next_move list, int u, int i, int &o, int &p);
    /// główna metoda ruchu pustego puzzla
    void move(Gameboard::Next_move k);
    /// metoda do wprowadzania ruchu do metody move
    Gameboard::Next_move move_insert();
    /// losowanie położeń puzzli
    void randomize();
    /// sprawdzanie czy obrazek został ułożony
    bool end();
    /// metoda pozwalająca na przesunięcie puzzli poprzez naciśnięcie klawisza w wersji okienkowej
    void get_move(Dialog *dial);


public slots:
    ///slot wykorzystywany w przypadku ruchu pustego puzzla do góry
    void rchose_w();
    ///slot wykorzystywany w przypadku ruchu pustego puzzla do dołu
    void rchose_s();
    ///slot wykorzystywany w przypadku ruchu pustego puzzla w lewo
    void rchose_a();
    ///slot wykorzystywany w przypadku ruchu pustego puzzla w prawo
    void rchose_d();
signals:
    /// sygnał emitowany do grafiki w momencie wykonania przesunięcia puzzli w logice
    void move_gui(int f, int g, int h, int j);
    /// sygnał emitowany do grafiki w momencie końca gry
    void game_passed();
    ///sygnał emitowany do grafiki w momencie wykonania błędnego ruchu
    void wrong_move();
    };





#endif // GAMEBOARD_H
