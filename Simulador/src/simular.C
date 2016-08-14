// $Id: main.C,v 1.3 2007/09/06 16:24:31 aosorio Exp $
// Include files 

#include "SimMatriculas.h"
#include "SimNotas.h"
#include "SimDesercion.h"

int main(int iargv, const char **argv) {
  
  if(iargv < 2 ) {
    std::cout << "usage : simular> [lista nombres]" << std::endl;
    return 0;
  }
  
  const char *fname = argv[1];
  
  //Simular Matriculas
  SimMatriculas * mat = new SimMatriculas(fname, "informacion.csv", "matriculas.csv");
  mat->CrearMatriculas();
  delete mat;
  
  //Simular Notas estudiantes Activos
  SimNotas * snot = new SimNotas("matriculas.csv","notas.csv");
  snot->CrearNotas();
  delete snot;
  
  //Simular Casos de desercion
  SimDesercion * des = new SimDesercion("matriculas.csv","deserciones.csv");
  des->CrearDeserciones();
  delete des;
  
  //....
  
  return 1;
    
}
