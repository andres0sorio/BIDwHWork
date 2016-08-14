// $Id: $
#ifndef ESTRELLA3_H 
#define ESTRELLA3_H 1

// Include files
#include "CargarTablas.h"

/** @class Estrella3 Estrella3.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-05-23
 */
class Estrella3 : public CargarTablas {
public: 
  /// Standard constructor
  Estrella3( ) : CargarTablas () { }; 

  Estrella3( const char * , int ); 
  
  virtual ~Estrella3( ); ///< Destructor
  
  virtual void LeerCargar();

  virtual void SetTablas();
  
  virtual void CleanTablas();


protected:

private:

  Deserciones * m_deserciones;
  
  RazonDesercion * m_razon;
  
};
#endif // ESTRELLA2_H
