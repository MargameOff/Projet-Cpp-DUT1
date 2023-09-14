#ifndef ETOILE_HPP
#define ETOILE_HPP

#include "shape.hpp"
#include "Point.hpp"
#include <vector>
#include <cmath>

using namespace std; 

typedef unsigned int uint;
typedef unsigned long int ulong;
/**
 * @brief Declaration de la classe Etoile, classe fille de Shape
 * 
 */
class Etoile : public Shape {
    std::vector<Point> tabPoint;/*!< Tableau de points */
	Point *PointSelect;/*!< Pointeur sur le Point selectionné par l'utilisateur */

	bool PressAnchor = false;/*!< booléen qui indique que l'utilisateur a selectionner l'ancre */
	bool PressSommet = false; /*!<booléen qui indique que l'utilisateur a selectionner un sommet */
	int previousAnchorX; /*!< sauvegarde l'ancienne abcsisse de l'ancre */
	int previousAnchorY;/*!< sauvegarde l'ancienne ordonnée de l'ancre */
	uint radius;/*!< uint qui stock le rayon interieur */
    uint radius2;/*!< unint qui stock le rayon exterieur */

public:
/**
 * @brief Constructeur à plusieurs parametres
 * 
 * @param _color stock la valeur d'une couleur. Elle definira la couleur du contour de la forme
 * @param _x stock l'abscisse de l'ancre
 * @param _y stock l'ordonnée de l'ancre
 * @param _tabPoint stock tous les points constituant le polynome sous la forme d'un tableau
 * @param _radius represente le rayon interieur
 * @param _radius2 represente de rayon exterieur
 */
	Etoile(ulong _color, int _x, int _y, std::vector<Point> _tabPoint, uint _radius , uint _radius2);
/**
 * @brief Constructeur de copie
 * 
 * @param orig Instantiation de la classe Etoile que l'on souhaite copié
 */
	Etoile(const Etoile &orig);
/**
 * @brief Constructeur d'Etoile a partir d'un flux d'entrée
 * 
 * @param is fichier de flux d'entrée
 */
	Etoile(istream &is);
/**
 * @brief Destructeur de la classe Etoile
 * 
 */
	~Etoile();
/**
 * @brief donne le perimetre
 * 
 * @return double resulat correspondant au parametre
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
 * @return Point* adresse du point de la classe Etoile qui est selectionné
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
 * @brief Setter modifiant l'adresse pointer par PointSelect
 * 
 * @param ppoint l'adresse du nouveau point selectionné
 */
	inline void setPointSelect(Point *ppoint) { PointSelect = ppoint; }
/**
 * @brief Getter indiquant le nombre de point contenue dans une instance d'Etoile
 * 
 * @return size_t le nombre de points du tableau de Point consituant une Etoile
 */
	inline size_t getNbPoint() const { return tabPoint.size(); }
/**
 * @brief Dessiner une instancitation de la class Etoile sur une fenetre EZWindow
 * 
 * @param w instantiation de la fenetre EZWindow
 * @param isActive booléen qui indique si la forme est selectionner
 */
	void draw(EZWindow &w, bool isActive) const override;
/**
 * @brief permet de faire translater une instantiation de la classe Etoile sur le canvas
 * 
 */
	void moveEtoile();
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

protected:
/**
 * @brief ecrit l'instantiation de la class Etoile dans un fichier de flux de sortie
 * 
 * @param os le fichier de flux de sortie
 * @return ostream& le flux de sortie qui sera stocker dans le fichier de flux de sortie
 */
	virtual ostream &write(ostream &os) const;
};

#endif