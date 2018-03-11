#ifndef ARETE_H
#define ARETE_H

#include "Graphe.h"
#include "Sommet.h"

///Classe Arete qui compose le graphe

class Arete
{
public:
    Arete();
    virtual ~Arete();
    void SetSommet1(std::string a);     // permet de rentrer le nom du sommet 1 de l'arete  -   on entre un string
    void SetSommet2(std::string a);     // permet de rentrer le nom du sommet 2 de l'arete  -   on entre un string
    std::string GetSommet1();           // permet d'obtenir le nom du sommet 2 de l'arete   -   on obtient un string
    std::string GetSommet2();           // permet d'obtenir le nom du sommet 2 de l'arete   -   on obtient un string



protected:

private:
    std::string sommet1;
    std::string sommet2;
};

#endif // ARETE_H
