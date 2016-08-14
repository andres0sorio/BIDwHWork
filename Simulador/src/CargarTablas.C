// $Id: $
// Include files 

// local
#include "CargarTablas.h"

//-----------------------------------------------------------------------------
// Implementation file for class : CargarTablas
//
// 2008-05-21 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
CargarTablas::CargarTablas( const char *_in ) {

  m_in = new std::ifstream( _in , ifstream::in );
  
  if(!m_in) {
    std::cout << "no se pudo abrir el archivo.\n";
    exit(1);
  } 
  
  m_nrecords=0;
  m_nrecibo = 0;

  m_db = TSQLServer::Connect("mysql://localhost/ustadb", "aosorio", "ago13shop");
  
}
//=============================================================================
// Destructor
//=============================================================================
CargarTablas::~CargarTablas() {

  if( m_db ) delete m_db;
  
  m_tables.clear();
  
} 

//=============================================================================
