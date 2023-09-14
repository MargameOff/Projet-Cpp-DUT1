/**
 * @file mywindowhelp.cpp
 * @author Rollet Vincent - Monges Océane - Deleuil Marius
 * @brief implémentation de la classe mywindowhelp
 */

using namespace std;



#include "mywindowhelp.hpp"
MyWindowHelp::MyWindowHelp(bool isVisible)
    : EZWindow(370, 350, "Help Window")
{
    this->setVisible(isVisible);
    setDoubleBuffer(true);
    menuGeneral();
}
MyWindowHelp::~MyWindowHelp()
{
}
void MyWindowHelp::menuGeneral()
{
    out.str("");
    out.clear();
    setColor(ez_blue);
    setMenuCouleurIsOpen(false);
    setMenuShapeIsOpen(false);
    out  
         << "H            : Fermeture du Menu Help" << endl
         << "C            : Accedez au Help Couleur" <<endl
         << "A            : Accedez au Help Shapes" <<endl
         << "B            : Accedez au Help Calque" <<endl
         << "q            : Fermer toutes les Fenetres" << endl
         << "E            : Ecrire la liste des formes sur la console" << endl
         << "S            : Sauvegarder la liste des formes sur disque" << endl
         << "L            : Chargee la liste des formes depuis le disque" << endl
         << "N            : Ouvrir une nouvelle fenetre" << endl
         << "Suppr        :  supprime une forme" << endl
         << "a            : Ajouter un point a un polygone" << endl //Une fois le polynome en question selectionne
         << "d            : supprimer un point d un polynome" << endl //Une fois le polynome en question selectionne
         << "Molette Haut : augmente la taille d image" << endl
         << "Molette Bas  : baisse la taille d image" << endl
         << "+            : augmente l epaisseur du trait" << endl
         << "-            : diminue l epaisseur du trait" << endl
         << "Click Droit  : Regler les attribut de la forme" << endl
        ;
}
void MyWindowHelp::menuCouleur(){
        out.str("");
        out.clear();
         out  << "C            : Fermer le Menu Couleur" << endl
              << "0            : met en noir la forme" << endl
              << "1            : met en gris la forme" << endl
              << "2            : met en rouge la forme" << endl
              << "3            : met en vert la forme" << endl
              << "4            : met en bleu la forme" << endl
              << "5            : met en jaune la forme" << endl
              << "6            : met en cyan la forme" << endl
              << "7            : met en magenta la forme" << endl
              ;
          setMenuCouleurIsOpen(true);
}
void MyWindowHelp::menuShapes(){
        out.str("");
        out.clear();
        out   << "A            : Fermer le Menu Shape" << endl
              << "r            : cree un rectangle" << endl
              << "e            : cree une ellipse" << endl
              << "s            : cree un carre" << endl
              << "c            : cree un cercle" << endl
              << "f            : remplie la forme" << endl
              << "i            : affiche une image" << endl
              << "p            : cree un polygone" << endl
              << "t            : cree un triangle" << endl
              << "w            : cree une etoile" << endl
              << "u            : cree une fleche" << endl
              << "O            : cree un string" << endl
              << "K            : cree un imageString"

              ;
        setMenuShapeIsOpen(true);
}
void MyWindowHelp::menuCalques(){
        out.str("");
        out.clear();
        out   << "A            : Fermer le Menu Calque"<<endl
              << "m             : changer de calque"<<endl
              << "j             : ajouter un calque"<<endl
              << "x             : supprimer un calque" <<endl
              << "F             : afficher/desafficher un calque" <<endl
              << "X             : ecrit la liste des formes du calque" <<endl 
              << "                actuel sur la console" <<endl
              << "J             : affiche les instantiations de calques"<<endl
              ;
        setMenuCalqueIsOpen(true);
}
void MyWindowHelp::expose()
{
  setFont(1);
  drawText(EZAlign::TC, 185, 3, "Menu Help");
  setFont(0);
  drawText(EZAlign::TL, 3, 35, out.str());
}

void MyWindowHelp::close()
{
  this->setVisible(false);
}
void MyWindowHelp::keyPress(EZKeySym keysym) // Une touche du clavier a ete enfoncee ou relachee
{
  switch (keysym)
  {
  case EZKeySym::H:
    this->setVisible(false);
    break;
  case EZKeySym::C:
    if(!getMenuCouleurIsOpen())
    {
      menuCouleur();
    }
    else
    {
      menuGeneral();
    }
  break;
  case EZKeySym::A:
    if(!getMenuShapeIsOpen())
    {
      menuShapes();
    }
    else
    {
      menuGeneral();
    }
  break;
  case EZKeySym::B:
    if(!getMenuCalqueIsOpen())
    {
      menuCalques();
    }
    else
    {
      menuGeneral();
    }
  break;
  default:
    break;
  }
  sendExpose();
}