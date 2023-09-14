/**
 * @file triangle.cpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief implémentation de la classe Triangle
 */

#include <iostream>
using namespace std;

#include "triangle.hpp"
Triangle::Triangle(ulong _couleur, uint _x, uint _y, uint _x1, uint _y1, uint _x2, uint _y2)
    : Shape(_couleur, _x, _y), Anchor(_x, _y), p1(_x1, _y1), p2(_x2, _y2), previousAnchor(_x, _y)
{
    Anchor.setXY(getAnchor().getX(), getAnchor().getY());

    p1.setXY(getAnchor().getX() + 60, getAnchor().getY() + 100);

    p2.setXY(getAnchor().getX() - 60, getAnchor().getY() + 100);
    previousAnchor.setXY(getAnchor().getX(), getAnchor().getY());
    savePoint();
}

Triangle::Triangle(const Triangle &orig)
    : Shape(orig), Anchor(0, 0), p1(0, 0), p2(0, 0), previousAnchor(0, 0)
{
}
Triangle::Triangle(istream &is)
    : Shape(is)
{
    Anchor.setXY(getAnchor().getX(), getAnchor().getY());
    is >> p1 >> p2;

    getAnchor().setXY(Anchor.getX(), Anchor.getY());
    previousAnchor.setXY(getAnchor().getX(), getAnchor().getY());
    savePoint();
}

Triangle::~Triangle()
{

}

void Triangle::draw(EZWindow &w, bool isActive) const
{
    Shape::draw(w, isActive);

    w.drawTriangle(getAnchor().getX(), getAnchor().getY(), p1.getX(), p1.getY(), p2.getX(), p2.getY());

    if (Shape::getFull())
    {
        w.fillTriangle(getAnchor().getX(), getAnchor().getY(), p1.getX(), p1.getY(), p2.getX(), p2.getY());
    }
    getAnchor().setXY(Anchor.getX(), Anchor.getY());
}

double Triangle::perimeter() const
{
    return (length((getAnchor().getX()), (getAnchor().getY()), p1.getX(), p1.getY()) +
            length((getAnchor().getX()), (getAnchor().getY()), p2.getX(), p2.getY()) +
            length(p1.getX(), p1.getY(), p2.getX(), p2.getY()));
}

ostream &Triangle::write(ostream &os) const
{
    os << "Triangle ";
    Shape::write(os);
    os << " " << p1 << " ";
    os << p2 ;
    return os;
}

void Triangle::moveTriangle()
{
    Anchor.setXY(Anchor.getX() + (getAnchor().getX() - previousAnchor.getX()), Anchor.getY() + (getAnchor().getY() - previousAnchor.getY()));
    p1.setXY(p1.getX() + (getAnchor().getX() - previousAnchor.getX()), p1.getY() + (getAnchor().getY() - previousAnchor.getY()));
    p2.setXY(p2.getX() + (getAnchor().getX() - previousAnchor.getX()), p2.getY() + (getAnchor().getY() - previousAnchor.getY()));

    savePoint();
}

void Triangle::signalClicked(uint x, uint y)
{
    if (Anchor.isOver(x, y))
        setPointSelect(&Anchor);
    if (p1.isOver(x, y))
        setPointSelect(&p1);
    if (p2.isOver(x, y))
        setPointSelect(&p2);
}

void Triangle::setXYSommet(uint x, uint y)
{
    if (PointSelect != nullptr)
    {
        PointSelect->setXY(x, y);
    }
}

bool Triangle::sommetIsSelect() const
{
    if (PointSelect != nullptr)
        return (PointSelect != nullptr);
    else
        return (false);
}

bool Triangle::sommetOver(uint x, uint y) const
{
    bool isOver = false;
    if (p1.isOver(x, y))
    {
        isOver = true;
    }
    if (p2.isOver(x, y))
    {
        isOver = true;
    }
    if (Anchor.isOver(x, y))
    {
        isOver = false;
    }
    return isOver;
}

void Triangle::savePoint()
{
    previousAnchor.setXY(Anchor.getX(), Anchor.getY());
}