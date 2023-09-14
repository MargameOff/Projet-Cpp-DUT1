 /**
 * @file circle.cpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief implémentation de la classe circle 
 */
#include <iostream>
#include <cmath>
using namespace std;

#include "circle.hpp"



Circle::Circle(ulong color_, uint x_, uint y_, uint radius_)
    : Shape(color_, x_, y_), radius(radius_)
{
}

Circle::Circle(istream &is)
    : Shape(is)
{
    is >> radius;
}

Circle::~Circle()
{
}

void Circle::draw(EZWindow &window, bool isActive) const
{
    Shape::draw(window, isActive);

    if (Shape::getFull())
    {
        window.fillCircle(
            getAnchor().getX(), getAnchor().getY(),
            (getAnchor().getX() + radius - getChangeGauche()), (getAnchor().getY() + radius - getChangeGauche()));
        window.drawCircle(
            getAnchor().getX(), getAnchor().getY(),
            (getAnchor().getX() + radius - getChangeGauche()), (getAnchor().getY() + radius - getChangeGauche()));
    }
    else
    {
        window.drawCircle(
            getAnchor().getX(), getAnchor().getY(),
            (getAnchor().getX() + radius - getChangeGauche()), (getAnchor().getY() + radius - getChangeGauche()));
    }
}

ostream &Circle::write(ostream &os) const
{
    os << "Circle ";
	Shape::write(os);
	os << " " << radius;
	return os;
}

double Circle::perimeter() const
{
    double pi = 2 * acos(0.0);
    return (2 * pi * radius);
}
