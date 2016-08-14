// $Id: $
// Include files 



// local
#include "SimDesercion.h"

//-----------------------------------------------------------------------------
// Implementation file for class : SimDesercion
//
// 2008-05-23 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
SimDesercion::SimDesercion( const char * _in, const char* _out ) : Hechos( _in, _out) {
  
}

//=============================================================================
// Destructor
//=============================================================================
SimDesercion::~SimDesercion() {} 

//=============================================================================
void SimDesercion::CrearDeserciones()
{
 
  long int _deserpk = 20001;
  long int _fechapk = 10000; //fecha (FK)
  long int _razonpk = 1001;  //codigo razon para desertar (FK)
  long int _estudpk = 10000; //estudiante ID (FK)
  long int _estucod = 10000; //codigo estudiante
 
  int _codigo = 3;

  std::string _razon[3];
  _razon[0] = std::string("Financiera");
  _razon[1] = std::string("Orientacion");
  _razon[2] = std::string("Academica");
  
  while( !m_in->fail() ) {
    
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
    
    if ( m_estatus->m_codigo != 2 ) {
      CleanTablas();
      continue;
    }
    
    m_desercion = new Deserciones("Desercion" , _deserpk );
    m_razon     = new RazonDesercion("RazonDesercion" , _razonpk , _codigo );
    
    m_razon->SetRazon( _razon[_codigo-1] );
    _estudpk = m_estudiante->m_pkey;
    m_estudiante->GetCodigo( _estucod );
    _fechapk = m_tiempo->m_pkey;
    
    m_desercion->AddFK( _estudpk );
    m_desercion->AddFK( _razonpk );
    m_desercion->AddFK( _fechapk );
        
    (*m_out) << (*m_desercion)
             << (*m_razon) << '\n';
    
    delete m_desercion;
    delete m_razon;
    CleanTablas();
    
    ++_deserpk;
    ++_razonpk;
    
  }
  
}

void SimDesercion::SetTablas()
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

void SimDesercion::CleanTablas()
{
  
  delete m_matriculas;
  delete m_estudiante;
  delete m_facultad;
  delete m_programa;
  delete m_asesor;
  delete m_estatus;
  delete m_tiempo;
    
}
