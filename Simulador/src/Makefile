SHELL = /bin/sh
UNAME = $(shell uname)

# Root variables
ROOTCFLAGS   = -L$(ROOTSYS)/lib $(shell $(ROOTSYS)/bin/root-config --cflags)
ROOTLIBS     = -L$(ROOTSYS)/lib $(shell $(ROOTSYS)/bin/root-config --libs) 
ROOTGLIBS    = -L$(ROOTSYS)/lib $(shell $(ROOTSYS)/bin/root-config --glibs)

BOOSTDIR     = -I/usr/local

#.................................................................
CXX          = g++
RM           = rm -f 
AR	     = ar cru

CXXFLAGS     = -O0 -g -Wall -fPIC

INCDIR       = .
SRCDIR       = .
LIBDIR       = .
EXEDIR       = ../exe

GARBAGE      = *.o $(EXEDIR)/simular $(EXEDIR)/llenar 

SOGARBAGE    = *.so

#.............................................................................
# Special dependencies
# Linux
ifeq "$(UNAME)" "Linux"
RANLIB       = ranlib
CXXFLAGS    += -I$(INCDIR) $(ROOTCFLAGS) $(BOOSTDIR)/include/boost-1_35
LINKFLAGS    =
endif

#Libraries
LIBS       += -L/usr/local/lib $(ROOTLIBS) -lMathCore

OBJSA   = $(COMMON) Data.o Tablas.o Hechos.o SimMatriculas.o \
	SimNotas.o SimDesercion.o simular.o

OBJSB   = $(COMMON) Tablas.o CargarTablas.o \
	Estrella1.o Estrella2.o Estrella3.o llenar.o

all : simular llenar

%.o : %.C 
	$(CXX) $(CXXFLAGS) -c $< 	

simular: $(OBJSA)
	 $(CXX) -o $(EXEDIR)/$@ $(OBJSA) $(LINKFLAGS) $(LIBS)

llenar: $(OBJSB)
	 $(CXX) -o $(EXEDIR)/$@ $(OBJSB) $(LINKFLAGS) $(LIBS)

clean		:
	$(RM) $(GARBAGE)



cleanall:
	$(RM) $(GARBAGE) $(SOGARBAGE)
