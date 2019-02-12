#include "dialog.h"
#include "ui_dialog.h"
#include <Qstring>
#include <QMessageBox>
#include <iostream>
#include <QDebug>
///konstruktor
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //QWidget::setFocusPolicy(Qt::StrongFocus);
    //game();
}
/// destruktor
Dialog::~Dialog()
{
    delete ui;
}




void Dialog::on_pushButton_clicked()
{
    /// wybór liczby puzzli
    int number=ui->spinBox->value();
    game.size_setter(number);
    int number1=ui->spinBox_2->value();
    game.size_setter1(number1);
    gameboard_ = new Gameboard(game);
    gameboard_->print(game);
    this->close(); ///<zakmnięcie okna dialog
    pic = new View_tile(); ///<stworzenie wskaźnika na obiekt klasy View_tile
    pic->display_picture(game,gameboard_);
    gameboard_->randomize(); ///<wywołanie losowania puzzli
    gameboard_->get_move(this); ///<pobranie ruchu od gracza
}

View_tile *Dialog::getPic()
{
    return pic;
}



void Dialog::on_spinBox_2_editingFinished()
{

}
