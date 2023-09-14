/**
 * @file Etoile.cpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief implémentation de la classe Etoile
 */


#include <iostream>
using namespace std;

#include "Etoile.hpp"

Etoile::Etoile(ulong _color, int _x, int _y, std::vector<Point> _tabPoint, uint _radius, uint _radius2)
    : Shape(_color, _x, _y), tabPoint(_tabPoint), radius(_radius), radius2(_radius2)
{
    double PI = 2 * acos(0.0);
    tabPoint[0].setXY(getAnchor().getX(), getAnchor().getY());
    for (size_t i = 0; i < tabPoint.size(); i= i+ 2 )
    {

        tabPoint[i].setXY(radius * cos((i + 1) * ((360 / tabPoint.size()) * PI / 180.0)) + getAnchor().getX() - radius * cos(0) + radius, radius * sin((i + 1) * ((360 / tabPoint.size()) * PI / 180.0)) + getAnchor().getY() - radius * sin(0));
    }
    for (size_t i = 1; i < tabPoint.size(); i= i+ 2 )
    {

        tabPoint[i].setXY(radius2 * cos((i + 1) * ((360 / tabPoint.size()) * PI / 180.0)) + getAnchor().getX() - radius2 * cos(0) + radius2, radius2 * sin((i + 1) * ((360 / tabPoint.size()) * PI / 180.0)) + getAnchor().getY() - radius2 * sin(0));
    }

    getAnchor().setXY(tabPoint[0].getX(), tabPoint[0].getY());
    previousAnchorX = getAnchor().getX();
    previousAnchorY = getAnchor().getY();
}

Etoile::Etoile(const Etoile &orig)
    : Shape(orig)
{
}

Etoile::Etoile(istream &is)
    : Shape(is)
{
    is >> radius;
    uint nbp;
    is >> radius2;
    is >> nbp;
    uint x, y;
    std::vector<Point> tabP;
    for (uint i = 0; i < nbp; i++)
    {
        is >> x >> y;
        Point tempp(x, y);
        tabP.push_back(tempp);
    }
    tabPoint = tabP;
    getAnchor().setXY(tabPoint[0].getX(), tabPoint[0].getY());
    previousAnchorX = getAnchor().getX();
    previousAnchorY = getAnchor().getY();
}

Etoile::~Etoile()
{
}

void Etoile::draw(EZWindow &w, bool isActive) const
{
    getAnchor().setXY(tabPoint[1].getX(), tabPoint[1].getY());
    Shape::draw(w, isActive);
    for (size_t i = 0; i < tabPoint.size(); i++)
    {
        w.drawLine(tabPoint[i].getX(), tabPoint[i].getY(), tabPoint[(i + 1) % tabPoint.size()].getX(), tabPoint[(i + 1) % tabPoint.size()].getY());
    }
}

double Etoile::perimeter() const
{
    double perimeter = 0;
    for (size_t i = 0; i < tabPoint.size(); i++)
    {
        if (tabPoint[(i + 1) % tabPoint.size()].getX() > tabPoint[i].getX() && tabPoint[(i + 1) % tabPoint.size()].getY() > tabPoint[i].getY())
            perimeter += sqrt(pow(tabPoint[(i + 1) % tabPoint.size()].getX() - tabPoint[i].getX(), 2) + pow(tabPoint[(i + 1) % tabPoint.size()].getY() - tabPoint[i].getY(), 2));
        else if ((tabPoint[(i + 1) % tabPoint.size()].getX() > tabPoint[i].getX() && tabPoint[i].getY() > tabPoint[(i + 1) % tabPoint.size()].getY()))
            perimeter += sqrt(pow(tabPoint[(i + 1) % tabPoint.size()].getX() - tabPoint[i].getX(), 2) + pow(tabPoint[i].getY() - tabPoint[(i + 1) % tabPoint.size()].getY(), 2));
        else if (tabPoint[i].getX() > tabPoint[(i + 1) % tabPoint.size()].getX() && tabPoint[(i + 1) % tabPoint.size()].getY() > tabPoint[i].getY())
            perimeter += sqrt(pow(tabPoint[i].getX() - tabPoint[(i + 1) % tabPoint.size()].getX(), 2) + pow(tabPoint[(i + 1) % tabPoint.size()].getY() - tabPoint[i].getY(), 2));
        else if (tabPoint[i].getX() > tabPoint[(i + 1) % tabPoint.size()].getX() && tabPoint[i].getY() > tabPoint[(i + 1) % tabPoint.size()].getY())
            perimeter += sqrt(pow(tabPoint[i].getX() - tabPoint[(i + 1) % tabPoint.size()].getX(), 2) + pow(tabPoint[i].getY() - tabPoint[(i + 1) % tabPoint.size()].getY(), 2));
    }
    return perimeter;
}

ostream &Etoile::write(ostream &os) const
{
    os << "Etoile ";
    Shape::write(os);
    os << " " << radius << " "<< radius2 << " " << tabPoint.size() << " " << endl;
    for(uint i=0; i<tabPoint.size(); i++)
    {
        os << tabPoint[i].getX() << " " << tabPoint[i].getY() << " ";
    }
    return os;
}

void Etoile::moveEtoile()
{
    for (size_t i = 0; i < tabPoint.size(); i++)
    {
        tabPoint[i].setXY(tabPoint[i].getX() + (getAnchor().getX() - previousAnchorX), tabPoint[i].getY() + (getAnchor().getY() - previousAnchorY));
    }
    savePoint();
}

void Etoile::signalClicked(int x, int y)
{
    for (size_t i = 0; i < tabPoint.size(); i++)
    {
        if (tabPoint[i].isOver(x, y))
        {
            setPointSelect(&tabPoint[i]);
        }
    }
}

bool Etoile::sommetIsSelect() const
{
    if (PointSelect != nullptr)
        return (PointSelect != nullptr);
    else
        return (false);
}

bool Etoile::sommetOver(int x, int y) const
{
    bool isOver = false;
    for (size_t i = 1; i < tabPoint.size(); i++)
    {
        if (tabPoint[i].isOver(x, y))
        {
            isOver = true;
        }
    }
    return isOver;
}

void Etoile::savePoint()
{
    previousAnchorX = getAnchor().getX();
    previousAnchorY = getAnchor().getY();

}