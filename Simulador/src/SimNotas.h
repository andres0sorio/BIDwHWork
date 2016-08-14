// $Id: $
#ifndef SIMNOTAS_H 
#define SIMNOTAS_H 1

// Include files
#include "Hechos.h"

/** @class SimNotas SimNotas.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-05-23
 */
class SimNotas : public Hechos {
public: 
  /// Standard constructor
  SimNotas( ) : Hechos() { }; 
  
  SimNotas(const char *, const char*);
  
  virtual ~SimNotas( ); ///< Destructor
  
  void CrearNotas();
  
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

  Notas * m_notas;
  Asignaturas * m_asignatura;
  TiempoNotas * m_tiemponota;
  

};
#endif // SIMNOTAS_H
