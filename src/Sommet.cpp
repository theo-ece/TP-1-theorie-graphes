#include "Sommet.h"

///Classe Sommet permettant de mod�liser le graphe

Sommet::Sommet() //constructeur
{
    //ctor
}

Sommet::Sommet(std::string a) //constructeur
{
    //ctor
    nom=a;
}

Sommet::~Sommet()//destructeur
{
    //dtor
}

void Sommet::SetNom(std::string a) //setter
{
    nom = a;
}
std::string Sommet::GetNom() //getter
{
    return nom;
}
