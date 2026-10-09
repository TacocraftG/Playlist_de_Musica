#include <iostream>

#include "Cancion.h"
#include "Duracion.h"
#include "Pista.h"
#include "Podcast.h"

int main() {
    std::cout << "--- PRUEBA CANCION Y PODCAST ---" << std::endl;
    Cancion c1("Bohemian Rhapsody", 5, 55, "Queen", "Rock");
    Podcast p1("Tecnologia Hoy", 45, 12, "Ana Gomez", 12);

    c1.mostrar();
    p1.mostrar();

    return 0;
}