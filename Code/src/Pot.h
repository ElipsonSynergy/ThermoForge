#ifndef Pot_H
#define Pot_H


#include <Arduino.h>

/**
 * @brief Clase que implementa un elemento de la interfaz BTTN.
 */

struct resultados {
    int lectura;     // Valor leído del sensor
    int option; // Resultado de la función map
};


class Pot {
    private:

    int pin;
    int maxOpciones;
    static const int NUM_MUESTRAS = 10;  // Número de muestras para promediar

    int leerPromediado() {
        long suma = 0;
        for (int i = 0; i < NUM_MUESTRAS; i++) {
            suma += analogRead(pin);  // Sumar las lecturas
            delay(5);  // Pequeño retraso entre las lecturas
        }
        return suma / NUM_MUESTRAS;  // Promedio de las lecturas
    }


    public:
    /**
     * @brief Constructor de la clase Pid.
     * 
     * @param pinNumber El número de pin al que está conectado el botón.
     */
    Pot(int pinNumber, int maxOpciones);

    /**
     * @brief Obtiene el valor del sensor botón.
     *
     * @return El valor del sensor botón.
     */

    resultados leerOpcion() {
        int lecturaPromediada = leerPromediado();  // Leer y promediar el valor del potenciómetro
        int option = map(lecturaPromediada, 0, 1023, 0, maxOpciones - 1);
        return {lecturaPromediada, option};
    }
};


#endif