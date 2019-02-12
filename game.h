#ifndef GAME_H
#define GAME_H
using namespace std;
#include <string>
class Game

{

private:
    string username; ///< nazwa użytkownika
    int boardsize; ///< rozmiar gry
    int boardsize1;
    int result;

public:
    /// deklaracja przyjaźni z klasą Gameboard
    friend class Gameboard;
    /// konstruktor
    Game();
    /// destruktor
    ~Game();
    ///pobieranie rozmiaru gry z konsoli
    void get_size();
    ///pobieranie nazwy użytkownika z konsoli
    void get_user();
    ///wyświetlanie danych gry do konsoli
    void display_data();
    ///zwracanie rozmiaru gry
    int size_getter();
    int size_getter1();
    ///pobieranie nazwy użytkownika w oknie
    void name_setter(string name);
    ///pobieranie rozmiary gry z okna
    void size_setter(int sizegame);
    void size_setter1(int sizegame1);

};

#endif // GAME_H
