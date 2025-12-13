# Animación de Logo en OLED SH1106 con ESP32-C3

Proyecto para mostrar y animar un logo personalizado en una pantalla OLED
128x64 basada en el controlador SH1106, utilizando un ESP32-C3 Super Mini
y la librería U8g2.

---

## 🧾 Lista de Materiales (BOM)

### 🔹 ESP32-C3 Super Mini
![ESP32-C3 Super Mini](assets/ESP32C3SuperMini.webp)

Microcontrolador principal del proyecto. Se encarga del control de la
pantalla OLED y la animación del logo.

---

### 🔹 Pantalla OLED 128x64 SH1106
![OLED SH1106](assets/oledsh1106.webp)

Pantalla monocromática I2C utilizada para mostrar el logo animado.

---

### 🔹 Protoboard
![Protoboard](assets/protoboard.webp)

Utilizada para el armado del circuito sin soldadura.

---

### 🔹 Regulador de voltaje 3.3V
![Regulador 3.3V](assets/regulador.webp)

Regulador balanceado para alimentar correctamente el ESP32 y la OLED.

---

### 🔹 Cables Dupont (Jumpers)
![Jumpers](assets/jumpers.webp)

Cables para realizar las conexiones entre los componentes.

---

## 🔌 Conexiones

| OLED SH1106 | ESP32-C3 |
|------------|----------|
| VCC        | 3.3V     |
| GND        | GND      |
| SDA        | GPIO X   |
| SCL        | GPIO Y   |

*(ver diagrama en la carpeta `/diagrams`)*

---

## 🖼️ Preparación del Logo

1. El logo se diseña en formato **PNG**
2. Se convierte a **BMP monocromático** usando Paint
3. Se usa la herramienta **image2cpp**
   - Resolución: 128x64
   - Formato: U8g2
4. El array generado se copia en el código `.ino`

---

## 📚 Librerías necesarias

- [U8g2](https://github.com/olikraus/u8g2)

Instalar desde el Administrador de Librerías del IDE de Arduino.

---

## 🚀 Funcionamiento

El programa inicializa la pantalla OLED y dibuja el logo almacenado en
memoria flash, permitiendo animaciones simples como:
- Desplazamiento
- Fade
- Frame por frame

---

## 📸 Resultado

*(agregar foto o gif del resultado final)*

---

## 📄 Licencia

Este proyecto es de uso libre para fines educativos.
