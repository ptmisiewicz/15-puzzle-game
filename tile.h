#ifndef TILE_H
#define TILE_H
using namespace std;
class Gameboard;
class Tile
{
private:
    int col;///<pierwotna kolumna puzzla
    int row;///< pierwotny wiersz puzzla
    int content;///<zawartość puzzla
    int new_col;///<aktualna kolumna puzzla
    int new_row;///<aktualny wiersz puzzla
public:
    ///deklaracja destruktora
    ~Tile();
    ///deklaracja konstruktora
    Tile ();
    /// setter zawartości puzzla
    void content_setter(int counter);
    /// getter zawartości puzzla
    void content_getter();
    /// getter zawartości puzzla
    int content_getter1();
    /// setter aktualnego wiersza puzzla
    void newrowposition_setter(int i);
    /// setter aktualnej kolumny puzzla
    void newcolposition_setter(int j);
    /// setter pierwotnego wiersza puzzla
    void rowposition_setter(int i);
    /// setter pierwotnej kolumny puzzla
    void colposition_setter(int j);
    /// getter pierwotnej kolumny puzzla
    int colposition_getter();
    /// getter pierwotnego wiersza puzzla
    int rowposition_getter();
    /// getter aktualnej kolumny puzzla
    int newcolposition_getter();
    /// getter aktualnego wiersza puzzla
    int newrowposition_getter();
    /// metoda sprawdzająca czy klocek jest na swoim miejscu
    bool ifend();
    /// metoda czysto wirtualna
    virtual void who_am_i()=0;

};

#endif // TILE_H
