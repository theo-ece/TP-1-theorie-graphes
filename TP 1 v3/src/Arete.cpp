#include "Arete.h"

Arete::Arete()
{
    //ctor
}

Arete::~Arete()
{
    //dtor
}
void Arete::set_sommet_1(std::string a)
{
    sommet_1.set_nom(a);
}
void Arete::set_sommet_2(std::string a)
{
    sommet_2.set_nom(a);
}
Sommet Arete::get_sommet_1()
{
    return sommet_1;
}
Sommet Arete::get_sommet_2()
{
    return sommet_2;
}
