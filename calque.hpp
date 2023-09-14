#ifndef CALQUE_HPP
#define CALQUE_HPP

#include "setOfShapes.hpp"
/**
 * @brief Declaration de la classe Calque
 * 
 */
class Calque {
    private : 
    uint maxShapes;     /*!< nombre de forme maximum qu'un calque peut contenir*/
    uint nbShapes;        /*!< nombre de shapes actuels contecnue dans le calque*/
    uint selection;  /*!< numero de calque qui est selectionné */
    SetOfShapes **calques; /*!< tableau de poiteur sur SetOfShapes */

public :
/**
 * @brief Constructeur des instances de Calques
 * 
 * @param size nombre de forme maximum pouvant etre contenu dans un calque
 */
    Calque(uint size=10); 
    /**
     * @brief Destructeur de l'instance de calque
     * 
     */
    ~Calque();
    /**
     * @brief Getter qui renvoie le pointeur SetOfShapes associé à un calque
     * 
     * @param k le numero du calque
     * @return SetOfShapes* le poiteur sur setofshapes
     */
    SetOfShapes *getCalques(uint k) const;
    /**
     * @brief Getter qui renvoie le numero du calque selectionnée
     * 
     * @return uint le numero du calque selectionné
     */
    inline uint getSelection() { return selection; }
    /**
     * @brief getter qui renvoie le nombre de shapes actuel contenu sur le calque
     * 
     * @return uint le nombre de shapes que contient le calques
     */
    inline uint getnbShapes() const { return nbShapes; }
/**
 * @brief Setter qui modifie l'adresse du pointeur sur setofshapes en fonction du numero de calque passé en parametre
 * 
 * @param i le numero de calque
 * @param f le pointeur sur setofshapes
 */
    inline void setCalques(uint i, SetOfShapes * f) { calques[i]=f; }
    /**
     * @brief Setter qui modifie le ccalques selectionné
     * 
     * @param i le numero de calque a selectionné
     */
    inline void setSelection(uint i) { selection=i; }
/**
 * @brief fonction qui ajoute un setofshapes dans le tableau donnée membre
 * 
 * @param f un pointeur sur setofshapes
 */
    void add(SetOfShapes * f=new SetOfShapes());
/**
 * @brief supprimer un numero de calques
 * 
 * @param i le calque que l'on veux supprimer
 */
    void suprr(uint i);
/**
 * @brief afficher une instance de calques sur le terminal
 * 
 */
    void show() const;
/**
 * @brief sauvegarde un calque
 * 
 * @param os flux de sortie dans lequel on stock la sauvegarde du calque
 */
    void save(ostream& os) const;
/**
 * @brief charge une instance de calque depuis un flux d'entrée
 * 
 * @param is le flux d'entrée
 */
    void load(istream& is);
    /**
     * @brief dessine tous les shapes contenus dans le calques actuels 
     * 
     * @param w la fenetre EZWindow qui sert de canvas
     * @param isActive si la fenetre est active
     */

    void draw(EZWindow &w, bool isActive) const;
    /**
     * @brief Affiche ou desative un calque 
     * Les ancres ne seront plus selectionnable une fois le calque desactivé mais les figures seront toujours visible
     * @param i le numero du calque a desactivé
     */
    void DisplayOrNo(uint i); 
};


#endif