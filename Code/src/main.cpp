#include <Arduino.h>
#include <pins.h>

#include <max6675.h>

#include "imagenes.h"
#include "Screen.h"
#include "Pot.h"
#include "Btn.h"

#include "Pid.h"


MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

Screen screen(display);

Btn enter(selectBtn, 1); Btn menu(menuBtn, 1);  
Pot potenciometroMenu(spinBtn, cant+2); Pot potenciometroTemp(spinBtn, 401);


// Variables globales
const char *materiales[] = {"BYPACK", "PE", "PP", "ABS", "PVC", "PET", "PS", "PC"};
int temperaturas[] = {160, 140, 170, 185, 155, 240, 105, 175};
int cant = sizeof(materiales) / sizeof(materiales[0]);

//PID
int minTem = 1000; int maxTem= 2000;
int _numsensors = 1; float rateTime = 1;
Pid pid(minTem, maxTem, _numsensors, rateTime);

Btn zeroCross(zeroCrossing, 0);

bool zero_cross_detected() {
  return !zeroCross.value();
}

void control(float maximum_firing_delay, float setPoint) {

  float PID_value = pid.traking(thermocouple.readCelsius(), setPoint);

  int zero_cross = zero_cross_detected();
  
  if (zero_cross)  {
    delayMicroseconds(maximum_firing_delay - PID_value); //This delay controls the power
    digitalWrite(triac, HIGH);
    delayMicroseconds(100);
    digitalWrite(triac, LOW);
    zero_cross = false;
  }
}


// Variables Locales
int opcionActual = 999;
int tempActual = 0;
int tempRead;
bool seleccionMaterial = true;
resultados pot;
resultados pot2;
String text;

void setup() {
  
  Serial.begin(9600);
  screen.iniciar();
  screen.mostrarImagen(HOME);
  delay(5000);

  pinMode(triac, OUTPUT);

}

void loop() {

  while (enter.value() && opcionActual == 999) {
    // Leer opción del potenciómetro
    pot = potenciometroMenu.leerOpcion();

    if (pot.option < cant){   
        // Mostrar la opción en la screen
        screen.mostrarOpciones(String(temperaturas[pot.option]), String(materiales[pot.option]));
    }
    else {
        screen.mostrarOpciones(" T ", "Elegir");
    }
  }

  opcionActual = pot.option;

  if (opcionActual >= cant){
    delay(100);
    while (enter.value() && tempActual == 0) {
    // Leer opción del potenciómetro
    resultados pot2 = potenciometroTemp.leerOpcion();
    screen.progressBar(pot2.option, 400, "Temperatura");
    tempRead = pot2.option;
    }
    tempActual = tempRead;
  }
  else{
    tempActual = temperaturas[pot.option];
  }
  screen.mostrarTitulo("Termoformando a " + String(tempActual), "", 1, 2);

}
