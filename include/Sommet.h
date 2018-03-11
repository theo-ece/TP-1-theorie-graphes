#ifndef SOMMET_H
#define SOMMET_H
#include "Graphe.h"

///Classe Sommet permettant de modéliser le graphe d'influence
class Sommet
{
public:
    Sommet();
    Sommet(std::string a);
    virtual ~Sommet();
    void SetNom(std::string a);     //Permet d'etablir le nom du sommet - string en entree
    std::string GetNom();           //Permet d'obtenir le nom du sommet - retourne un string

protected:

    std::string nom;
private:
};

#endif // SOMMET_H
