/**
 * @file ellipse.hpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * 
 * 
 * @brief  implémentation de la classe Ellipse 
 * 
 */



#include <iostream>
#include <cmath>

using namespace std;

#include "ellipse.hpp"

Ellipse::Ellipse(ulong color_, uint x_, uint y_, uint semiWidth_, uint semiHeight_)
    : Shape(color_, x_, y_), semiWidth(semiWidth_), semiHeight(semiHeight_)
{
}

Ellipse::Ellipse(const Ellipse &orig)
    : Ellipse(orig.getColor(), orig.getAnchor().getX(), orig.getAnchor().getY(), orig.getSemiWidth(), orig.getSemiHeight())
{
}

Ellipse::~Ellipse()
{
}

Ellipse::Ellipse(istream &is)
    : Shape(is), semiWidth(0), semiHeight(0)
{
  is >> semiWidth >> semiHeight;
}

void Ellipse::draw(EZWindow &window, bool isActive) const
{
  Shape::draw(window, isActive);

  if (Shape::getFull())
  {
    window.fillCircle(
        getAnchor().getX(), getAnchor().getY(),
        getAnchor().getX() + semiWidth - getChangeGauche(), (getAnchor().getY() + semiHeight - getChangeHaut()));
    window.drawCircle(
        getAnchor().getX(), getAnchor().getY(),
        getAnchor().getX() + semiWidth - getChangeGauche(), (getAnchor().getY() + semiHeight - getChangeHaut()));
  }
  else
  {
    window.drawCircle(
        getAnchor().getX(), getAnchor().getY(),
        getAnchor().getX() + semiWidth - getChangeGauche(), (getAnchor().getY() + semiHeight - getChangeHaut()));
  }
}

ostream &Ellipse::write(ostream &os) const
{
  os << "Ellipse" << " ";
	Shape::write(os);
	os << " " << semiWidth << " " << semiHeight;
	return os;
}
double Ellipse::perimeter() const
{
  double pi = 2 * acos(0.0);
  return (2 * pi * sqrt(((semiWidth ^ 2) + (semiHeight ^ 2)) / 2));
}
