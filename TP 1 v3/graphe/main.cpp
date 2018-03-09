/*
 *    Sujet:   Gestion de graphe (main)
 *    Version: 3.0
 *    Màj:     18.03.2004
 *    Auteur:  Landercy Jean
 *    E-mail:  dr.degree@caramail.com
 *    Site:    http://endorphin.imb.free.fr/
 */

// Inclusions:
#include <iostream>
using namespace std;

#include "lbc.hpp"			// Liste Bilatérale Circulaire
#include "graphe.hpp"		// Gestion de graphe


// Programme:
int main() {

	pGraphe G = new Graphe;

	pmSommet s1 = G->AjouterSommet('a');
	pmSommet s2 = G->AjouterSommet('b');
	pmSommet s3 = G->AjouterSommet('c');

	pmArete a1 = G->AjouterArete(s1,s2);
	pmArete a2 = G->AjouterArete(s2,s3);
	pmArete a3 = G->AjouterArete(s1,s3);
	pmArete a4 = G->AjouterArete(s1,s1);

/*	G->SupprimerSommet(s1);
	G->SupprimerSommet(s2);
	G->SupprimerSommet(s3);*/

	G->Afficher();

	G->SupprimerTout();

	G->Afficher();

   system("PAUSE");
   return 0;
}

