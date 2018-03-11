#include "Graphe.h"

///Classe principale du graphe

Graphe::Graphe()
{
    //ctor
}

Graphe::~Graphe()
{
    //dtor
}

int Graphe::OrdreGraphe()       ///on recupere la taille des sommets
{
    return tab_sommets.size();
}

std::string Graphe::Saisir()    ///permet de saisir le nom du fichier contenant les parametres du graphe
{
    std::string a("");
    std::cout<<"Enter file path : " ;       //En anglais pour tout le monde
    std::cin>>a;
    return a;                               //On retourne le chemin du fichier par un string
}

void Graphe::Recuperation(std::string path)                             ///on lit le fichier
{
    std::string line("");
    std::ifstream Fichierinfluence(path.c_str(), std::ios::in);
    if(Fichierinfluence)
    {
        line="";
        std::vector<string> tab_lignes;                                 ///on recupere les differents noms des influenceurs/influencés dans un tableau de string
        getline(Fichierinfluence,line);
        while(line!="fin")                                              ///tant que le fichier n'est pas integralement lu -> derniere ligne du fichier est "fin"
        {
            tab_lignes.push_back(line);                                 ///on stocke les differents parametres du fichier dans le vecteur "tab_lignes"
            line="";
            getline(Fichierinfluence,line);
        }
        Fichierinfluence.close();                                       ///on ferme le fichier une fois celui-ci entierement lu

        for(unsigned int i=0; i<tab_lignes.size(); i++)                 ///tant que la variable i est inferieure au nombre d'elements contenus dans le vecteur "tab_lignes"
        {
            bool test=true;
            std::string b = tab_lignes.at(i);
            std::string a = b;
            for(unsigned int y=b.size(); y>0 ; y--) a.erase(y);         ///On ne s'interesse qu'au premier terme du string (pos. 0)
            for(unsigned int g=0; g<tab_sommets.size(); g++)
            {
                if(tab_sommets.at(g).GetNom()==a) test = false;         /// on s'assure de ne pas mettre de doublon dans le tableau de sommet en utilisant le booleen test, si faux, on ajoute pas le sommet
            }
            if(test==true)                                              ///test si le sommet n'existe pas, si vrai alors...
            {
                Sommet newsommet;
                newsommet.SetNom(a);
                tab_sommets.push_back(newsommet);                       /// On ajoute un nouveau sommet dans notre tableau de sommet
            }
        }
        for(unsigned int i=0; i<tab_lignes.size(); i++)
        {
            std::string a = tab_lignes.at(i);
            if(a.size()!=1)                                             ///Si le string contient plus d'un caractere (sujet infulence...)
            {
                Arete newArete;                                         ///Creation d'une arete
                std::string c = a;
                std::string b = a;
                c.erase(1);                                             ///On s'interesse au premier terme
                b.erase(b.begin());                                     ///On ne s'interesse pas au premier terme
                newArete.SetSommet1(c);                                 ///On nomme le premier sommet
                newArete.SetSommet2(b);                                 ///On nomme le deuxieme sommet
                tab_arete.push_back(newArete);                          ///On ajoute l'arete au tableau des aretes
            }
        }
    }
    else
    {
        std::cout<< path << " introuvable" << endl;  ///si le nom de fichier entre n'existe pas, on affiche une erreur
    }
}

void Graphe::AfficherInfluence()                     ///une fois le graphe tracé/complété on affiche celui-ci
{


    for(unsigned int i = 0; i<tab_sommets.size() ; i++)                                             ///tant que la variable est  inferieure au nombre d'elements contenus dans le vecteur "tab_lignes
    {
        int comp=0; // sert a savoir si le sujet influence quelqu'un ou non
        std::string sujet = tab_sommets.at(i).GetNom();                                             ///On cherche a obtenir le sujet de notre analise ex: Macron influence....
        for(unsigned int j = 0 ; j<tab_arete.size() ; j++)                                          ///Boucle permettant de chercher les influences correspondants au sujet
        {
            if(sujet == tab_arete.at(j).GetSommet1())                                               ///On test si dans le tableau des aretes le premier sommet est bien notre sujet
            {
                std::cout<< sujet << " influence " << tab_arete.at(j).GetSommet2() << endl ;        ///on affiche les personnes que celles-ci influencent
                comp++;                                                                             ///On indique que le sujet influence au moins une personne, comp!=0
            }
        }
        if(comp==0) std::cout<< sujet << " n'influence personne" << endl;                           ///on affiche que ces personnes n'influencent personne
    }
}



















