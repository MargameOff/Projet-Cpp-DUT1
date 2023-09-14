#ifndef Triangle_HPP
#define Triangle_HPP

#include <vector>
#include <cmath>

#include "Shape.hpp"
#include "Point.hpp"
/**
 * @brief Declaration de la classe Triangle, classe fille de Shape
 * 
 */
class Triangle : public Shape
{

private:
	Point Anchor;/*!< Instantiation de Point qui stock les coordonnées de l'ancre */
	Point p1;/*!< Instantiation de Point qui stock les coordonnées du premier point */
	Point p2;/*!< Instantiation de Point qui stock les coordonnées du deuxieme point */
	
	Point *PointSelect;	/*!< Pointeur sur le point selectionnée par l'utilisateur */
	Point previousAnchor;/*!< Instantiation de Point qui stock les copie des corrdonnées de l'ancre, elle est utilisé comme sauvegarde */
	bool PressSommet = false;/*!< bool qui indique si un sommet est selectionné ou non */
	bool PressAnchor = false;/*!< bool qui indique si l'ancre est selectionnée ou non */

public:
/**
 * @brief Constructeur de Triangle a plusieurs parametre
 * 
 * @param _couleur indique la couleur du contour de la forme
 * @param _x represente l'abscisse de l'ancre
 * @param _y represente l'ordonnée de l'ancre
 * @param _x1 represente l'abscisse du point1
 * @param _y1 represente l'ordonnée du point1
 * @param _x2 represente l'abscisse du point2
 * @param _y2 represente l'ordonnée du point2
 */
	Triangle(ulong _couleur, uint _x, uint _y, uint _x1, uint _y1, uint _x2, uint _y2);
/**
 * @brief Constructeur de copie de la classe Triangle 
 * 
 * @param orig l'adresse du Triangle que l'on souhaite copié
 */
	Triangle(const Triangle &orig);

	Triangle(istream &is);

/**
 * @brief Destructeur de la classe Triangle
 * 
 */
	~Triangle();
/**
 * @brief dessine dnas une fenetre EZWindow une instantiation de Triangle
 * 
 * @param w fenetre EZWindow
 * @param isActive booléen qui indique si la forme est selectionner
 */
	void draw(EZWindow &w, bool isActive) const override;
/**
 * @brief Donne le permettre de l'instantiation Triangle
 * 
 * @return double le perimetre
 */
	double perimeter() const;
/**
 * @brief Getter qui renvoie le nombre de points 
 * 
 * @return size_t egale à 3, correspond au nombre de sommets d'un triangle
 */
	inline size_t getNbPoint() const { return 3; };
/**
 * @brief permet de faire translater une instantiation de la classe Triangle sur le canvas
 * 
 */
	void moveTriangle();
/**
 * @brief Permet d'emmetre un signal lorsque la souris click sur un sommet
 * 
 * @param x abscisse de la souris
 * @param y ordonnée de la souris
 */
	void signalClicked(uint x, uint y);
/**
 * @brief Setter modifiant l'adresse pointer par PointSelect
 * 
 * @param ppoint l'adresse du nouveau point selectionné
 */
	inline void setPointSelect(Point *ppoint) { PointSelect = ppoint; };
/**
 * @brief modifie les coordonnées d'un sommet
 * 
 * @param x la nouvelle abscisse 
 * @param y la nouvelle ordonnée
 */
	void setXYSommet(uint x, uint y);
/**
 * @brief Indique si un sommet est selectionné ou non
 * 
 * @return true le sommet est selectionné
 * @return false le sommet n'est pas selectionné
 */
	bool sommetIsSelect() const;
/**
 * @brief pour connaitre la distance entre deux points
 * 
 * @param x1 l'abscisse d'un premier point
 * @param y1 l'ordonnée d'un premier point
 * @param x2 l'abscisse d'un second point
 * @param y2 l'ordonnée d'un second point
 * @return double la distance entre deux points
 */
	inline double length(uint x1, uint y1, uint x2, uint y2) const { return ((getmax(x1, x2) - getmin(x1, x2) + getmax(y1, y2) - getmin(y1, y2)) / 2); }
/**
 * @brief renvoie la plus petite coordonnée
 * 
 * @param x1 premiere coordonnée 
 * @param x2 seconde coordonnée 
 * @return uint coordonée la plus petite
 */
	inline uint getmin(uint x1, uint x2) const
	{
		if (x1 >= x2)
		{
			return x2;
		}
		else
		{
			return x1;
		}
	}
/**
 * @brief renvoie la plus grande coordonnée 
 * 
 * @param x1 premiere coordonnée 
 * @param x2 seconde coordonnée 
 * @return uint coordonée la plus grande
 */
	inline uint getmax(uint x1, uint x2) const
	{
		if (x1 >= x2)
		{
			return x1;
		}
		else
		{
			return x2;
		}
	}
/**
 * @brief un sommet est pointé
 * 
 * @param x abscisse de la souris
 * @param y ordonnée de la souris
 * @return true les coordonnées correspondent
 * @return false les coordonnées ne correspondent pas
 */
	bool sommetOver(uint x, uint y) const;
/**
 * @brief Getter qui dit si un sommet est selectionnée ou non
 * 
 * @return true il existe un sommet selectionné
 * @return false aucun des sommets n'est selectionné
 */
	inline bool getPressSommet() const { return PressSommet; };
/**
 * @brief Setter qui modifie la donnée membre PressSommet
 * 
 * @param _PressSommet indique si un sommet est selectionné ou non
 */
	inline void setPressSommet(bool _PressSommet) { PressSommet = _PressSommet; };
/**
 * @brief Getter qui renvoie l'adresse du point selectionné 
 * 
 * @return Point* adresse du point de la classe Triangle qui est selectionné
 */	
	inline Point *getPointSelect() { return PointSelect; }
/**
 * @brief Getter qui permet de retourner si l'ancre est selectionné ou non
 * 
 * @return true l'ancre est selectionné
 * @return false l'ancre n'est pas selectionné
 */
	inline bool getPressAnchor() const { return PressAnchor; };
/**
 * @brief Setter qui modifie la donnée membre PressAnchor
 * 
 * @param _PressAnchor indique si l'ancre est selectionnée ou non
 */
	inline void setPressAnchor(bool _PressAnchor) { PressAnchor = _PressAnchor; };
/**
 * @brief Indique si les coordonées de la souris correspondent au coordonnées de l'ancre
 * 
 * @param x nombre representant l'abcisse de la souris
 * @param y nombre representant l'ordonnée de la souris
 * @return true la souris est sur l'ancre
 * @return false la souris n'est pas sur l'ancre
 */
	inline bool AnchorIsOnTheMouse(uint x, uint y) const { return getAnchor().isOver(x, y); };
/**
 * @brief Execute une sauvegarde des points de l'ancre
 * 
 */
	void savePoint();

protected:
	virtual ostream &write(ostream &os) const;
};

#endif