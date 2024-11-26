#include "Btn.h"

Btn::Btn(int pinNumber, int btntype) : pin(pinNumber), type(btntype) {
    pinMode(pin, INPUT);
}

/**
 * Obtiene el valor digital del boton.
 *
 * @return El valor digital del sensor Qtr (0 o 1).
 */
int Btn::DigitalValue() {
    if (type == 1) {
        int value = digitalRead(pin);
        return value;
    } 
}

float Btn::value() {
    if (type == 0) {
        int analogReading = analogRead(pin);
        return analogReading;
    }  
}