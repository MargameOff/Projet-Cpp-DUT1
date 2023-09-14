/**
 * @file shape.cpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief implémentation de la classe shape
 */

#include <iostream>

using namespace std;
#include "Grid.hpp"
#include "shape.hpp"

typedef unsigned int uint;
typedef unsigned long int ulong;

Shape::Shape(ulong _color, uint _x, uint _y)
    : color(_color), anchor(_x, _y), selected(true) //liste d'initialisation des données membres
{
}

Shape::Shape(const Shape &orig)
    : Shape(orig.color, orig.anchor.getX(), orig.anchor.getY())
{
}

Shape::~Shape()
{
}

Shape::Shape(istream &is)
    : color(ez_black), selected(false), thickness(1), Full(false)
{
    uint x, y;
    is >>  color >>  x >> y >> thickness >> Full;
    anchor.setXY(x,y);
}

void Shape::draw(EZWindow &window, bool isActive) const
{

    anchor.draw(window, isActive);
    window.setColor(color);
    window.setThick(thickness);
}

ostream &Shape::write(ostream &os) const
{
    os << color << " " << anchor << " " << thickness << " " << Full;
    return os;
}

ostream &operator<<(ostream &os, const Shape &shape)
{
    shape.write(os);
    return os;
}

#include "rectangle.hpp"
#include "circle.hpp"
#include "square.hpp"
#include "ellipse.hpp"
#include "image.hpp"
#include "Etoile.hpp"
#include "triangle.hpp"
#include "polygone.hpp"
#include "string.hpp"
#include "imagestring.hpp"

Shape *Shape::load(istream &is)
{
    string typestr;
    is >> typestr;
    if (typestr == "Rectangle")
        return new Rectangle(is);
    else if (typestr == "Ellipse")
        return new Ellipse(is);
    else if (typestr == "Square")
        return new Square(is);
    else if (typestr == "Circle")
        return new Circle(is);
    else if (typestr == "Image")
        return new Image(is);
    else if (typestr == "Grid")
        return new Grid(is);
    else if (typestr == "Etoile")
        return new Etoile(is);
    else if(typestr == "Triangle")
        return new Triangle(is);
    else if(typestr == "Polygone")
        return new Polygone(is);/**
    else if(typestr == "String")
        cerr<<"Non Disponible pour le moment";
    else if(typestr == "ImageString")
        <<"Non Disponible pour le moment";**/
    else
        throw runtime_error("Inconnu");
}
