/*
 *    Sujet:   Gestion de graphe
 *    Version: 3.1
 *    M�j:     19.03.2004
 *    Auteur:  Landercy Jean
 *    E-mail:  dr.degree@caramail.com
 *    Site:    http://endorphin.imb.free.fr/
 */

// Teste la d�finition de l'identificateur iostream: 
#ifndef iostream
	// Inclus iostream, si ce n'est pas d�j� fait:
	#include <iostream>
	using namespace std;
#endif

// Teste la d�finition de l'identificateur LBC: 
#ifndef LBC
	// Inclus lbc.hpp, si ce n'est pas d�j� fait:
	#include "lbc.hpp"
#endif

enum typeLien { indefini=-1, depart=0, arrivee=1 };

// D�claration des classes:
class Lien;
class Sommet;
class Arete;
class Graphe;

// Pointeurs sur les maillons encapsulant les classes:
typedef Maillon<Lien> * pmLien;
typedef Maillon<Sommet> * pmSommet;
typedef Maillon<Arete> * pmArete;


// Autres pointeurs:
typedef Graphe * pGraphe;

// Pointeurs nuls:
const pmLien pmL_Null=0;
const pmSommet pmS_Null=0;
const pmArete pmA_Null=0;


// D�finition des classes:

// Lien:
class Lien {

	public:
		// Donn�es membres:
		pmArete AreteIncidente;
		typeLien Orientation;

		// Constructeur:		
		Lien() {
			AreteIncidente=pmA_Null;
			Orientation=indefini;
 		}

 		// Destructeur:
 		~Lien() {}

};

// Sommet:
class Sommet {

	public:

		// Donn�es membres:
		char Symbole;						// Symbole du sommet
		int Degre;							// Degr� du sommet = nombre d'ar�tes incidentes
		pmLien AretesIncidentes;		// Pointeurs vers la liste des liens vers les ar�tes incidentes
		
		// Constructeur:		
		Sommet() {
			Symbole='\0';
			Degre=0;
			AretesIncidentes=pmL_Null;
 		}

 		// Destructeur:
 		~Sommet() {
 		}
 		
 		// M�thodes:
 		pmLien AjouterLien(pmArete a1, typeLien orient);
 		void SupprimerLien(pmLien l1);
 		
};

// M�thodes d�port�es de la classe Sommet:

// Ajoute un lien vers l'ar�te a1:
pmLien Sommet::AjouterLien(pmArete a1, typeLien orient) {

	pmLien l1 = new Maillon<Lien>;						// Cr�e un maillon Lien dans le tas

	l1->Objet.AreteIncidente=a1;							// Pointe vers l'ar�te
	l1->Objet.Orientation=orient;							// Donne l'orientation

	InsererMaillonQueueListe(AretesIncidentes,l1);	// Ins�re le maillon l1 en queue de la liste des ar�tes incidentes
	Degre++;														// Incr�mente le degr� du sommet

	return l1;													// Retourne la r�f�rence du maillon Lien

}

// Supprime le maillon lien l1  :
void Sommet::SupprimerLien(pmLien l1) {

	SupprimerMaillonDansListe(AretesIncidentes,l1);	// Supprime le maillon de la liste
	Degre--;														// D�cr�mente le degr� du sommet

}


// Arete:
class Arete {

	public:

		// Donn�es membres:
		pmSommet Extremites[2];			// Extr�mit�s de l'ar�te (2 pointeurs des sommets)
		pmLien Liens[2];				// 2 pointeurs vers les maillons Lien
		
		// Constructeur:		
		Arete() {
 		}

 		// Destructeur:
 		~Arete() {}

};

/*

	Le graphe G est le couple (S,A)
	G=(S,A)
	
		o�:	-	S est l'ensemble des sommets du graphe G
					S := { a, b, c, ... }
					
				-	A est l'ensemble des ar�tes (A est un sous ensemble de SxS)
					A C SxS et A := { (x,y) tel que: x, y soient �l�ments de S }

*/

// Graphe:
class Graphe {

	public:
		// Donn�es membres:
		
		bool GrapheOriente;	// D�termine si le graphe est orient� ou non;
		
		int nbSommets;			// Nombre de sommets du graphe
		int nbAretes;			// Nombre d'ar�tes du graphe
		
		pmSommet Sommets;		// Pointe vers la liste des sommets du graphe
		pmArete Aretes;		// Pointe vers la liste des ar�tes du graphe

		// Constructeur:		
		Graphe() {
			GrapheOriente=false;
			nbSommets=0;
			nbAretes=0;
			Sommets=pmS_Null;
			Aretes=pmA_Null;
 		}
 		
 		// Destructeur:
 		~Graphe() {
 			SupprimerTout();
 		}
 		
 		// M�thodes:
 		void SupprimerTout();
 		pmSommet AjouterSommet(char symbole);
 		void SupprimerSommet(pmSommet s1);
 		pmArete AjouterArete(pmSommet s1, pmSommet s2);
 		void SupprimerArete(pmArete a1);

		// Affichage:
		void AfficherSommets() const;
		void AfficherAretes() const;
		void Afficher() const;
		
};


// M�thodes d�port�s de la classe Graphe:

// Supprime tout les objets (sommets et ar�tes) du graphe:
void Graphe::SupprimerTout() {
	// La suppression de tout les sommets du graphe implique une supression de toute les ar�tes:
	if(nbSommets>0) {
		pmSommet * ListeSommets;
  		ListeSommets = new pmSommet[nbSommets];
  		pmSommet s1 = Sommets;
  		for(int i=0; i<nbSommets; i++) {
  			ListeSommets[i]=s1;
  			s1=s1->suivant;
    	}
    	for(int i=(nbSommets-1); i>=0; i--) {
    		SupprimerSommet(ListeSommets[i]);
     	}
    	delete [] ListeSommets;
 	}
}

// Ajoute un nouveau sommet � la liste des sommets du graphe et retourne la r�f�rence du nouveau sommet:
pmSommet Graphe::AjouterSommet(char symbole) {

	pmSommet s1 = new Maillon<Sommet>;			// Cr�e un maillon sommet dans le tas

	s1->Objet.Symbole=symbole;

	InsererMaillonQueueListe(Sommets,s1);		// Ins�re en queue de liste le nouveau sommet
	nbSommets++;										// Incr�mente le nombre de sommet du graphe

	return s1;											// retourne la r�f�rence du nouveau sommet

}

// Supprime le sommet point� par s1:
void Graphe::SupprimerSommet(pmSommet s1) {

	// Supprission des ar�tes incidentes au sommet:
	int nbAI = s1->Objet.Degre;							// Nombre d'ar�tes incidente au sommet
	if(nbAI>0) {
	// Il y a des ar�tes incidentes � ce sommet:
		pmArete * ListeAI = new pmArete[nbAI];			// Cr�e un tableau dynamique contenant les r�f�rences des ar�tes incidentes
		pmLien l1 = s1->Objet.AretesIncidentes;
		for(int i=0; i<nbAI; i++) {						// Copie les r�f�rences des ar�tes incidentes dans le tableau
			ListeAI[i]=l1->Objet.AreteIncidente;
			l1=l1->suivant;
 		}
 		for(int i=(nbAI-1); i>=0; i--) {					// Supprime les ar�tes incidentes dans l'ordre inverse de leur ajout dans la liste
 			if(i>0) {
 				if(ListeAI[i]==ListeAI[i-1]) {			// Dans le cas ou il y a une ar�te ayant pour extr�mites le m�me sommet, il ne faut pas la supprimer deux fois. (cette manipulation est possible car les deux maillons Liens sont contig�s)
 					continue;
  				}
    		}
 			SupprimerArete(ListeAI[i]);
   	}
	delete [] ListeAI;										// Supprime le tableau dynamique
	}

	SupprimerMaillonDansListe(Sommets,s1);				// Supprime le maillon sommet s1 de la liste Sommets
	nbSommets--;												//	D�cr�mente le nombre de sommets du graphe

}



// Ajoute une ar�te � la liste des ar�tes du graphe et retourne l'adresse de la nouvelle ar�te:
pmArete Graphe::AjouterArete(pmSommet s1, pmSommet s2) {

	pmArete a1 = new Maillon<Arete>;				// Cr�e un maillon Arete dans le tas

	a1->Objet.Extremites[depart] = s1;			// Assigne les r�f�rences des sommets extr�mit�s
	a1->Objet.Extremites[arrivee] = s2;			// Idem

	a1->Objet.Liens[depart] = s1->Objet.AjouterLien(a1,depart);		// Cr�e un maillon Lien pointant vers le maillon Arete a1 (dans la liste AretesIncidente du sommet s1)
	a1->Objet.Liens[arrivee] = s2->Objet.AjouterLien(a1,arrivee);	// Cr�e un maillon Lien pointant vers le maillon Arete a1 (dans la liste AretesIncidente du sommet s2)

	InsererMaillonQueueListe(Aretes,a1);		// Ins�re le maillon Arete en queue de la liste des ar�tes
	nbAretes++;											// Incr�mente le nombre d'ar�tes du graphe

	return a1;											// Retourne la r�f�rence du maillon Arete

}

// Supprime l'arete point� par a1:
void Graphe::SupprimerArete(pmArete a1) {

	a1->Objet.Extremites[arrivee]->Objet.SupprimerLien(a1->Objet.Liens[arrivee]);		// Supprime aux sommet d'arriv�e de l'ar�te le lien vers l'ar�te
	a1->Objet.Extremites[depart]->Objet.SupprimerLien(a1->Objet.Liens[depart]);		// Supprime aux sommet de d�part de l'ar�te le lien vers l'ar�te

	SupprimerMaillonDansListe(Aretes,a1);		// Supprime le maillon Arete de la liste Aretes
	nbAretes--;											// D�cr�mente le nombre d'ar�tes du graphe

}



// Affiche la liste de maillons sommets:
void Graphe::AfficherSommets() const {
	pmSommet s1=Sommets;
	if(s1!=pmS_Null) {
		do {
			cout << "+ Sommet (" << s1 << ") :" << endl;
			cout << "  - Degre = " << s1->Objet.Degre << endl;
			cout << "  - AretesIncidentes[" << s1->Objet.Degre << "] = { ";
			pmLien l1 = s1->Objet.AretesIncidentes;
			if(l1!=pmL_Null) {
				do {
					if(l1!=s1->Objet.AretesIncidentes) {
						cout << ", ";
     				}
					cout << l1;
					l1 = l1->suivant;
				} while(l1!=s1->Objet.AretesIncidentes);
			}
			cout << " }" << endl;
			cout << endl;
			s1=s1->suivant;
  		} while(s1!=Sommets);
	} else {
		cout << "La liste Sommets est vide !" << endl;
 	}
}

void Graphe::AfficherAretes() const {
	pmArete a1=Aretes;
	if(a1!=pmA_Null) {
		do {
			cout << "+ Arete (" << a1 << ") :" << endl;
			cout << "  - Extremites[2] = { " << a1->Objet.Extremites[0] << ", " << a1->Objet.Extremites[1] << " }" << endl;
			cout << "  - Liens[2] = { " << a1->Objet.Liens[0] << ", " << a1->Objet.Liens[1] << " }" << endl;
			cout << endl;
			a1=a1->suivant;
  		} while(a1!=Aretes);
	} else {
		cout << "La liste Aretes est vide !" << endl;
 	}
}

void Graphe::Afficher() const {
	cout << "+ Graphe (" << this << ") :" << endl;
	cout << "  - GrapheOriente = " << GrapheOriente << endl;
	cout << "  - nbSommets = " << nbSommets << endl;
	cout << "  - nbAretes = " << nbAretes << endl;
	cout << "  - Sommets = " << Sommets << endl;
	cout << "  - Aretes = " << Aretes << endl;

	cout << "  - Sommets[" << nbSommets << "] = { ";
	pmSommet s1=Sommets;
	if(s1!=pmS_Null) {
		do {
			if(s1!=Sommets) {
				cout << ", ";
  			}
			cout << s1;
			s1=s1->suivant;
 		} while(s1!=Sommets);
	}
	cout << " }" << endl;


	cout << "  - Aretes[" << nbAretes << "] = { ";
	pmArete a1=Aretes;
	if(a1!=pmA_Null) {
		do {
			if(a1!=Aretes) {
				cout << ", ";
  			}
			cout << a1;
			a1=a1->suivant;
 		} while(a1!=Aretes);
	}
 	cout << " }" << endl;

	cout << "  - Sommets[" << nbSommets << "] = { ";
	if(s1!=pmS_Null) {
		s1=Sommets;
		do {
			if(s1!=Sommets) {
				cout << ", ";
  			}
			cout << s1->Objet.Symbole;
			s1=s1->suivant;
 		} while(s1!=Sommets);
	}
 	cout << " }" << endl;

	cout << "  - Aretes[" << nbAretes << "] = { ";
	if(a1!=pmA_Null) {
		a1=Aretes;
		do {
			if(a1!=Aretes) {
				cout << ", ";
  			}
			cout << "(" << a1->Objet.Extremites[0]->Objet.Symbole << "," << a1->Objet.Extremites[1]->Objet.Symbole << ")";
			a1=a1->suivant;
 		} while(a1!=Aretes);
	}
 	cout << " }" << endl;

	cout << endl;
  	
}

