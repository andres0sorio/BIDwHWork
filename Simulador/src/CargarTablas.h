// $Id: $
#ifndef CARGARTABLAS_H 
#define CARGARTABLAS_H 1

// Include files
#include "Tablas.h"
#include <sstream>
#include "TSQLServer.h"
#include "TSQLResult.h"

/** @class CargarTablas CargarTablas.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-05-21
 */
class CargarTablas {
public: 
  /// Standard constructor
  CargarTablas( ); 

  CargarTablas( const char * );
  
  virtual ~CargarTablas( ); ///< Destructor

  virtual void LeerCargar() = 0;
  virtual void SetTablas() = 0;
  virtual void CleanTablas() = 0;
    
  std::ifstream *m_in;
  
  long int m_nrecords;

  long int m_nrecibo;

  std::ostringstream *m_oss[10];
  
  TSQLServer *m_db;
  
  TSQLResult *m_sqlres;

  std::vector<std::string> m_tables;

  int m_ntables;

  int m_mode;
    
protected:
  
private:
  
  
};
#endif // CARGARTABLAS_H
