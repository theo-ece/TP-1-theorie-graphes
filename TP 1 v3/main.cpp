#include <iostream>
#include "header.h"

using namespace std;




int main()
{
    Graphe graphe_number_one;
    graphe_number_one.recuperation(graphe_number_one.saisir());
    graphe_number_one.afficher_influence();
    return 0;
}
