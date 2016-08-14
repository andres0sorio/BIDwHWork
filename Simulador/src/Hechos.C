// $Id: $
// Include files 

// local
#include "Hechos.h"

//-----------------------------------------------------------------------------
// Implementation file for class : Hechos
//
// 2008-05-22 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
Hechos::Hechos( const char* _in, const char * _out ) {
  
  //Abrir archivo con informacion fija
  m_in =  new std::ifstream( _in, ifstream::in );
  
  //Abrir archivo para exportar los datos simulados
  m_out = new std::ofstream( _out, ofstream::out );
  
  if(!m_out) {
    std::cout << "no se pudo abrir el archivo.\n";
    exit(1);
  } 
  
  for(int i=0; i < 10; ++i) m_rnd[i] = new TRandom3(0);
  
}
//=============================================================================
// Destructor
//=============================================================================
Hechos::~Hechos() {

  if ( m_in ) {
    m_in->close();
    delete m_in;
  }
  
  if ( m_out ) {
    m_out->close();
    delete m_out;
  }
  
  if ( m_rnd[0] ) for(int i=0; i < 10; ++i) delete m_rnd[i];
  
} 

//=============================================================================
