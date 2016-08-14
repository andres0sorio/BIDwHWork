// $Id: $
#ifndef SIMULADOR_SIMMATRICULAS_H 
#define SIMULADOR_SIMMATRICULAS_H 1

// Include files
#include "Hechos.h"

/** @class SimMatriculas SimMatriculas.h Simulador/SimMatriculas.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-05-20
 */

class SimMatriculas : public Hechos {
public: 
  /// Standard constructor
  SimMatriculas( ) : Hechos() { }; 
  
  SimMatriculas( const char*, const char* , const char *); 
  
  virtual ~SimMatriculas( ); ///< Destructor
  
  void CrearMatriculas();
  
  void SelectAsesor( long int &, std::string&, std::string&, std::string&, int );
  
  void SelectCodigo( long int &, int );
  
  void SelectFacultad( long int &, long int &, std::string&, std::string&);
  
  void SelectEstatus( long int & , std::string& );

  void ReadInformacion();
  
    
protected:

private:

  Estudiante * m_estudiante;
  Facultad   * m_facultad;
  Programa   * m_programa;
  Asesor     * m_asesor;
  Estatus    * m_estatus;
  Tiempo     * m_tiempo;
  Matriculas * m_matricula;
  
  Data *m_data;
  
  std::vector<std::string> m_ests;
  
  std::vector<std::string> m_facs;
  
};
#endif // SIMULADOR_SIMMATRICULAS_H
