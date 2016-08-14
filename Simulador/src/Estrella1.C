// $Id: $
// Include files 

// local
#include "Estrella1.h"

//-----------------------------------------------------------------------------
// Implementation file for class : Estrella1
//
// 2008-05-21 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
Estrella1::Estrella1( const char *_in , int _mode ) : CargarTablas( _in ) {
  
  m_tables.push_back(std::string("Matriculas"));
  m_tables.push_back(std::string("Estudiante"));
  m_tables.push_back(std::string("Asesor"));
  m_tables.push_back(std::string("Programas"));
  m_tables.push_back(std::string("Facultades"));
  m_tables.push_back(std::string("Estatus"));
  m_tables.push_back(std::string("Tiempo"));
  
  m_ntables = m_tables.size();
  
  m_mode = _mode;
  
}
//=============================================================================
// Destructor
//=============================================================================
Estrella1::~Estrella1() {

} 

//=============================================================================
void Estrella1::LeerCargar()
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
    (*m_in) >> (*m_matriculas)
            >> (*m_estudiante)
            >> (*m_programa)
            >> (*m_facultad)
            >> (*m_asesor)
            >> (*m_tiempo)
            >> (*m_estatus);
    
    if ( m_in->eof() ) {
      CleanTablas();
      break;
    }
    
    //... Generar comando SQL para insertar en base de datos
    m_estudiante->SetQuery();
    m_oss[0] =  m_estudiante->GetQuery();
    m_programa->SetQuery();
    m_oss[1] =  m_programa->GetQuery();
    m_asesor->SetQuery();
    m_oss[2] =  m_asesor->GetQuery();
    m_facultad->SetQuery();
    m_oss[3] =  m_facultad->GetQuery();
    m_tiempo->SetQuery();
    m_oss[4] =  m_tiempo->GetQuery();
    m_estatus->SetQuery();
    m_oss[5] =  m_estatus->GetQuery();
    m_matriculas->SetQuery();
    m_oss[6] =  m_matriculas->GetQuery();
    
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

void Estrella1::SetTablas()
{
  
  m_matriculas = new Matriculas("Matriculas");
  m_estudiante = new Estudiante("Estudiante");
  m_asesor     = new Asesor("Asesor");
  m_facultad   = new Facultad("Facultades");
  m_programa   = new Programa("Programas");
  m_estatus    = new Estatus("Estatus");
  m_tiempo     = new Tiempo("Tiempo");
  
  m_programa->SetFacultad( m_facultad );
  m_estudiante->SetPrograma( m_programa );
  m_estudiante->SetAsesor( m_asesor );
  m_estudiante->SetEstatus( m_estatus );

  
}

void Estrella1::CleanTablas()
{

  delete m_matriculas;
  delete m_estudiante;
  delete m_facultad;
  delete m_programa;
  delete m_asesor;
  delete m_estatus;
  delete m_tiempo;
    
}
