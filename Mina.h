#ifndef MINA_H
#define MINA_H
#include "Enemygo.h"

class Mina:public Enemygo
{
    public:
        Mina(Personaje * personaje);
        void logica();
        void reset();
        virtual ~Mina();
    protected:
    private:
};

#endif // MINA_H
