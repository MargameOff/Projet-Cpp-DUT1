#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "Point.hpp"

typedef unsigned int uint;
typedef unsigned long int ulong;
/**
 * @brief Declaration de la classe Shape
 * 
 */
class Shape
{
private:
    ulong color; /*!< stock la couleur de contour*/
    Point anchor;/*!< stock le point de l'ancre*/
    bool selected;/*!< dit si le shape est selectionné ou pas*/
    uint thickness = 1;/*!< Stock la largeur du contour*/
    int changeDroite = 0;/*!< stock la valeur lors du changement de taille par la droite*/
    int changeGauche = 0;/*!< stock la valeur lors du changement de taille par la gauche*/
    int changeHaut = 0;/*!< stock la valeur lors du changement de taille par le haut*/
    int changeBas = 0;/*!< stock la valeur lors du changement de taille par le bas*/
    bool Full = false;/*!< booléen qui indique si la forme est remplit ou non*/

public:
/**
 * @brief Constructeur a plusieur parametres
 * 
 * @param color la couleur de la forme
 * @param x l'abscisse de l'ancre
 * @param y l'ordonnée de l'ancre
 */
    Shape(ulong color, uint x, uint y);
/**
 * @brief Constructeur de copie 
 * 
 * @param orig le shape d'origine que l'on veux cloner
 */
    Shape(const Shape &orig);
/**
 * @brief Constructeur par flux d'entrée
 * 
 * @param is le flux d'entrée
 */
    Shape(istream &is);
/**
 * @brief destructeur de la classe shape
 * 
 */
    virtual ~Shape();
/**
 * @brief Getter couleur
 * 
 * @return ulong la couleur de la forme
 */
    inline ulong getColor() const { return color; }
/**
 * @brief Setter couleur
 * 
 * @param _color la couleur que l'on veut affecter a notre shape
 */
    inline void setColor(ulong _color) { color = _color; }
/**
 * @brief retounre le perimetre
 * 
 * @return double le perimettre
 */
    virtual double perimeter() const = 0;
/**
 * @brief Getter changeDroite
 * 
 * @return int la valeur dont on a modifer la taille de l'image par la droite
 */
    inline int getChangeDroite() const { return changeDroite; }
/**
 * @brief Getter changeBas
 * 
 * @return int la valeur dont on a modifer la taille de l'image par la bas
 */
    inline int getChangeBas() const { return changeBas; }
/**
 * @brief Getter changeGauche
 * 
 * @return int la valeur dont on a modifer la taille de l'image par la gauche
 */
    inline int getChangeGauche() const { return changeGauche; }
    /**
 * @brief Getter changeHaut
 * 
 * @return int la valeur dont on a modifer la taille de l'image par la haut
 */
    inline int getChangeHaut() const { return changeHaut; }
/**
 * @brief Setter changeDroite
 * 
 * @param _a modifie le changement de taille par la droite de _a
 */
    inline void setChangeDroite(int _a) { changeDroite = _a; }
    /**
 * @brief Setter changeBas
 * 
 * @param _a modifie le changement de taille par la bas de _a
 */
    inline void setChangeBas(int _a) { changeBas = _a; }
/**
 * @brief Setter changeGauche
 * 
 * @param _a modifie le changement de taille par la gauche de _a
 */
    inline void setChangeGauche(int _a) { changeGauche = _a; }
/**
 * @brief Setter changeHaut
 * 
 * @param _a modifie le changement de taille par le haut de _a
 */
    inline void setChangeHaut(int _a) { changeHaut = _a; }
/**
 * @brief Getter de l'ancre
 * 
 * @return Point renvoie le x et le y de l'ancre
 */
    inline Point getAnchor() const { return anchor; }
/**
 * @brief Setter setAnchor
 * 
 * @param _a modifie les coordonnées de l'ancre
 */
    inline void setAnchor(uint x, uint y) { anchor.setXY(x, y); }
/**
 * @brief Getter selected
 * 
 * @return true si la fome est selectionné
 * @return false si la forme n'est pas selectionnée
 */
    inline bool getSelected() const { return selected; }
/**
 * @brief Setter selected
 * 
 * @param c modifie la donnée membre Selected d'une shape
 */
    inline void setSelected(bool c) { selected = c; }
/**
 * @brief Getter Epaisseur
 * 
 * @return uint recupere l'eppaisseur d'une shape
 */
    inline uint getThickness() const { return thickness; }
/**
 * @brief Setter epaisseur
 * 
 * @param _thickness valeur par laquelle est remplacer la donnée membre Trichness
 */
    inline void setThickness(uint _thickness) { thickness = _thickness; }
    /**
     * @brief Getter Full
     * 
     * @return true la forme est remplit (coloriage)
     * @return false la forme n'est pas remplit (coloriage)
     */
    inline bool getFull() const { return Full; }
    /**
     * @brief Setter Full
     * 
     * @param _Full modifie l'etat d'un remplissage d'une shape
     */
    inline void setFull(bool _Full) { Full = _Full; }
    /**
     * @brief calcul si la souris est sur une shape
     * 
     * @param x abscisse de la souris
     * @param y ordonnée de la souris
     * @return true les coordonnées souris-ancre correspondent : la souris survole une ancre
     * @return false les coordonnées souris-ancre ne correspondent pas.
     */
    inline bool isOver(uint x, uint y) const { return anchor.isOver(x, y); };
    /**
     * @brief Permet de dessiner une instance de forme sur le canvas
     * 
     * @param window fenetre EZDWindow sur laquelle on dessine l'instance de shape
     * @param isActive l'etat de la fenetre
     */
    virtual void draw(EZWindow &window, bool isActive = false) const;
/**
 * @brief surchage de l'operateur <<
 * 
 * @param os contient un flux de sortie
 * @param shape une reference de shape
 * @return ostream& un flux de sortie
 */
    friend ostream &operator<<(ostream &os, const Shape &shape);
    /**
     * @brief charger une forme
     * 
     * @param is un flux d'entrée
     * @return Shape* un pointeur sur shape
     */
    static Shape *load(istream &is);

protected:
	/**
	 * @brief fonction qui renvoie dans un flux de sortie la valeur de ses données membres ainsi que celle de ses classes - filles
	 * 
	 * @param os contient un flux 
	 * @return ostream& renvoie un flux 
	 */
    virtual ostream &write(ostream &os) const;
};

#endif
