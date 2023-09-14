/**
 * @file mywindowhelp.hpp
 * @author DELEUIL Marius MONGES Océane ROLLET Vincent
 * @brief HPP de la fenetre graphique de help
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef MYWINDOWHELP_HPP
#define MYWINDOWHELP_HPP
#include "ez-draw++.hpp"
#include <sstream>
class MyWindowHelp : public EZWindow
{
private:
  bool menuCouleurIsOpen=false,menuShapeIsOpen=false, menuCalqueIsOpen=false;
public:
/**
 * @brief Setteur de l'etat du menu Couleur
 * 
 * @param _c l'etat du menu couleur
 */
  void setMenuCouleurIsOpen(bool _c){menuCouleurIsOpen=_c;}
/**
 * @brief Setteur de l'etat du menu Calque
 * 
 * @param _c l'etat du menu Calque
 */
  void setMenuCalqueIsOpen(bool _c){menuCalqueIsOpen=_c;}
  /**
 * @brief Setteur de l'etat du menu Shape
 * 
 * @param _s l'etat du menu Shape
 */
  void setMenuShapeIsOpen(bool _s){menuShapeIsOpen=_s;}
  /**
   * @brief Getteur de l'etat du menu Calque
   * 
   * @return true si le menu est ouvert
   * @return false si le menu est fermé
   */
  bool getMenuCalqueIsOpen() const {return menuCalqueIsOpen;}
  /**
   * @brief Getteur de l'etat du menu Couleur
   * 
   * @return true si le menu est ouvert
   * @return false si le menu est fermé
   */
  bool getMenuCouleurIsOpen() const {return menuCouleurIsOpen;}
  /**
   * @brief Getteur de l'etat du menu Shape
   * 
   * @return true si le menu est ouvert
   * @return false si le menu est fermé
   */
  bool getMenuShapeIsOpen() const {return menuShapeIsOpen;}
  std::ostringstream out;
  /**
   * @brief Constructeur de la fenetre d'aide
   * 
   * @param isVisible determine si la fenettre est visible
   */
  MyWindowHelp(bool isVisible=false);
  /**
   * @brief Destructeur de fenetre d'aide
   * 
   */
  ~MyWindowHelp();
  /**
   * @brief Affiche le menu Général
   * 
   */
  void menuGeneral();
  /**
   * @brief Affiche le menu Couleur
   * 
   */
  void menuCouleur();
  /**
   * @brief Affiche le menu Calques
   * 
   */
  void menuCalques(); 
  /**
   * @brief Affiche le menu Shapes
   * 
   */
  void menuShapes();
  /**
   * @brief Fonction qui est constament rafraichie
   * 
   */
  void expose();
  /**
   * @brief fonction qui je lance quand une touche est préssée
   * 
   * @param keysym ecesseur de touche
   */
  void keyPress(EZKeySym keysym);
  /**
   * @brief gere les actions quand on ferme la fenetre de Help
   * 
   */
  void close();
};

#endif
