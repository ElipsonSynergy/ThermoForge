#include "Pot.h"

Pot::Pot(int pinNumber, int maxOpciones) : pin(pinNumber), maxOpciones(maxOpciones) {

    pinMode(pin, INPUT);
}