#include "gameview.h"

GameView::GameView()
{

}

void GameView::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W){
        qDebug()<<"you chose w";
        //zmienna = 'w';
        //gameboard_.move(Gameboard::Next_move::Up);
        emit chose_w();
    }

    if(event->key() == Qt::Key_S){
        qDebug()<<"you chose s";
        //gameboard_.move(Gameboard::Next_move::Down);
        //zmienna = 's';
        emit chose_s();
    }
    if(event->key() == Qt::Key_A){
        qDebug()<<"you chose a";
        //gameboard_.move(Gameboard::Next_move::Left);
        //zmienna = 'a';
        emit chose_a();
    }
    if(event->key() == Qt::Key_D){
        qDebug()<<"you chose d";
        // gameboard_.move(Gameboard::Next_move::Right);
        //zmienna = 'd';
        emit chose_d();
    }
}
