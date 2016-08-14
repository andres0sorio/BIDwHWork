// $Id: $
// Include files 


// local
#include "Tablas.h"

//-----------------------------------------------------------------------------
// Implementation file for class : Dimension
//
// 2008-05-20 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
Dimension::Dimension( const char *_title, long int _key ) {
  
  m_pkey = _key;
  m_name = std::string(_title);
  m_oss = new std::ostringstream(ostringstream::app);
}
//=============================================================================
// Destructor
//=============================================================================
Dimension::~Dimension () {
  if (m_oss) delete m_oss;
} 

//-----------------------------------------------------------------------------
// Implementation file for class : Estudiante
//
// 2008-05-20 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
Estudiante::Estudiante( const char *_title, long int _key, 
                        const char * _nn, const char * _ap1, const char * _ap2 ) 
  : Dimension ( _title, _key) {
  
  m_nombre    = std::string(_nn);
  m_apellido1 = std::string(_ap1);
  m_apellido2 = std::string(_ap2);
  
}

Estudiante::Estudiante( const char *_title, long int _key, 
                        const std::string &_nn, const std::string &_ap1, const std::string & _ap2) 
  : Dimension (_title, _key) {
  
  m_nombre    = _nn;
  m_apellido1 = _ap1;
  m_apellido2 = _ap2;
  m_tipoid    = std::string("CC");
  
}
//=============================================================================
// Destructor
//=============================================================================
Estudiante::~Estudiante() {
  
} 

//=============================================================================

std::ostream& operator<<(std::ostream &ostr, Estudiante &rhs) {

  ostr << rhs.m_pkey << " ";
  ostr << rhs.m_codigo << " ";
  ostr << rhs.m_nombre << " " << rhs.m_apellido1 << " " << rhs.m_apellido2 << " ";
  ostr << rhs.m_tipoid << " " << rhs.m_numid << " " << rhs.m_telefono << " ";
  ostr << rhs.m_asesor->m_pkey << " ";
      
  return ostr;
  
}

std::ostringstream& operator<<(std::ostringstream &ostr, Estudiante &rhs) {

  ostr << "('" << rhs.m_pkey;
  ostr << "','" << rhs.m_codigo;
  ostr << "','" << rhs.m_nombre << "','" << rhs.m_apellido1 << "','" << rhs.m_apellido2;
  ostr << "','" << rhs.m_tipoid << "','" << rhs.m_numid << "','" << rhs.m_telefono;
  ostr << "','" << rhs.m_asesor->m_pkey << "')";
      
  return ostr;
  
}

std::istream& operator>>(std::istream &istr, Estudiante &rhs) {

  istr >> rhs.m_pkey;
  istr >> rhs.m_codigo;
  istr >> rhs.m_nombre >> rhs.m_apellido1 >> rhs.m_apellido2;
  istr >> rhs.m_tipoid >> rhs.m_numid >> rhs.m_telefono;
  istr >> rhs.m_asesor->m_pkey;
    
  return istr;
  
}

//-----------------------------------------------------------------------------
// Implementation file for class : Facultad
//
// 2008-05-20 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
Facultad::Facultad( const char *_title, long int &_key, long int &_cod,
                    const std::string & _nn  ) : Dimension (_title, _key) {

  m_codigo = _cod;
  m_nombre = _nn;
  m_decano = std::string("JuanPerez");
  
}
//=============================================================================
// Destructor
//=============================================================================
Facultad::~Facultad() {} 

std::ostream& operator<<(std::ostream &ostr, Facultad &rhs) {

  ostr << rhs.m_pkey << " " 
       << rhs.m_codigo << " "
       << rhs.m_nombre << " ";
  
  return ostr;
  
}

std::ostringstream& operator<<(std::ostringstream &ostr, Facultad &rhs) {
  
  ostr << "('"  
       << rhs.m_pkey << "','" 
       << rhs.m_codigo << "','"
       << rhs.m_nombre;
  ostr << "')";
  
  return ostr;
  
}

std::istream& operator>>(std::istream &istr, Facultad &rhs) {
  
  istr >> rhs.m_pkey >> rhs.m_codigo >> rhs.m_nombre;
  
  return istr;
  
}

//-----------------------------------------------------------------------------
// Implementation file for class : Programa
//
// 2008-05-20 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
Programa::Programa( const char *_title, long int &_key, long int &_cod, const std::string & _nn ) 
  : Dimension (_title, _key) {

  m_codigo = _cod;
  m_nombre = _nn;
    
}
//=============================================================================
// Destructor
//=============================================================================
Programa::~Programa() {} 

//=============================================================================
std::ostream& operator<<(std::ostream &ostr, Programa &rhs) {

  ostr << rhs.m_pkey << " ";
  ostr << rhs.m_codigo << " ";
  ostr << rhs.m_nombre << " ";
  ostr << rhs.m_facultad->m_pkey << " ";

  return ostr;
  
}

std::ostringstream& operator<<(std::ostringstream &ostr, Programa &rhs) {
  
  ostr << "('"  << rhs.m_pkey;
  ostr << "','" << rhs.m_codigo;  
  ostr << "','" << rhs.m_nombre;
  ostr << "','" << rhs.m_facultad->m_pkey << "')";
  
  return ostr;
  
}

std::istream& operator>>(std::istream &istr, Programa &rhs) {

  istr >> rhs.m_pkey;
  istr >> rhs.m_codigo;
  istr >> rhs.m_nombre;
  istr >> rhs.m_facultad->m_pkey;
  
  return istr;
  
}

//-----------------------------------------------------------------------------
// Implementation file for class : Estatus
//
// 2008-05-20 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
Estatus::Estatus( const char *_title, long int &_key, long int &_cod, const std::string & _stn ) 
  : Dimension (_title, _key) {
  
  m_codigo  = _cod;
  m_estatus = _stn;
  
}
//=============================================================================
// Destructor
//=============================================================================
Estatus::~Estatus() {} 

//=============================================================================
std::ostream& operator<<(std::ostream &ostr, Estatus &rhs) {

  ostr << rhs.m_pkey << " ";
  ostr << rhs.m_codigo << " ";
  ostr << rhs.m_estatus << " ";
  
  return ostr;
  
}

std::ostringstream& operator<<(std::ostringstream &ostr, Estatus &rhs) {

  ostr << "('" << rhs.m_pkey;
  ostr << "','" << rhs.m_codigo;
  ostr << "','" << rhs.m_estatus << "')";
  
  return ostr;
  
}

std::istream& operator>>(std::istream &istr, Estatus &rhs) {
  
  istr >> rhs.m_pkey;
  istr >> rhs.m_codigo;
  istr >> rhs.m_estatus;
  
  return istr;
  
}

//-----------------------------------------------------------------------------
// Implementation file for class : Tiempo
//
// 2008-05-21 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
Tiempo::Tiempo( const char *_title, long int _key, 
                const char *_fecha, int & _sem, int & _per ) : Dimension (_title, _key) {
  
  m_fecha = std::string(_fecha);
  m_semestre = _sem;
  m_periodo = _per;
  
}

//=============================================================================
// Destructor
//=============================================================================
Tiempo::~Tiempo() {} 

//=============================================================================
std::ostream& operator<<(std::ostream &ostr, Tiempo &rhs) {
  
  ostr << rhs.m_pkey << " " 
       << rhs.m_fecha << " " 
       << rhs.m_semestre << " " 
       << rhs.m_periodo << " ";
  
  return ostr;
  
}

std::ostringstream& operator<<(std::ostringstream &ostr, Tiempo &rhs) {
  
  ostr << "('" << rhs.m_pkey << "','"
       << rhs.m_fecha << "','" 
       << rhs.m_semestre << "','" 
       << rhs.m_periodo << "')";
  
  return ostr;
  
}

std::istream& operator>>(std::istream &istr, Tiempo &rhs) {
  
  istr >> rhs.m_pkey >> rhs.m_fecha >> rhs.m_semestre >> rhs.m_periodo;
  
  return istr;
  
}

//-----------------------------------------------------------------------------
// Implementation file for class : Asesor
//
// 2008-05-20 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
Asesor::Asesor( const char *_title, long int &_key, long int &_cod,
                const std::string &_nn, const std::string &_ap1, const std::string & _ap2) 
  : Dimension (_title, _key) {
  
  m_codigo    = _cod;
  m_nombre    = _nn;
  m_apellido1 = _ap1;
  m_apellido2 = _ap2;
  m_facultad  = std::string("Ciencias");
   
}
//=============================================================================
// Destructor
//=============================================================================
Asesor::~Asesor() {} 

//=============================================================================
std::ostream& operator<<(std::ostream &ostr, Asesor &rhs) {

  ostr << rhs.m_pkey << " ";
  ostr << rhs.m_codigo << " ";
  ostr << rhs.m_nombre << " " << rhs.m_apellido1 << " " << rhs.m_apellido2 << " ";
  ostr << rhs.m_facultad << " ";
  
  return ostr;
  
}

std::ostringstream& operator<<(std::ostringstream &ostr, Asesor &rhs) {

  ostr << "('" << rhs.m_pkey;
  ostr << "','" << rhs.m_codigo;
  ostr << "','" << rhs.m_nombre << "','" << rhs.m_apellido1 << "','" << rhs.m_apellido2;
  ostr << "','" << rhs.m_facultad << "')";
  
  return ostr;
  
}

std::istream& operator>>(std::istream &istr, Asesor &rhs) {
  
  istr >> rhs.m_pkey;
  istr >> rhs.m_codigo;
  istr >> rhs.m_nombre >> rhs.m_apellido1 >> rhs.m_apellido2;
  istr >> rhs.m_facultad;
  
  return istr;
  
}

//-----------------------------------------------------------------------------
// Implementation file for class : Matriculas
//
// 2008-05-20 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
Matriculas::Matriculas( const char *_title, long int _key) : Dimension (_title, _key) {
  
}
//=============================================================================
// Destructor
//=============================================================================
Matriculas::~Matriculas() {
  m_fkeys.clear();
} 

//=============================================================================
void Matriculas::AddFK( long int & _fk )
{
  m_fkeys.push_back( _fk );
}

std::ostream& operator<<(std::ostream &ostr, Matriculas &rhs) {

  ostr << rhs.m_pkey << " ";
  std::vector<long int>::iterator itr;
  itr = rhs.m_fkeys.begin();
  while ( itr != rhs.m_fkeys.end() ) { ostr << (*itr) << " "; ++itr;};
  
  return ostr;
  
}

std::ostringstream& operator<<(std::ostringstream &ostr, Matriculas &rhs) {

  ostr << "('" << rhs.m_pkey << "','";
  std::vector<long int>::iterator itr;
  itr = rhs.m_fkeys.begin();
  while ( itr != rhs.m_fkeys.end() ) {
    ostr << (*itr);
    ++itr;
    if ( itr != rhs.m_fkeys.end() ) ostr << "','";
    else ostr << "')";
  }
  
  return ostr;
  
}

std::istream& operator>>(std::istream &istr, Matriculas &rhs) {
  
  istr >> rhs.m_pkey;
  
  for(int i=0; i < 4; ++i) {
    long int _key;
    istr >> _key;
    rhs.m_fkeys.push_back(_key);
  }
  
  return istr;
  
}

//-----------------------------------------------------------------------------
// Implementation file for class : Asignaturas
//
// 2008-05-20 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
Asignaturas::Asignaturas( const char *_title, long int &_key, long int &_cod,
                          const std::string &_nn, int & _cred ) 
  : Dimension (_title, _key) {
  
  m_codigo    = _cod;
  m_nombre    = _nn;
  m_creditos  = _cred;
    
}
//=============================================================================
// Destructor
//=============================================================================
Asignaturas::~Asignaturas() {} 

//=============================================================================
std::ostream& operator<<(std::ostream &ostr, Asignaturas &rhs) {
  
  ostr << rhs.m_pkey << " ";
  ostr << rhs.m_codigo << " ";
  ostr << rhs.m_nombre << " ";
  ostr << rhs.m_creditos << " ";
  
  return ostr;
  
}

std::ostringstream& operator<<(std::ostringstream &ostr, Asignaturas &rhs) {

  ostr << "('" << rhs.m_pkey;
  ostr << "','" << rhs.m_codigo;
  ostr << "','" << rhs.m_nombre;
  ostr << "','" << rhs.m_creditos << "')";
  
  return ostr;
  
}

std::istream& operator>>(std::istream &istr, Asignaturas &rhs) {
  
  istr >> rhs.m_pkey;
  istr >> rhs.m_codigo;
  istr >> rhs.m_nombre;
  istr >> rhs.m_creditos;

  return istr;
  
}

//-----------------------------------------------------------------------------
// Implementation file for class : Notas
//
// 2008-05-20 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
Notas::Notas( const char *_title, long int _key )
  : Dimension (_title, _key) {
  
}
//=============================================================================
// Destructor
//=============================================================================
Notas::~Notas() { m_fkeys.clear(); } 

//=============================================================================
void Notas::AddFK( long int & _fk )
{
  m_fkeys.push_back( _fk );
}

std::ostream& operator<<(std::ostream &ostr, Notas &rhs) {
  
  ostr << rhs.m_pkey << " ";
  
  std::vector<long int>::iterator itr;
  itr = rhs.m_fkeys.begin();
  while ( itr != rhs.m_fkeys.end() ) { ostr << (*itr) << " "; ++itr;};
  
  ostr << rhs.m_notadef << " ";
  
  return ostr;
  
}

std::ostringstream& operator<<(std::ostringstream &ostr, Notas &rhs) {
  
  ostr << "('" << rhs.m_pkey << "','";
  std::vector<long int>::iterator itr;
  itr = rhs.m_fkeys.begin();
  while ( itr != rhs.m_fkeys.end() ) {
    ostr << (*itr);
    ++itr;
    ostr << "','";
  }
  
  ostr << rhs.m_notadef << "')";
  
  return ostr;
  
}

std::istream& operator>>(std::istream &istr, Notas &rhs) {
  
  istr >> rhs.m_pkey;
  
  for(int i=0; i < 3; ++i) {
    long int _key;
    istr >> _key;
    rhs.m_fkeys.push_back(_key);
  }
  
  istr >> rhs.m_notadef;
    
  return istr;
  
}

//-----------------------------------------------------------------------------
// Implementation file for class : TiempoNotas
//
// 2008-05-20 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
TiempoNotas::TiempoNotas( const char *_title, long int &_key,
                          long int & _fecha, int & _sem, int & _per , int & _cor) 
  : Dimension (_title, _key) {
  
  m_fecha = _fecha;
  m_semestre = _sem;
  m_periodo = _per;
  m_corte = _cor;
  
}
//=============================================================================
// Destructor
//=============================================================================
TiempoNotas::~TiempoNotas() {} 

//=============================================================================
std::ostream& operator<<(std::ostream &ostr, TiempoNotas &rhs) {
  
  ostr << rhs.m_pkey << " " 
       << rhs.m_fecha << " "
       << rhs.m_semestre << " " 
       << rhs.m_periodo << " "
       << rhs.m_corte << " ";
  
  return ostr;
  
}

std::ostringstream& operator<<(std::ostringstream &ostr, TiempoNotas &rhs) {
  
  ostr << "('" << rhs.m_pkey << "','"
       << rhs.m_fecha << "','"
       << rhs.m_semestre << "','" 
       << rhs.m_periodo << "','" 
       << rhs.m_corte << "')";
  
  return ostr;
  
}

std::istream& operator>>(std::istream &istr, TiempoNotas &rhs) {
  
  istr >> rhs.m_pkey >> rhs.m_fecha >> rhs.m_semestre >> rhs.m_periodo >> rhs.m_corte;
  
  return istr;
  
}

//-----------------------------------------------------------------------------
// Implementation file for class : RazonDesercion
//
// 2008-05-20 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RazonDesercion::RazonDesercion( const char *_title, long int &_key, int & _cod) 
  : Dimension (_title, _key) {
  
  m_codigo = _cod;
  
}
//=============================================================================
// Destructor
//=============================================================================
RazonDesercion::~RazonDesercion() {} 

//=============================================================================
std::ostream& operator<<(std::ostream &ostr, RazonDesercion &rhs) {
  
  ostr << rhs.m_pkey << " " << rhs.m_codigo << " " << rhs.m_razon << " ";
  return ostr;
  
}

std::ostringstream& operator<<(std::ostringstream &ostr, RazonDesercion &rhs) {
  
  ostr << "('" << rhs.m_pkey << "','" 
       << rhs.m_codigo << "','" << rhs.m_razon << "')";
  
  return ostr;
  
}

std::istream& operator>>(std::istream &istr, RazonDesercion &rhs) {
  
  istr >> rhs.m_pkey >> rhs.m_codigo >> rhs.m_razon;
  
  return istr;
  
}

//-----------------------------------------------------------------------------
// Implementation file for class : Deserciones
//
// 2008-05-20 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
Deserciones::Deserciones( const char *_title, long int _key )
  : Dimension (_title, _key) {
  
}
//=============================================================================
// Destructor
//=============================================================================
Deserciones::~Deserciones() { m_fkeys.clear(); } 

//=============================================================================
void Deserciones::AddFK( long int & _fk )
{
  m_fkeys.push_back( _fk );
}

std::ostream& operator<<(std::ostream &ostr, Deserciones &rhs) {
  
  ostr << rhs.m_pkey << " ";
  std::vector<long int>::iterator itr;
  itr = rhs.m_fkeys.begin();
  while ( itr != rhs.m_fkeys.end() ) { ostr << (*itr) << " "; ++itr;};
  
  return ostr;
  
}

std::ostringstream& operator<<(std::ostringstream &ostr, Deserciones &rhs) {
  
  ostr << "('" << rhs.m_pkey << "','";
  std::vector<long int>::iterator itr;
  itr = rhs.m_fkeys.begin();
  while ( itr != rhs.m_fkeys.end() ) {
    ostr << (*itr);
    ++itr;
    if ( itr != rhs.m_fkeys.end() ) ostr << "','";
    else ostr << "')";
  }
  return ostr;
  
}

std::istream& operator>>(std::istream &istr, Deserciones &rhs) {
  
  istr >> rhs.m_pkey;
  
  for(int i=0; i < 3; ++i) {
    long int _key;
    istr >> _key;
    rhs.m_fkeys.push_back(_key);
  }
  
  return istr;
  
}


