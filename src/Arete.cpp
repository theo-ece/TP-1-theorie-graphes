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
    sommet_1=a;
}
void Arete::set_sommet_2(std::string a)
{
    sommet_2=a;
}
std::string Arete::get_sommet_1()
{
    return sommet_1;
}
std::string Arete::get_sommet_2()
{
    return sommet_2;
}
