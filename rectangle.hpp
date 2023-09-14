/**
 * @file rectangle.hpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * 
 * 
 * @brief  Déclaration de la classe rectangle
 * 
 */


#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>
#include <stdexcept>

using namespace std;

#include "shape.hpp"



typedef unsigned int uint;
typedef unsigned long int ulong;

/**
 * Classe Rectangle
 * @brief Classe permettant de créer une Rectangle
 * 
 */
class Rectangle : public Shape
{
private:
	uint width; /*!< uint largeur du rectangle*/
	uint height; /*!< uint hauteur du rectangle*/

public:
	/**
	 * @brief Construit le nouvelle objet rectangle
	 * 
	 * @param color couleur du rectangle
	 * @param x abscisse de l'ancre du rectangle
	 * @param y ordonnée de l'ancre de l'ellipse
	 * @param width lareur du rectangle
	 * @param height hauteur de rectangle
	 */
	Rectangle(ulong color, uint x, uint y, uint width, uint height);
	/**
	 * @brief Constructeur de copie de l'objet rectangle 
	 *
	 * 
	 * @param orig 
	 */
	Rectangle(const Rectangle &orig);
	/**
	 * @brief Fonction de création par lecture d'une instance d'un rectangle.
	 * 
	 * @param is stock un flux 
	 */
	Rectangle(istream &is);
/**
 * @brief destructeur de l'objet rectangle
 * 
 */
	~Rectangle();
	/**
	 * @brief dessine la forme d'un rectangle 
	 * 
	 * @param window fenetre sur laquelle est dessiner le rectangle 
	 * @param isActive indique si forme selectionner 
	 */
	void draw(EZWindow &window, bool isActive = false) const;
	/**
	 * @brief renvoie la largeur d'un rectangle
	 * 
	 * @return uint qui contient la largeur d'un rectangle
	 */
	inline uint getWidth() const { return width; };
	/**
	 * @brief change la largeur d'un rectangle 
	 * 
	 * @param _width qui contient la largeur d'un rectangle 
	 */
	inline void setWidth(uint _width) { width = _width; };
	/**
	 * @brief renvoie la hauteur d'un rectangle 
	 * @return uint qui contient la hauteur d'un rectangle
	 */
	inline uint getHeight() const { return height; };
	/**
	 * @brief renvoie la hauteur d'un rectangle
	 * 
	 * @param _height uint qui contient la largeur d'un rectangle 
	 */
	inline void setHeight(uint _height) { height = _height; };
	/**
	 * @brief fonction qui revoie le perimetre 
	 * 
	 * @return double qui contient le perimetre 
	 */

	double perimeter() const; 

protected:
	/**
	 * @brief fonction qui renvoie dans un flux de sortie la valeur de ses données membres 
	 * 
	 * @param os contient un flux 
	 * @return ostream& renvoie un flux 
	 */
	virtual ostream &write(ostream &os) const;
};

#endif