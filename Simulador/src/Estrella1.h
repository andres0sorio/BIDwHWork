// $Id: $
#ifndef ESTRELLA1_H 
#define ESTRELLA1_H 1

// Include files
#include "CargarTablas.h"

/** @class Estrella1 Estrella1.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-05-21
 */
class Estrella1 : public CargarTablas {
public: 
  /// Standard constructor
  Estrella1() : CargarTablas() {}; 

  Estrella1( const char * , int );
  
  virtual ~Estrella1( ); ///< Destructor

  virtual void LeerCargar();

  virtual void SetTablas();
  
  virtual void CleanTablas();
    
protected:

private:

  Matriculas * m_matriculas;
  Estudiante * m_estudiante;
  Facultad   * m_facultad;
  Programa   * m_programa;
  Asesor     * m_asesor;
  Estatus    * m_estatus;
  Tiempo     * m_tiempo;
  
    
};
#endif // CARGARTABLAS_H
