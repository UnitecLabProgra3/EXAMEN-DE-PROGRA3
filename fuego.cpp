#include "fuego.h"

fuego::fuego(Personaje * personaje)
{
  this->x=400;
     this->y=0;
     sprites.push_back(IMG_Load("Endless Run/llama01.png"));
      sprites.push_back(IMG_Load("Endless Run/llama02.png"));
       sprites.push_back(IMG_Load("Endless Run/llama03.png"));
        sprites.push_back(IMG_Load("Endless Run/llama03.png"));    //ctor
}

fuego::~fuego()
{
    //dtor
}
void fuego::logica(){
if (y<300){
    y++;
}
if (y==300){
    x--;
}
if (x==0){
    this->x=400;
     this->y=0;
}
}
void fuego::reset(){
    this->x=600;
    this->y=0;
}
