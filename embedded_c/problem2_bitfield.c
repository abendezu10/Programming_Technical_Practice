/*
 * PROBLEM 2: Multi-bit Field Read/Write
 * ---------------------------------------
 * Real registers usually don't just have single flag bits — they have
 * multi-bit FIELDS. For example, a UART control register might have
 * a 3-bit "baud select" field starting at bit 4 (bits 4-6).
 *
 * You need to be able to:
 *   1. READ a field of `width` bits starting at bit position `start`
 *   2. WRITE a new value into a field of `width` bits starting at
 *      `start`, WITHOUT disturbing any other bits in the register.
 *
 * Example: reg = 0x00000073 (0111 0011)
 *          field at start=4, width=3  ->  bits 4,5,6 = 1,1,1 = 0b111 = 7
 *
 * TASK: implement both functions below.
 */

#include <stdio.h>
#include <stdint.h>

// Extract a field of `width` bits starting at bit `start` from reg.
// Return it right-aligned (i.e. as a normal integer value).
uint32_t read_field(uint32_t reg, uint8_t start, uint8_t width) {
    // TODO
    return 0;
}

// Write `value` into a field of `width` bits starting at bit `start`
// in *reg, without disturbing any other bits.
// Assume value fits within `width` bits.
void write_field(uint32_t *reg, uint8_t start, uint8_t width, uint32_t value) {
    // TODO
}

int main(void) {
    uint32_t reg = 0x00000073; // 0111 0011

    uint32_t field = read_field(reg, 4, 3);
    printf("read_field(reg, 4, 3) = %u (expect 7)\n", field);

    write_field(&reg, 4, 3, 0x5); // 101
    printf("After write_field(reg, 4, 3, 5): 0x%08X (expect 0x00000053)\n", reg);

    write_field(&reg, 0, 4, 0xF);
    printf("After write_field(reg, 0, 4, 0xF): 0x%08X (expect 0x0000005F)\n", reg);

    return 0;
}
