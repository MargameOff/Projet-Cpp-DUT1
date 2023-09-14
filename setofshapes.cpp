#include <iostream>
#include <stdexcept>

using namespace std;

#include "ez-draw++.hpp"

#include "SetOfShapes.hpp"

SetOfShapes::SetOfShapes(size_t _maxShapes)
	: maxShapes(_maxShapes), nbShapes(0), shapes(nullptr)
{
	shapes = new Shape *[maxShapes];
}

SetOfShapes::~SetOfShapes()
{
		for(size_t i=0;i<nbShapes;i++)
	{
		delete shapes[i];
	}
	delete[] shapes;
}

//Définition des fonctions membres
void SetOfShapes::add(Shape *_pshape)
{
	if (nbShapes >= maxShapes)
	{
		size_t resize = 2 * maxShapes;
		Shape **data = new Shape *[resize];
		for (size_t i = 0; i < nbShapes; i++)
			data[i] = shapes[i];

		delete[] data;
		maxShapes = resize;
		shapes = data;
	}
	shapes[nbShapes++] = _pshape;
}

Shape *SetOfShapes::isOver(uint mouse_x, uint mouse_y) const
{
	for (size_t i = 0; i < nbShapes; i++)
		if (shapes[i]->isOver(mouse_x, mouse_y))
			return shapes[i];

	return nullptr;
}

void SetOfShapes::draw(EZWindow &window) const
{
	for (size_t i = 0; i < nbShapes; i++)
		shapes[i]->draw(window);
}

void SetOfShapes::save(ostream &os) const
{
	os << nbShapes << endl;
	os << *this << endl;
}

void SetOfShapes::load(istream &is) //factory: fonction membre de classe
									// qui fabrique un pointeur sur sa classe
{
	uint nbf;
    is >>  nbf;
    for(uint i=0; i<nbf; i++)
		add(Shape::load(is));
}
// fonction non membre

//Surcharge opérateur<<
ostream &operator<<(ostream &os, const SetOfShapes &_sOfShape)
{
	for (size_t i = 0; i < _sOfShape.nbShapes; i++)
		os << *_sOfShape.shapes[i] << endl;
	return os;
}