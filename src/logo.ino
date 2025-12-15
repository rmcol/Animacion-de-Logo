/****************************************************
 *  LIBRERÍA Y CONFIGURACIÓN DE LA PANTALLA OLED
 ****************************************************/
#include <U8g2lib.h>

// Objeto para pantalla OLED 128x64 con controlador SH1106
// Comunicación I2C por software
// SDA -> pin 9
// SCL -> pin 8
U8G2_SH1106_128X64_NONAME_F_SW_I2C u8g2(
  U8G2_R0,        // Rotación normal
  9,              // Pin SDA
  8,              // Pin SCL
  U8X8_PIN_NONE   // Reset no usado
);


/****************************************************
 *  BITMAP DEL LOGO (64x64 píxeles)
 ****************************************************/
// Bitmap monocromático del logo
// PROGMEM = se guarda en memoria Flash para ahorrar RAM
const unsigned char epd_bitmap_Logo [] PROGMEM = {
  // 'Logo, 64x64px
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  // ...
  // (Datos binarios del bitmap)
  // ...
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


/****************************************************
 *  VARIABLES DE CONTROL DE ANIMACIÓN
 ****************************************************/
int frame = 0;                    // Frame actual de la animación
unsigned long lastUpdate = 0;     // Control del tiempo entre frames


/****************************************************
 *  SETUP
 ****************************************************/
void setup() {
  // Inicializa la pantalla OLED
  u8g2.begin();

  // Ajusta el contraste (0–255)
  // 255 = máximo brillo
  u8g2.setContrast(255);
}


/****************************************************
 *  LOOP PRINCIPAL
 ****************************************************/
void loop() {

  // Obtiene el tiempo actual en milisegundos
  unsigned long now = millis();

  // Controla la velocidad de la animación (150 ms)
  // Evita usar delay(), permitiendo código no bloqueante
  if (now - lastUpdate >= 150) {
    lastUpdate = now;

    // Limpia el buffer interno antes de dibujar
    u8g2.clearBuffer();

    // Posición base del logo
    // 128px (pantalla) - 64px (logo) = 64 / 2 = 32
    int base_x = 32;
    int base_y = 0;

    // Avanza al siguiente frame (0 a 7)
    frame = (frame + 1) % 8;


    /************************************************
     *  DIBUJO DE SOMBRA (EFECTO PROFUNDIDAD)
     ************************************************/
    // La sombra solo aparece en frames pares
    if (frame % 2 == 0) {

      // Color bajo para simular sombra
      u8g2.setDrawColor(32);

      // Dibuja el logo desplazado 1px
      // Solo se usan 56px de alto para evitar recorte inferior
      u8g2.drawXBM(
        base_x + 1,
        base_y + 1,
        64,          // Ancho del bitmap
        56,          // Alto del bitmap (recortado)
        epd_bitmap_Logo
      );

      // Restaura color normal (blanco)
      u8g2.setDrawColor(255);
    }


    /************************************************
     *  DIBUJO DEL LOGO PRINCIPAL (ANIMADO)
     ************************************************/
    // Pequeña variación en X (0 a 2 px)
    int anim_x = base_x + (frame % 3);

    // Pequeña variación en Y (0 a 1 px)
    int anim_y = base_y + ((frame / 3) % 2);

    // Dibuja el logo principal
    u8g2.drawXBM(
      anim_x,
      anim_y,
      64,          // Ancho
      56,          // Alto recortado
      epd_bitmap_Logo
    );


    /************************************************
     *  ENVÍO DEL BUFFER A LA PANTALLA
     ************************************************/
    // Muestra todo lo dibujado en la OLED
    u8g2.sendBuffer();
  }
}
