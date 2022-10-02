#ifndef NODOS_H
#define NODOS_H

struct nodo {
  int dato;
  nodo *siguiente;
};

void Insertar_Nodo(nodo *&cabeza, int dato);
void Mostrar_Nodos(nodo *cabeza);
void Buscar_Nodos(nodo *cabeza, int numero);
void Eliminar_Nodos(nodo **cabeza_referencia, int numero);
void Promedio_Impares(nodo *cabeza);
void Promedio_Pares(nodo *cabeza);
void Calcular_Mayor(nodo *cabeza);
void Calcular_Menor(nodo *cabeza);
void Nodos_Repetidos(nodo *cabeza);
void Eliminar_Repetidos(nodo *&lista);
void Invertir_Lista(nodo *cabeza);
void Ordenar_Decreciente(nodo *cabeza);

#endif