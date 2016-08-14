// $Id: $
#ifndef OPERADORES_H 
#define OPERADORES_H 1

// Include files
#include <sstream>

class Estudiante;
class Programa;
class Facultad;
class Estatus;
class Tiempo;
class Asesor;
class Matriculas;
class Asignaturas;
class Notas;
class TiempoNotas;
class Deserciones;
class RazonDesercion;

std::ostringstream& operator<<(std::ostringstream &, Estudiante &);
std::ostream& operator<<(std::ostream &, Estudiante &);
std::istream& operator>>(std::istream &, Estudiante &);

std::ostream& operator<<(std::ostream &, Tiempo &);
std::ostringstream& operator<<(std::ostringstream &, Tiempo &);
std::istream& operator>>(std::istream &, Tiempo &);

std::ostream& operator<<(std::ostream &, Estatus &);
std::ostringstream& operator<<(std::ostringstream &, Estatus &);
std::istream& operator>>(std::istream &, Estatus &);

std::ostream& operator<<(std::ostream &, Asesor &);
std::ostringstream& operator<<(std::ostringstream &, Asesor &);
std::istream& operator>>(std::istream &, Asesor &);

std::ostream& operator<<(std::ostream &, Programa &);
std::ostringstream& operator<<(std::ostringstream &, Programa &);
std::istream& operator>>(std::istream &, Programa &);

std::ostream& operator<<(std::ostream &, Facultad &);
std::ostringstream& operator<<(std::ostringstream &, Facultad &);
std::istream& operator>>(std::istream &, Facultad &);

std::ostream& operator<<(std::ostream &, Asignaturas &);
std::ostringstream& operator<<(std::ostringstream &, Asignaturas &);
std::istream& operator>>(std::istream &, Asignaturas &);

std::ostream& operator<<(std::ostream &, TiempoNotas &);
std::ostringstream& operator<<(std::ostringstream &, TiempoNotas &);
std::istream& operator>>(std::istream &, TiempoNotas &);

std::ostream& operator<<(std::ostream &, Matriculas &);
std::ostringstream& operator<<(std::ostringstream &, Matriculas &);
std::istream& operator>>(std::istream &, Matriculas &);

std::ostream& operator<<(std::ostream &, Notas &);
std::ostringstream& operator<<(std::ostringstream &, Notas &);
std::istream& operator>>(std::istream &, Notas &);

std::ostream& operator<<(std::ostream &, Deserciones &);
std::ostringstream& operator<<(std::ostringstream &, Deserciones &);
std::istream& operator>>(std::istream &, Deserciones &);

std::ostream& operator<<(std::ostream &, RazonDesercion &);
std::ostringstream& operator<<(std::ostringstream &, RazonDesercion &);
std::istream& operator>>(std::istream &, RazonDesercion &);

#endif // OPERADORES_H
