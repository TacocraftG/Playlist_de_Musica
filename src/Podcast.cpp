// Implementación de la clase Podcast.

#include "Podcast.h"
#include <iostream>

// TODO 3.2: implementa el constructor, los accedentes y mostrar() de Podcast.

Podcast::Podcast(const std::string& titulo, int min, int seg,
                 const std::string& anfitrion, int numeroEpisodio)
    : Pista(titulo, min, seg), anfitrion(anfitrion), numeroEpisodio(numeroEpisodio) {}

std::string Podcast::getAnfitrion() const { return anfitrion; }

int Podcast::getNumeroEpisodio() const { return numeroEpisodio; }

void Podcast::mostrar() const {
    mostrarInfo();
    std::cout << " | Anfitrion: " << anfitrion << " | Episodio: " << numeroEpisodio << std::endl;
}