#include <Arduino.h>
#include <max6675.h>
#include <pins.h>
#include "Pid.h"
#include "Btn.h"


//Comentarios
bool comments = true;


//PID
int _numSensors = 1; //cantidad de sensores usados
int sensorValues[1];

int reference = 255;
int sensibility = 140;
int attack_velocity = 0;

float Kp = 3, Ki = 0, Kd = 0;

Pid pid(Kp, Ki, Kd, 20, reference, _numSensors);

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

Btn enter(selectBtn, 1);
Btn menu(menuBtn, 1); 
Btn spin(spinBtn, 0);


/**
 * Muestra los valores de los sensores.
 */
void show_sensors() {
  Serial.print(" Max 6675 Temp (C): ");
  Serial.println(thermocouple.readCelsius());
}


/**
 * @brief Configura el entorno inicial del programa.
 * 
 * Esta función se ejecuta una vez al inicio del programa y se utiliza para configurar
 * los pines y los dispositivos necesarios.
 */
void setup() {
  // put your setup code here, to run once:
  if (comments == true) {
    Serial.begin(9600);
  }

  delay(500);

}


/**
 * @brief Función principal del programa que se ejecuta en un bucle infinito.
 * 
 */
void loop() {

  
   Serial.print("Select = "); 
   Serial.println(thermocouple.readCelsius());

   delay(1000);

}
