/**
 * @file square.hpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
*
 * 
 * @brief declaration de la classe square 
 * 
 */
#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"

typedef unsigned int uint;
typedef unsigned long int ulong;


/**
 * Classe square 
 * @brief Classe permettant de créer des carrés 
 * 
 */
class Square : public Shape
{
private:
	uint length;  /*!< uint taille du cote du carre*/

public:
/**
 * @brief Construit le nouvelle objet carré
 * 
 * @param color couleur de carré
 * @param x abscisse de l'ancre du carré 
 * @param y ordonnée de l'ancre du carré
 * @param length taille du cote d'un carré
 */
	Square(ulong color, uint x, uint y, uint length);
	/**
	 * @brief Constructeur de copie de l'objet carrée
	 * 
	 * @param orig 
	 */
	Square(const Square &orig);
	/**
	 * @brief Fonction de création par lecture d'une instance d'un carrée
	 * 
	 * @param is stock un flux 
	 */
	Square(istream &is);
	/**
	 * @brief Destructeur de l'objet carré
	 */
	~Square();

	/**
	 * @brief dessine la forme d'un carré
	 * 
	 * @param window fenetre sur laqeulle on va dessiner 
	 * @param isActive indique si la forme est selectionner
	 */
	void draw(EZWindow &window, bool isActive = false) const override;
	/**
	 * @brief renvoie la taille d'un coté
	 * 
	 * @return uint contient la taille du coté d'un carré
	 */
	inline uint getLength() const { return length; };
	/**
	 * @brief renvoie le perimetre 
	 * 
	 * @param _length contient le perimetre
	 */
	inline void setLength(uint _length) { length = _length; };
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
	ostream &write(ostream &) const;
};

#endif