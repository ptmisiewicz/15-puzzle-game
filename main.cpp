
#include <QApplication>
#include "dialog.h"
#include "gameboard.h"
#include "view_tile.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog konwers;
    konwers.show();


    return a.exec();
}
