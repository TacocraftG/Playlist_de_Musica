#include <iostream>
#include <string>
#include <limits>

#include "Cancion.h"
#include "Podcast.h"
#include "Playlist.h"

// Función auxiliar para limpiar la entrada tras usar std::cin >>
void limpiarBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::string nombrePlaylist;
    std::cout << "=== CREACION DE PLAYLIST ===" << std::endl;
    std::cout << "Ingrese el nombre para la playlist: ";
    std::getline(std::cin, nombrePlaylist);

    Playlist miPlaylist(nombrePlaylist);

    int opcion = 0;
    do {
        std::cout << "\n========================================" << std::endl;
        std::cout << "         MENU DE PLAYLIST: " << nombrePlaylist << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "1. Agregar Cancion" << std::endl;
        std::cout << "2. Agregar Podcast" << std::endl;
        std::cout << "3. Mostrar Playlist completa" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Seleccione una opcion (1-4): ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cin.clear();
            limpiarBuffer();
            std::cout << "Opcion invalida. Intente de nuevo." << std::endl;
            continue;
        }

        limpiarBuffer();

        if (opcion == 1) {
            std::string titulo, artista, genero;
            int min, seg;

            std::cout << "\n--- AGREGAR CANCION ---" << std::endl;
            std::cout << "Titulo: ";
            std::getline(std::cin, titulo);
            std::cout << "Artista: ";
            std::getline(std::cin, artista);
            std::cout << "Genero: ";
            std::getline(std::cin, genero);
            std::cout << "Minutos: ";
            std::cin >> min;
            std::cout << "Segundos: ";
            std::cin >> seg;

            Cancion* nuevaCancion = new Cancion(titulo, min, seg, artista, genero);
            if (miPlaylist.agregarCancion(nuevaCancion)) {
                std::cout << "-> Cancion agregada exitosamente." << std::endl;
            } else {
                std::cout << "-> Error: La cancion ya existia o no es valida." << std::endl;
                delete nuevaCancion; // Liberar memoria si no se agregó
            }

        } else if (opcion == 2) {
            std::string titulo, anfitrion;
            int min, seg, episodio;

            std::cout << "\n--- AGREGAR PODCAST ---" << std::endl;
            std::cout << "Titulo: ";
            std::getline(std::cin, titulo);
            std::cout << "Anfitrion: ";
            std::getline(std::cin, anfitrion);
            std::cout << "Numero de Episodio: ";
            std::cin >> episodio;
            std::cout << "Minutos: ";
            std::cin >> min;
            std::cout << "Segundos: ";
            std::cin >> seg;

            Podcast* nuevoPodcast = new Podcast(titulo, min, seg, anfitrion, episodio);
            if (miPlaylist.agregarPodcast(nuevoPodcast)) {
                std::cout << "-> Podcast agregado exitosamente." << std::endl;
            } else {
                std::cout << "-> Error: El podcast ya existia o no es valido." << std::endl;
                delete nuevoPodcast; // Liberar memoria si no se agregó
            }

        } else if (opcion == 3) {
            std::cout << std::endl;
            miPlaylist.mostrar();

        } else if (opcion == 4) {
            std::cout << "Saliendo del programa..." << std::endl;
        } else {
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        }

    } while (opcion != 4);

    return 0;
}