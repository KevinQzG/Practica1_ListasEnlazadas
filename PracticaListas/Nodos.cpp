#include "Nodos.h"
#include <iostream>
using namespace std;

void Insertar_Nodo(nodo *&cabeza, int dato) {
  {
    nodo *newnodo = new nodo;
    newnodo->dato = dato;
    newnodo->siguiente = NULL;

    if (cabeza == NULL) {
      cabeza = newnodo;
    } else {
      nodo *ultimo = cabeza;
      while (ultimo->siguiente != NULL)
        ultimo = ultimo->siguiente;
      ultimo->siguiente = newnodo;
    }
  }
}

void Mostrar_Nodos(nodo *cabeza) {
  nodo *actual = new nodo;
  actual = cabeza;
  while (actual != NULL) {
    cout << actual->dato << " -> ";
    actual = actual->siguiente;
  }
  if (cabeza == NULL) {
    cout << "No hay elementos en la lista";
  }
}

void Buscar_Nodos(nodo *cabeza, int numero) {
  nodo *actual = new nodo;
  actual = cabeza;
  int contador = 0;
  while (actual != NULL) {
    if (actual->dato == numero) {
      contador++;
    }
    actual = actual->siguiente;
  }
  if (contador == 0) {
    cout << "El elementos no se encuentra en la lista \n" << endl;
  } else {
    cout << "El elemento se encuentra en la lista \n" << endl;
  }
}

void Eliminar_Nodos(nodo **cabeza_referencia, int numero) {
  nodo *actual = new nodo;
  nodo *anterior = new nodo;
  actual = *cabeza_referencia;
  while (actual != NULL && actual->dato != numero) {
    anterior = actual;
    actual = actual->siguiente;
  }
  if (actual == NULL) {
    cout << "El numero " << numero << " no ha sido encontrado" << endl;
  } else if (actual == *cabeza_referencia) {
    *cabeza_referencia = actual->siguiente;
    delete actual;
    cout << "El numero " << numero << " ha sido eliminado" << endl;
  } else {
    anterior->siguiente = actual->siguiente;
    delete actual;
    cout << "El numero " << numero << " ha sido eliminado" << endl;
  }
}

void Promedio_Impares(nodo *cabeza) {
  nodo *actual = new nodo;
  actual = cabeza;
  double suma = 0;
  double contador = 0;
  while (actual != NULL) {
    if (actual->dato % 2 != 0) {
      suma = suma + actual->dato;
      contador++;
    }
    actual = actual->siguiente;
  }
  if (contador == 0) {
    cout << "No hay numeros impares en la lista" << endl;
  } else {
    cout << "La suma promedio de los numeros impares es: " << suma / contador
         << endl;
  }
}

void Promedio_Pares(nodo *cabeza) {
  nodo *actual = new nodo;
  actual = cabeza;
  double suma = 0;
  double contador = 0;
  while (actual != NULL) {
    if (actual->dato % 2 == 0) {
      suma = suma + actual->dato;
      contador++;
    }
    actual = actual->siguiente;
  }
  if (contador == 0) {
    cout << "No hay numeros pares en la lista" << endl;
  } else {
    cout << "La suma promedio de los numeros pares es: " << suma / contador
         << endl;
  }
}

void Calcular_Mayor(nodo *cabeza) {
  nodo *actual = new nodo;
  actual = cabeza;
  int mayor = 0;
  while (actual != NULL) {
    if (actual->dato > mayor) {
      mayor = actual->dato;
    }
    actual = actual->siguiente;
  }
  cout << "El numero mayor de la lista es: \n" << mayor << endl;
}

void Calcular_Menor(nodo *cabeza) {
  nodo *actual = new nodo;
  actual = cabeza;
  int menor = actual->dato;
  while (actual != NULL) {
    if (actual->dato < menor) {
      menor = actual->dato;
    }
    actual = actual->siguiente;
  }
  cout << "El numero menor de la lista es: \n" << menor << endl;
}

void Nodos_Repetidos(nodo *cabeza) {
    for (nodo *i = cabeza; i != NULL; i = i->siguiente) {
        int contador = 0;
        for (nodo *j = cabeza; j != NULL; j = j->siguiente) {
            if (i->dato == j->dato) {
                contador++;
            }
        }
        if (contador > 1) {
            cout << "El elemento " << i->dato << " se repite " << contador << " veces\n" << endl;
        } else {
            cout << "No se repiten elementos en esta lista\n" << endl;
        }
    }
}

void Eliminar_Repetidos(nodo *&lista) {
    nodo *actual = lista;
    while(actual != NULL) {
        nodo *siguiente = actual->siguiente;
        while(siguiente != NULL && siguiente->dato == actual->dato) {
            nodo *aux = siguiente;
            siguiente = siguiente->siguiente;
            delete aux;
        }
        actual->siguiente = siguiente;
        actual = siguiente;
    }
}

void Invertir_Lista(nodo *cabeza) {
  nodo *actual = new nodo;
  actual = cabeza;
  nodo *anterior = NULL;
  nodo *siguiente = NULL;
  while (actual != NULL) {
    siguiente = actual->siguiente;
    actual->siguiente = anterior;
    anterior = actual;
    actual = siguiente;
  }
  cabeza = anterior;
  Mostrar_Nodos(cabeza);
}

void Ordenar_Decreciente(nodo *cabeza) {
  nodo *actual = new nodo;
  actual = cabeza;
  nodo *siguiente = new nodo;
  siguiente = actual->siguiente;
  int aux;
  while (actual != NULL) {
    while (siguiente != NULL) {
      if (actual->dato < siguiente->dato) {
        aux = actual->dato;
        actual->dato = siguiente->dato;
        siguiente->dato = aux;
      }
      siguiente = siguiente->siguiente;
    }
    actual = actual->siguiente;
    siguiente = actual->siguiente;
  }
  Mostrar_Nodos(cabeza);
}
