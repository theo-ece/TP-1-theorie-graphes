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

class Graphe
{
    public:
        Graphe();
        virtual ~Graphe();
        int ordre_graphe();
        std::string saisir();
        void recuperation(std::string a);
        void afficher_influence();
        void traitement();

    protected:

    private:
        std::vector<class Sommet> tab_sommets;
        std::vector<class Arete> tab_arete;
        std::vector<std::vector<std::string>> matrice;
        int ordre;
};

#endif // GRAPHE_H
