#include "Sommet.h"

Sommet::Sommet()
{
    //ctor
}

Sommet::Sommet(std::string a)
{
    //ctor
    nom=a;
}

Sommet::~Sommet()
{
    //dtor
}

void Sommet::set_nom(std::string a)
{
    nom = a;
}
std::string Sommet::get_nom()
{
    return nom;
}
