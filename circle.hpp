#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

typedef unsigned int uint;
typedef unsigned long int ulong;

/**
 * @brief Déclaration de la classe cercle 
 * 
 */
class Circle : public Shape
{
private:
	uint radius; /*!< uint rayon du cercle*/

public:
	/**
 	* @brief construit un nouvelle objet cercle 
 	*	 
 	* @param color couleur du cercle 
 	* @param x abscisse de l'ancre 
 	* @param y ordonnée de l'ancre 
 	* @param radius rayon du cercle 
 	*/
	Circle(ulong color, uint x, uint y, uint radius);
 
	/**
	 * @brief constructeur de copie de l'objet cercle 
	 * @param orig 
	 */
	Circle(const Circle &orig);
		/**
	 * @brief Fonction de création par lecture d'une instance d'un cerle 
	 * 
	 * @param orig  stock un flux
	 */
	
	Circle(istream &orig);
	/**
	 * @brief Destrcuteur de l'objet cercle 
	 * 
	 */
	~Circle();
	/**
	 * @brief dessine la forme d'un cercle 
	 * 
	 * @param window fenetre sur laquelle est dessiner le cercle
	 * @param isActive indique si forme selectionner 
	 */
	void draw(EZWindow &window, bool isActive = false) const;
	/**
	 * @brief renvoie le rayon
	 * 
	 * @param _radius qui contient le rayon a renvoyé 
	 */
	inline uint getRadius() const { return radius; };
	/**
	 * @brief change le rayon 
	 * 
	 * @param _radius contient le rayon 
	 */
	inline void setRadius(uint _radius) { radius = _radius; };
	/**
 	* @brief  renvoie le perimetre
 	*
 	* @return double qui contient le perimetre.
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