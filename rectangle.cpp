/**
 * @file rectangle.cpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief   implémentation de la classe rectangle  
 * 
 */


#include <iostream>

using namespace std;

#include "Rectangle.hpp"

Rectangle::Rectangle(ulong color_, uint x_, uint y_, uint width_, uint height_)
    : Shape(color_, x_, y_), width(width_), height(height_)
{
}

Rectangle::Rectangle(const Rectangle &orig)
    : Rectangle(orig.getColor(), orig.getAnchor().getX(), orig.getAnchor().getY(), orig.getWidth(), orig.getHeight())
{
}

Rectangle::Rectangle(istream &is)
    : Shape(is), width(0), height(0)
{
    is >> width >> height;
}

Rectangle::~Rectangle()
{
}

void Rectangle::draw(EZWindow &window, bool isActive) const
{
    Shape::draw(window, isActive);

    if (Shape::getFull())
    {
        window.fillRectangle(
            (getAnchor().getX()), 
            (getAnchor().getY()),
            (getAnchor().getX() + width - getChangeGauche()), 
            (getAnchor().getY() + height - getChangeHaut()));
        window.drawRectangle(
            (getAnchor().getX()), 
            (getAnchor().getY()),
            (getAnchor().getX() + width - getChangeGauche()), 
            (getAnchor().getY() + height - getChangeHaut()));
    }

    else
    {
        window.drawRectangle(
            (getAnchor().getX()), 
            (getAnchor().getY()),
            (getAnchor().getX() + width - getChangeGauche()), 
            (getAnchor().getY() + height - getChangeHaut()));
    }
}

ostream &Rectangle::write(ostream &os) const
{
    os << "Rectangle ";
    Shape::write(os);
    os <<  ' ' << width << ' ' << height;
    return os;
}

double Rectangle::perimeter() const
{
    return 2 * width + 2 * height;
}
