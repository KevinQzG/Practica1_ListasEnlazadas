#include "Listas_Enlazadas.h"
using namespace std;
#include <iostream>

void Listas_Enlazadas::Mostrar_Menu() {
  cout << "\n ***** Menú de opciones *****" << endl;
  cout << "       ****************  \n" << endl;
  cout << "1. Insertar elemento a la lista" << endl;
  cout << "2. Mostrar elementos a la lista" << endl;
  cout << "3. Buscar elementos en la lista" << endl;
  cout << "4. Eliminar elemento de la lista" << endl;
  cout << "5. Promedio de los elementos pares de la lista" << endl;
  cout << "6. Promedio de los elementos impares de la lista" << endl;
  cout << "7. Mostrar el elemento menor de la lista" << endl;
  cout << "8. Mostrar el elemento mayor de la lista" << endl;
  cout << "9. Mostrar elementos repetidos en la lista" << endl;
  cout << "10. Eliminar elementos repetidos en la lista" << endl;
  cout << "11. Invertir la lista" << endl;
  cout << "12. Ordenar la lista de forma decreciente" << endl;
  cout << "13. Salir \n" << endl;
}

void Listas_Enlazadas::Elegir_Menu() {
  bool control = true;
  while (control) {
    cout << "Ingrese una opción del menú: ";
    cin >> opcion;
    if (opcion < 1 || opcion > 13) {
      cout << "Opción invalida, ingrese una opción del menú" << endl;
      continue;
    }
    switch (opcion) {
    case 1: {
      int new_Dato;
      bool control = true;
      string respuesta;
      while (control) {
        cout << "Ingrese un número para insertar en la lista: ";
        cin >> new_Dato;
        cout << "Desea insertar otro elemento? (s/n): " << endl;
        cin >> respuesta;
        if (respuesta == "s" || respuesta == "S") {
          Insertar_Nodo(cabeza, new_Dato);
        } else if (respuesta == "n" || respuesta == "N") {
          Insertar_Nodo(cabeza, new_Dato);
          control = false;
        } else {
          cout << "Opción invalida, ingrese una opción del menú" << endl;
        }
      }
    } break;

    case 2: {
      cout << "Mostrando elementos de la lista: " << endl;
      Mostrar_Nodos(cabeza);
      cout << "\n" << endl;

    } break;

    case 3: {
      string respuesta;
      cout << "Ingrese el elemento a buscar: ";
      cin >> elemento_para_buscar;
      Buscar_Nodos(cabeza, elemento_para_buscar);
      if (elemento_para_buscar == 0) {
        cout << "No hay elementos en la lista" << endl;
      } else if (elemento_para_buscar == 1) {
        cout << "El elemento se encuentra en la lista" << endl;
      }
      cout << "Desea buscar otro elemento? (s/n): " << endl;
      cin >> respuesta;
      if (respuesta == "s" || respuesta == "S") {
        cout << "Ingrese el elemento a buscar: ";
        cin >> elemento_para_buscar;
        Buscar_Nodos(cabeza, elemento_para_buscar);
      } else if (respuesta == "n" || respuesta == "N") {
        Elegir_Menu();
      } else {
        cout << "Opción invalida, ingrese una opción del menú" << endl;
      }
    } break;

    case 4: {
      string respuesta;
      int elemento_para_eliminar;
      cout << "Ingrese el elemento a eliminar: ";
      cin >> elemento_para_eliminar;
      Eliminar_Nodos(&cabeza, elemento_para_eliminar);
      if (elemento_para_eliminar == 0) {
        cout << "No hay elementos en la lista" << endl;
      } else if (elemento_para_eliminar == 1) {
        cout << "El elemento se ha eliminado de la lista" << endl;
      }
      while (control) {
        cout << "Desea eliminar otro elemento? (s/n): ";
        cin >> respuesta;
        if (respuesta == "s" || respuesta == "S") {
          cout << "Ingrese el elemento a eliminar: ";
          cin >> elemento_para_eliminar;
          Eliminar_Nodos(&cabeza, elemento_para_eliminar);
        } else if (respuesta == "n" || respuesta == "N") {
          Elegir_Menu();
        } else {
          cout << "Opción invalida, ingrese una opción del menú" << endl;
        }
      }
    }

    break;

    case 5: {
      {
        Promedio_Pares(cabeza);
      }
      break;
    }

    case 6: {
      Promedio_Impares(cabeza);
      break;
    }

    case 7: {
      Calcular_Menor(cabeza);
      break;
    }

    case 8: {
      Calcular_Mayor(cabeza);
      break;
    }

    case 9: {
      cout << "Los elementos repetidos son: " << endl;
      Nodos_Repetidos(cabeza);
    } break;

    case 10: {
      cout << "Los elementos repetidos han sido eliminados" << endl;
      Eliminar_Repetidos(cabeza);

    } break;

    case 11: {
      cout << "La lista ha sido invertida" << endl;
      Invertir_Lista(cabeza);
      cout << "\n" << endl;
    } break;

    case 12: {
      cout << "La lista ha sido ordenada de forma decreciente" << endl;
      Ordenar_Decreciente(cabeza);
      cout << "\n" << endl;
    } break;

    case 13: {
      cout << "Saliendo del programa... Creado por Kevin Quiroz" << endl;
      control = false;
    }
    }
  }
}
