#include "Graphe.h"

Graphe::Graphe()
{
    //ctor
}

Graphe::~Graphe()
{
    //dtor
}

int Graphe::ordre_graphe()
{
    return tab_sommets.size();
}

std::string Graphe::saisir()
{
    std::string a;
    std::cout<<"Enter file path : " ;
    std::cin>>a;
    return a;
}

void Graphe::recuperation(std::string path)
{
    std::string line("");
    std::ifstream fichiercartes(path.c_str(), std::ios::in);
    if(fichiercartes)
    {
        line="";
        std::vector<string> tab_lignes;
        getline(fichiercartes,line);
        while(line!="fin")
        {
            tab_lignes.push_back(line);
            line="";
            getline(fichiercartes,line);
        }
        fichiercartes.close();
        for(unsigned int i=0; i<tab_lignes.size(); i++)
        {
            std::string b = tab_lignes.at(i);
            std::string a = b;
            for(unsigned int y=b.size(); y>0 ; y--) a.erase(y);
            Sommet newsommet;
            newsommet.set_nom(a);
            tab_sommets.push_back(newsommet);
        }
        for(unsigned int i=0; i<tab_lignes.size();i++)
        {
            std::string a = tab_lignes.at(i);
            std::string c = a;
            for(unsigned int y=a.size()-1; y>0 ; y--) c.erase(y);
            for(unsigned int j=1; j<a.size();j++)
            {
                std::string b = a;
                if(b.size()!=1)
                {
                    for(unsigned int y=a.size()-1; y>j ; y--) b.erase(y);
                    for(unsigned int y=0; y<j ; y++) b.erase(0);
                    Arete newarete;
                    newarete.set_sommet_1(c);
                    newarete.set_sommet_2(b); ///  A revoir ?
                    tab_arete.push_back(newarete);
                }
            }
        }
    }
    traitement();
}

void Graphe::afficher_influence()
{
    for(unsigned int i = 0; i<tab_sommets.size() ; i++)
    {

    }
}



















