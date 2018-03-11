#include "Arete.h"
///Classe Arete permettant de modéliser le graphe

Arete::Arete() //constructeur
{
    //ctor
}

Arete::~Arete() //destructeur
{
    //dtor
}
void Arete::SetSommet1(std::string a) //setter
{
    sommet1=a;
}
void Arete::SetSommet2(std::string a) //setter
{
    sommet2=a;
}
std::string Arete::GetSommet1() //getter
{
    return sommet1;
}
std::string Arete::GetSommet2() //getter
{
    return sommet2;
}
