// Implementación de la clase Cancion.
#include "Cancion.h"
#include <iostream>

// TODO 3.1: implementa el constructor de Cancion.
//   Llama al constructor de Pista desde la lista de inicialización.

Cancion::Cancion(const std::string& titulo, int min, int seg,
                 const std::string& artista, const std::string& genero)
    : Pista(titulo, min, seg), artista(artista), genero(genero) {}

// TODO 3.1: implementa getArtista() y getGenero().

std::string Cancion::getArtista() const { return artista; }
std::string Cancion::getGenero() const { return genero; } 

// TODO 3.1: implementa  void Cancion::mostrar() const
// Llama a mostrarInfo() y agrega artista y género.

void:: Cancion::mostrar() const {
    mostrarInfo();
    std::cout << " | Artista: " << artista << " | Genero: " << genero << std::endl;
}