// main.cpp
#include <iostream>

using namespace std;

#include "ez-draw++.hpp"
#include "setofwindow.hpp"
SetOfWindow _setOfWindow;
int main()
{
    EZDraw ezDraw;
    _setOfWindow.addWindow();

    ezDraw.setAutoQuit(false);
    ezDraw.mainLoop();

    return 0;
}
