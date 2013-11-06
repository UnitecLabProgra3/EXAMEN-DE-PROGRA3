#include "Cocodrilo.h"

Cocodrilo::Cocodrilo(Personaje * personaje)
{
    this->x=-100;
    this->y=480;
    sprites.push_back(IMG_Load("Endless Run/croc01.png"));
    sprites.push_back(IMG_Load("Endless Run/croc02.png"));
    sprites.push_back(IMG_Load("Endless Run/croc03.png"));
    sprites.push_back(IMG_Load("Endless Run/croc04.png"));
}

Cocodrilo::~Cocodrilo()
{
    //dtor
}
void Cocodrilo::logica(){
x++;
y--;
if (x==640){
x=0;
y=480;
}
}
void Cocodrilo::reset(){
    this->x=1-00;
    this->y=480;
}
