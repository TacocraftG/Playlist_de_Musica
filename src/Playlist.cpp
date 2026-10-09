// Implementación de la clase Playlist.

#include "Playlist.h"
#include <iostream>
#include <algorithm>

// TODO 4.1: implementa el constructor de Playlist.

// TODO 4.2: implementa  bool Playlist::agregarCancion(Cancion* cancion)
//   Devuelve false si el puntero es nullptr o si la canción ya está en la
//   playlist; en otro caso la agrega y devuelve true.

// TODO 4.3: implementa  bool Playlist::agregarPodcast(Podcast* podcast)
//   Mismas reglas que agregarCancion.

// TODO 4.4: implementa  int Playlist::cantidadPistas() const

// TODO 4.5: implementa  Duracion Playlist::duracionTotal() const
//   Suma los segundos de todas las pistas y devuelve una Duracion.

// TODO 4.6: implementa  void Playlist::mostrar() const
//   Imprime el nombre, cada pista, la cantidad de pistas y la duración total.

Playlist::Playlist(const std::string& nombre) : nombre(nombre) {}

bool Playlist::agregarCancion(Cancion* cancion) {
    if (cancion == nullptr) return false;

    for (Cancion* c : canciones) {
        if (c == cancion) return false;
    }

    canciones.push_back(cancion);
    return true;
}

bool Playlist::agregarPodcast(Podcast* podcast) {
    if (podcast == nullptr) return false;

    for (Podcast* p : podcasts) {
        if (p == podcast) return false;
    }

    podcasts.push_back(podcast);
    return true;
}

int Playlist::cantidadPistas() const {
    return canciones.size() + podcasts.size();
}

Duracion Playlist::duracionTotal() const {
    int totalSeg = 0;

    for (Cancion* c : canciones) {
        totalSeg += c->getDuracion().totalSegundos();
    }
    for (Podcast* p : podcasts) {
        totalSeg += p->getDuracion().totalSegundos();
    }

    return Duracion(0, totalSeg);
}

void Playlist::mostrar() const {
    std::cout << "Playlist: " << nombre << std::endl;
    std::cout << "--------------------------------" << std::endl;
    for (Cancion* c : canciones) {
        c->mostrar();
    }
    for (Podcast* p : podcasts) {
        p->mostrar();
    }
    std::cout << "Cantidad de pistas: " << cantidadPistas() << std::endl;
    std::cout << "Duracion total: ";
    duracionTotal().imprimir();
    std::cout << std::endl;
}