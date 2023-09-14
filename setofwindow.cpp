/**
 * @file setofwindow.cpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief implémentation de la classe setofmywindows
 */

#include <iostream>
#include <stdexcept>

using namespace std;

#include "ez-draw++.hpp"

#include "setofwindow.hpp"

SetOfWindow::SetOfWindow()
{

}

SetOfWindow::~SetOfWindow()
{
}

void SetOfWindow::deleteWindow(MyWindow *window)
{
    size_t c = 0;
    bool find = false;
    for (size_t i = 0; i < tabWindow.size(); i++) //cherche quel forme correspond dans la liste
    {
        if (tabWindow[i] == window)
        {
            c = i;
            find = true;
        }
    }
    if (find)
    {
        delete tabWindow[c];
        tabWindow.erase(tabWindow.begin() + c);
    }
}
void SetOfWindow::addWindow()
{
    tabWindow.push_back(new MyWindow(800, 500, "Shape Editor ULTIATE GAMING EDITION", this));
}