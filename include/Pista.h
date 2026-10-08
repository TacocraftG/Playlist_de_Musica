// Interfaz de la clase Pista (clase base).
// Datos comunes a cualquier cosa que se pueda reproducir.
// Relación: una Pista TIENE una Duracion (composición).

#ifndef PISTA_H
#define PISTA_H

#include <string>

#include "Duracion.h"

class Pista {
private:
    std::string titulo;
    Duracion duracion;

public:
    Pista(const std::string& titulo, int min, int seg);

    std::string getTitulo() const;
    Duracion getDuracion() const;

    // TODO 2.2: declara  void setTitulo(const std::string& nuevoTitulo);
    void setTitulo(const std::string& nuevoTitulo);

    // TODO 2.3: declara  void mostrarInfo() const;
    void mostrarInfo() const;
};

#endif
