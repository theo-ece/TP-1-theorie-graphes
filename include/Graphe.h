#ifndef GRAPHE_H
#define GRAPHE_H

#include <iostream>
using namespace std;

#include "Sommet.h"
#include "Arete.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

///Classe permettant de visualiser le graphe en entier

class Graphe
{
public:
    Graphe();
    virtual ~Graphe();
    int OrdreGraphe();
    std::string Saisir();                   //Permet d'appeler la saisie du fichier retournant un string (qu'on aura taper dans la console
    void Recuperation(std::string a);       //Permet de recuperer les données d'un fichier et de les analyser pour les inclure dans le programme - on a en entree un string qui est le chemin d'acces du ficher
    void AfficherInfluence();               //Permet d'afficher les influences de chaque individu - rien en entree, rien en sortie -> affichage console uniquement

protected:

private:
    std::vector<class Sommet> tab_sommets;
    std::vector<class Arete> tab_arete;
    std::vector<std::vector<std::string> > matrice;
    int ordre;
};

#endif // GRAPHE_H
