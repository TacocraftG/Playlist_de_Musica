#include "Playlist.h"
#include <iostream>

Playlist::Playlist(const std::string& nombre) : nombre(nombre) {}

bool Playlist::agregarPista(Pista pista) {
    // Al pasarse por valor y guardarse en std::vector<Pista>,
    // cualquier Cancion o Podcast pierde sus atributos derivados (Slicing)
    pistas.push_back(pista); // Agrega la pista sin importar si ya existe
    return true;
}

int Playlist::cantidadPistas() const {
    return pistas.size();
}

Duracion Playlist::duracionTotal() const {
    int totalSeg = 0;
    for (const Pista& p : pistas) {
        totalSeg += p.getDuracion().totalSegundos();
    }
    return Duracion(0, totalSeg);
}

void Playlist::mostrar() const {
    std::cout << "Playlist: " << nombre << std::endl;
    std::cout << "--------------------------------" << std::endl;
    for (const Pista& p : pistas) {
        p.mostrarInfo(); // Se llama a Pista::mostrarInfo(), perdiendo artista/anfitrión por slicing
        std::cout << std::endl;
    }
    std::cout << "Cantidad de pistas: " << cantidadPistas() << std::endl;
    std::cout << "Duracion total: ";
    duracionTotal().imprimir();
}