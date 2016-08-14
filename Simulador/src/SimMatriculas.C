// $Id: $
// Include files 

// local
#include "SimMatriculas.h"

//-----------------------------------------------------------------------------
// Implementation file for class : SimMatriculas
//
// 2008-05-20 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
SimMatriculas::SimMatriculas( const char * _info, const char * _in , const char *_out) 
  : Hechos (_in, _out) {
  
  //Abrir archivo con lista de nombres a asignar
  m_data = new Data(_info);
  m_data->showfirst();
  m_data->rewind();
  
  ReadInformacion();
     
}
//=============================================================================
// Destructor
//=============================================================================
SimMatriculas::~SimMatriculas() {
  
  if ( m_data ) delete m_data;

} 

//=============================================================================
void SimMatriculas::CrearMatriculas() 
{
  
  int _semestre     = 01;
  int _periodo      = 200600 + _semestre;
  
  long int _recibo  = 13000;
  long int _stcod   = 1;
  long int _codigo  = 10001;
  long int _acscod  = 19990000;
  long int _faccod  = 1000;
  long int _pgcod   = 10000;
  long int _fechapk = 10000;
  long int _estudid = 10000;
  long int _ascpk   = 1000;
  long int _pgpk    = 1000;
  long int _stpk    = 1000;
  long int _facpk   = 1000;
    
  std::string _ff   = std::string("Economia");
  std::string _pg   = std::string("Economia");
  std::string _nn   = std::string("Fabio");
  std::string _ap1  = std::string("Davila");
  std::string _ap2  = std::string("Hurtado");
  std::string _stdesc = std::string("Activo");
  int k = 1;
  
  while( m_data->next() ) {
    
    SelectAsesor( _acscod, _nn, _ap1, _ap2, k);
    SelectCodigo( _codigo, k);
    SelectFacultad( _faccod, _pgcod, _ff , _pg );
    SelectEstatus( _stcod , _stdesc );
    
    char _fecha[20];
    int _aaaa = 2006;
    int _mm   = 1;
    int _dd   = 15;
    
    _fechapk = 1000+k;
    _estudid = 1000+k;
    
    sprintf(_fecha, "%d%d%d",_aaaa, _mm, _dd);
    
    m_estudiante = new Estudiante( "Estudiante", _estudid, m_data->X1() , m_data->X3() , m_data->X4() );
    m_asesor     = new Asesor( "Asesor", _ascpk, _acscod, _nn, _ap1, _ap2 );
    m_facultad   = new Facultad( "Facultad", _facpk, _faccod, _ff );
    m_programa   = new Programa("Programa", _pgpk, _pgcod, _pg );
    m_estatus    = new Estatus( "Estatus", _stpk, _stcod, _stdesc );
    m_tiempo     = new Tiempo( "Tiempo", _fechapk, _fecha, _semestre , _periodo );
    m_matricula  = new Matriculas( "Matriculas", _recibo );
    
    m_programa->SetFacultad( m_facultad );

    m_matricula->AddFK( _fechapk );
    m_matricula->AddFK( _estudid );
    m_matricula->AddFK( _pgpk );
    m_matricula->AddFK( _stpk );
     
    m_estudiante->SetCodigo( _codigo );
    m_estudiante->SetNumID( m_data->X5() );
    m_estudiante->SetTelefono( m_data->X6() );
    m_estudiante->SetPrograma( m_programa );
    m_estudiante->SetAsesor( m_asesor );
    m_estudiante->SetEstatus( m_estatus );
    
    (*m_out) << (*m_matricula)
             << (*m_estudiante)
             << (*m_programa)
             << (*m_facultad)
             << (*m_asesor)
             << (*m_tiempo)
             << (*m_estatus) << '\n';
    
    delete m_estudiante;
    delete m_facultad;
    delete m_programa;
    delete m_asesor;
    delete m_estatus;
    delete m_tiempo;
    delete m_matricula;
    
    ++k;
    
    ++_recibo;
    ++_ascpk;
    ++_pgpk;
    ++_stpk;
    ++_facpk;
    
  }
  
}

void  SimMatriculas::SelectFacultad( long int & _fcode, long int & _pcode, 
                                  std::string & _Fc, std::string & _Pg )
{
  
  int r1 = (int) floor ( m_rnd[3]->Gaus(5,0.5) );
  _Fc = m_facs[r1-1];
  _Pg = m_facs[r1-1];
  _fcode = 1000*(r1+2);
  _pcode = 1*r1;
  
}

void  SimMatriculas::SelectEstatus( long int & _St , std::string & _stdc )
{
  
  double r1 =  100.0* m_rnd[4]->Rndm();
  if ( r1 < 5.0 ) _St = 2;
  else _St = 1;
  
  _stdc = m_ests[_St-1];
       
}

void  SimMatriculas::SelectCodigo( long int & _cd , int _k)
{
  
  int r1 = (int) floor ( m_rnd[1]->Gaus(4,0.5) );
  int r2 = (int) floor ( 1.0 + 2.0*m_rnd[2]->Rndm() );

  if ( r1 > 7) r1 = 6;
  
  _cd = 2000000000 + r1*1000000 + r2*100000 + _k;
  
}

void  SimMatriculas::SelectAsesor( long int &_cd, 
                                std::string & _n, std::string & _s1, std::string & _s2 , int k) 
{
  
  if ( m_rnd[0]->Rndm() < 0.05 ) {
    _n  = m_data->X2();
    _s1 = m_data->X4();
    _s2 = m_data->X3();
    _cd = 19990000+k;
  }
  
   
}

void  SimMatriculas::ReadInformacion()
{
  
  char _header[256];
  m_in->getline(_header,256);
  
  for (int i=0; i<3; ++i) {
    char _name[80];
    int _code;
    (*m_in) >> _code >>  _name ; 
    m_ests.push_back( std::string(_name) );
  }
  
  m_in->getline(_header,256);
  m_in->getline(_header,256);
  
  while( !m_in->fail() ) {
    char _name[80];
    int _code;
    (*m_in) >> _code >>  _name;
    if ( m_in->eof() ) break;
    m_facs.push_back( std::string(_name) );
  }
  
}
