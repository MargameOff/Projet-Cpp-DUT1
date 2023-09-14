/**
 * @file calque.cpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief implémentation de la classe Calque
 */

#include <iostream>
using namespace std;

#include "Calque.hpp"

Calque::Calque(unsigned int size)
:maxShapes(size),nbShapes(0),selection(0), calques(nullptr)
{
    calques = new SetOfShapes*[size];
    for(unsigned int i=0; i<size; i++)
        calques[i]=nullptr;
}

Calque::~Calque()
{
    delete [] calques;
}

SetOfShapes* Calque::getCalques(uint i) const
{
    if(i<nbShapes) 
        return calques[i];
    else 
        throw runtime_error("Ce calque n'existe pas !");
}

void Calque::draw(EZWindow &w, bool isActive) const
{
    for(uint i=0; i<nbShapes; i++)
    {
        calques[i]->draw(w);
    }
}


void Calque::add(SetOfShapes * f)
{
    if(nbShapes>=maxShapes)
        cout << "Le nombre maximum de calque a déjà était atteint !" << endl;
    else
        calques[nbShapes++]=f;
}

void Calque::suprr(uint k)
{
    if(k>nbShapes-1)
        cout << "Ce calque n'existe pas !" << endl;
    else if(nbShapes>=1)
    {
        uint j=0;
        SetOfShapes **temp = new SetOfShapes*[maxShapes];
        for (uint i=0; i<nbShapes; i++)
        {
            if(i!=k)
                temp[j++]=calques[i];
        }
        calques[k]->~SetOfShapes();
        delete [] calques;
        calques=temp;
        nbShapes--;
    }
}

void Calque::save(ostream& os) const
{
    os << nbShapes << endl;
    for(uint i=0; i<nbShapes; i++)
    {
        os << "Calque " << i << endl;
        calques[i]->save(os);
    }
}

void Calque::load(istream& is)
{
    uint j;
    is >> j;
    string mot;
    for(uint i=0; i<j; i++)
    {
	    is >> mot;
        if(mot=="Calque")
        {
            is >> selection;
            add();
            calques[selection]->load(is);
        }
    }
}

void Calque::DisplayOrNo(uint i)
{
    if(i<nbShapes)
        calques[i]->setIsDisplay((!calques[i]->getIsDisplay()));
}

void Calque::show() const
{
    cout << "--------------------------Calques--------------------------" << endl;
    for(uint i=0;i<nbShapes;i++)
    {
        cout << "|| Calque " << i+1;
        if(calques[i]->getIsDisplay())
            cout << " : Afficher     ";
        else
            cout << " : Non afficher ";
        if(i==selection)
            cout << "(Actuel) ";
        else
            cout << "         ";
        if(calques[i]->getNbShapes()==0)
            cout << "  (vide)             ||" << endl;
        else
            cout << "  (Nb forme(s) : " << calques[i]->getNbShapes() << " ) ||" << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
}
