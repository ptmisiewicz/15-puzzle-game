#ifndef GAMEVIEW_H
#define GAMEVIEW_H

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
///dziedziczenie po QGraphicsView
class GameView :public QGraphicsView
{
    Q_OBJECT
public:
    GameView();
    void keyPressEvent(QKeyEvent *event);///<sterowanie klockami za pomocą klawiszy w okienku
signals:
    void chose_w();
    void chose_s();
    void chose_a();
    void chose_d();


};

#endif // GAMEVIEW_H
