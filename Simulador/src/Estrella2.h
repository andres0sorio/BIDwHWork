// $Id: $
#ifndef ESTRELLA2_H 
#define ESTRELLA2_H 1

// Include files
#include "CargarTablas.h"

/** @class Estrella2 Estrella2.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-05-23
 */
class Estrella2 : public CargarTablas {
public: 
  /// Standard constructor
  Estrella2( ) : CargarTablas () { }; 

  Estrella2( const char * , int ); 
  
  virtual ~Estrella2( ); ///< Destructor
  
  virtual void LeerCargar();

  virtual void SetTablas();
  
  virtual void CleanTablas();


protected:

private:

  Notas * m_notas;
  
  Asignaturas * m_asignatura;
  
  TiempoNotas * m_tiempo;


};
#endif // ESTRELLA2_H
