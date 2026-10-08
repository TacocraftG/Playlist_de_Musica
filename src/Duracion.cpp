// Implementación de la clase Duracion.

#include "Duracion.h"

#include <iostream>

 // TODO 1.1: valida y normaliza.
    //   - Si min o seg son negativos, la duración queda en 0:00.
    //   - Si seg es mayor a 59, convierte el excedente en minutos
    //     (0 min 75 seg debe quedar como 1:15).
    // Pregunta: ¿por qué conviene validar aquí y no en main?
    /* De esa forma, cada objeto de tipo duración queda validado inmediatamente,
       evitando posibles futuros errores
    */

Duracion::Duracion(int min, int seg) : minutos(min), segundos(seg) 
{
    if (min < 0 || seg < 0)
    {
        minutos = 0;
        segundos = 0;
    }
    else
    {
        minutos = minutos + (segundos / 60);
        segundos = segundos % 60;
    }
}

//Getter para obtener los minutos de la pista
int Duracion::getMinutos() const { return minutos; }

//Gettter para obtener los segundos de la pista
int Duracion::getSegundos() const { return segundos; }

// TODO 1.2: implementa  int Duracion::totalSegundos() const
//   Devuelve la duración completa expresada en segundos.
int Duracion::totalSegundos() const {
    return minutos * 60 + segundos;
}

// TODO 1.3: implementa  void Duracion::imprimir() const
//   Imprime con el formato m:ss (por ejemplo 3:05, no 3:5).
void Duracion::imprimir() const {
    std::cout << minutos << ":";

    if (segundos < 10) {
        /*Imprimimos este 0 antes para 
        que se imprima por ejemplo 3:05 en vez de 3:5*/
        std::cout << "0";
    }

    std::cout << segundos;
}