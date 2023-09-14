#ifndef Polygone_HPP
#define Polygone_HPP

#include <vector>
#include <cmath>

#include "Shape.hpp"
#include "point.hpp"
/**
 * @brief Declaration de la classe Polygone, classe fille de Shape
 * 
 */
class Polygone : public Shape
{
private:
	std::vector<Point> tabPoint;/*!< Tableau de points */
	Point *PointSelect;/*!< Pointeur sur le Point selectionné par l'utilisateur */

	bool PressAnchor = false;/*!< booléen qui indique que l'utilisateur a selectionner l'ancre */
	bool PressSommet = false;/*!<booléen qui indique que l'utilisateur a selectionner un sommet */
	int previousAnchorX;/*!< sauvegarde l'ancienne abcsisse de l'ancre */
	int previousAnchorY;/*!< sauvegarde l'ancienne ordonnée de l'ancre */
	uint radius;/*!< uint qui stock un rayon, utilisé ici comme taille */

public:
/**
 * @brief Constructeur de la classe polygone a plusieurs parametres
 * 
 * @param _color stock la valeur d'une couleur. Elle definira la couleur du contour de la forme
 * @param _x stock l'abscisse de l'ancre
 * @param _y stock l'ordonnée de l'ancre
 * @param _tabPoint stock tous les points constituant le polynome sous la forme d'un tableau
 * @param _radius uint qui stock un rayon, utilisé ici commme taille
 */
	Polygone(ulong _color, int _x, int _y, std::vector<Point> _tabPoint, uint _radius);
	/**
	 * @brief Constructeur de copie de la classe Polynome
	 * 
	 * @param orig instantiation de Polynome que l'on souhaite copié
	 */
	Polygone(const Polygone &orig);

	Polygone(istream &is);

	/**
	 * @brief Destructeur de la classe polygone
	 * 
	 */
	~Polygone();
/**
 * @brief retourne le parametre
 *  
 * @return double le parametre du polygone 
 */
		double perimeter() const;
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
 * @brief Setter qui modifie la donnée membre PressAnchor
 * 
 * @param _PressAnchor indique si l'ancre est selectionnée ou non
 */
	inline void setPressAnchor(bool _PressAnchor) { PressAnchor = _PressAnchor; };
/**
 * @brief Getter qui permet de retourner si l'ancre est selectionné ou non
 * 
 * @return true l'ancre est selectionné
 * @return false l'ancre n'est pas selectionné
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
 * @brief Getter qui renvoie l'adresse du point selectionné 
 * 
 * @return Point* adresse du point de la classe Polygone qui est selectionné
 */
	inline Point *getPointSelect() { return PointSelect; }

/**
 * @brief permet de faire translater une instantiation de la classe Etoile sur le canvas
 * 
 */
	void movePolygone();
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
 * @brief Setter modifiant l'adresse pointer par PointSelect
 * 
 * @param ppoint l'adresse du nouveau point selectionné
 */
	inline void setPointSelect(Point *ppoint) { PointSelect = ppoint; }
/**
 * @brief Getter indiquant le nombre de point contenue dans une instance d'Polygone
 * 
 * @return size_t le nombre de points du tableau de Point consituant une Polygone
 */
	inline size_t getNbPoint() const { return tabPoint.size(); }
/**
 * @brief Dessiner une instancitation de la class Polygone sur une fenetre EZWindow
 * 
 * @param w instantiation de la fenetre EZWindow
 * @param isActive booléen qui indique si la forme est selectionner
 */
	void draw(EZWindow &w, bool isActive) const override;
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
	void addPoint();
	void suprrPoint();

protected:
	virtual ostream &write(ostream &os) const;
};

#endif