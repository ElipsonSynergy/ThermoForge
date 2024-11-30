#include "Btn.h"

Btn::Btn(int pinNumber, int btntype) : pin(pinNumber), type(btntype) {
    
    if (type == 1) {
        pinMode(pin, INPUT_PULLUP);
    } else if (type == 0) {
        pinMode(pin, INPUT);
    } 
}

/**
 * Obtiene el valor digital del boton.
 *
 * @return El valor digital del sensor Qtr (0 o 1).
 */
float Btn::value() {
    if (type == 1) {
        return digitalRead(pin);
    } else if (type == 0) {
        return analogRead(pin);
    } 
}
