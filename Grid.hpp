/**
 * @file Grid.hpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief déclaration de la classe Grid
 */

#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>
#include <stdexcept>

using namespace std;

#include "shape.hpp"

typedef unsigned int uint; 
typedef unsigned long int ulong;


/**
 * @brief Classe permettant de créer une instance de grille 
 * 
 */
class Grid : public Shape
{
private:
	uint width; /*!< uint largeur des grilles  */
	uint height; /*!< uint auteur des grilles */
    size_t nbLines;/*!< size_t nombre de ligne */
	size_t nbColumns; /*!< size_t nombre de colonne */


public:
/**
 * @brief construit une nouvelle instance de grille
 * 
 * @param color couleur de la grille
 * @param x abscisse de le l'ancre
 * @param y ordonnée de l'ancre 
 * @param width largeur de la grille 
 * @param height hauteur de la grille 
 * @param nbLines nombre de ligne d'une grille 
 * @param nbColumns nombre de colonne d'une grille 
 */
	Grid(ulong color, uint x, uint y, uint width, uint height, size_t nbLines, size_t nbColumns);
	/**
	 * @brief constructeur de copie de l'objet grille 
	 * 
	 * @param orig 
	 */
	Grid(const Grid &orig);
	/**
	 * @brief Fonction de création par lecture de flux d'entré d'une instance de grille 
	 * 
	 * @param orig  stock un flux
	 */
	Grid(istream &is);
	/**
	 * @brief  destructeur de l'objet grille
	 * 
	 */
	~Grid();
	/**
	 * @brief dessine la forme grille 
	 * 
	 * @param window fenetre sur laquelle est dessiner l'ellipse
	 * @param isActive indique si forme selectionner 
	 */
	void draw(EZWindow &window, bool isActive = false) const;
	/**
	 * @brief renvoie la largeur de l'objet grille 
	 * 
	 * @return uint qui contient la largeur de l'objet grille
	 */
    inline uint getHeight() const { return height; }
	/**
	 * @brief renvoie la hauteur de l'objet grille 
	 * 
	 * @return uint qui contient la hauteur de l'objet grille 
	 */
	inline uint getWidth() const { return width; }
	/**
	 * @brief renvoie le nombre de ligne de l'objet grille 
	 * 
	 * @return uint ui contient le nombre de ligne de l'objet grille
	 */
    inline uint getNbLines() const { return nbLines; }
	/**
	 * @brief renvoie le nombre de colone de l'objet grille 
	 * 
	 * @return uint qui contient le nombre de colone de l'objet grille 
	 */
    inline uint getNnbColumns() const { return nbColumns; }
	/**
	 * @brief change la largeur de l'objet grille
	 * 
	 * @param _width uint qui contient la largeur de l'objet
	 */
	inline void setWidth(uint _width) { width = _width; }
	/**
	 * @brief change la hauteur de l'objet grille 
	 * 
	 * @param _height uint qui contient la hauteur de l'objet grille 
	 */
	inline void setHeight(uint _height) { height = _height; }
	/**
	 * @brief change le nombre de ligne de l'objet grille 
	 * 
	 * @param _nbLines uint qui contient le nombre de ligne de l'objet grille 
	 */
    inline void setNbLines(uint _nbLines) { nbLines = _nbLines; }
	/**
	 * @brief change le nombre de colone de l'objet grille 
	 * 
	 * @param _nbColumns qui contient le nombre de colone de l'objet grille 
	 */
    inline void setNbColumns(uint _nbColumns) { nbColumns = _nbColumns; }
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
	virtual ostream &write(ostream &os) const;
};

#endif