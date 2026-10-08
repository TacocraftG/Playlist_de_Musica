// Interfaz de la clase Duracion.
// Guarda un tiempo en minutos y segundos, siempre en un estado válido.

#ifndef DURACION_H
#define DURACION_H

class Duracion {
private:
    int minutos;
    int segundos;

public:
    Duracion(int min, int seg);

    int getMinutos() const;
    int getSegundos() const;

    // TODO 1.2: declara  int totalSegundos() const;
    int totalSegundos() const;
    // TODO 1.3: declara  void imprimir() const;
    void imprimir() const;

    // Pregunta: ¿qué significa el const al final de estos métodos?
    // protege al objeto de cambios hechos por ese método.
};

#endif
