// $Id: $
#ifndef HECHOS_H 
#define HECHOS_H 1

// Include files
#include "CommonIncludes.h"
#include "TRandom3.h"
#include "Data.h"
#include "Tablas.h"

/** @class Hechos Hechos.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-05-22
 */
class Hechos {
public: 
  /// Standard constructor
  Hechos( ) { }; 

  Hechos( const char* , const char * );
  
  virtual ~Hechos( ); ///< Destructor

  std::ifstream *m_in;
  
  std::ofstream *m_out;
  
  TRandom3 *m_rnd[10];

protected:

private:

};
#endif // HECHOS_H
