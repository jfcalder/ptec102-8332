#include <iostream>
#include <vector>
#include "usist_clases.h"

using namespace std;

int main() { 

  Carrera* miCarrera = new Carrera("Ingenieria Civil Informatica", new DirectorCarrerra("Giannina", "Ingenieria", 12345678, 1000000));
 miCarrera->iniciarCarrera();
}
