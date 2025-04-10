#include <iostream>
#include <vector>

using namespace std;

class Persona{
  private:
    string nombre;
    int rut;
  public:
    Persona(string nombre, int rut);
    ~Persona();
    string getNombre();
    void setNombre(string nombre);
    int getRut();
    void setRut(int rut);
};

class Estudiante : public Persona{
private:
  string carrera;
  float ppa;
public:
  Estudiante(string nombre, string carrera, int rut, float ppa); 
  Estudiante(string nombre, int rut);
  void aprender(string contenido);
  string getCarrera();
  void setCarrera(string carrera);
};

class Profesor : public Persona{
private:
  string asignatura;
public:
  Profesor(string nombre, string asignatura, int rut);
  Profesor(string nombre, int rut);
  ~Profesor();
  string getAsignatura();
  void setAsignatura(string asignatura);
  void ensenar(string contenido);
  virtual void ayudar(Estudiante* e);
  void cambiarCarrera(Estudiante* e, string carrera);
};


class DirectorCarrerra : public Profesor{
private:
  int presupuesto;
public:
  DirectorCarrerra(string nombre, string asignatura, int rut, int presupuesto);
  ~DirectorCarrerra();
  void entrevistarProfesor(Profesor* p);
  void ayudar(Estudiante* e);
};


class Curso{
private:
  int nrc;
  string nombre;
  Profesor* docente;
  vector<Estudiante*> estudiantes;
public:
  Curso(int nrc, string nombre, Profesor* docente);
  ~Curso();
  void inscribirEstudiante(Estudiante* estudiante);
  void comenzarImparticion();
  void mostrarListaEstudiantes();
};

class Carrera{
private:
  string nombre;
  DirectorCarrerra* director;
  vector<Curso*> cursos;
public:
  Carrera(string nombre, DirectorCarrerra* director);
  ~Carrera();
  void agregarCurso(Curso* curso);
  void iniciarCarrera();
};

