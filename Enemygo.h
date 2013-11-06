#ifndef ENEMYGO_H
#define ENEMYGO_H
#include "SDL.h"
#include "SDL_image.h"
#include "Personaje.h"

#include <vector>

class Enemygo
{
    public:
        Personaje *personaje;
        Enemygo();
        int x,y;

        std::vector<SDL_Surface*>sprites;
        virtual void Dibujar(SDL_Surface*screen);
        virtual void logica();
        virtual void reset();
        virtual ~Enemygo();
    protected:
    private:
};

#endif // ENEMYGO_H
