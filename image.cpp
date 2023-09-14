/**
 * @file image.cpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief implémentation de la classe image
 * 
 */

using namespace std;

#include "Image.hpp"

Image::Image(uint _x, uint _y, const char *_path)
    : Shape(ez_white, _x, _y), path(_path), imageF(nullptr)
{
    EZImage tempimage(path);
    imageF = new EZImage(tempimage);
    savepath = std::string(path);
}

Image::Image(const Image &orig)
    : Image(orig.getAnchor().getX(), orig.getAnchor().getY(), orig.path)
{
}

Image::Image(istream &is)
    : Shape(is), path(nullptr), imageF(nullptr), alpha(true), factor(1)
{
    delete imageF;
    is >> savepath >> alpha >> factor;
    path = savepath.c_str();
    EZImage tempimage(path);
    imageF = tempimage.scale(factor);
    path = savepath.c_str();
}

Image::~Image()
{
    delete imageF;
}

void Image::draw(EZWindow &w, bool isActive) const
{
    Shape::draw(w, isActive);
    imageF->setAlpha(getAlpha());
    imageF->paint(w, getAnchor().getX(), getAnchor().getY());
}

void Image::changeFactor()
{
    path = savepath.c_str();
    EZImage tempimage(path);
    delete imageF;
    imageF = tempimage.scale(factor);
    path = savepath.c_str();
}

double Image::perimeter() const
{
    return imageF->getHeight() * 2 + imageF->getWidth() * 2;
}

ostream &Image::write(ostream &os) const
{
    os<<"Image ";
    Shape::write(os);
    os << " " << savepath << " " << alpha << " " << factor;
    return os;
}
