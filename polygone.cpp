/**
 * @file Polygone.cpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief implémentation de la classe Polygone
 */

#include <iostream>
using namespace std;

#include "polygone.hpp"

Polygone::Polygone(ulong _color, int _x, int _y, std::vector<Point> _tabPoint, uint _radius)
    : Shape(_color, _x, _y), tabPoint(_tabPoint), radius(_radius)
{
    double PI = 2 * acos(0.0);
    tabPoint[0].setXY(getAnchor().getX(), getAnchor().getY());
    for (size_t i = 1; i < tabPoint.size(); i++)
    {

        tabPoint[i].setXY(radius * cos((i + 1) * ((360 / tabPoint.size()) * PI / 180.0)) + getAnchor().getX() - radius * cos(0) + radius, radius * sin((i + 1) * ((360 / tabPoint.size()) * PI / 180.0)) + getAnchor().getY() - radius * sin(0));
    }
    getAnchor().setXY(tabPoint[0].getX(), tabPoint[0].getY());
    previousAnchorX = getAnchor().getX();
    previousAnchorY = getAnchor().getY();
}

Polygone::Polygone(const Polygone &orig)
    : Shape(orig)
{
}
Polygone::Polygone(istream &is)
    : Shape(is)
{
    is >> radius;
    uint nbp;
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

Polygone::~Polygone()
{
}

void Polygone::draw(EZWindow &w, bool isActive) const
{
    Shape::draw(w, isActive);
    for (size_t i = 0; i < tabPoint.size(); i++)
    {
        w.drawLine(tabPoint[i].getX(), tabPoint[i].getY(), tabPoint[(i + 1) % tabPoint.size()].getX(), tabPoint[(i + 1) % tabPoint.size()].getY());
    }
    getAnchor().setXY(tabPoint[0].getX(), tabPoint[0].getY());
}

double Polygone::perimeter() const
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

ostream &Polygone::write(ostream &os) const
{
    os << "Polygone"<< " ";
    Shape::write(os);
    os << " " << radius << " " << tabPoint.size() << " ";
    for (uint i = 0; i < tabPoint.size(); i++)
    {
        os << tabPoint[i].getX() << " " << tabPoint[i].getY() << " ";
    }
    return os;
}

void Polygone::movePolygone()
{
    for (size_t i = 0; i < tabPoint.size(); i++)
    {
        tabPoint[i].setXY(tabPoint[i].getX() + (getAnchor().getX() - previousAnchorX), tabPoint[i].getY() + (getAnchor().getY() - previousAnchorY));
    }
    savePoint();
}

void Polygone::signalClicked(int x, int y)
{
    for (size_t i = 0; i < tabPoint.size(); i++)
    {
        if (tabPoint[i].isOver(x, y))
        {
            setPointSelect(&tabPoint[i]);
        }
    }
}

bool Polygone::sommetIsSelect() const
{
    if (PointSelect != nullptr)
        return (PointSelect != nullptr);
    else
        return (false);
}

bool Polygone::sommetOver(int x, int y) const
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

void Polygone::savePoint()
{
    previousAnchorX = getAnchor().getX();
    previousAnchorY = getAnchor().getY();
}

void Polygone::addPoint()
{

    Point tempPoint(0, 0);
    try
    {
        tabPoint.push_back(tempPoint);
    }
    catch (std::exception const &e)
    {
        cerr << "Erreur : " << e.what();
    }
    getAnchor().setXY(tabPoint[0].getX(), tabPoint[0].getY());
    tabPoint[tabPoint.size() - 1].setXY(radius + getAnchor().getX(), getAnchor().getY() - radius);
    previousAnchorX = getAnchor().getX();
    previousAnchorY = getAnchor().getY();
}

void Polygone::suprrPoint()
{
    if (tabPoint.size() > 0)
    {
        tabPoint.pop_back();
        getAnchor().setXY(tabPoint[0].getX(), tabPoint[0].getY());
        previousAnchorX = getAnchor().getX();
        previousAnchorY = getAnchor().getY();
    }
}