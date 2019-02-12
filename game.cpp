#include <iostream>
#include "game.h"
#include <QDebug>
using namespace std;
Game::Game()
{
username="Gracz";
boardsize=1;
result=0;
this->display_data();
}
Game::~Game()
{
}

void Game::get_size(){
    cout<<"Podaj rozmiar planszy"<<endl;
    cin>>boardsize;
    while(boardsize<=0){
            cout<<"Rozmiar planszy nieprawidlowy. Podaj rozmiar ponownie"<<endl;
            cin>>boardsize;
    }
}

void Game::get_user(){
    cout<<"Podaj nazwe gracza"<<endl;
    cin>> username;
}

void Game::display_data(){
    cout<<"Gracz "<<username<<" posiada "<<result<<"punktow"<<endl;
    cout<<"rozmiar planszy wynosi "<<boardsize<<endl;

}

int Game::size_getter()
{
    return boardsize;
}

int Game::size_getter1()
{
    return boardsize1;
}



void Game::name_setter(string name)
{
    username=name;
}

void Game::size_setter(int sizegame)
{
    boardsize=sizegame;
}

void Game::size_setter1(int sizegame1)
{
    boardsize1=sizegame1;
}
