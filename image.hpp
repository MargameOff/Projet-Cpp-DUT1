/**
 * @file image.hpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief declaration de la classe image
 * 
 */

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "shape.hpp"
/**
 * Classe Image
 * @brief classe permettant de creer des images 
 * 
 */
class Image : public Shape
{
private:
    const char *path;  /*!< uint largeur du rectangle*/
    string savepath;   /*!< uint largeur du rectangle*/
    EZImage *imageF;   /*!< uint largeur du rectangle*/
    bool alpha = true; /*!< uint largeur du rectangle*/
    double factor = 1; /*!< uint largeur du rectangle*/
public:
/**
 * @brief Constructeur de l'objet image 
 * 
 * @param x uint contenant la coordonnée x
 * @param y uint contenant la coordonnée y 
 * @param path const char* contenant le chemin de l'image
 */
    Image(uint x, uint y, const char *path);
    /**
     * @brief Constructeur de copie  d'une image
     * 
     * @param orig image que l'on copie
     */
    Image(const Image &orig);
/**
 * @brief Constructeur sur flux d'une image
 * 
 * @param is input
 */
    Image(istream &is);
    /**
     * @brief Destructeur d'une image
     * 
     */
    ~Image();
    /**
     * @brief fonction permettant de recuperer le degrès d'opasité 
     * 
     * @return true 
     * @return false 
     */ 
    inline bool getAlpha() const { return alpha; }
    /**
     * @brief fonction permettant de changer la transparence de l'image 
     * 
     * @param _alpha booleen si transparant 
     */
    inline void setAlpha(bool _alpha) { alpha = _alpha; }
    /**
     * @brief permet de changer le facteur de taille de l'image
     * 
     * @return double contenant
     */
    inline double getFactor() const { return factor; }
    /**
     * @brief permet de changer le facteur de taille de l'image
     * 
     * @param _factor contenant le facteur 
     */
    inline void setFactor(double _factor)
    {
        if (_factor > 0)
        {
            factor = _factor;
            changeFactor();
        }
    }
    /**
     * @brief permet de dessiner une image
     * 
     * @param w la fenetre ou l'on dessine 
     * @param isActive indique si l'image est selectionnée ou non
     */
    void draw(EZWindow &w, bool isActive) const override;
    /**
     * @brief permet de recuperer le perimetre d'une image
     * 
     * @return double  contenant le perimetre 
     */
    double perimeter() const;
    /**
     * @brief permet de mettre a jour le facteur de taille de l'image sur la fenetre 
     * 
     */
    void changeFactor();

protected:
/**
 * @brief ecrit l'instantiation de la class Etoile dans un fichier de flux de sortie
 * 
 * @param os le fichier de flux de sortie
 * @return ostream& le flux de sortie qui sera stocker dans le fichier de flux de sortie
 */
    ostream &write(ostream &) const;
};
#endif
