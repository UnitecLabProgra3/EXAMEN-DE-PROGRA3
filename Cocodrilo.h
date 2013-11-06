#ifndef COCODRILO_H
#define COCODRILO_H
#include "Enemygo.h"

class Cocodrilo:public Enemygo
{
    public:
        Cocodrilo(Personaje * personaje);
        void logica();
        void reset();
        virtual ~Cocodrilo();
    protected:
    private:
};

#endif // COCODRILO_H
