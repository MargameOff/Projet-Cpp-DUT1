/**
 * @file square.cpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief implémentation de la classe carré
 */


#include <iostream>

using namespace std;

#include "square.hpp"

Square::Square(ulong color_, uint x_, uint y_, uint length_)
    : Shape(color_, x_, y_), length(length_)
{
}

Square::Square(const Square &orig)
    : Square(orig.getColor(), orig.getAnchor().getX(), orig.getAnchor().getY(), orig.getLength())
{
}

Square::~Square()
{
}

Square::Square(istream &is)
    : Shape(is), length(0)
{
    is >> length;
}

void Square::draw(EZWindow &window, bool isActive) const
{
    Shape::draw(window, isActive);
    if (Shape::getFull())
    {
        window.fillRectangle(getAnchor().getX(), getAnchor().getY(),
                             getAnchor().getX() + length - getChangeHaut(), (getAnchor().getY() + length - getChangeHaut()));
        window.drawRectangle(getAnchor().getX(), getAnchor().getY(),
                             getAnchor().getX() + length - getChangeHaut(), (getAnchor().getY() + length - getChangeHaut()));
    }

    else
    {
        window.drawRectangle(getAnchor().getX(), getAnchor().getY(),
                             getAnchor().getX() + length - getChangeHaut(), (getAnchor().getY() + length - getChangeHaut()));
    }
}
ostream &Square::write(ostream &os) const
{
    os << "Square" << " ";
	Shape::write(os);
	os << " " << length;
	return os;
}
double Square::perimeter() const
{
    return (length * 4);
}
