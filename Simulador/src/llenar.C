// $Id: main.C,v 1.3 2007/09/06 16:24:31 aosorio Exp $
// Include files 

#include "Estrella1.h"
#include "Estrella2.h"
#include "Estrella3.h"

int main(int iargv, const char **argv) {
  
  if(iargv < 5 ) {
    std::cout << "usage : llenar> [datos estrella1] " 
              << "[datos estrella2] " 
              << "[datos estrella3] [modo: 1=borrar contenido previo 0= adicionar datos]" << std::endl;
    return 0;
  }
  
  int mode = atoi( argv[4] );
  
  Estrella1 *etl1 = new Estrella1(argv[1], mode);
  etl1->LeerCargar();
  delete etl1;

  Estrella2 *etl2 = new Estrella2(argv[2], mode);
  etl2->LeerCargar();
  delete etl2;

  Estrella3 *etl3 = new Estrella3(argv[3], mode);
  etl3->LeerCargar();
  delete etl3;
    
  return 1;
    
}
