#ifndef FANTASMITA_H
#define FANTASMITA_H

#include "Enemygo.h"
class Fantasmita:public Enemygo{
    public:
        Fantasmita(Personaje *Personaje);
        void reset();
        virtual ~Fantasmita();
    protected:
    private:
};

#endif // FANTASMITA_H
