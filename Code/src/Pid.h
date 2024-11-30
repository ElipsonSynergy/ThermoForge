#ifndef PID_H
#define PID_H

#include <Arduino.h>

/**
 * @brief Clase que implementa un controlador PID.
 */
class Pid {
    private:

    
    int _numSensors;
    float setPoint;
    float maxSat;
    float minSat;
    float position;
    float proportional ;
    float integral;
    float derivative;
    int proportional_past;
    float control_output;
    float last_value;
    float rateTime;


    public:

    float Kp;
    float Ki;
    float Kd;

    
    /**
     * @brief Constructor de la clase Pid.
     * @param cKp Valor del coeficiente proportional .
     * @param cKi Valor del coeficiente integral.
     * @param cKd Valor del coeficiente derivative.
     * @param cSetPoint Valor del punto de consigna.
     * @param Vreference Valor de referencia.
     * @param numSensors Número de sensores.
     */
    Pid(float cminSat, float cmaxSat, int numSensors, float crateTime);

    /**
     * @brief Método para realizar el seguimiento de la posición.
     * @param position Posición actual.
     * @return Valor de salida del controlador. 
     */
    float traking(int position, int setPoint);

    /**
     * @brief Método para calcular el error.
     * @param sensors_values Valores de los sensores.
     * @return Valor del error calculado.
     */
    int calculateError(int* sensors_values);

    float* tuning(float Kp, float T, float L, int method);

};

#endif