#ifndef VIEW_TILE_H
#define VIEW_TILE_H

#include <QVector>
#include <QDialog>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>
#include <QDebug>
#include <QObject>
#include <QKeyEvent>
#include <QMessageBox>
#include "gameboard.h"
#include "game.h"
#include "gameview.h"
#include "gui_gameboard.h"
class View_tile: public QObject
{
    Q_OBJECT
public:
    ///metoda wyświetlająca obraz
    void display_picture(Game game_, Gameboard *gameboard_);
    ///konstruktor
    View_tile();
    ///funkcja zwracająca obiekt klasy QGraphicsView
    QGraphicsView *getView() const;

public slots:
    void change_place_gui(int i, int j, int k, int l);///<zmiana puzzli w grafice
    void show_message();///<wyświetlanie informacji o końcu gry
    void show_info();///<wyświetlanie informacji o nieprawidłowym ruchu

private:
    ///rozmiar obrazka
    int size;
    int size1;
    ///współrzędna x
    int x;
    ///współrzędna y
    int y;
    ///szerokość jednego puzzla
    int w;
    ///wysokość jednego puzzla
    int h;
    ///char choice;
    GameView *view;
    ///wektor wektorów w części graficznej
    vector<vector<QGraphicsPixmapItem*>> board;

};

#endif // VIEW_TILE_H
