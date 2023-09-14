
/**
 * @file string.cpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief implémentation de la classe string 
 * 
 */

#include "string.hpp"

String::String(ulong color_,uint x_, uint y_, const std::string &_str)
    : Shape(color_,x_,y_), str(_str)
{
}

String::String(const String &orig)
    :String(orig.getColor(),orig.getAnchor().getX(),orig.getAnchor().getY(),orig.getString())
{
}
String::~String()
{
}
String::String(istream &is)
    :Shape(is)
    {  /**
        string recup;
        int i=0;
        bool trouve=false;
        while (i<str.size() || !trouve)
        {   
        do                  // Répéter...
        {                                                       Essai foireux a voir plus tard mais pas assez de temps :( 
            char c=is.get();     // On lit un caractère
            if (c!='.')
        {
            pile.empiler(c);
        }
    }
        } **/
        
    }
void String::draw(EZWindow &window, bool isActive) const
{
    Shape::draw(window,isActive);
    window.drawText(EZAlign::TL,getAnchor().getX(),getAnchor().getY(),getString());
}
double String::perimeter() const
{
    return 2;
}
/**
ostream &String::write(ostream &os) const
{
    os << "String ";
    Shape::write(os);
    os <<  " {" << str <<"}";
    return os;
}**/