#ifndef DIALOG_H
#define DIALOG_H
#include "game.h"
#include "view_tile.h"
#include <QDialog>
#include <gameboard.h>
#include <QKeyEvent>
class View_tile;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
     Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    View_tile* getPic();///<getter wskaźnika na obiekt klasy View_tile


private slots:
    ///funkcja obsługująca przycisk w oknie Dialog
    void on_pushButton_clicked();

    void on_spinBox_2_editingFinished();

private:
    Ui::Dialog *ui;
    View_tile* pic;
    Game game;
    Gameboard* gameboard_;

};

#endif // DIALOG_H
