/**
 * @file setofshapes.hpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief delaration de la classe setofshapes
 * 
 */
#ifndef SETOFSHAPES_HPP
#define SETOFSHAPES_HPP

#include "shape.hpp"

typedef unsigned int uint;
typedef unsigned long int ulong;

/**
 * class setofshapes
 * @brief classe permettant la gestion des formes 
 * 
 */
class SetOfShapes
{
private:
    size_t maxShapes; /*!< size_t nombre maximal de formes*/
    size_t nbShapes; /*!< size_t nombre de formes*/
    Shape **shapes; /*!< Formes** tableau de formes*/

bool IsDisplay = true; /*!< bool est afficher*/
public:
    /**
     * @brief constructeur de formes
     * 
     * @param maxShapes spécifie le nombre de forme
     */
    SetOfShapes(size_t maxShapes = 10);
    /**
     * @brief constructeur de copie du constructeur de formes
     * 
     * @param orig 
     */
    SetOfShapes(const SetOfShapes &orig);
    /**
	 * @brief Fonction de création par lecture d'une instance d'un constructeur de forme 
	 * 
	 * @param is stock un flux
     */

    SetOfShapes(istream &is);
    /**
     * @brief Destructeur de l'objet setofshapes
     * 
     */
    ~SetOfShapes();
        /**
     * @brief getter pour le nombre de forme 
     * 
     * @param _nb  
     */
    inline size_t getNbShapes() const { return nbShapes; }
    /**
     * @brief setter pour le nombre de forme 
     * 
     * @param _nb 
     */
    inline void setNbShapes(size_t _nb) { nbShapes = _nb; }
    /**
     * @brief getteur pour le booléen qui indique si les formes sont affichées ou non
     * 
     * @return true 
     * @return false 
     */
    inline bool getIsDisplay()  { return IsDisplay; }
    /**
     * @brief Setter pour indique si les formes sont affichées ou non
     * 
     * @param b le bool
     */
	inline void setIsDisplay(bool b) { IsDisplay=b; }
    /**
     * @brief Getter nombre max de shapes dans un setofshape
     * 
     * @return size_t nombre max de shape sur un setofshape
     */
    inline size_t getMaxShapes() const { return maxShapes; }
    /**
     * @brief getter sur un instanciation de forme 
     * 
     * @return Shape** le shape pointé
     */
    inline Shape **getShapes() { return shapes; }
    /**
     * @brief setteur qui permet d'avoir plusieurs formes
     * 
     * @param _shapes 
     */
    inline void setShapes(Shape **_shapes) { shapes = _shapes; }
    /**
     * @brief  fonction pour ajouter une forme 
     * 
     * @param pshape la forme a ajouter
     */
    void add(Shape *pshape);
    /**
     * @brief fonction pour indiquer la fome indiquée par les coordonnée
     
     * @param x 
     * @param y 
     * @return Shape* 
     */
    Shape *isOver(uint x, uint y) const;
    /**
     * @brief fonction permettant de dessiner les formes
     * 
     * @param window fenetre ou l'on dessine les formes 
     */
    void draw(EZWindow &window) const;
    /**
     * @brief fonction permettant d'ecrire les formes
     * 
     * @param os sortie ou on écrit
     * @param setOfShapes le tableau de formes a écrire
     * @return ostream& 
     */
    friend ostream &operator<<(ostream &os, const SetOfShapes &setOfShapes);
    /**
     * @brief fonction permettant de sauvgarder les formes
     * 
     * @param os sortie
     */
    void save(ostream &os) const;
    /**
     * @brief permettant de recharger les formes 
     * 
     * @param is entré
     */
    void load(istream &is);
};

#endif
