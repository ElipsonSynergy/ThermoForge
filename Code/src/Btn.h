#ifndef BTN_H
#define BTN_H


#include <Arduino.h>

/**
 * @brief Clase que implementa un elemento de la interfaz BTTN.
 */
class Btn {
    private:

    int pin;
    int type;


    public:
    /**
     * @brief Constructor de la clase Pid.
     * 
     * @param pinNumber El número de pin al que está conectado el botón.
     */
    Btn(int pinNumber, int btntype);

    /**
     * @brief Obtiene el valor del sensor botón.
     *
     * @return El valor del sensor botón.
     */
    int DigitalValue();
    float value();
};


#endif