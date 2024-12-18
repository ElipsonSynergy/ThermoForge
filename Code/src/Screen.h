#ifndef SCREN_H
#define SCREN_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Instancia Pantalla
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  // Reset pin (if not used, set to -1)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

/**
 * @brief Clase que implementa un controlador PID.
 */
class Screen {
    public:

        Screen(Adafruit_SSD1306 &oled);

        void iniciar();

        void mostrarImagen(const uint8_t* Imagen);
        

        void mostrarTitulo(String titulo, String titulo2 = "", int s1=1, int s2=1);

        void mostrarOpciones(String temp, String material);

        // Mostrar la barra de progreso
        void progressBar(int valor, int maxValor, String title);

    private:
        Adafruit_SSD1306 &oled;
};

#endif