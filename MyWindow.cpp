/**
 * @file MyWindow.cpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief implémentation de la classe MyWindow
 */


// MyWindow.cpp
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;


#include "ez-draw++.hpp"
#include "MyWindow.hpp"
#include "polygone.hpp"
#include "SetOfShapes.hpp"
#include "calque.hpp"
#include "triangle.hpp"
#include "Point.hpp"   // Uniquement pour le constructeur qui peuple la fenêtre
#include "Ellipse.hpp" // avec quelques shapes.
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "image.hpp"
#include "imagestring.hpp"
#include "Grid.hpp"
#include "Etoile.hpp"
#include "arrow.hpp"
#include "string.hpp"
MyWindow::MyWindow(int w, int h, const char *name, SetOfWindow *_setOfWindow)
    : EZWindow(w, h, name), calques(200), pshape(nullptr), shapes(nullptr), setOfWindow(_setOfWindow), helpWindow()
{
  shapes = new SetOfShapes(200);
  calques.add(shapes);

  setDoubleBuffer(true);
}

MyWindow::~MyWindow()
{
}

void MyWindow::expose()
{
  calques.draw(*this, true);
  if (pshape != nullptr) 
    pshape->draw(*this, true);
  setColor(ez_black);
  drawText(EZAlign::TL, 3, 3, "H : Ouvre le Menu Help");
}

void MyWindow::buttonPress(int mouse_x, int mouse_y, int button)
{
  if (button == 1)
  {
    tmpX = mouse_x;
    tmpY = mouse_y;
    bool temp = true;
    Etoile *eetoile = dynamic_cast<Etoile *>(pshape);
    Polygone *ppolygone = dynamic_cast<Polygone *>(pshape);
    Triangle *ttriangle = dynamic_cast<Triangle *>(pshape);
     Arrow *aarrow = dynamic_cast<Arrow *>(pshape);
    if (ppolygone != nullptr)
    {
      ppolygone->savePoint();
      if (ppolygone->sommetOver(mouse_x, mouse_y))
      {
        temp = false;
        ppolygone->setPressSommet(true);
      }
      else if (ppolygone->AnchorIsOnTheMouse(mouse_x, mouse_y))
      {
        temp = true;
        ppolygone->movePolygone();
        ppolygone->setPressAnchor(true);
      }
      ppolygone->setPointSelect(nullptr);
      ppolygone->signalClicked(mouse_x, mouse_y);
    }
    else if (eetoile != nullptr)
    {
      eetoile->savePoint();
      if (eetoile->AnchorIsOnTheMouse(mouse_x, mouse_y))
      {
        temp = true;
        eetoile->moveEtoile();
        eetoile->setPressAnchor(true);
      }
      eetoile->setPointSelect(nullptr);
      eetoile->signalClicked(mouse_x, mouse_y);
    }
        else if (aarrow != nullptr)
    {
      aarrow->savePoint();
      if (aarrow->AnchorIsOnTheMouse(mouse_x, mouse_y))
      {
        temp = true;
        aarrow->moveArrow();
        aarrow->setPressAnchor(true);
      }
      aarrow->setPointSelect(nullptr);
      aarrow->signalClicked(mouse_x, mouse_y);
    }
    else if (ttriangle != nullptr)
    {
      ttriangle->savePoint();
      if (ttriangle->sommetOver(mouse_x, mouse_y))
      {
        temp = false;
        ttriangle->setPressSommet(true);
      }
      else if (ttriangle->AnchorIsOnTheMouse(mouse_x, mouse_y))
      {
        temp = true;
        ttriangle->moveTriangle();
        ttriangle->setPressAnchor(true);
      }
      ttriangle->setPointSelect(nullptr);
      ttriangle->signalClicked(mouse_x, mouse_y);
    }
    else
    {
      if (pshape != nullptr)
        pshape->setSelected(false);
      pshape = shapes->isOver(mouse_x, mouse_y);
      if (pshape != nullptr)
        pshape->setSelected(true);
    }
    if (temp)
    {
      pshape = shapes->isOver(mouse_x, mouse_y);
      Polygone *ppolygone = dynamic_cast<Polygone *>(pshape);
      Triangle *ttriangle = dynamic_cast<Triangle *>(pshape);
      Arrow *aarrow = dynamic_cast<Arrow *>(pshape);
      Etoile *eetoile = dynamic_cast<Etoile *>(pshape);
      if (ppolygone != nullptr)
      {
        if (ppolygone->AnchorIsOnTheMouse(mouse_x, mouse_y))
        {
          ppolygone->movePolygone();
          ppolygone->setPressAnchor(true);
          ppolygone->setPressSommet(true);
        }
      }
      else if (eetoile != nullptr)
      {
        if (eetoile->AnchorIsOnTheMouse(mouse_x, mouse_y))
        {
          eetoile->moveEtoile();
          eetoile->setPressAnchor(true);
          eetoile->setPressSommet(true);
        }
      }
            else if (aarrow != nullptr)
      {
        if (aarrow->AnchorIsOnTheMouse(mouse_x, mouse_y))
        {
          aarrow->moveArrow();
          aarrow->setPressAnchor(true);
          aarrow->setPressSommet(true);
        }
      }
      else if (ttriangle != nullptr)
      {
        if (ttriangle->AnchorIsOnTheMouse(mouse_x, mouse_y))
        {
          ttriangle->moveTriangle();
          ttriangle->setPressAnchor(true);
          ttriangle->setPressSommet(true);
        }
      }
    }
  }

  if (button == 4)
  {
    Image *_image = dynamic_cast<Image *>(pshape);
    ImageString *_imageString = dynamic_cast<ImageString *>(pshape);
    if (_image != nullptr)
    {
      _image->setFactor(_image->getFactor() + 0.02);
    }
    else if (_imageString != nullptr)
    {
      _imageString->setFactor(_imageString->getFactor() + 0.02);
    }
    
  }
  if (button == 5)
  {
    Image *_image = dynamic_cast<Image *>(pshape);
    ImageString *_imageString = dynamic_cast<ImageString *>(pshape);
    if (_image != nullptr)
    {
      _image->setFactor(_image->getFactor() - 0.02);
    }
    else if (_imageString != nullptr)
    {
      _imageString->setFactor(_imageString->getFactor() - 0.02);
    }
  }
  if (button == 3 && pshape != nullptr)
  {
    tmpX = mouse_x;
    tmpY = mouse_y;
    pshape->setChangeGauche(0);
    pshape->setChangeHaut(0);
  }
}
void MyWindow::close()
{
  setOfWindow->deleteWindow(this);
}
// Deplacement de la souris :
void MyWindow::motionNotify(int mouse_x, int mouse_y, int button)
{
  posMouseX=mouse_x;
  posMouseY=mouse_y;
  bool temp = true;
  if (button == 1 && pshape != nullptr)
  {
    Etoile *eetoile = dynamic_cast<Etoile *>(pshape);
    Polygone *ppolygone = dynamic_cast<Polygone *>(pshape);
    Arrow *aarrow = dynamic_cast<Arrow *>(pshape);
    Triangle *ttriangle = dynamic_cast<Triangle *>(pshape);
    if (ppolygone != nullptr)
    {
      if (ppolygone->getPressSommet())
      {
        temp = false;
        if (ppolygone->getPressAnchor())
        {
          temp = true;
          ppolygone->movePolygone();
        }
      }
    }
    
    else if (eetoile != nullptr)
    {
      if (eetoile->getPressSommet())
      {
        temp = false;
        if (eetoile->getPressAnchor())
        {
          temp = true;
          eetoile->moveEtoile();
        }
      }
    }
     else if (aarrow != nullptr)
    {
      if (aarrow->getPressSommet())
      {
        temp = false;
        if (aarrow->getPressAnchor())
        {
          temp = true;
          aarrow->moveArrow();
        }
      }
    }
    else if (ttriangle != nullptr)
    {
      if (ttriangle->getPressSommet())
      {
        temp = false;
        if (ttriangle->getPressAnchor())
        {
          temp = true;
          ttriangle->moveTriangle();
        }
      }
    }
    if (temp)
    {
      pshape->setAnchor(mouse_x, mouse_y);
    }
    if (ppolygone != nullptr && !ppolygone->getPressAnchor())
    {
      if (ppolygone->sommetIsSelect())
        ppolygone->setXYSommet(mouse_x, mouse_y);
    }
    else if (ttriangle != nullptr && !ttriangle->getPressAnchor())
    {
      if (ttriangle->sommetIsSelect())
        ttriangle->setXYSommet(mouse_x, mouse_y);
    }
  }
  else if (button == 3 && pshape != nullptr)
  {
    pshape->setChangeGauche(tmpX - mouse_x);
    pshape->setChangeHaut(tmpY - mouse_y);
  }

  sendExpose();
}

void MyWindow::buttonRelease(int mouse_x, int mouse_y, int button)
{
  Polygone *ppolygone = dynamic_cast<Polygone *>(pshape);
  Triangle *ttriangle = dynamic_cast<Triangle *>(pshape);
  Etoile *eetoile = dynamic_cast<Etoile *>(pshape);
  Arrow *aarrow = dynamic_cast<Arrow *>(pshape);
  if (button == 1 && pshape != nullptr)
  { //pshape->setAnchor(mouse_x,mouse_y);
    if (ppolygone != nullptr)
    {
      if (ppolygone->sommetIsSelect() && !ppolygone->getPressAnchor())
      {
        ppolygone->setXYSommet(mouse_x, mouse_y);
      }
      if (ppolygone->getPressAnchor())
      {
        ppolygone->movePolygone();
      }
      ppolygone->setPressSommet(false);
      ppolygone->setPressAnchor(false);
    }
    else if (eetoile != nullptr)
    {
      if (eetoile->sommetIsSelect() && !eetoile->getPressAnchor())
      {
        eetoile->setXYSommet(mouse_x, mouse_y);
      }
      if (eetoile->getPressAnchor())
      {
        eetoile->moveEtoile();
      }
      eetoile->setPressSommet(false);
      eetoile->setPressAnchor(false);
    }
     else if (aarrow != nullptr)
    {
      if (aarrow->sommetIsSelect() && !aarrow->getPressAnchor())
      {
        aarrow->setXYSommet(mouse_x, mouse_y);
      }
      if (aarrow->getPressAnchor())
      {
        aarrow->moveArrow();
      }
      aarrow->setPressSommet(false);
      aarrow->setPressAnchor(false);
    }
    else if (ttriangle != nullptr)
    {
      if (ttriangle->sommetIsSelect() && !ttriangle->getPressAnchor())
      {
        ttriangle->setXYSommet(mouse_x, mouse_y);
      }
      if (ttriangle->getPressAnchor())
      {
        ttriangle->moveTriangle();
      }
      ttriangle->setPressSommet(false);
      ttriangle->setPressAnchor(false);
    }
  } // Si on clique sur l'anchor d'une shape
  else if (button == 3 && pshape != nullptr)
  {
    changeSize();
  }

  sendExpose();
}
void MyWindow::changeSize()
{
  int changeTmpHaut = pshape->getChangeHaut();
  int changeTmpGauche = pshape->getChangeGauche();
  pshape->setChangeGauche(0);
  pshape->setChangeHaut(0);
  Rectangle *_rectangle = dynamic_cast<Rectangle *>(pshape);
  Ellipse *_ellipse = dynamic_cast<Ellipse *>(pshape);
  Square *_square = dynamic_cast<Square *>(pshape);
  Grid *_grid = dynamic_cast<Grid *>(pshape);
  Circle *_circle = dynamic_cast<Circle *>(pshape);
  if (_rectangle != nullptr)
  {
    _rectangle->setHeight(_rectangle->getHeight() - changeTmpHaut);
    _rectangle->setWidth(_rectangle->getWidth() - changeTmpGauche);
  }
  else if (_grid != nullptr)
  {
    _grid->setHeight(_grid->getHeight() - changeTmpHaut);
    _grid->setWidth(_grid->getWidth() - changeTmpGauche);
  }
  else if (_ellipse != nullptr)
  {
    _ellipse->setSemiHeight(_ellipse->getSemiHeight() - changeTmpHaut);
    _ellipse->setSemiWidth(_ellipse->getSemiWidth() - changeTmpGauche);
  }
  else if (_square != nullptr)
  {
    _square->setLength(_square->getLength() - changeTmpHaut);
  }
  else if (_circle != nullptr)
  {
    _circle->setRadius(_circle->getRadius() - changeTmpGauche);
  }

  sendExpose();
}

void MyWindow::keyPress(EZKeySym keysym) // Une touche du clavier a ete enfoncee ou relachee
{
  switch (keysym)
  {
  case EZKeySym::Escape:
  case EZKeySym::q:
    EZDraw::quit();
    break;
  case EZKeySym::E:
    cout << shapes;
    break;
  case EZKeySym::H:
    helpWindow.setVisible(true);
    break;
  case EZKeySym::S:
  {
    string nom;
    cout << "Quel nom pour votre fichier de sauvegarde?" <<endl;
    cin >> nom;
    ofstream f(nom);
    calques.save(f);
  }
  break;
  case EZKeySym::L:
   {
        for(uint i=calques.getnbShapes();i>0;i--){
          calques.suprr(i-1);
        }
        string nom;
      cout << "Quel est le nom du fichier a charger" <<endl;
      cin >> nom;
  const char *cpath = nom.c_str();
      FILE *file = fopen(cpath, "rb");
      if (file != NULL){
          ifstream f(nom);
          calques.load(f);
          shapes=calques.getCalques(0);}
      else
        cout << "Error: Bad entry" << endl;
        }
  break;
  case EZKeySym::_0:
    if (pshape)
      pshape->setColor(ez_black);
    break;
  case EZKeySym::_1:
    if (pshape)
      pshape->setColor(ez_grey);
    break;
  case EZKeySym::_2:
    if (pshape)
      pshape->setColor(ez_red);
    break;
  case EZKeySym::_3:
    if (pshape)
      pshape->setColor(ez_green);
    break;
  case EZKeySym::_4:
    if (pshape)
      pshape->setColor(ez_blue);
    break;
  case EZKeySym::_5:
    if (pshape)
      pshape->setColor(ez_yellow);
    break;
  case EZKeySym::_6:
    if (pshape)
      pshape->setColor(ez_cyan);
    break;
  case EZKeySym::_7:
    if (pshape)
      pshape->setColor(ez_magenta);
    break;
  case EZKeySym::Delete:
    if (pshape)
    {
      uint c = 0;
      bool find = false;
      for (size_t i = 0; i < shapes->getNbShapes(); i++) //cherche quel forme correspond dans la liste
      {
        if (shapes->getShapes()[i] == pshape)
        {
          c = i;
          find = true;
        }
      }
      if (find)
      {
        Shape **temp = new Shape *[shapes->getMaxShapes()];
        uint j = 0;
        for (uint i = 0; i < shapes->getNbShapes(); i++)
        {
          if (i != c)
            temp[j++] = shapes->getShapes()[i];
        }
        shapes->getShapes()[c]->~Shape();

        delete[] shapes->getShapes();
        shapes->setShapes(nullptr);
        shapes->setShapes(temp);
        shapes->setNbShapes(shapes->getNbShapes() - 1);
      }
    };
    break;
  case EZKeySym::Control_L:
    if (pshape)
    {
    }
    break;
  case EZKeySym::r:
    shapes->add(new Rectangle(ez_black, posMouseX,posMouseY, posMouseX+50,posMouseY+50));
    break;
    case EZKeySym::u:{
    uint width;
    cout << "Quelle taille souhaitez vous afffecter a votre Fleche? " <<endl;
    cin >> width; 
    size_t _nbPoint = 7;
    std::vector<Point> tabPointEtoile;
    for (size_t i = 0; i < _nbPoint; i++)
    {
      Point tempPoint(getWidth() / 2, getHeight() / 2);
      tabPointEtoile.push_back(tempPoint);
    }
    shapes->add(new Arrow(ez_black, getWidth() / 2 - 25, getHeight() / 2 - 25, tabPointEtoile, width / 2 + 25, width / 2 * 1.6 + 25));
  }break;
  case EZKeySym::e:
    shapes->add(new Ellipse(ez_black, posMouseX,posMouseY, 50, 30));
    break;
  case EZKeySym::s:
    shapes->add(new Square(ez_black, posMouseX,posMouseY, 50));
    break;
  case EZKeySym::c:
    shapes->add(new Circle(ez_black, posMouseX,posMouseY, 25));
    break;
  case EZKeySym::K:{
    cout << "Veuillez entrer le chemin d'acces de la police a afficher :" << endl;
    string path;
    cin >> path;
    cout << "Veuillez entrer la taille d'une lettre sur l axe X" << endl;
    int fontSizeX;
    cin >> fontSizeX;
    cout << "Veuillez entrer la taille d'une lettre sur l axe Y" << endl;
    int fontSizeY;
    cin >> fontSizeY;
    cout << "Veuillez entrer le nombre de lettre par ligne de la police" << endl;
    int fontLetterInX;
    cin >> fontLetterInX;
    cout << "Veuillez entrer le nombre de colone de la police" << endl;
    int fontLetterInY;
    cin >> fontLetterInY;
    cout << "Veuillez entrer le mot a afficher" << endl;
    string inputString;
    cin >> inputString;
    const char *cpath = path.c_str();
    FILE *file = fopen(cpath, "rb");
    if (file != NULL)
      shapes->add(new ImageString(posMouseX, posMouseY, cpath,fontSizeX,fontSizeY,fontLetterInX,fontLetterInY,inputString));
    else
      cout << "Error: Bad entry" << endl;}
    break;
  case EZKeySym::O:{
    string texte;
    cout << "Saisissez le texte à afficher" << endl;
    cin >> texte;
    shapes->add(new String(ez_black, posMouseX,posMouseY,texte));
  }break;
  case EZKeySym::t:
  {
    shapes->add(new Triangle(ez_black, posMouseX * cos(0), posMouseY + 50 * sin(0), 0, 0, 0, 0));
  }
  break;
  case EZKeySym::p:
  {
    int nbPoint;
    uint radius;
    cout << "Saisissez un nombre de points pour la création de votre polynome" << endl;
    cin >> nbPoint;
    while (nbPoint < 1)
    {
      cerr << "Attention, la valeur est invalide. Veuillez en choisir une autre : ";
      cin >> nbPoint;
      cerr << endl;
    }
    cout << "Saisissez la taille que vous souhaitez affecter a votre polynome" << endl;
    cin >> radius;
    while (radius <= 0)
    {
      cerr << "Attention, la valeur est invalide. Veuillez en choisir une autre : ";
      cin >> radius;
      cerr << endl;
    }
    size_t _nbPoint = nbPoint;
    std::vector<Point> tabPointPolygone;
    for (size_t i = 0; i < _nbPoint; i++)
    {
      Point tempPoint(posMouseX, posMouseY);
      tabPointPolygone.push_back(tempPoint);
    }
    //calcul : wiki
    double PI = 2 * acos(0.0);
    shapes->add(new Polygone(ez_black,
                            (radius * cos((1) * ((360 / _nbPoint) * PI / 180.0)) + posMouseX* cos(0) - radius * cos(0) + radius),
                            (radius * sin((1) * ((360 / _nbPoint) * PI / 180.0)) + posMouseY+ 50 * sin(0) - radius * sin(0)), tabPointPolygone, radius));
  }
  break;
  case EZKeySym::plus:
    if (pshape)
    {
      pshape->setThickness((pshape->getThickness()) + 1);
    }
    break;
  case EZKeySym::minus:
    if (pshape)
    {
      pshape->setThickness((pshape->getThickness()) - 1);
    }
    break;
  case EZKeySym::w:
  {
    int nbPoint;
    uint radius;
    uint radius2; 
    cout << "Saisissez un nombre de sommet pour la création de votre étoile" << endl;
    cin >> nbPoint;
    while (nbPoint < 1)
    {
      cerr << "Attention, la valeur est invalide. Veuillez en choisir une autre : ";
      cin >> nbPoint;
      cerr << endl;
    }
    cout << "Saisissez le rayon externe que vous souhaitez affecter a votre étoile" << endl;
    cin >> radius;
    while (radius <= 0)
    {
      cerr << "Attention, la valeur est invalide. Veuillez en choisir une autre : ";
      cin >> radius;
      cerr << endl;
    }
    cout << "Saisissez le rayon interne que vous souhaitez affecter a votre étoile" << endl;
    cin >> radius2;
    while (radius <= 0)
    {
      cerr << "Attention, la valeur est invalide. Veuillez en choisir une autre : ";
      cin >> radius2;
      cerr << endl;
    }
    if (radius < radius2)
    {
      uint temp = radius;
      radius = radius2;
      radius2 = temp;
    }
    size_t _nbPoint = nbPoint*2;
    std::vector<Point> tabPointPolygone;
    for (size_t i = 0; i < _nbPoint; i++)
    {
      Point tempPoint(posMouseX+50, posMouseY+50);
      tabPointPolygone.push_back(tempPoint);
    }
    double PI = 2 * acos(0.0);
    shapes->add(new Etoile(ez_black,
                            (radius * cos((1) * ((360 / _nbPoint) * PI / 180.0)) + posMouseX * cos(0) - radius * cos(0) + radius),
                            (radius * sin((1) * ((360 / _nbPoint) * PI / 180.0)) + posMouseY + 50 * sin(0) - radius * sin(0)), tabPointPolygone, radius, radius2));
  
  }break;
  case EZKeySym::f:
    if (pshape)
    {
      pshape->setFull(!(pshape->getFull()));
    }
    break;
    case EZKeySym::g:
  {
    size_t nbLines;
    size_t nbColumns;

    cout << "Saisissez le nombre de lignes que comportera votre grille [superieur à 1]" << endl;
    cin >> nbLines;
    while (nbLines < 0)
    {
      cerr << "Attention, la valeur est invalide. Veuillez en choisir une autre : ";
      cin >> nbLines;
      cerr << endl;
    }
    cout << "Saisissez le nombre de colonnes que comportera votre grille [superieur à 1]" << endl;
    cin >> nbColumns;
    while (nbColumns <= 0)
    {
      cerr << "Attention, la valeur est invalide. Veuillez en choisir une autre : ";
      cin >> nbColumns;
      cerr << endl;
    }
    shapes->add(new Grid(ez_black, posMouseX,posMouseY, posMouseX+50,posMouseY+50, nbLines, nbColumns));
  break;}
  case EZKeySym::N:
    setOfWindow->addWindow();
    break;
  case EZKeySym::i:
  {
    cout << "Veuillez entrer le chemin d'acces de l'image a afficher :" << endl;
    string path;
    cin >> path;
    const char *cpath = path.c_str();
    FILE *file = fopen(cpath, "rb");
    if (file != NULL)
      shapes->add(new Image(posMouseX, posMouseY, cpath));
    else
      cout << "Error: Bad entry" << endl;
    break;
  }
  case EZKeySym::a: 
  {
    Polygone *ppolygone = dynamic_cast<Polygone*>(pshape);
     if(ppolygone != nullptr)
     {
       ppolygone->addPoint();
     }
     }break;
  case EZKeySym::d: 
  {
    Polygone *ppolygone = dynamic_cast<Polygone*>(pshape);
     if(ppolygone != nullptr)
     {
       ppolygone->suprrPoint();
     }
  }break;
  default:
    break;
  }
  sendExpose();
}
void MyWindow::keyRelease(EZKeySym keysym) // Une touche du clavier a ete enfoncee ou relachee
{
  switch (keysym)
  {

  case EZKeySym::Control_L:
    if (pshape)
    {
    }
    break;
   case EZKeySym::J: calques.show(); break;
    case EZKeySym::X:
      cout << "--------------------------Calques--------------------------" << endl;
      cout << "Calque (Actuel)";
      for(uint i=0;i<calques.getnbShapes();i++)
        if(i==calques.getSelection())
            cout << "         " 
            << "  (Nb forme(s) : " << calques.getCalques(i)->getNbShapes() << " ) " << endl;
      cout << *shapes;
      cout << "-----------------------------------------------------------" << endl;
      break;
 case EZKeySym::m: {
    calques.show();
        cout << "Quel numero de calques voulez vous selectionez ? " << endl;
            uint i;
            cin >> i;
            if (calques.getnbShapes()>i-1)
            {
              shapes=calques.getCalques(i-1);
              calques.setSelection(i-1);
            }
            else
              cout << "Ce calque n'existe pas" << endl;
  }break;
  case EZKeySym::j: {
    calques.add();
    cout << "Calques ajouté avec succées" <<endl;
  }break;
  case EZKeySym::x:
    {
      calques.show();
      cout << "Quel numero de calques voulez vous supprimer? " << endl;
      uint k;
      cin >> k;
      calques.suprr(k-1);
      cout << "Supression effectué avec sucées"<<endl;
      shapes=calques.getCalques(0);
      calques.setSelection(0);
  }break;
  case EZKeySym::F:
  {
    calques.show();
    cout << "Donnez le numero du calque à afficher" << endl;
            uint j;
            cin >> j;
            calques.DisplayOrNo(j-1);
  }break;
  default:
    break;
  }
  sendExpose();
}