#include "bomba.h"

bomba::bomba(Personaje *Personaje)
{
    this->x=100;
    this->y=480;
    sprites.push_back(IMG_Load("Endless Run/bomba01.png"));
    sprites.push_back(IMG_Load("Endless Run/bomba02.png"));
    sprites.push_back(IMG_Load("Endless Run/bomba03.png"));
}

bomba::~bomba()
{
}   //dt
void bomba::logica(){
y--;
if (y==-480)
    y=480;
}

void bomba::reset(){
    this->x=100;
    this->y=480;
}
