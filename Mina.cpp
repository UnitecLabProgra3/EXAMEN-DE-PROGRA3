#include "Mina.h"

Mina::Mina(Personaje * personaje)
{
     this->x=500;
     this->y=480;
     sprites.push_back(IMG_Load("Endless Run/mina.png"));
      sprites.push_back(IMG_Load("Endless Run/mina.png"));
       sprites.push_back(IMG_Load("Endless Run/mina.png"));
        sprites.push_back(IMG_Load("Endless Run/mina.png"));
}

Mina::~Mina()
{
    //dtor
}
void Mina::logica(){
x--;
y--;
if (y==0){
    x=640;
    y=480;
}
}
void Mina::reset(){
    this->x=500;
    this->y=480;
}
