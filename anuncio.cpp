/*
 * Asignatura: Estructuras de Datos y Algoritmos (EDA)
 * Práctica 4: Programación de TAD genérico arborescente en C++
 *
 * Autores: Carla Burdaspar, Ivan Deza y Níobe Clavería
 * NIP: 895743, 837603, 869412
 */

#include "anuncio.hpp"
#include <string>

// Implementación de las operaciones del TAD Anuncio

// Construye en e el anuncio con los valores indicados
void crearAnuncio(anuncio &e, const string &i, const string &t, const string &d,
                  const string &c, const Fecha &p, const Fecha &f) {
  e.identificador = i;
  e.titulo = t;
  e.descripcion = d;
  e.categoria = c;
  e.publicacion = p;
  e.finalizacion = f;
}

// Selectores del TAD Anuncio
string suIdentificador(const anuncio &e) { return e.identificador; }

string suTitulo(const anuncio &e) { return e.titulo; }

string suDescripcion(const anuncio &e) { return e.descripcion; }

string suCategoria(const anuncio &e) { return e.categoria; }

Fecha suPublicacion(const anuncio &e) { return e.publicacion; }

Fecha suFinalizacion(const anuncio &e) { return e.finalizacion; }

// Modificadores del TAD Anuncio (devuelven un nuevo anuncio sin alterar e)
anuncio cambiarTitulo(const anuncio &e, const string &n) {
  anuncio a = e;
  a.titulo = n;
  return a;
}

anuncio cambiarDescripcion(const anuncio &e, const string &n) {
  anuncio a = e;
  a.descripcion = n;
  return a;
}

anuncio cambiarCategoria(const anuncio &e, const string &n) {
  anuncio a = e;
  a.categoria = n;
  return a;
}
