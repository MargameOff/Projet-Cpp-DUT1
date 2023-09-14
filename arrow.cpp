/**
 * @file arrow.cpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief implementation de la classe flèche 
 * 
 */

#include <iostream>
using namespace std;

#include "arrow.hpp"

Arrow::Arrow(ulong _color, int _x, int _y, std::vector<Point> _tabPoint, uint _width, uint _height)
    : Shape(_color, _x, _y), tabPoint(_tabPoint), width(_width), height(_height)
{
    tabPoint[0].setXY(getAnchor().getX(), getAnchor().getY());
    
    tabPoint[1].setXY(tabPoint[0].getX(), tabPoint[0].getY()-(height )/2);
    tabPoint[2].setXY(tabPoint[1].getX()+(width ),tabPoint[1].getY() );
    tabPoint[3].setXY(tabPoint[2].getX(), tabPoint[2].getY()-(height /4));
    tabPoint[4].setXY(tabPoint[3].getX()+ width , tabPoint[3].getY()+(height )/2);
    tabPoint[5].setXY(tabPoint[4].getX()-width, tabPoint[4].getY()+(height /2));
        tabPoint[6].setXY(tabPoint[5].getX(), tabPoint[5].getY()-(height /4));
    previousAnchorX = getAnchor().getX();
    previousAnchorY = getAnchor().getY();
}

Arrow::Arrow(const Arrow &orig)
    : Shape(orig)
{
}
/**
Arrow::Arrow(istream &is)
    : Shape(is)
{
    is >> width;
    is >> height;
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
}**/

Arrow::~Arrow()
{
}

void Arrow::draw(EZWindow &w, bool isActive) const
{
    getAnchor().setXY(tabPoint[0].getX(), tabPoint[0].getY());
    Shape::draw(w, isActive);
    for (size_t i = 0; i < tabPoint.size(); i++)
    {
        w.drawLine(tabPoint[i].getX(), tabPoint[i].getY(), tabPoint[(i + 1) % tabPoint.size()].getX(), tabPoint[(i + 1) % tabPoint.size()].getY());
    }
}

double Arrow::perimeter() const
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
/**
ostream &Arrow::write(ostream &os) const
{
    os << "Arrow ";
    Shape::write(os);
    os << " " << width << " " << height << " " << tabPoint.size() << " " << endl;
    for (uint i = 0; i < tabPoint.size(); i++)
    {
        os << tabPoint[i].getX() << " " << tabPoint[i].getY() << " ";
    }
    os << endl;
    return os;
}
**/
void Arrow::moveArrow()
{
    for (size_t i = 0; i < tabPoint.size(); i++)
    {
        tabPoint[i].setXY(tabPoint[i].getX() + (getAnchor().getX() - previousAnchorX), tabPoint[i].getY() + (getAnchor().getY() - previousAnchorY));
    }
    savePoint();
}

void Arrow::signalClicked(int x, int y)
{
    for (size_t i = 0; i < tabPoint.size(); i++)
    {
        if (tabPoint[i].isOver(x, y))
        {
            setPointSelect(&tabPoint[i]);
        }
    }
}

bool Arrow::sommetIsSelect() const
{
    if (PointSelect != nullptr)
        return (PointSelect != nullptr);
    else
        return (false);
}

bool Arrow::sommetOver(int x, int y) const
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


void Arrow::savePoint()
{
    previousAnchorX = getAnchor().getX();
    previousAnchorY = getAnchor().getY();
}