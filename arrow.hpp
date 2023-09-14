/**
 * @file arrow.hpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief declaration de la classe arrow

 * 
 */
#ifndef ARROW_HPP
#define ARROW_HPP

#include "shape.hpp"
#include "Point.hpp"
#include <vector>
#include <cmath>

using namespace std; 

typedef unsigned int uint;
typedef unsigned long int ulong;

/**
 * classe arrow 
 * @brief classe permettant de créer des flèches 
 * 
 */

class Arrow : public Shape {
    std::vector<Point> tabPoint;
	Point *PointSelect;

	uint width; /*!< uint largeur de la flèche*/
    uint height;/*!< uint hauteur de la flèche*/

	int previousAnchorX; /*!<int sauvegarde de getAnchor.getX(), stock l'ancienne abscisse */
	int previousAnchorY; /*!<int sauvegarde de getAnchor.getiY(), stock l'ancienne ordonnée */

	bool PressAnchor = false; /*!<bool indique quand l'ancre est selectionnée */
	bool PressSommet = false; /*!<bool indique quand un sommet est selectionné*/

public:
/**
 * @brief construit une nouvelle instance de flèche 
 * 
 * @param _color couleur de la flèche
 * @param _x abscisse de l'ancre 
 * @param _y ordonnée de l'ancre 
 * @param _tabPoint tableau de point contenant les sommets de la flèche
 * @param width largeur de la flèche 
 * @param _height hauteur de la flèche 
 */
	Arrow(ulong _color, int _x, int _y, std::vector<Point> _tabPoint, uint width , uint _height);
	/**
	 * @brief Constructeur de copie de l'objet flèche
	 * 
	 * @param orig 
	 */
	Arrow(const Arrow &orig);
	/**
	 * @brief destructeur de l'objet flèche
	 * 
	 */
	~Arrow();
	 
	/**
 	* @brief  renvoie le perimetre
 	*
 	* @return double qui contient le perimetre.
 	*/
	
	double perimeter() const;
	/**
	 * @brief renvoie la largeur de la flèche 
	 * 
	 * @return uint qui contient la largeur de la flèche
	 */
	inline uint getWidth() const { return width; };
	/**
	 * @brief change la larggeur de la flèche 
	 * 
	 * @param _width uint qui conient la largeur de  la flèche 
	 */
	inline void setWidth(uint _width) { width = _width; };
	/**
	 * @brief renvoie la hauteur de la flèche
	 * 
	 * @return uint qui contient la hauteur flèche
	 */
	inline uint getHeight() const { return height; };
	/**
	 * @brief change la hauteur de la flèche 
	 * 
	 * @param _height uint qui contient la hauteur de la flèche 
	 */
	inline void setHeight(uint _height) { height = _height; };
	/**
 	* @brief Getter qui dit si un sommet est selectionnée ou non
 	* 
 	* @return true il existe un sommet selectionné
 	* @return false aucun des sommets n'est selectionné
 	*/
	inline bool getPressSommet() const { return PressSommet; };
	/**
	 * @brief Getter qui renvoie l'adresse du point selectionné 
 	* 
 	* @return Point* adresse du point de la classe Triangle qui est selectionné
 	*/	
	inline void setPressSommet(bool _PressSommet) { PressSommet = _PressSommet; };
	/**
 	* @brief Setter qui modifie la donnée membre PressAnchor
 	* 
 	* @param _PressAnchor indique si l'ancre est selectionnée ou non
 	*/
	inline void setPressAnchor(bool _PressAnchor) { PressAnchor = _PressAnchor; };
	/**
 	* @brief Getter qui permet de retourner si l'ancre est selectionné ou non
 	* 
 	* @return true l'ancre est selectionné
 	* @return false l'ancre n'est pas selectionnée
 	*/
	inline bool getPressAnchor() const { return PressAnchor; };
	/**
 	* @brief Indique si les coordonées de la souris correspondent au coordonnées de l'ancre
 	* 
 	* @param x nombre representant l'abcisse de la souris
 	* @param y nombre representant l'ordonnée de la souris
 	* @return true la souris est sur l'ancre
 	* @return false la souris n'est pas sur l'ancre
 	*/
	inline bool AnchorIsOnTheMouse(int x, int y) const { return getAnchor().isOver(x, y); };
	/**
 	* @brief Getter qui permet de retourner si l'ancre est selectionné ou non
 	* 
 	* @return true l'ancre est selectionné
 	* @return false l'ancre n'est pas selectionné
 	*/
	inline Point *getPointSelect() { return PointSelect; }
	/**
 	* @brief modifie les coordonnées d'un sommet
 	* 
 	* @param x la nouvelle abscisse 
 	* @param y la nouvelle ordonnée
 	*/
	inline void setXYSommet(int x, int y)
	{
		if (PointSelect != nullptr)
		{
			PointSelect->setXY(x, y);
		}
	}
	/**
 	* @brief Getter qui renvoie l'adresse du point selectionné 
 	* 
 	* @return Point* adresse du point de la classe Triangle qui est selectionné
 	*/	
	inline void setPointSelect(Point *ppoint) { PointSelect = ppoint; }

	/**
	 * @brief dessine l'objet flèche 
	 * 
	 * @param window fenetre sur laquelle est dessiner la flèche 
	 * @param isActive indique si forme selectionner 	 

	 */
	void draw(EZWindow &w, bool isActive) const override;
	/**
 	* @brief permet de faire translater une instantiation de la classe arrow sur le canvas
	* 
 	*/
	void moveArrow();
	/**
 	* @brief Permet d'emmetre un signal lorsque la souris click sur un sommet
 	* 
 	* @param x abscisse de la souris
 	* @param y ordonnée de la souris
 	*/
	void signalClicked(int x, int y);
	/**
 	* @brief Indique si un sommet est selectionné ou non
 	* 
 	* @return true le sommet est selectionné
 	* @return false le sommet n'est pas selectionné
 	*/
	bool sommetIsSelect() const;
	/**
 	* @brief un sommet est pointé
 	* 
 	* @param x abscisse de la souris
 	* @param y ordonnée de la souris
 	* @return true les coordonnées correspondent
 	* @return false les coordonnées ne correspondent pas
 	*/
	bool sommetOver(int x, int y) const;
	/**
 	* @brief Execute une sauvegarde des points de l'ancre
 	* 
 	*/
	void savePoint();

/*protected:

	virtual ostream &write(ostream &os) const;*/
};
#endif