/*
 * PROBLEM 3: Peripheral Register Configuration
 * ----------------------------------------------
 * You're bringing up a (simulated) UART peripheral. The control
 * register has this made-up layout:
 *
 *   Bit 0        : ENABLE       (1 bit)  - 1 = UART on
 *   Bits 1-3     : BAUD_SEL     (3 bits) - baud rate select code
 *   Bits 4-5     : PARITY       (2 bits) - 00=none, 01=even, 10=odd
 *   Bit 6        : STOP_BITS    (1 bit)  - 0 = 1 stop bit, 1 = 2 stop bits
 *   Bits 7-31    : reserved, must not be touched
 *
 * TASK:
 * Implement uart_init() so that it configures ONLY the bits it's
 * told to configure, leaving bits 7-31 (reserved) completely
 * untouched, no matter what garbage is already sitting in them.
 *
 * You'll want to reuse the read_field/write_field style logic
 * from Problem 2 — but here you're setting multiple fields in one
 * register, so think about whether you can do it with one
 * read-modify-write pass instead of calling write_field() three
 * separate times (both are valid, but think about which a
 * reviewer would prefer and why).
 */

#include <stdio.h>
#include <stdint.h>

#define UART_ENABLE_BIT   0
#define UART_BAUD_SEL_POS 1
#define UART_BAUD_SEL_WIDTH 3
#define UART_PARITY_POS   4
#define UART_PARITY_WIDTH 2
#define UART_STOP_BITS_BIT 6

// Configure the UART control register with the given settings.
// Must NOT disturb bits 7-31 (reserved/unknown contents).
void uart_init(uint32_t *ctrl_reg, uint8_t enable, uint8_t baud_sel,
                uint8_t parity, uint8_t stop_bits) {
    
                   
}

int main(void) {
    // Simulate garbage already sitting in reserved bits (7-31)
    uint32_t ctrl_reg = 0xDEADFF7F; // low byte = 0x7F -> bit7=0 (reserved), bits6-0=garbage to be overwritten

    uart_init(&ctrl_reg, /*enable=*/1, /*baud_sel=*/5, /*parity=*/2, /*stop_bits=*/1);

    printf("ctrl_reg after init: 0x%08X\n", ctrl_reg);
    printf("expect reserved bits (31-7) untouched: 0xDEADFF__ pattern preserved\n");
    printf("expect low byte      : 0b%d %d%d %d%d%d %d\n",
           (ctrl_reg >> 6) & 1, // stop_bits
           (ctrl_reg >> 5) & 1, (ctrl_reg >> 4) & 1, // parity
           (ctrl_reg >> 3) & 1, (ctrl_reg >> 2) & 1, (ctrl_reg >> 1) & 1, // baud
           ctrl_reg & 1); // enable
    printf("expect low byte value: 0x%02X (bit6=1 stop, bits5-4=10 parity, bits3-1=101 baud, bit0=1 enable)\n",
           ctrl_reg & 0xFF);

    return 0;
}