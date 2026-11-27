/*
 * Asignatura: Estructuras de Datos y Algoritmos (EDA)
 * Práctica 4: Programación de TAD genérico arborescente en C++
 *
 * Autores: Carla Burdaspar, Ivan Deza y Níobe Clavería
 * NIP: 895743, 837603, 869412
 */

#ifndef COLECCIONITF_HPP
#define COLECCIONITF_HPP

#include "fecha.hpp"
#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

// Pre-declaración del TAD genérico coleccionITF
// Los valores del TAD representan colecciones de datos T (ITF) con
// identificadores no repetidos.
// Se requiere que el género T tenga definidas las operaciones:
//   string identificador(const T &i);
//   string tema(const T &i);
//   Fecha fecha(const T &i);
template <typename T> struct coleccionITF;

// Inicializa c como una colección de ITF vacía, sin ítems.
template <typename T> void crear(coleccionITF<T> &c);

// Devuelve verdad si y sólo si c no contiene ningún ítem.
template <typename T> bool esVacia(const coleccionITF<T> &c);

// Devuelve el número de ítems que hay en la colección c.
template <typename T> int tamanyo(const coleccionITF<T> &c);

// Si en c no hay ningún ítem con identificador igual al de i, añade el ítem i
// a la colección c y devuelve true. En caso contrario, deja c igual y devuelve
// false.
template <typename T> bool anyadir(coleccionITF<T> &c, const T &i);

// Si en c no hay ningún ítem con identificador igual al de i, deja c igual.
// En caso contrario, sustituye en c el ítem con identificador igual al de i por
// i.
template <typename T> void actualizar(coleccionITF<T> &c, const T &i);

// Si en c hay algún ítem con identificador igual a ident, lo borra de c.
// En caso contrario, deja c igual.
template <typename T> void borrar(const string &ident, coleccionITF<T> &c);

// Devuelve verdad si y sólo si en c hay algún ítem con identificador igual a
// ident.
template <typename T> bool esta(const string &ident, const coleccionITF<T> &c);

// Si en c hay algún ítem con identificador igual a ident, devuelve dicho ítem.
// Parcial: la operación no está definida si en c no hay ningún ítem con
// identificador igual a ident.
template <typename T>
T obtenerITF(const string &ident, const coleccionITF<T> &c);

// Devuelve la cadena resultante de concatenar los identificadores de todos los
// ítems que hay en c con fecha estrictamente anterior a f, y separados entre sí
// por la cadena separador.
template <typename T>
string obsoletos(const Fecha &f, const string &separador,
                 const coleccionITF<T> &c);

// Elimina de c todos los ítems con fecha estrictamente anterior a f.
template <typename T> void purgar(const Fecha &f, coleccionITF<T> &c);

// Devuelve verdad si y sólo si en c hay algún ítem i cuyo tema es igual a t.
template <typename T>
bool existeTema(const string &t, const coleccionITF<T> &c);

// Devuelve la cadena resultante de concatenar los identificadores de todos los
// ítems que hay en c con tema igual a t, separados entre sí por la cadena
// separador.
template <typename T>
string delTema(const string &t, const string &separador,
               const coleccionITF<T> &c);

// Elimina de c todos los ítems i cuyo tema es igual a t.
template <typename T> void zanjarTema(const string &t, coleccionITF<T> &c);

// Las siguientes operaciones constituyen un iterador que permite visitar los
// elementos de la colección de forma que siempre se visiten antes los elementos
// con identificador anterior (lexicográficamente menor) a los que se visitarán
// más tarde:

// Inicializa el iterador para recorrer los ítems de la colección c, de forma
// que el siguiente ítem a visitar sea el que tiene el identificador
// (lexicográficamente) menor.
template <typename T> void iniciarIterador(coleccionITF<T> &c);

// Devuelve verdad si queda algún ítem por visitar con el iterador de la
// colección c, devuelve falso si ya se ha visitado el último ítem.
template <typename T> bool existeSiguiente(const coleccionITF<T> &c);

// Devuelve el siguiente ítem a visitar con el iterador de la colección c.
// Parcial: la operación no está definida si no quedan ítems por visitar
// (no existeSiguiente(c)).
template <typename T> T siguiente(const coleccionITF<T> &c);

// Prepara el iterador de la colección c para que se pueda visitar el siguiente
// ítem, entendiendo por siguiente aquel ítem con (lexicográficamente) menor
// identificador de los todavía no visitados.
// Parcial: la operación no está definida si no quedan ítems por visitar
// (no existeSiguiente(c)).
template <typename T> void avanza(coleccionITF<T> &c);

// Declaración del TAD genérico coleccionITF
template <typename T> struct coleccionITF {
  friend void crear<T>(coleccionITF<T> &c);
  friend bool esVacia<T>(const coleccionITF<T> &c);
  friend int tamanyo<T>(const coleccionITF<T> &c);
  friend bool anyadir<T>(coleccionITF<T> &c, const T &i);
  friend void actualizar<T>(coleccionITF<T> &c, const T &i);
  friend void borrar<T>(const string &ident, coleccionITF<T> &c);
  friend bool esta<T>(const string &ident, const coleccionITF<T> &c);
  friend T obtenerITF<T>(const string &ident, const coleccionITF<T> &c);
  friend string obsoletos<T>(const Fecha &f, const string &separador,
                             const coleccionITF<T> &c);
  friend void purgar<T>(const Fecha &f, coleccionITF<T> &c);
  friend bool existeTema<T>(const string &t, const coleccionITF<T> &c);
  friend string delTema<T>(const string &t, const string &separador,
                           const coleccionITF<T> &c);
  friend void zanjarTema<T>(const string &t, coleccionITF<T> &c);
  friend void iniciarIterador<T>(coleccionITF<T> &c);
  friend bool existeSiguiente<T>(const coleccionITF<T> &c);
  friend T siguiente<T>(const coleccionITF<T> &c);
  friend void avanza<T>(coleccionITF<T> &c);

private:
  // Representación en memoria dinámica mediante una lista simplemente enlazada
  // ordenada ascendentemente (de menor a mayor) según el identificador del
  // ítem, sin identificadores repetidos.
  struct Nodo {
    T dato;
    Nodo *pNext;
  };

  Nodo *primero;  // Puntero al primer nodo de la lista (nullptr si está vacía)
  Nodo *iterador; // Puntero al siguiente nodo a visitar por el iterador
  int total;      // Número total de ítems almacenados en la colección
};

// Implementación de las operaciones del TAD genérico coleccionITF

template <typename T> void crear(coleccionITF<T> &c) {
  c.primero = nullptr;
  c.iterador = nullptr;
  c.total = 0;
}

template <typename T> bool anyadir(coleccionITF<T> &c, const T &i) {
  string idNuevo = identificador(i);

  // Caso 1: La lista está vacía o el nuevo identificador es menor que el
  // primero
  if (c.primero == nullptr || identificador(c.primero->dato) > idNuevo) {
    typename coleccionITF<T>::Nodo *nuevoNodo =
        new typename coleccionITF<T>::Nodo;
    nuevoNodo->dato = i;
    nuevoNodo->pNext = c.primero;
    c.primero = nuevoNodo;
    c.total++;
    return true;
  }

  // Si el primero ya tiene el mismo identificador, no se inserta
  if (identificador(c.primero->dato) == idNuevo) {
    return false;
  }

  // Caso 2: Buscar posición ordenada en el resto de la lista
  typename coleccionITF<T>::Nodo *actual = c.primero;
  while (actual->pNext != nullptr &&
         identificador(actual->pNext->dato) < idNuevo) {
    actual = actual->pNext;
  }

  // Si ya existe un ítem con ese identificador, no se inserta
  if (actual->pNext != nullptr &&
      identificador(actual->pNext->dato) == idNuevo) {
    return false;
  }

  // Insertar el nuevo nodo en su posición ordenada
  typename coleccionITF<T>::Nodo *nuevoNodo =
      new typename coleccionITF<T>::Nodo;
  nuevoNodo->dato = i;
  nuevoNodo->pNext = actual->pNext;
  actual->pNext = nuevoNodo;
  c.total++;
  return true;
}

template <typename T> void actualizar(coleccionITF<T> &c, const T &i) {
  typename coleccionITF<T>::Nodo *act = c.primero;
  string idBuscado = identificador(i);

  // Avanzar mientras los identificadores sean estrictamente menores
  while (act != nullptr && identificador(act->dato) < idBuscado) {
    act = act->pNext;
  }

  // Sustituir el dato cuando se encuentra el identificador buscado
  if (act != nullptr && identificador(act->dato) == idBuscado) {
    act->dato = i;
  }
}

template <typename T> void borrar(const string &ident, coleccionITF<T> &c) {
  typename coleccionITF<T>::Nodo *act = c.primero;
  typename coleccionITF<T>::Nodo *ant = nullptr;

  // Buscamos el nodo conservando el anterior
  while (act != nullptr && identificador(act->dato) < ident) {
    ant = act;
    act = act->pNext;
  }

  if (act != nullptr && identificador(act->dato) == ident) {
    // Si es el primero de la lista
    if (ant == nullptr) {
      c.primero = act->pNext;
    } else { // Si está por medio o al final
      ant->pNext = act->pNext;
    }

    // Mantener válido el iterador si apuntaba al nodo eliminado
    if (c.iterador == act) {
      c.iterador = act->pNext;
    }
    delete act;
    c.total--;
  }
}

template <typename T> bool esta(const string &ident, const coleccionITF<T> &c) {
  // Ponemos el puntero en el primer nodo de la colección
  typename coleccionITF<T>::Nodo *act = c.primero;

  // Buscamos el identificador en la lista ordenada
  while (act != nullptr && identificador(act->dato) < ident) {
    act = act->pNext;
  }

  // Devolvemos true si encontramos el ítem
  return act != nullptr && identificador(act->dato) == ident;
}

template <typename T>
T obtenerITF(const string &ident, const coleccionITF<T> &c) {
  // Ponemos el puntero en el primer nodo de la colección
  typename coleccionITF<T>::Nodo *act = c.primero;

  // Buscamos el identificador en la lista ordenada
  while (act != nullptr && identificador(act->dato) < ident) {
    act = act->pNext;
  }

  // Devolvemos el ítem (precondición: existe un ítem con identificador ident)
  return act->dato;
}

template <typename T>
string obsoletos(const Fecha &f, const string &separador,
                 const coleccionITF<T> &c) {
  string resultado = "";
  bool esPrimero = true;
  typename coleccionITF<T>::Nodo *act = c.primero;

  // Recorremos la lista en orden lexicográfico de identificadores
  while (act != nullptr) {
    if (anterior(fecha(act->dato), f)) {
      if (!esPrimero) {
        resultado += separador;
      }
      resultado += identificador(act->dato);
      esPrimero = false;
    }
    act = act->pNext;
  }

  return resultado;
}

template <typename T> void purgar(const Fecha &f, coleccionITF<T> &c) {
  typename coleccionITF<T>::Nodo *act = c.primero;
  typename coleccionITF<T>::Nodo *ant = nullptr;

  while (act != nullptr) {
    if (anterior(fecha(act->dato), f)) {
      typename coleccionITF<T>::Nodo *aux = act;

      // Desenlazar el nodo manteniendo el enlace de cabecera o del anterior
      if (ant == nullptr) {
        c.primero = act->pNext;
      } else {
        ant->pNext = act->pNext;
      }

      // Si el iterador apuntaba al nodo borrado, avanzarlo al siguiente
      if (c.iterador == aux) {
        c.iterador = act->pNext;
      }

      act = act->pNext;
      c.total--;
      delete aux;
    } else {
      ant = act;
      act = act->pNext;
    }
  }
}

template <typename T> void zanjarTema(const string &t, coleccionITF<T> &c) {
  typename coleccionITF<T>::Nodo *act = c.primero;
  typename coleccionITF<T>::Nodo *ant = nullptr;

  while (act != nullptr) {
    if (tema(act->dato) == t) {
      typename coleccionITF<T>::Nodo *aux = act;

      // Desenlazar el nodo manteniendo el enlace de cabecera o del anterior
      if (ant == nullptr) {
        c.primero = act->pNext;
      } else {
        ant->pNext = act->pNext;
      }

      // Si el iterador apuntaba al nodo borrado, avanzarlo al siguiente
      if (c.iterador == aux) {
        c.iterador = act->pNext;
      }

      act = act->pNext;
      c.total--;
      delete aux;
    } else {
      ant = act;
      act = act->pNext;
    }
  }
}

template <typename T>
bool existeTema(const string &t, const coleccionITF<T> &c) {
  typename coleccionITF<T>::Nodo *act = c.primero;
  while (act != nullptr) {
    if (tema(act->dato) == t) {
      return true;
    }
    act = act->pNext;
  }
  return false;
}

template <typename T>
string delTema(const string &t, const string &separador,
               const coleccionITF<T> &c) {
  string resultado = "";
  bool esPrimero = true;
  typename coleccionITF<T>::Nodo *act = c.primero;

  // Recorremos la lista en orden lexicográfico de identificadores
  while (act != nullptr) {
    if (tema(act->dato) == t) {
      if (!esPrimero) {
        resultado += separador;
      }
      resultado += identificador(act->dato);
      esPrimero = false;
    }
    act = act->pNext;
  }

  return resultado;
}

template <typename T> bool esVacia(const coleccionITF<T> &c) {
  return c.total == 0;
}

template <typename T> int tamanyo(const coleccionITF<T> &c) { return c.total; }

// Operaciones del iterador de la colección (recorrido ordenado ascendente)
template <typename T> void iniciarIterador(coleccionITF<T> &c) {
  c.iterador = c.primero;
}

template <typename T> bool existeSiguiente(const coleccionITF<T> &c) {
  return c.iterador != nullptr;
}

template <typename T> T siguiente(const coleccionITF<T> &c) {
  return c.iterador->dato;
}

template <typename T> void avanza(coleccionITF<T> &c) {
  if (c.iterador != nullptr) {
    c.iterador = c.iterador->pNext;
  }
}

#endif
