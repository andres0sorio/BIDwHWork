// $Id: $
// Include files 

// local
#include "Estrella2.h"

//-----------------------------------------------------------------------------
// Implementation file for class : Estrella2
//
// 2008-05-23 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
Estrella2::Estrella2( const char * _in , int _mode ) : CargarTablas(_in) {
  
  m_tables.push_back(std::string("Notas"));
  m_tables.push_back(std::string("Asignaturas"));
  m_tables.push_back(std::string("TiempoNotas"));
  
  m_ntables = m_tables.size();
  
  m_mode = _mode;
  
}
//=============================================================================
// Destructor
//=============================================================================
Estrella2::~Estrella2() {} 

//=============================================================================
void Estrella2::LeerCargar()
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
    (*m_in) >> (*m_notas)
            >> (*m_asignatura)
            >> (*m_tiempo);
    
    if ( m_in->eof() ) {
      CleanTablas();
      break;
    }
    
    //... Generar comando SQL para insertar en base de datos
    m_notas->SetQuery();
    m_oss[0] =  m_notas->GetQuery();
    m_asignatura->SetQuery();
    m_oss[1] =  m_asignatura->GetQuery();
    m_tiempo->SetQuery();
    m_oss[2] =  m_tiempo->GetQuery();
    
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

void Estrella2::SetTablas()
{
  
  m_notas         = new Notas("Notas");
  m_asignatura    = new Asignaturas("Asignaturas");
  m_tiempo        = new TiempoNotas("TiempoNotas");
  
}

void Estrella2::CleanTablas()
{
  
  delete m_notas;
  delete m_asignatura;
  delete m_tiempo;
  
}
