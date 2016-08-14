// $Id: $
#ifndef SIMULADOR_TABLAS_H 
#define SIMULADOR_TABLAS_H 1

// Include files

#include "CommonIncludes.h"
#include "Operadores.h"
#include <sstream>

/** @class Dimension Dimension.h Simulador/Dimension.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-05-20
 */

class Dimension {
public: 
  /// Standard constructor
  Dimension( ) {  m_pkey=0; 
  m_name=std::string("Dim"); 
  m_oss = new std::ostringstream(ostringstream::app);};

  Dimension( const char * _name) {  m_pkey=0; 
  m_name=std::string(_name) ;
  m_oss = new std::ostringstream(ostringstream::app);};
  
  Dimension( const char * , long int );
  
  virtual ~Dimension( ); ///< Destructor
  
  long int m_pkey;
  std::string m_name;
  std::ostringstream *m_oss;

  std::ostringstream * GetQuery() { return m_oss; };
    
protected:
  
private:
  
};

/** @class Facultad Facultad.h Simulador/Facultad.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-05-20
 */

class Facultad : public Dimension {
public: 
  /// Standard constructor
  Facultad( ) : Dimension() {}; 

  Facultad(const char * _name) : Dimension( _name ) {}; 
  
  Facultad( const char * , long int &, long int &, const std::string & ); 
  
  virtual ~Facultad( ); ///< Destructor
  
  long int m_codigo;
  std::string m_nombre;
  std::string m_decano;
  
  void SetQuery() 
  {
    (*m_oss) << "INSERT INTO " << (this->m_name) << " VALUES ";
    (*m_oss) << (*this);
  }
  
protected:
  
private:

};

/** @class Programa Programa.h Simulador/Programa.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-05-20
 */

class Programa : public Dimension {
public: 
  /// Standard constructor
  Programa( ) : Dimension() { }; 

  Programa( const char * _name) : Dimension(_name) { };
  
  Programa( const char * , long int &, long int &, const std::string & ); 
  
  virtual ~Programa( ); ///< Destructor

  long int m_codigo;
  std::string m_nombre;
  
  Facultad * m_facultad;
  
  void SetFacultad( Facultad *_fc ) { m_facultad = _fc; };

  void SetQuery() 
  {
    (*m_oss) << "INSERT INTO " << (this->m_name) << " VALUES ";
    (*m_oss) << (*this);
  }

  
protected:

private:

};

/** @class Asesor Asesor.h Simulador/Asesor.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-05-20
 */

class Asesor : public Dimension {
public: 
  /// Standard constructor
  Asesor( ) : Dimension() { }; 
  
  Asesor(const char * _name ) : Dimension( _name ) { };
  
  Asesor(const char * , long int &, long int &, 
         const std::string &, const std::string &, const std::string &);
  
  virtual ~Asesor( ); ///< Destructor
  
  long int m_codigo;
  std::string m_nombre;
  std::string m_apellido1;
  std::string m_apellido2;
  std::string m_facultad;
  
  void SetQuery() 
  {
    (*m_oss) << "INSERT INTO " << (this->m_name) << " VALUES ";
    (*m_oss) << (*this);
  }

protected:

private:

};

/** @class Estatus Estatus.h Simulador/Estatus.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-05-20
 */

class Estatus : public Dimension {
public: 
  /// Standard constructor
  Estatus( ) : Dimension() { };

  Estatus( const char * _name ) : Dimension( _name ) { };
  
  Estatus( const char * , long int &, long int &, const std::string & );
  
  virtual ~Estatus( ); ///< Destructor

  long int m_codigo;
  std::string m_estatus;

  void SetQuery() 
  {
    (*m_oss) << "INSERT INTO " << (this->m_name) << " VALUES ";
    (*m_oss) << (*this);
  }
  
protected:

private:

};

/** @class Tiempo Tiempo.h Simulador/Tiempo.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-05-21
 */
class Tiempo : public Dimension {
public: 
  /// Standard constructor
  Tiempo( ) : Dimension() { }; 

  Tiempo( const char * _name ) : Dimension( _name ) { }; 

  Tiempo( const char * , long int, const char *, int &, int & );
  
  virtual ~Tiempo( ); ///< Destructor
  
  std::string m_fecha;
  int m_semestre;
  int m_periodo;
  
  void SetQuery() 
  {
    (*m_oss) << "INSERT INTO " << (this->m_name) << " VALUES ";
    (*m_oss) << (*this);
  }


protected:
  
private:
  
};

/** @class Estudiante Estudiante.h Simulador/Estudiante.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-05-20
 */

class Estudiante : public Dimension {
public: 
  /// Standard constructor
  Estudiante(): Dimension() { };

  Estudiante(const char * _name ): Dimension( _name ) { };
  
  Estudiante(const char *, long int, const char *, const char *, const char *); 
  
  Estudiante(const char *, long int, const std::string &, const std::string &, const std::string &);
  
  virtual ~Estudiante( ); ///< Destructor

  std::string m_nombre;
  std::string m_apellido1;
  std::string m_apellido2;
  std::string m_tipoid;
  
  long int m_codigo;
  long int m_telefono;
  long int m_numid;
  
  Asesor *m_asesor;
  Estatus *m_estatus;
  Programa *m_programa;
  
  void SetCodigo( long int _cod ) { m_codigo = _cod; };
  
  void GetCodigo( long int & _cod) { _cod = m_codigo; };
  
  void SetTelefono( long int _tel) { m_telefono = _tel; };

  void SetNumID( long int _id ) { m_numid = _id; };
    
  void SetAsesor( Asesor * _ar) { m_asesor = _ar; };
  
  void SetEstatus( Estatus * _st ) { m_estatus = _st; };
  
  void SetPrograma( Programa * _fc) { m_programa = _fc; };

  void SetQuery() 
  {
    (*m_oss) << "INSERT INTO " << (this->m_name) << " VALUES ";
    (*m_oss) << (*this);
  }
  
protected:
  
private:
  
};

/** @class Matriculas Matriculas.h Simulador/Matriculas.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-05-21
 */
class Matriculas : public Dimension {
public: 
  /// Standard constructor
  Matriculas( ) : Dimension() { }; 

  Matriculas( const char * _name ) : Dimension( _name ) { }; 

  Matriculas( const char * , long int );
  
  virtual ~Matriculas( ); ///< Destructor
  
  std::vector<long int> m_fkeys;

  void AddFK( long int & );
    
  void SetQuery() 
  {
    (*m_oss) << "INSERT INTO " << (this->m_name) << " VALUES ";
    (*m_oss) << (*this);
  }


protected:
  
private:
  
};

/** @class Asignaturas Asignaturas.h Simulador/Asignaturas.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-05-21
 */
class Asignaturas : public Dimension {
public: 
  /// Standard constructor
  Asignaturas( ) : Dimension() { }; 

  Asignaturas( const char * _name ) : Dimension( _name ) { }; 

  Asignaturas( const char * , long int &, long int &, const std::string &, int & );
  
  virtual ~Asignaturas( ); ///< Destructor
  
  long int m_codigo;
  std::string m_nombre;
  int m_creditos;

  void SetQuery() 
  {
    (*m_oss) << "INSERT INTO " << (this->m_name) << " VALUES ";
    (*m_oss) << (*this);
  }


protected:
  
private:
  
};

/** @class Notas Notas.h Simulador/Notas.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-05-21
 */
class Notas : public Dimension {
public: 
  /// Standard constructor
  Notas( ) : Dimension() { }; 

  Notas( const char * _name ) : Dimension( _name ) { }; 

  Notas( const char * , long int );
  
  virtual ~Notas( ); ///< Destructor

  //Hechos:
  float m_notadef;
    
  std::vector<long int> m_fkeys;

  void SetNota( float & _nota ) { m_notadef = _nota; };
  
  void AddFK( long int & );
  
  void SetQuery() 
  {
    (*m_oss) << "INSERT INTO " << (this->m_name) << " VALUES ";
    (*m_oss) << (*this);
  }

protected:
  
private:
  
};

/** @class TiempoNotas TiempoNotas.h Simulador/TiempoNotas.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-05-21
 */
class TiempoNotas : public Dimension {
public: 
  /// Standard constructor
  TiempoNotas( ) : Dimension() { }; 

  TiempoNotas( const char * _name ) : Dimension( _name ) { }; 

  TiempoNotas( const char * , long int &, long int &, int &, int & , int & );
  
  virtual ~TiempoNotas( ); ///< Destructor
  
  long int m_fecha;
  int m_semestre;
  int m_periodo;
  int m_corte;
  
  void SetQuery() 
  {
    (*m_oss) << "INSERT INTO " << (this->m_name) << " VALUES ";
    (*m_oss) << (*this);
  }
  
protected:
  
private:
  
};

/** @class RazonDesercion RazonDesercion.h Simulador/RazonDesercion.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-05-21
 */
class RazonDesercion : public Dimension {
public: 
  /// Standard constructor
  RazonDesercion( ) : Dimension() { }; 

  RazonDesercion( const char * _name ) : Dimension( _name ) { }; 

  RazonDesercion( const char * , long int &, int & );
  
  virtual ~RazonDesercion( ); ///< Destructor
  
  void SetRazon(std::string &_raz) { m_razon = _raz; };
  
  int m_codigo;
  std::string m_razon;
  
  void SetQuery() 
  {
    (*m_oss) << "INSERT INTO " << (this->m_name) << " VALUES ";
    (*m_oss) << (*this);
  }

protected:
  
private:
  
};

/** @class Deserciones Deserciones.h Simulador/Deserciones.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-05-21
 */
class Deserciones : public Dimension {
public: 
  /// Standard constructor
  Deserciones( ) : Dimension() { }; 

  Deserciones( const char * _name ) : Dimension( _name ) { }; 

  Deserciones( const char * , long int );
  
  virtual ~Deserciones( ); ///< Destructor
  
  std::vector<long int> m_fkeys;
  
  void AddFK( long int & );
  
  void SetQuery() 
  {
    (*m_oss) << "INSERT INTO " << (this->m_name) << " VALUES ";
    (*m_oss) << (*this);
  }
  
protected:
  
private:
  
};




#endif // SIMULADOR_TABLAS_H
