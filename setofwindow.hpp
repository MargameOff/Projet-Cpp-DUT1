/**
 * @file setofwindow.hpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief declaration de la classe setofwindows
 * 
 */



#ifndef SETOFWINDOW_HPP
#define SETOFWINDOW_HPP

#include "MyWindow.hpp"
#include <vector>

typedef unsigned int uint;
typedef unsigned long int ulong;
class MyWindow;
/**
 * classe SetOfWindow
 * @brief classes permettant la gestion des fenetre
 * 
 */
class SetOfWindow
{
private:
    std::vector<MyWindow *> tabWindow;

public:
/**
 * @brief construit une instance d'une fenetre
 * 
 */
    SetOfWindow();
/**
 * @brief destructeur de l'instance de fenetre
 * 
 */
    ~SetOfWindow();
    /**
     * @brief Getter pour le nombre de fenetre 
     * 
     * @return int qui contient le nombre de fenetre 
     */
    inline int getWindowSize() const { return tabWindow.size(); }
    /**
     * @brief fonction qui supprime la fenetre 
     * 
     */
    void deleteWindow(MyWindow *);
/**
 * @brief fonction qui ajoute une fenetre 
 * 
 */
    void addWindow();
};

#endif
