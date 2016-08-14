// $Id: $
// Include files 



// local
#include "SimNotas.h"

//-----------------------------------------------------------------------------
// Implementation file for class : SimNotas
//
// 2008-05-23 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
SimNotas::SimNotas( const char *_in, const char *_out  ) : Hechos(_in, _out){

}
//=============================================================================
// Destructor
//=============================================================================
SimNotas::~SimNotas() {} 

//=============================================================================
void SimNotas::CrearNotas()
{

  int _semestre     = 01;
  int _periodo      = 200600 + _semestre;
  int _corte        = 04;

  float _nota = 3.9;
  long int _fechapk = 1000; //fecha PK
  long int _fecha   = 20060601; //fecha FK
  long int _notapk  = 10000; //codigo Nota PK
  long int _asigcod = 1000101; //asignatura PK
  long int _asigpk  = 1000; //codigo asignatura FK
  long int _estudpk = 10000; //estudiante ID FK
  long int _estucod = 10000; //codigo estudiante
  
  std::string _asg  = std::string("Fisica01"); //nombre asignatura
  int _creditos = 3;
  
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
    
    if ( m_estatus->m_codigo != 1 ) {
      CleanTablas();
      continue;
    }
    
    m_notas = new Notas("Notas" , _notapk );
    m_asignatura = new Asignaturas("Asignatura" , _asigpk , _asigcod, _asg , _creditos );
    m_tiemponota = new TiempoNotas("TiempoNota" , _fechapk , _fecha, _semestre, _periodo, _corte);
    
    _estudpk = m_estudiante->m_pkey;
    
    m_estudiante->GetCodigo( _estucod );
    
    m_notas->SetNota(_nota);
    m_notas->AddFK( _asigpk );
    m_notas->AddFK( _fechapk );
    m_notas->AddFK( _estudpk );
        
    (*m_out) << (*m_notas)
             << (*m_asignatura)
             << (*m_tiemponota) << '\n';
    
    delete m_notas;
    delete m_asignatura;
    delete m_tiemponota; 
    CleanTablas();
    
    ++_notapk;
    ++_fechapk;
    ++_asigpk;
    
  }
  
}

void SimNotas::SetTablas()
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

void SimNotas::CleanTablas()
{
  
  delete m_matriculas;
  delete m_estudiante;
  delete m_facultad;
  delete m_programa;
  delete m_asesor;
  delete m_estatus;
  delete m_tiempo;
    
}
