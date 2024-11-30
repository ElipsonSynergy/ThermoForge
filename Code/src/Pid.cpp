#include "Pid.h"

Pid::Pid(float cminSat, float cmaxSat, int numSensors, float crateTime) : Kp(0), Ki(0), Kd(0), _numSensors(numSensors), maxSat(cmaxSat), minSat(cminSat), proportional (0), integral(0), derivative(0), proportional_past
(0), control_output(0), position(0), last_value(0), rateTime(crateTime) {

}

/**
 * Calcula el error del controlador PID basado en los valores de los sensores.
 *
 * @param sensorsValues Un arreglo de enteros que representa los valores de los sensores.
 * @return El valor del error calculado.
 */
int Pid::calculateError(int* sensorsValues) {

    long avg = 0;
    long sum = 0;
    int on_line = 0;

    for (int i = 0;i < _numSensors;i++) {
        int value = sensorsValues[i];
        if (value > 0) {
            on_line = 1;
        }
        avg += (long)(value) * (i * 10);
        sum += value;
    }
    if (!on_line) {
        if (last_value < 1) {
            return 0;
        }
        else {
            return (_numSensors - 1) * 10;
        }
    }
    last_value = avg / sum;
    return last_value;
}

/**
 * Calcula la salida de control del controlador PID para seguir una posición objetivo.
 *
 * @param sensors La posición actual del sistema.
 * @return La salida de control calculada por el controlador PID.
 */
float Pid::traking(int sensors, int setpoint) {

    position = sensors;

    proportional  = setPoint - (position);
    integral = integral + proportional_past;
    derivative = (proportional  - proportional_past) / rateTime;

    float ITerm = integral * Ki;
    ITerm = constrain(ITerm, minSat, maxSat);

    control_output = (proportional  * Kp) + (derivative * Kd) + ITerm;

    // Saturador del la salida del controlador
    control_output = constrain(control_output, minSat, maxSat);

    proportional_past = proportional;

    return control_output;
}


/**
 * @brief Método de sintonización basado en Ziegler-Nichols para controladores P, PI, PID ideal y PID serie.
 * 
 * @param Kp Ganancia proporcional del sistema.
 * @param T Constante de tiempo del sistema.
 * @param L Tiempo muerto del sistema.
 * @param method Método de sintonización basado en Ziegler-Nichols:
 *               - 1: Controlador P
 *               - 2: Controlador PI
 *               - 3: Controlador PID ideal
 *               - 4: Controlador PID serie
 * 
 * @return float* Array estático con los coeficientes de sintonización en el siguiente orden:
 *                 - results[0]: Ganancia del controlador (Kc).
 *                 - results[1]: Tiempo derivativo (Td).
 *                 - results[2]: Tiempo integral (Ti).
 */


float* Pid::tuning(float Kp, float T, float L, int method) {

    static float results[3];

    float Kc = 0;
    float Ti = 0;
    float Td = 0;

    switch (method)
    {
    case 1:

        Kc = T / (L*Kp);
        Td = 0;
        Ti = 0;
        
        break;

    case 2:

        Kc = (0.9*T) / (L*Kp);
        Td = 3.33 * L;
        Ti = 0;
        
        break;

    case 3:

        Kc = 1.2*T / (L*Kp);
        Td = 2 * L;
        Ti = 0.5 * L;
        
        break;

    case 4:

        Kc = 0.6*T / (L*Kp);
        Td = L;
        Ti = L;
        
        break;
    
    default:
        break;
    }

    results[0] = Kc;  
    results[1] = Td;   
    results[2] = Ti; 
    return results;

}