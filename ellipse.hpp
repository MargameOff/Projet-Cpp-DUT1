/**
 * @file ellipse.hpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * 
 * 
 * @brief  déclaration de la classe Ellipse 
 * 
 */



#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"

typedef unsigned int uint;
typedef unsigned long int ulong;

/**
 * Classe Ellipse
 * @brief Classe permettant de créer une ellipse
 * 
 */
class Ellipse : public Shape
{
private:
	uint semiWidth; /*!< uint Demi-largeur de l'ellipse */
	uint semiHeight; /*!< uint Demi-hauteur de l'ellipse */

public:
	/**
	 * @brief construit le nouvelle objet ellipse
	 * 
	 * @param color couleur de l'ellipse  
	 * @param x 	abscisse de l'ancre 
	 * @param y 	ordonnée de l'ancre de l'ellipse 
	 * @param semiWidth semi-largeur de l'ellipse 
	 * @param semiHeight semi-hauteur de l'ellipse
	 */
	Ellipse(ulong color, uint x, uint y, uint semiWidth, uint semiHeight);
	/**
	 * @brief constructeur de copie de l'objet ellipse
	 * 
	 * @param orig 
	 */
	Ellipse(const Ellipse &orig);
	/**
	 * @brief Fonction de création par lecture d'une instance d'une ellipse 
	 * 
	 * @param is stock un flux
	 */
	Ellipse(istream &is);
	/**
	 * @brief Destructeur de l'objet ellipse 
	 * 
	 */
	~Ellipse();
	/**
	 * @brief dessine la forme ellipse
	 * 
	 * @param window fenetre sur laquelle est dessiner l'ellipse
	 * @param isActive indique si forme selectionner 
	 */
	void draw(EZWindow &window, bool isActive = false) const;
	/**
	 * @brief renvoie la semi-largeur de l'ellipse
	 * 
	 * @return uint qui contient la semi-largeur de l'ellipse
	 */
	uint getSemiWidth() const { return semiWidth; };
	/**
	 * @brief change la semi-largeur de l'ellipse
	 * 
	 * @param _semiWidth uint qui contient la semi-largeur de l'ellipse 
	 */
	void setSemiWidth(uint _semiWidth) { semiWidth = _semiWidth; };
		/**
	 * @brief renvoie la semi-hauteur de l'ellipse
	 * 
	 * @return uint qui contient la semi-hauteur de l'ellipse
	 */
	uint getSemiHeight() const { return semiHeight; };
		/**
	 * @brief change la semi-hauteur de l'ellipse
	 * 
	 * @param _semiWidth uint qui contient la semi-hauteur de l'ellipse 
	 */

	void setSemiHeight(uint _semiHeight) { semiHeight = _semiHeight; };
	/**
	 * @brief renvoie le perimetre de l'ellipse
	 * 
	 * @return double 
	 */
	double perimeter() const;

protected:
	/**
	 * @brief fonction qui renvoie dans un flux de sortie la valeur de ses données membres 
	 * 
	 * @param os contient un flux 
	 * @return ostream& renvoie un flux 
	 */
	ostream &write(ostream &os) const;
};

#endif
