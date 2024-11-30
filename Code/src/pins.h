#ifndef PINS_H
#define PINS_H

#include <Arduino.h>

/**
 * @brief Pines de conexión a ESP 32.
 *
 * Se definen los pines de las conexiones para los diferentes dispositivos.
 */
#define thermoDO  23
#define thermoCS  5
#define thermoCLK  18

#define selectBtn  2
#define menuBtn  15
#define spinBtn  4

#define SCL 22
#define SDA 21

//Instancia Pantalla
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  // Reset pin (if not used, set to -1)



#endif 