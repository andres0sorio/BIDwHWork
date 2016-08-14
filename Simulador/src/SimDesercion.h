// $Id: $
#ifndef SIMDESERCION_H 
#define SIMDESERCION_H 1

// Include files
#include "Hechos.h"

/** @class SimDesercion SimDesercion.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-05-23
 */
class SimDesercion : public Hechos {
  
public: 
  /// Standard constructor
  SimDesercion( ) : Hechos() {}; 
  
  SimDesercion(const char *, const char*); 
  
  virtual ~SimDesercion( ); ///< Destructor
  
  void CrearDeserciones();
  
  void SetTablas();
  
  void CleanTablas();
  
protected:

private:
  
  Matriculas * m_matriculas;
  Estudiante * m_estudiante;
  Facultad   * m_facultad;
  Programa   * m_programa;
  Asesor     * m_asesor;
  Estatus    * m_estatus;
  Tiempo     * m_tiempo;
  
  Deserciones        * m_desercion;
  RazonDesercion     * m_razon;
  
};
#endif // SIMDESERCION_H
