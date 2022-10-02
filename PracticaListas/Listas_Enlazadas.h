#include "Nodos.h"
#include <string>
#ifndef LISTAS_ENLAZADAS_H
#define LISTAS_ENLAZADAS_H
using namespace std;

class Listas_Enlazadas {
private:
  nodo *cabeza = NULL;
  int elemento_para_buscar;
  int opcion;

public:
  void Mostrar_Menu();
  void Elegir_Menu();
};

#endif