/*
 * Asignatura: Estructuras de Datos y Algoritmos (EDA)
 * Práctica 4: Programación de TAD genérico arborescente en C++
 * 
 * Autores: Carla Burdaspar, Ivan Deza y Níobe Clavería
 * NIP: 895743, 837603, 869412
 */

#ifndef ANUNCIO_HPP
#define ANUNCIO_HPP

#include "fecha.hpp"
#include <iostream>
#include <string>

using namespace std;

// Interfaz del TAD Anuncio
// Los valores del TAD anuncio representan tuplas formadas como:
//   (identificador, título, descripción, categoría, publicación, finalización)
// siendo publicación y finalización fechas válidas del calendario gregoriano,
// y el resto cadenas de texto.

// Pre-declaración de la estructura
struct anuncio;

// Dados el identificador i, título t, descripción d, categoría c, fecha de
// publicación p y fecha de finalización f, construye en e el anuncio compuesto
// como (i, t, d, c, p, f).
void crearAnuncio(anuncio &e, const string &i, const string &t, const string &d,
                  const string &c, const Fecha &p, const Fecha &f);

// Dado un anuncio e formado como (I, T, D, C, P, F), devuelve I,
// i.e. el identificador del anuncio e.
string suIdentificador(const anuncio &e);

// Dado un anuncio e formado como (I, T, D, C, P, F), devuelve T,
// i.e. el título del anuncio e.
string suTitulo(const anuncio &e);

// Dada una cadena n y un anuncio e formado como (I, T, D, C, P, F),
// devuelve un anuncio igual al compuesto como (I, n, D, C, P, F).
anuncio cambiarTitulo(const anuncio &e, const string &n);

// Dado un anuncio e formado como (I, T, D, C, P, F), devuelve D,
// i.e. la descripción del anuncio e.
string suDescripcion(const anuncio &e);

// Dada una cadena n y un anuncio e formado como (I, T, D, C, P, F),
// devuelve un anuncio igual al compuesto como (I, T, n, C, P, F).
anuncio cambiarDescripcion(const anuncio &e, const string &n);

// Dado un anuncio e formado como (I, T, D, C, P, F), devuelve C,
// i.e. la categoría del anuncio e.
string suCategoria(const anuncio &e);

// Dado un anuncio e formado como (I, T, D, C, P, F) y una cadena n,
// devuelve un anuncio igual al compuesto como (I, T, D, n, P, F).
anuncio cambiarCategoria(const anuncio &e, const string &n);

// Dado un anuncio e formado como (I, T, D, C, P, F), devuelve P,
// i.e. la fecha de publicación de e.
Fecha suPublicacion(const anuncio &e);

// Dado un anuncio e formado como (I, T, D, C, P, F), devuelve F,
// i.e. la fecha de finalización de e.
Fecha suFinalizacion(const anuncio &e);

// Declaración de la estructura del TAD anuncio
struct anuncio {
  friend void crearAnuncio(anuncio &e, const string &i, const string &t,
                           const string &d, const string &c, const Fecha &p,
                           const Fecha &f);
  friend string suIdentificador(const anuncio &e);
  friend string suTitulo(const anuncio &e);
  friend anuncio cambiarTitulo(const anuncio &e, const string &n);
  friend string suDescripcion(const anuncio &e);
  friend anuncio cambiarDescripcion(const anuncio &e, const string &n);
  friend string suCategoria(const anuncio &e);
  friend anuncio cambiarCategoria(const anuncio &e, const string &n);
  friend Fecha suPublicacion(const anuncio &e);
  friend Fecha suFinalizacion(const anuncio &e);

private:
  // Representación de los valores del TAD anuncio:
  // tupla (identificador, título, descripción, categoría, publicación,
  // finalización)
  string identificador;
  string categoria;
  string titulo;
  string descripcion;
  Fecha publicacion;
  Fecha finalizacion;
};

#endif
