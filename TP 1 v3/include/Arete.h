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
        std::string get_sommet_1();
        std::string get_sommet_2();



    protected:

    private:
        std::string sommet_1;
        std::string sommet_2;
};

#endif // ARETE_H
