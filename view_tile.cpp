#include "view_tile.h"

View_tile::View_tile()
{   ///inicjalizacja wartości początkowych
    size = 600;
    size1 = 450;
    x=0;
    y=0;
}






void View_tile::display_picture(Game game_, Gameboard *gameboard_)
{   ///załadowanie używanych obrazków
    QPixmap srcImage(":/images/kwadrat.jpg");
    QPixmap srcImage2(":/images/bialy034.jpg");
    QPixmap srcImage3(":/images/bojar.jpg");
    QPixmap srcImage4(":/images/angelina.jpg");
    QPixmap srcImage5(":/images/bialy.jpg");
    QPixmap srcImage6(":/images/cartoon.jpg");
    ///stworzenie sceny
    QGraphicsScene *scene = new QGraphicsScene();
     ///ustawienie rozmiaru sceny
    scene->setSceneRect(0,0,600,450);
    ///pobranie ilości puzzli
    int sizer=game_.size_getter();
    int sizer1=game_.size_getter1();
    ///obliczenie szerokości puzzla
    w=size/sizer1;
    int h=size1/sizer;
    ///zmienne służące do wypełnienia wektora wektorów
    int q=0;
    int r=0;
    QPixmap tileImg;
    ///uzupełnianie wektora częściami obrazka
    for (y=0;y<size1;y+=h){
        vector<QGraphicsPixmapItem*> temp;
        for (x=0;x<size;x+=w){
            if (x==0 && y==0)
                ///pierwsze pole to biały obrazek
                tileImg = srcImage5.copy(x, y, w, h);
            else
                ///pozostałe to kawałki właściwego obrazu
                tileImg = srcImage6.copy(x, y, w, h);
            ///stworzenie puzzla
            QGraphicsPixmapItem* pTile = new QGraphicsPixmapItem(tileImg);
            temp.push_back(pTile);
            ///umożliwienie przesuwania puzzla
            pTile->setFlag(QGraphicsItem::ItemIsFocusable);
            pTile->setFocus();
            ///ustawienie pozycji puzzla na scenie
            pTile->setPos(x,y);
            ///dodanie puzzla do sceny
            scene->addItem(pTile);
            r=r+1;
            }
        board.push_back(temp);
        q=q+1;
        }
        ///odbiór sygnałów o przesunięciu puzzla w logice, końcu gry oraz złym ruchu
        connect(gameboard_,SIGNAL(move_gui(int, int, int, int)),this,SLOT(change_place_gui(int, int, int, int)));
        connect(gameboard_,SIGNAL(game_passed()),this,SLOT(show_message()));
        connect(gameboard_,SIGNAL(wrong_move()),this,SLOT(show_info()));
        ///stworzenie wskaźnika na obiekt klasy Gameview
        GameView *_view = new GameView();
        view = _view;
        ///wstawienie dotychczasowej sceny do sceny
        view->setScene(scene);
        ///wyświetlenie widoku
        view->show();
}

void View_tile::change_place_gui(int i, int j, int k, int l){
    ///pobranie połozeń puzzli
    qreal temp1=board[i][j]->scenePos().x();
    qreal temp2=board[i][j]->scenePos().y();
    qreal temp3=board[k][l]->scenePos().x();
    qreal temp4=board[k][l]->scenePos().y();
    ///ustalenie nowych położeń puzzli
    board[i][j]->setPos(temp3,temp4);
    board[k][l]->setPos(temp1,temp2);
    ///zamiana puzzli w wektorze wektorów
    std::swap(board[i][j],board[k][l]);
}

void View_tile::show_message()
{
    QMessageBox::information(view, "Koniec gry", "Obrazek został ułożony! Gratulacje :)");
}

void View_tile::show_info()
{
    QMessageBox::warning(view, "Zły ruch", "Wybierz poprawny ruch, aby ułożyć obrazek");
}



QGraphicsView *View_tile::getView() const
{
    return view;
}

