/**
 * @file imagestring.cpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief implémentation de la classe imagstring
 * 
 */

using namespace std;
#include <math.h>
#include "imagestring.hpp"

ImageString::ImageString(uint _x, uint _y, const char *_path,int _fontSizeX,int _fontSizeY,int _fontLetterInX,int _fontLetterInY, string _inputString)
    : Shape(ez_black, _x, _y), path("Font/Font3.png"), imageF(nullptr),fontSizeX(_fontSizeX),fontSizeY(_fontSizeY),fontLetterInX(_fontLetterInX),fontLetterInY(_fontLetterInY),inputString(_inputString)
{
    
    EZImage tempimage(path);
    imageF = new EZImage(tempimage);
    savepath = std::string(path);
    letterAvailable={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','0','.',',',':',';','"','-','(',')','/','?','+'};
}

ImageString::ImageString(const ImageString &orig)
    : ImageString(orig.getAnchor().getX(), orig.getAnchor().getY(), orig.path,orig.fontSizeX,orig.fontSizeY,orig.fontLetterInX,orig.fontLetterInY,orig.inputString)
{
}

ImageString::ImageString(istream &is)
    : Shape(is), path(nullptr), imageF(nullptr), alpha(true), factor(1)
{
    is >> savepath >> alpha >> factor >> fontSizeX >> fontSizeY >>fontLetterInX >>fontLetterInY>>inputString;
    //getline(is, inputString, '}'); ne marche pas
    path = savepath.c_str();
    EZImage tempimage(path);
    imageF = tempimage.scale(factor);
    path = savepath.c_str();
}

ImageString::~ImageString()
{
    delete imageF;
}

void ImageString::draw(EZWindow &w, bool isActive) const
{
    Shape::draw(w, isActive);
    imageF->setAlpha(getAlpha());
    for (size_t i = 0; i < inputString.size(); i++)
    {
        drawLetter(w, getAnchor().getX()+(fontSizeX*i),getAnchor().getY(), inputString[i]);
    }
    
}

void ImageString::drawLetter(EZWindow &w, uint x, uint y, char l) const
{
    size_t c=0;
    bool findLetter= false;
    while (c<letterAvailable.size() && !findLetter)
    {
        if (letterAvailable[c] == l)
        {
            findLetter=true;
        }
        else
        {
            c++;
        }
    }
    if (findLetter)
    {
        uint x1 = fontSizeX*(c%fontLetterInX);
        uint y1 = fontSizeY*((c/fontLetterInX));
        imageF->paintSubimage(w, x, y,x1,y1,fontSizeX,fontSizeY);
    }

}

void ImageString::changeFactor()
{
    path = savepath.c_str();
    EZImage tempimage(path);
    delete imageF;
    imageF = tempimage.scale(factor);
    path = savepath.c_str();
}

double ImageString::perimeter() const
{
    return imageF->getHeight() * 2 + imageF->getWidth() * 2;
}

ostream &ImageString::write(ostream &os) const
{
    os << "ImageString"
       << " ";
    Shape::write(os);
    os << " " << savepath << " " << alpha << " " << factor << " " << fontSizeX << " " << fontSizeY << " " << fontLetterInX<< " " << fontLetterInY<< " {" << inputString << "}";
    return os;
}
