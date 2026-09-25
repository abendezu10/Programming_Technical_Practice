/*
 * PROBLEM 9: Packed Structs & Bit-Fields
 * ------------------------------------------
 * You already know the compiler inserts padding for alignment
 * (Problem 5). But sometimes you need EXACT control over layout —
 * e.g. when a struct maps directly onto bytes coming over UART,
 * SPI, or a network packet, where the sender and receiver must
 * agree on the exact byte layout, with zero padding.
 *
 * TWO tools solve this:
 *
 *   1. __attribute__((packed)) — tells the compiler "don't insert
 *      ANY padding, lay members out back-to-back no matter what."
 *
 *   2. Bit-fields — let you specify a member takes up exactly N
 *      BITS (not bytes), useful for packing several small values
 *      (flags, small enums) into a single byte/word.
 *
 * SCENARIO: You're defining the on-wire format for a firmware
 * update chunk header (like your real fw_chunk_t). The protocol
 * spec says the header is EXACTLY 6 bytes on the wire:
 *
 *   Byte 0:      chunk_type   (values 0-15, so 4 bits) +
 *                flags        (4 individual 1-bit flags)
 *   Bytes 1-2:   sequence_num (16-bit value)
 *   Bytes 3-6:   payload_len  (32-bit value)
 *
 * Wait — that's actually 7 bytes (1 + 2 + 4). Let's fix the spec:
 * assume payload_len is only 24 bits (3 bytes), giving exactly
 * 1 + 2 + 3 = 6 bytes total.
 *
 * PART A: Without packed/bit-fields, what would
 * sizeof(struct fw_chunk_naive) probably be, and why is that a
 * real problem if you memcpy() this struct directly into a UART
 * TX buffer expecting exactly 6 bytes?
 *
 * PART B: Implement fw_chunk_t using bit-fields for the byte-0
 * flags/type packing, and __attribute__((packed)) on the whole
 * struct so the compiler doesn't insert padding between members.
 * Verify sizeof(fw_chunk_t) == 6.
 */

#include <stdio.h>
#include <stdint.h>

// A "naive" version with no packing control — for Part A discussion.
struct fw_chunk_naive {
    uint8_t  chunk_type;
    uint8_t  flags;
    uint16_t sequence_num;
    uint32_t payload_len;
};

// TODO: Part B. Use bit-fields for chunk_type (4 bits) and 4
// separate 1-bit flags, packed into the byte-0 layout. Use
// __attribute__((packed)) on the struct. payload_len should be
// declared to take exactly 24 bits.
typedef struct {
    // TODO
} fw_chunk_t;

int main(void) {
    printf("sizeof(struct fw_chunk_naive) = %zu (see Part A)\n", sizeof(struct fw_chunk_naive));
    printf("sizeof(fw_chunk_t)            = %zu (target: 6)\n", sizeof(fw_chunk_t));
    return 0;
}
