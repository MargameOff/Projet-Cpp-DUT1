#ifndef IMAGESTRING_HPP
#define IMAGESTRING_HPP

#include "shape.hpp"
#include <vector>

class ImageString : public Shape
{
private:
    const char *path;  /*!< char pointé de l'emplacement de l'image*/
    string savepath;   /*!< string sauvegarde de l'emplacement*/
    EZImage *imageF;   /*!< EZImage pointé de l'image importé*/
    bool alpha = true; /*!< bool de l'etat de la transparence*/
    double factor = 1; /*!< double du facteur taille*/
    int fontSizeX, fontSizeY, fontLetterInX, fontLetterInY;
    
public:
    /**
     * @brief string qui contiend les caracteres a envoyer
     * 
     */
    string inputString;
    /**
     * @brief liste des lettres disponible avec l'image
     * 
     */
    std::vector<char> letterAvailable;
    /**
     * @brief Constructeur de la classe ImageString
     * 
     * @param x est la position X d'ou vas se positionner l'ancre et la string
     * @param y est la position Y d'ou vas se positionner l'ancre et la string
     * @param path est le repertoire de la font
     * @param _fontSizeX est la taille X d'une lettre sur l'image Font en pixel
     * @param _fontSizeY est la taille Y d'une lettre sur l'image Font en pixel
     * @param _fontLetterInX est le nombre de lettre situé sur l'axe X donc horizontal
     * @param _fontLetterInY est le nombre de lettre situé sur l'axe Y donc vertical
     * @param inputString est la chaine à convertir en imageString
     */
    ImageString(uint x, uint y, const char *path,int _fontSizeX,int _fontSizeY,int _fontLetterInX,int _fontLetterInY,string inputString);
    /**
     * @brief Constructeur de copie de ImageString
     * 
     * @param orig est une référence ImageString
     */
    ImageString(const ImageString &orig);
    /**
     * @brief Constructeur par Istream
     * 
     * @param is est une entrée Istream pour elements externes
     */
    ImageString(istream &is);
    /**
     * @brief Destructeur de ImageString
     * 
     */
    ~ImageString();
    /**
     * @brief Getteur de Alpha
     * 
     * @return true si la transparance est activee
     * @return false si la transparance est desactivé
     */
    inline bool getAlpha() const { return alpha; }
    /**
     * @brief Setteur de Alpha
     * 
     * @param _alpha qui est la valeur à rentrer sur alpha
     */
    inline void setAlpha(bool _alpha) { alpha = _alpha; }
    /**
     * @brief Getteur de Factor
     * 
     * @return double qui est la valeur du facteur taille de ImageString
     */
    inline double getFactor() const { return factor; }
    /**
     * @brief Setteur de Facteur
     * 
     * @param _factor qui sera la valeur du facteur taille de ImageString
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
     * @brief Fonction qui dessine l'element ImageString par drawLetter
     * 
     * @param w est la Fenettre actuelle
     * @param isActive est le booleen qui défini si on selectionne une shape
     */
    void draw(EZWindow &w, bool isActive) const override;
    /**
     * @brief Fonction qui découpe et dimentionne les lettres pour le draw
     * 
     * @param w est la Fenettre actuelle
     * @param x est la position du dessin sur X
     * @param y est la position du dessin sur Y
     * @param l est le caractere à convertir
     */
    void drawLetter(EZWindow &w, uint x, uint y, char l) const;
    /**
     * @brief Fonction qui ressort le perimetre
     * 
     * @return double est le perimetre de la forme
     */
    double perimeter() const;
    /**
     * @brief Fonction qui change le facteur de l'ImageString
     * 
     */
    void changeFactor();

protected:
/**
 * @brief Fonction qui ecrit dans un ostream
 * 
 * @return ostream& est la sortie de la fonction qui peut etre un fichier notament
 */
    ostream &write(ostream &) const;
};
#endif
