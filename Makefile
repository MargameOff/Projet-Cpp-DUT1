# Variables pour Unix/X11
ifdef OS
   RM = del /Q
   FixPath = $(subst /,\,$1)
   EXE      =.exe
   LIBS     = -lgdi32 -lmsimg32
else
   ifeq ($(shell uname), Linux)
      RM = rm -f
      FixPath = $1
	  LIBS     = -lX11 -lXext
	  EXE      =
   endif
endif
ifeq ($(CXX),)
CXX=g++
endif
CFLAGS   = -g -Wall -pedantic -O2
CXXFLAGS = $(CFLAGS) -std=c++17

OBJECTS= point.o shape.o rectangle.o setofshapes.o triangle.o Grid.o calque.o
OBJECTS+= ellipse.o square.o circle.o image.o polygone.o Etoile.o string.o arrow.o imagestring.o

OBJECTS+= main.o ez-draw++.o MyWindow.o mywindowhelp.o setofwindow.o
.PHONY:: all clean distclean zip

# Rajoutez vos executables C++ a la fin de EXECSPP =
#
EXECSPP = ShapesEditor$(EXE)

all :: $(EXECSPP)

# Règle générale qui indique comment compiler n'importe quel fichier XXX.cpp en un fichier XXX.o.
.cpp.o :
	$(CXX) -c $(CXXFLAGS) $*.cpp


ShapesEditor$(EXE) : $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBS)

depends :
	$(CXX) -MM $(CXXFLAGS) *.cpp >depends

clean ::
	$(RM) *.o core
	$(RM) depends
	$(RM) ShapesEditor$(EXE)

distclean :: clean
	$(RM) $(EXECSPP)

include depends

