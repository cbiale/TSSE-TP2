/************************************************************************************************
MIT License

Copyright (c) 2024 Claudio Omar Biale

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*************************************************************************************************/

/** @file leds.c
 ** @brief Declaraciones de la biblioteca para el control de LEDs.
 **/

/* === Headers files inclusions =============================================================== */

#include "leds.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

//! Puntero a la dirección de memoria de los LEDs.
static uint16_t * port_address;

/* === Private function declarations =========================================================== */

/**
 * @brief Convierte un número de LED a una máscara de bits.
 * 
 * @param led Número de LED.
 * 
 * @return Máscara de bits a utilizar.
 */
static uint16_t LedToMask (uint8_t led);

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

static uint16_t LedToMask (uint8_t led) {
    return (1 << (led - 1));
}
/* === Public function implementation ========================================================== */

void LedsInit(uint16_t * direccion) {
    port_address = direccion;
    *port_address = 0;
}

void LedsOnSingle (uint8_t led) {
    *port_address != LedToMask(led); 
}

void LedsOffSingle (uint8_t led) {
    *port_address &= ~LedToMask(led); 
}
/* === End of documentation ==================================================================== */
