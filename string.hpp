/**
 * @file string.hpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief déclaration de la classe string
 */


#ifndef STRING_HPP
#define STRING_HPP

#include "shape.hpp"
/**
 * Classe string
 * @brief  Classe permettant de creer une chaine de charactère
 * 
 */
class String : public Shape
{
private:
    string str; /*!< string chaine de caractère */

public:
    /**
     * @brief Construit un nouvelle objet chaine de caractère
     * 
     * @param color_ couleur de la chaine de caractère
     * @param x abscisse de l'ancre
     * @param y ordonnée de l'ancre
     * @param str chaine de caractère a afficher
     */
    String(ulong color_,uint x, uint y, const std::string &str);
    /**
	 * @brief Fonction de création par lecture d'une instance d'une ellipse 
	 * 
	 * @param is stock un flux
     */
    String(istream &is);
    /**
	 * @brief constructeur de copie de l'objet chaine de caractère
	 * 
	 * @param orig 
     */
    String(const String &orig);
    /**
     * @brief destructeur de l'objet chaine de caractère 
     * 
     */
    ~String();
/**
 * @brief dessine la chaine de caractère 
 * 
 * @param window fenetre sur laquelle est dessiner la chaine de caractère
 * @param isActive indique si la forme est selectionner 
 */
    void draw(EZWindow &window, bool isActive = false) const;
    /**
     * @brief renvoie le contenue de la chaine de caractère
     * 
     * @return string qui contient le contenue de la chaine de caractère
     */
    inline string getString() const { return str; };
    /**
     * @brief change le contenue de la chaine de caractère 
     * 
     * @param _str strinf qui contient la valeur de la chaine de caratère
     */
    inline void setString(string _str) { str = _str; };
	/**
	 * @brief renvoie le perimetre de l'ellipse
	 * 
	 * @return double 
	 */
    double perimeter() const;
/**
protected:
    virtual ostream &write(ostream &os) const;

    
    virtual ostream &write(ostream &os) const;**/

};

#endif