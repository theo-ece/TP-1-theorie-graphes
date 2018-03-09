#ifndef ARETE_H
#define ARETE_H

#include "Graphe.h"
#include "Sommet.h"

class Arete
{
    public:
        Arete();
        virtual ~Arete();
        void set_sommet_1(std::string a);
        void set_sommet_2(std::string a);
        Sommet get_sommet_1();
        Sommet get_sommet_2();



    protected:

    private:
        Sommet sommet_1;
        Sommet sommet_2;
};

#endif // ARETE_H
