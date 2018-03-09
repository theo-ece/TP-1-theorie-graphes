#ifndef SOMMET_H
#define SOMMET_H
#include "Graphe.h"

class Sommet
{
    public:
        Sommet();
        Sommet(std::string a);
        virtual ~Sommet();
        void set_nom(std::string a);
        std::string get_nom();

    protected:

        std::string nom;
    private:
};

#endif // SOMMET_H
