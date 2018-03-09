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
    std::string a("");
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
        ///Sommet register - fonctionnel
        for(unsigned int i=0; i<tab_lignes.size(); i++)
        {
            bool test=true;
            std::string b = tab_lignes.at(i);
            std::string a = b;
            for(unsigned int y=b.size(); y>0 ; y--) a.erase(y);
            for(unsigned int g=0; g<tab_sommets.size(); g++)
            {
                if(tab_sommets.at(g).get_nom()==a) test = false;
            }
            if(test==true)
            {
            Sommet newsommet;
            newsommet.set_nom(a);
            tab_sommets.push_back(newsommet);
            }
        }
        ///Arete register - fonctionnel
        for(unsigned int i=0; i<tab_lignes.size(); i++)
        {
            std::string a = tab_lignes.at(i);

            if(a.size()!=1)
            {
                std::string c = a;
                std::string b = a;
                c.erase(1);
                b.erase(begin(b));
                Arete newArete;
                newArete.set_sommet_1(c);
                newArete.set_sommet_2(b);
                tab_arete.push_back(newArete);
            }
        }
    }
    else
    {
        std::cout<< path << " introuvable" << endl;
    }
}

void Graphe::afficher_influence()
{
    //for(unsigned int i = 0; i<tab_sommets.size() ; i++) cout << tab_sommets.at(i).get_nom();

    for(unsigned int i = 0; i<tab_sommets.size() ; i++)
    {
        int comp=0;
        std::string sujet = tab_sommets.at(i).get_nom();
        for(unsigned int j = 0 ; j<tab_arete.size() ; j++)
        {
            if(sujet == tab_arete.at(j).get_sommet_1())
            {
                std::cout<< sujet << " influence " << tab_arete.at(j).get_sommet_2() << endl ;
                comp++;
            }
        }
        if(comp==0) std::cout<< sujet << " n'influence personne" << endl;
    }
}



















