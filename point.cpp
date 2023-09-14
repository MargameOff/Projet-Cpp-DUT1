/**
 * @file point.cpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief implémentation de la classe point
 */
#include "Point.hpp"

//Constructeur
Point::Point(uint _x, uint _y)
    : x(_x), y(_y)
{
}

// Constructeur par copie
Point::Point(const Point &orig)
    : Point(orig.x, orig.y)
{
}

//Constructeur à partir d'un fichier
Point::Point(istream &is)
    : x(0), y(0)
{
    is >> x >> y;
}

//Destructeur
Point::~Point()
{
    
}

//Definition des fonctions membres

// Vérifie si les coordonnées en paramètre
// cad position curseur souris
// sont au dessus des coord de l'instance de Point

void Point::draw(EZWindow &window, bool isActive = false) const
{
    if (isActive)
    {
        window.setColor(ez_red);
    }
    else
    {
        window.setColor(ez_black);
    }
    window.setThick(1);
    window.drawRectangle(x - size, y - size, x + size, y + size);
}

//Définition des fonctions non membres

//Surcharge opérateur<<
ostream &operator<<(ostream &os, const Point &orig)
{
    os << orig.getX() << " " << orig.getY();
    return os;
}

//surcharge opérateur >>
istream &operator>>(istream &is, Point &dest)
{
    uint tmp_x;
    uint tmp_y;
    uint tmp_size;
    is >> tmp_x >> tmp_y >> tmp_size;
    dest.setXY(tmp_x, tmp_y);
    dest.setSize(tmp_size);
    return is;
}