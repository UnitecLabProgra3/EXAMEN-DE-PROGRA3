#ifndef FUEGO_H
#define FUEGO_H
#include "Enemygo.h"

class fuego:public Enemygo
{
    public:
        fuego(Personaje * personaje);
        void logica();
        void reset();
        virtual ~fuego();
    protected:
    private:
};

#endif // FUEGO_H
