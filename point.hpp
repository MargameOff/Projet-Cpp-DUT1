/**
 * @file point.hpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief déclaration de la classe point
 * 
 */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

using namespace std;

#include "EZ-Draw++.hpp"

typedef unsigned int uint;
typedef unsigned long int ulong;
/**
 * Classe point
 * @brief Classe permettant de creer un point 
 * 
 */
class Point
{
private: //données membres
    uint size = 3; /*!< taille de selection du point*/
    uint x, y; /*!< uint coordonnées x et y*/

public:
    /**
     * @brief Constructeur de point a 2 paramètre
     * 
     * @param x coordonnée x
     * @param y coordonnée y
     */
    Point(uint x=100, uint y=100);

    /**
     * @brief constructeur de copie de l'objet point
     * 
     * @param orig 
     */
    Point(const Point &orig);
    /**
 	 * @brief Fonction de création par lecture de flux d'entré d'une instance de point
	 * 
	 * @param orig  stock un flux

     */
    Point(istream &is);
    /**
     * @brief Destructeur de l'objet point 
     * 
     */
    ~Point();
    /**
     * @brief renvoie la valeur pour la coordonnée x
     * 
     * @return uint x
     */
    inline uint getX() const { return x; };
    /**
     * @brief renvoie la valeur pour la coordonnée y
     * 
     * @return uint y
     */
    inline uint getY() const { return y; };
    /**
     * @brief change la valeur pour la coordonnée x
     * 
     * @param _x 
     */
    inline void setX(uint _x) { x = _x; }
    /**
     * @brief change la valeur pour la coordonnée y
     * 
     * @param _y 
     */
    inline void setY(uint _y) { y = _y; }
    /**
     * @brief change la valeur des coordonnées
     * 
     * @param _x nouveau x
     * @param _y nouveau y
     */
    inline void setXY(uint _x, uint _y)
    {
        x = _x;
        y = _y;
    }
    /**
     * @brief Fonction qui indique si les coordonnées indiquées correspondent à celles du point
     * 
     * @param _x coordonnée x
     * @param _y coordonnée y 
     * @return true 
     * @return false 
     */
     inline bool isOver(uint _x, uint _y) const { return (x - size <= _x && _x <= x + size) && (y - size <= _y && _y <= y + size); };
    /**
     * @brief fonction permettant de dessiner un point
     * 
	 * @param window fenetre sur laquelle est dessiner le point
	 * @param isActive indique si forme selectionner 
     */
    void draw(EZWindow &window, bool active) const;
    /**
     * @brief Setter pour les coordonnée
     * 
     * @param _size taille de nouvelle taille
     */
    inline void setSize(uint _size) { size = _size; };
    /**
     * @brief getter de taille 
     * 
     * @return uint de taille  
     */
    inline uint getSize() const { return size; };
    /**
     * @brief fonction permettant d'écrire un point  
     * 
     * @param os sorit
     * @param p le point a écrire
     * @return ostream& contenant le flux
     */
    friend ostream &operator<<(ostream &os, const Point &p);
    /**
     * @brief fonction permettant de lire un point
     * 
     * @param is entrée
     * @param p le point a lire 
     * @return istream& contenant le flux
     */
    friend istream &operator>>(istream &is, Point &p);
};

#endif
