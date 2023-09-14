/**
 * @file Grid.cpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief implémentation de la classe grid
 * 
 */

#include <iostream>

using namespace std;

#include "Grid.hpp"

Grid::Grid(ulong _color, uint _x, uint _y, uint _width, uint _height, size_t _nbLines, size_t _nbColumns)
    : Shape(_color, _x, _y), width(_width), height(_height), nbLines(_nbLines), nbColumns(_nbColumns)
{
}

Grid::Grid(const Grid &orig)
    : Grid(orig.getColor(), orig.getAnchor().getX(), orig.getAnchor().getY(), orig.getWidth(), orig.getHeight(), orig.getNbLines(),orig.getNnbColumns())
{
}

Grid::Grid(istream &is)
    : Shape(is), width(0), height(0), nbLines(0) , nbColumns(0)
{
    is >> width >> height >> nbLines >> nbColumns;
}

Grid::~Grid()
{
}

void Grid::draw(EZWindow &window, bool isActive) const
{

    Shape::draw(window, isActive);

    {
        window.drawRectangle((getAnchor().getX()), (getAnchor().getY()),(getAnchor().getX() + width - getChangeGauche()), (getAnchor().getY() + height - getChangeHaut()));
        for (size_t i=1; i<nbColumns ; i++)
        {
            window.drawLine(
                getAnchor().getX()+i*((width - getChangeGauche())/nbColumns ), getAnchor().getY(),
                getAnchor().getX()+i*((width - getChangeGauche())/nbColumns ), getAnchor().getY()+( height - getChangeHaut()));
                
        }
        for (size_t i=1; i< nbLines; i++)
        {
            window.drawLine(getAnchor().getX(), getAnchor().getY()+i*(height - getChangeHaut())/nbLines, 
                            getAnchor().getX()+(width - getChangeGauche()), getAnchor().getY()+i*(height - getChangeHaut())/nbLines);
        }
    }
}

ostream &Grid::write(ostream &os) const
{
    os << "Grid ";
    Shape::write(os);
    os << " " << width << ' ' << height
    << ' ' << nbLines << ' ' << nbColumns; 
    return os;
}

double Grid::perimeter() const
{
    return 2 * width + 2 * height;
}
