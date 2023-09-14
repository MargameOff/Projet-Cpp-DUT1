// MyWindow.hpp

#ifndef MYWINDOW_HPP
#define MYWINDOW_HPP

#include "SetOfShapes.hpp"
#include "setofwindow.hpp"
#include "mywindowhelp.hpp"
#include "calque.hpp"
class SetOfWindow;
/**
 * @brief Création de la classe MyWindow, classe fille heritant de EZWindow
 * 
 */
class MyWindow : public EZWindow
{
  Calque calques;/*!< Instance de Calque */
  Shape *pshape;/*!< Pointeur de Shape */
  SetOfShapes *shapes;/*!< Pointeur sur SetOfShapes */
  SetOfWindow *setOfWindow;/*!< Pointeur sur SetOfWindow */
  MyWindowHelp helpWindow;/*!< Instance de la class MyWindowHelp */
public:
  int posMouseX, posMouseY; /*!< coordonnée de la souris */
  int tmpY, tmpX; /*!<coordonnée temportaire */
/**
 * @brief Constructeur a plusieurs parametres
 * 
 * @param w largeur de la fenetre EZWindow
 * @param h hauteur de la fenetre EZWindow
 * @param name nom de la fenetre EZWindow
 * @param _setOfWindow Instance de setOfWindow à afficher sur la fenetre EZWindow
 */
  MyWindow(int w, int h, const char *name, SetOfWindow *_setOfWindow);
/**
 * @brief Destructeur de la classe MyWindow
 * 
 */
  ~MyWindow();
/**
 * @brief Cette fonction virtuelle est déclenchée lorsque la fenêtre doit être redessinée 
 * 
 */
  void expose();
  /**
   * @brief fonction appeler à chaque fois qu'une touche du clavier est enfoncée et que la fenêtre est sélectionnée (active)
   * 
   * @param keysym touche enfoncé
   */
  void keyPress(EZKeySym keysym);
/**
   * @brief fonction appeler à chaque fois qu'une touche du clavier est relaché et que la fenêtre est sélectionnée (active)
   * 
   * @param keysym touche relaché
   */
  void keyRelease(EZKeySym keysym);
  /**
   * @brief fonction déclenchée à chaque fois qu'un des boutons de la souris est appuyé
   * 
   * @param mouse_x abscisse de la souris
   * @param mouse_y ordonnée de la souris
   * @param button bouton de la souris
   */
  void buttonPress(int mouse_x, int mouse_y, int button);
  /**
   * @brief Cette fonction virtuelle est appelée à chaque mouvent de la souris dans la fenêtre.
   * 
   * @param mouse_x abscisse de la souris
   * @param mouse_y ordonnée de la souris
   * @param button bouton de la souris
   */
  void motionNotify(int mouse_x, int mouse_y, int button);
  /**
   * @brief Cette fonction virtuelle est déclenchée à chaque relâchement d'un bouton de la souris.
   * 
   * @param mouse_x abscisse de la souris
   * @param mouse_y ordonnée de la souris
   * @param button bouton de la souris
   */
  void buttonRelease(int mouse_x, int mouse_y, int button);
  /**
   * @brief Cette fonction est appelée chaque fois que l'on a besoin de modifier la taille d'une forme
   * 
   */
  void changeSize();
  /**
   * @brief Cette fonction virtuelle est déclenchée lorsque l'utilisateur a réclamé la fermeture de cette fenêtre en cliquant sur le bouton prévu à cet effet
   * 
   */
  void close();
};

#endif
