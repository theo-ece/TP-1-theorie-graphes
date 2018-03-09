#include <iostream>
#include "header.h"

using namespace std;




int main()
{
    Graphe graphe_number_one;
    graphe_number_one.recuperation(graphe_number_one.saisir());
    graphe_number_one.afficher_influence();
    std::cout << "lien github :     https://github.com/theo-ece/TP-1-theorie-graphes" << endl;
    return 0;
}
