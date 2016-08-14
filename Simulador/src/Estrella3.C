// $Id: $
// Include files 

// local
#include "Estrella3.h"

//-----------------------------------------------------------------------------
// Implementation file for class : Estrella3
//
// 2008-05-23 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
Estrella3::Estrella3( const char * _in , int _mode ) : CargarTablas(_in) {
  
  m_tables.push_back(std::string("Deserciones"));
  m_tables.push_back(std::string("RazonDesercion"));
  
  m_ntables = m_tables.size();
  
  m_mode = _mode;

}
//=============================================================================
// Destructor
//=============================================================================
Estrella3::~Estrella3() {} 

//=============================================================================
void Estrella3::LeerCargar()
{
  
  if ( m_mode == 1 ) {
    
    for(int i=0; i < m_ntables; ++i) {
      char _delfrom[40];
      sprintf(_delfrom,"DELETE FROM %s", m_tables[i].c_str() );
      m_sqlres = m_db->Query(_delfrom);
      delete m_sqlres;
    }
    
  }
  
  while( !m_in->fail() ) {
    
    //if( m_nrecords > 5 ) break;
    
    SetTablas();
    
    //... Extraer datos
    (*m_in) >> (*m_deserciones)
            >> (*m_razon);
    
    if ( m_in->eof() ) {
      CleanTablas();
      break;
    }
    
    //... Generar comando SQL para insertar en base de datos
    m_deserciones->SetQuery();
    m_oss[0] =  m_deserciones->GetQuery();
    m_razon->SetQuery();
    m_oss[1] =  m_razon->GetQuery();
        
    //... Cargar registros en la base de datos
    
    for(int i=0; i < m_ntables; ++i) { 
      //std::cout << (*m_oss[i]).str() << ";" << std::endl;
      m_sqlres = m_db->Query( (*m_oss[i]).str().c_str() );
      delete m_sqlres;
    }
    
    ++m_nrecords;
    
    CleanTablas();
    
  }
 
  std::cout << "LeerCargar> total registros adicionados: " << m_nrecords << '\n';
    
}

void Estrella3::SetTablas()
{

  m_deserciones  = new Deserciones("Deserciones");
  m_razon        = new RazonDesercion("RazonDesercion");
  
}

void Estrella3::CleanTablas()
{
  
  delete m_deserciones;
  delete m_razon;

  
}
