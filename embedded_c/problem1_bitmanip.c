/*
 * PROBLEM 1: Bit Manipulation Warm-up
 * ------------------------------------
 * Write a function that sets, clears, and toggles a specific bit
 * in a register (represented as a uint32_t), and a function to
 * check if a bit is set.
 *
 * This is a VERY common embedded interview opener — it checks that
 * you're comfortable with bitwise ops before going into registers,
 * flags, or peripheral config.
 *
 * TASK:
 * Implement the four functions below. Do not use any library
 * functions — just bitwise operators (&, |, ^, ~, <<, >>).
 *
 * `bit_num` is 0-indexed (bit 0 = LSB).
 */

#include <stdio.h>
#include <stdint.h>

// Set the bit at position `bit_num` in *reg to 1
void set_bit(uint32_t *reg, uint8_t bit_num) {
    // TODO
}

// Clear the bit at position `bit_num` in *reg to 0
void clear_bit(uint32_t *reg, uint8_t bit_num) {
    // TODO
}

// Toggle the bit at position `bit_num` in *reg
void toggle_bit(uint32_t *reg, uint8_t bit_num) {
    // TODO
}

// Return 1 if bit is set, 0 if not
int is_bit_set(uint32_t reg, uint8_t bit_num) {
    // TODO
    return 0;
}

int main(void) {
    uint32_t reg = 0x00000000;

    set_bit(&reg, 3);
    printf("After set_bit(3):    0x%08X (expect 0x00000008)\n", reg);

    set_bit(&reg, 0);
    printf("After set_bit(0):    0x%08X (expect 0x00000009)\n", reg);

    clear_bit(&reg, 3);
    printf("After clear_bit(3):  0x%08X (expect 0x00000001)\n", reg);

    toggle_bit(&reg, 0);
    printf("After toggle_bit(0): 0x%08X (expect 0x00000000)\n", reg);

    toggle_bit(&reg, 5);
    printf("After toggle_bit(5): 0x%08X (expect 0x00000020)\n", reg);

    printf("is_bit_set(reg, 5):  %d (expect 1)\n", is_bit_set(reg, 5));
    printf("is_bit_set(reg, 4):  %d (expect 0)\n", is_bit_set(reg, 4));

    return 0;
}
