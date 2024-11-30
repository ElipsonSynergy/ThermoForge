#include "Screen.h"

Screen::Screen(Adafruit_SSD1306 &oled): oled(oled) {}

void Screen::iniciar() {
    if (!oled.begin(SSD1306_PAGEADDR, 0x3C)) {
        Serial.println(F("No se pudo inicializar la pantalla!"));
        for (;;);
    }
    oled.clearDisplay();
    oled.display();
}

void Screen::mostrarImagen(const uint8_t* Imagen){
    oled.clearDisplay();
    oled.drawBitmap(0, 0, Imagen, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
    oled.display();
}

void Screen::mostrarTitulo(String titulo, String titulo2 = "", int s1=1, int s2=1) {
    oled.clearDisplay();
    oled.setTextSize(s1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(10, 10);
    oled.println(titulo);
    oled.setTextSize(s2);
    oled.setCursor(10, 30);
    oled.println(titulo2);
    oled.display();
}

void Screen::mostrarOpciones(String temp, String material) {
    oled.clearDisplay();
    oled.setTextSize(2);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(30, 15);
    oled.println(material);
    oled.setCursor(30, 35);
    oled.println(temp);
    oled.drawCircle(78, 38, 3, SSD1306_WHITE);
    oled.setCursor(75,35);
    oled.print(" C");
    oled.display();
}



 void Screen::progressBar(int valor, int maxValor, String title) {
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor((SCREEN_WIDTH/2)-30, 5);
    oled.println(title);
    // Dimensiones de la barra
    int barraAnchoMax = SCREEN_WIDTH - 20;  // Ancho máximo de la barra (con márgenes)
    int barraAltura = 10;                  // Altura de la barra
    int barraX = 10;                       // Posición X de la barra
    int barraY = (SCREEN_HEIGHT / 2) - 10;        // Posición Y (centrado verticalmente)
    // Calcular el ancho actual de la barra
    int barraAncho = map(valor, 0, maxValor, 0, barraAnchoMax);
    // Dibujar el contorno de la barra
    oled.drawRect(barraX, barraY, barraAnchoMax, barraAltura, SSD1306_WHITE);
    // Dibujar el progreso
    oled.fillRect(barraX, barraY, barraAncho, barraAltura, SSD1306_WHITE);
    // Mostrar en la pantalla
    oled.setCursor((SCREEN_WIDTH/2 - 10), SCREEN_HEIGHT - 20);
    oled.setTextSize(2);
    oled.println(valor);
    oled.display();
}