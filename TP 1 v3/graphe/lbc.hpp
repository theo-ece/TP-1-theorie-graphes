/*
 *    Sujet:   Liste Bilatérale Circulaire à maillons génériques
 *    Version: 1.3
 *    Màj:     18.03.2004
 *    Auteur:  Landercy Jean
 *    E-mail:  dr.degree@caramail.com
 *    Site:    http://endorphin.imb.free.fr/
 */

// Teste la définition de l'identificateur iostream: 
#ifndef iostream
	// Inclus iostream, si ce n'est pas dèjà fait:
	#include <iostream>
	using namespace std;
#endif

// Définit l'identificateur LBC:
#define LBC

/*
A ne pas faire:
	- Utiliser une fonction en lui passant en paramètre un pointeur fou ou incompatible
	- Isoler ou supprimer le Maillon de tête (les éléments de la liste seraient perdus)
	- Permuter le Maillon de tête sans remettre à jour la tête de liste
*/

// Patron de classe Maillon (paramètré par la classe T):
template <class T> class Maillon {
	public:
		// Objet contenu par le Maillon:
		T Objet;
		// Liens:
		Maillon<T> * precedent;		// Pointe vers le Maillon précédent
		Maillon<T> * suivant;		// Pointe vers le Maillon suivant
		// Constructeur:
		Maillon<T>() {
			suivant=this;				// A sa création le Maillon pointe sur lui-même
			precedent=this;
  		}
  		// Destructeur:
  		~Maillon<T>() {
  		}
};

// Insere le Maillon m2 après le Maillon m1:
template <class T> void InsererMaillonApres(Maillon<T> * m1, Maillon<T> * m2) {
	m2->precedent=m1;
	m2->suivant=m1->suivant;
	m1->suivant=m1->suivant->precedent=m2;
}

// Insere le Maillon m2 avant le Maillon m1:
template <class T> void InsererMaillonAvant(Maillon<T> * m1, Maillon<T> * m2) {
	m2->precedent=m1->precedent;
	m2->suivant=m1;
	m1->precedent=m1->precedent->suivant=m2;
}

// Isole le Maillon m1:
template <class T> void IsolerMaillon(Maillon<T> * m1) {
	if(m1->precedent!=m1 && m1->suivant!=m1) {
 	// Le maillon n'est pas isolé:
			m1->precedent->suivant=m1->suivant;			// Referme la liste
			m1->suivant->precedent=m1->precedent;		// Referme la liste
			m1->precedent=m1->suivant=m1;					// Isole le Maillon m1
 	}
}

// Insère le maillon m1 en tête de la liste L:
template <class T> void InsererMaillonTeteListe(Maillon<T> * & L, Maillon<T> * m1) {
	if(L!=0) {
		InsererMaillonAvant(L,m1);
	}
	L=m1;
}

// Insère le maillon m1 en queue de la liste L:
template <class T> void InsererMaillonQueueListe(Maillon<T> * & L, Maillon<T> * m1) {
	if(L!=0) {
		InsererMaillonAvant(L,m1);
	} else {
		L=m1;
	}
}

// Supprime le Maillon m1:
template <class T> void SupprimerMaillon(Maillon<T> * m1) {
	IsolerMaillon(m1);
	delete m1;
}

template <class T> void SupprimerMaillonDansListe(Maillon<T> * & L, Maillon<T> * m1) {
	if(m1==L) {
	// Le maillon à supprimer m1 est le maillon pointé par la liste L:
		if(m1->suivant!=m1) {
		// Il y a un autre maillon dans la liste:
			L=m1->suivant;
		} else {
		// Il n'y a que le maillon m1 dans la liste:
			L=0;
		}
	}
	SupprimerMaillon(m1);
}

// Supprime la liste pointé par L:
template <class T> void SupprimerListe(Maillon<T> * & L) {
	if(L!=0) {
	// La liste n'est pas vide:
		Maillon<T> * m1;
		Maillon<T> * m2;
		m1=L;									// m1 pointe vers la maillon en tête de liste
		do {							// Visiter les maillons...
			m2=m1->suivant;				// Sauve l'adresse du maillon suivant dans m2
			delete m1;						// Supprime le maillon m1
			m1=m2;							// m1 pointe vers le maillon suivant
		} while(m1!=L);			// ... jusqu'à la fin de la liste !
		L=0;									// La liste L est vide
	}
}

// Permuter les Maillons m1 et m2:
template <class T> void PermuterMaillons(Maillon<T> * m1, Maillon<T> * m2) {
	// Les Maillons sont contigüs (2 ou 3 Maillons):
 	if(m1->suivant==m2) {
 	// Le Maillon m1 est juste avant le Maillon m2:
		IsolerMaillon(m2);									// Isole le Maillon m2 de la liste, et ...
		InsererMaillonAvant(m1,m2);						// ... l'insère avant le Maillon m1.
 	} else if (m1->precedent==m2) {
  	// Le Maillon m1 est juste après le Maillon m2:
  		IsolerMaillon(m2);									// Isole le Maillon m2 de la liste, et ...
 		InsererMaillonApres(m1,m2);						// ... l'insère après le Maillon m1.
  	} else {
   // Les Maillons m1 et m2 ne sont pas contigüs (4 Maillons ou +):
		// Balises p1 et p2: Maillons précédents les Maillons à permuter:
   	Maillon<T> * p1=m1->precedent;
   	Maillon<T> * p2=m2->precedent;
		// Isole les Maillons à permuter:
	  	IsolerMaillon(m1);
   	IsolerMaillon(m2);
		// Insèrer les Maillons après les balises p1 et p2:
   	InsererMaillonApres(p1,m2);
   	InsererMaillonApres(p2,m1);
   }
}

// Affiche la référence d'un Maillon m1 et ses liens de références:
template <class T> void AfficherMaillon(Maillon<T> * m1) {
	cout << "+ Maillon<T> (" << m1 << ") :" << endl;
	cout << "  - this->precedent = " << m1->precedent << endl;
	cout << "  - this->suivant   = " << m1->suivant << endl << endl;
}

// Affiche une liste de Maillon pointée par le Maillon m1:
template <class T> void AfficherListe(Maillon<T> * L) {
	Maillon<T> * m1 = L;
	if(m1 != 0) {
		do {
			AfficherMaillon(m1);
			m1=m1->suivant;
  		} while(m1 != L);
	} else {
		cout << "La liste est vide !" << endl;
 	}
}
