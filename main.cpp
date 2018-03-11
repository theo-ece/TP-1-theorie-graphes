#include <iostream>
#include "header.h"

using namespace std;




int main()
{
    std::cout<<"Nom du fichier : influence.txt"<<std::endl;                        ///nom du fichier
    Graphe graphe_number_one;                                                     ///on desire creer un graphe
    graphe_number_one.Recuperation(graphe_number_one.Saisir());                  ///on parcourt le fichier contenant les données du graphe
    graphe_number_one.AfficherInfluence();                                      ///on affiche le graphe

    std::cout << "lien github :     https://github.com/theo-ece/TP-1-theorie-graphes" << endl;
    return 0;
}
