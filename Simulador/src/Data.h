// $Id: $
#ifndef DATA_H 
#define DATA_H 1

// Include files
#include "CommonIncludes.h"

/** @class Data Data.h 3.7/Data.h
 *  
 *
 *  @author Andres Osorio
 *  @date   2008-04-29
 */
class Data {
public: 
  /// Standard constructor
  Data( ) { }; 
  Data(const char*);
  
  virtual ~Data( ); ///< Destructor
  
  int  next();
  
  void rewind() { 
    m_in->clear();
    m_in->seekg(0,ios::beg); 
  }
  
  void showfirst();
  
  std::string X1() { return m_x1;};
  std::string X2() { return m_x2;};
  std::string X3() { return m_x3;};
  std::string X4() { return m_x4;};
  long int    X5() { return m_x5;};
  long int    X6() { return m_x6;};
    
protected:
  
private:
  
  std::ifstream * m_in;
  
  std::string m_x1;
  std::string m_x2;
  std::string m_x3;
  std::string m_x4;
  
  long int m_x5;
  long int m_x6;
  
};
#endif // DATA_H
