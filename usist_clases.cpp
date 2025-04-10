#include <iostream>
#include <vector>
#include "usist_clases.h"


Persona::Persona(string nombre, int rut){
  this->nombre = nombre;
  this->rut = rut;                       
}

Persona::~Persona(){
  cout << "destruyendo" << endl;                   
}

string Persona::getNombre(){
   return this->nombre;      
}

void Persona::setNombre(string nombre){
   this->nombre = nombre;      
}


int Persona::getRut(){
   return this->rut;      
}

void Persona::setRut(int rut){
   this->rut = rut;      
}

Profesor::Profesor(string nombre, string asignatura, int rut) : Persona(nombre, rut){
  if(asignatura != "ingles"){
    this->asignatura = asignatura;
  }
  else{
    this->asignatura = "No tiene asignatura";
  }
}

Profesor::Profesor(string nombre, int rut) : Persona(nombre,rut){
  this->asignatura = "No tiene asignatura";
}

Profesor::~Profesor(){
  cout << "Destruyendo objeto de tipo Profesor" << endl;
}


string Profesor::getAsignatura(){
  return this->asignatura;
}
void Profesor::setAsignatura(string asignatura){
  if(asignatura != "ingles"){
    this->asignatura = asignatura;
  }
}

void Profesor::ensenar(string contenido){
  cout << "El profesor " << this->getNombre() << " esta enseñando " << contenido << endl;
}

void Profesor::ayudar(Estudiante* e){
  cout << "El profesor " << this->getNombre() << " esta ayudando al estudiante " << e->getNombre() << " en aspectos docentes / pedagógicos"<< endl;
}

void Profesor::cambiarCarrera(Estudiante* e, string carrera){
  if(carrera != "antropologia"){
      e->setCarrera(carrera);
  }
}



Estudiante::Estudiante(string nombre, string carrera, int rut, float ppa) : Persona(nombre,rut){
  this->carrera = carrera;
  this->ppa = ppa;
}

Estudiante::Estudiante(string nombre, int rut) : Persona(nombre,rut){
  this->carrera = "No tiene carrera";
  this->ppa = 1.0;
}

string Estudiante::getCarrera(){
  return this->carrera;
}

void Estudiante::setCarrera(string carrera){
  this->carrera = carrera;
}


void Estudiante::aprender(string contenido){
  cout << "El estudiante " << this->getNombre() << " esta aprendiendo " << contenido << endl;
}

DirectorCarrerra::DirectorCarrerra(string nombre, string asignatura, int rut, int presupuesto) : Profesor(nombre, asignatura, rut){
  this->presupuesto = presupuesto;
}

DirectorCarrerra::~DirectorCarrerra(){
  cout << "Destruyendo objeto de tipo DirectorCarrera" << endl;
}

void DirectorCarrerra::entrevistarProfesor(Profesor* p){
  cout << "El director " << this->getNombre() << " esta entrevistando al profesor " << p->getNombre() << endl;
}

void DirectorCarrerra::ayudar(Estudiante* e){
  cout << "El director " << this->getNombre() << " esta ayudando al estudiante " << e->getNombre() << " en aspectos académicos / administrativos"<< endl;
}

Curso::Curso(int nrc, string nombre, Profesor* docente){
  this->nrc = nrc;
  this->nombre = nombre;
  this->docente = docente;
}

Curso::~Curso(){
  cout << "Destruyendo objeto de tipo Curso" << endl;
}

void Curso::comenzarImparticion(){
  cout << "Empezando curso de " << this->nombre << endl;
}

void Curso::inscribirEstudiante(Estudiante* estudiante){
  this->estudiantes.push_back(estudiante);
}

void Curso::mostrarListaEstudiantes(){
  cout << "Estudiantes inscritos curso " << this->nombre << " - Profesor " << this->docente->getNombre() << endl;
  for(int i = 0; i < this->estudiantes.size(); i++){
    cout << this->estudiantes[i]->getNombre() << endl;
  }
}

Carrera::Carrera(string nombre, DirectorCarrerra* director){
  this->nombre = nombre;
  this->director = director;
}

Carrera::~Carrera(){
  for(int i = 0; i < cursos.size(); i++){
    delete this->cursos[i];
  }
}

void Carrera::agregarCurso(Curso* curso){
  this->cursos.push_back(curso);
}

void Carrera::iniciarCarrera(){
  cout << "Iniciando carrera " << this->nombre << endl;
  Profesor* p1 = new Profesor("Juan Pedro", "Matematicas", 123456);
  Profesor* p2 = new Profesor("Pedro", 654321);
  //Profesor* p3 = new Profesor("Lorena", "matemática", 654876);
  Estudiante* e1 = new Estudiante("Lorena",5636);
  Estudiante* e2 = new Estudiante("Juan Luis",65365365);

  Curso* curso1 = new Curso(101, "Matematicas", p1);
  curso1->inscribirEstudiante(e1);
  curso1->inscribirEstudiante(e2);
  curso1->comenzarImparticion();
  curso1->mostrarListaEstudiantes();

  Curso* curso2 = new Curso(102, "Lenguaje", p2);
  curso2->inscribirEstudiante(e1);
  curso2->mostrarListaEstudiantes();

  p1->ayudar(e2);
  p2->ayudar(e1);
  p1->cambiarCarrera(e1, "Ingenieria");
  p1->cambiarCarrera(e2, "antropologia");
  cout << e1->getCarrera() << endl;
  cout << e2->getCarrera() << endl;

  DirectorCarrerra* d1 = new DirectorCarrerra("Carlos", "Matematicas", 123456, 1000000);  
  d1->entrevistarProfesor(p1);
  d1->ensenar("Sumas");
  d1->ayudar(e1);
  p1->ayudar(e1);

  cout << "----------------------------------------" << endl;
  vector<Profesor*> profesores;

  profesores.push_back(new Profesor("Fabiola", "Matematicas", 123456));
  profesores.push_back(new Profesor("Gabriel", 654321));
  profesores.push_back(new Profesor("Javiera", "termodinámica", 654876));
  profesores.push_back(new DirectorCarrerra("Felipe", "Ing. Aeroespacial", 123456, 1000000));
  profesores.push_back(new DirectorCarrerra("Jorge", "Ing. Civil", 123456, 1000000));

  for(int i = 0; i < profesores.size(); i++){
    profesores[i]->ayudar(e2);
  }
}