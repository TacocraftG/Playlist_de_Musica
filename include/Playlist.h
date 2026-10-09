#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include "Pista.h"
#include "Duracion.h"

class Playlist {
private:
    std::string nombre;
    std::vector<Pista> pistas; // Slicing: almacena objetos Pista por valor

public:
    Playlist(const std::string& nombre);

    bool agregarPista(Pista pista); // Slicing: recibe por valor
    int cantidadPistas() const;
    Duracion duracionTotal() const;
    void mostrar() const;
};

#endif