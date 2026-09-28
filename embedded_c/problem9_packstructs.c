/*
 * PROBLEM 9 (REVISED): Encode a 6-byte firmware header
 *
 * Wire format:
 *   Byte 0: bits 7–4 = chunk_type (0–15)
 *           bits 3–0 = four flags
 *   Byte 1: high byte of sequence_num
 *   Byte 2: low byte of sequence_num
 *   Byte 3: highest byte of payload_len
 *   Byte 4: middle byte of payload_len
 *   Byte 5: lowest byte of payload_len
 *
 * Write encode_header() to fill out[0] through out[5].
 * Use shifts and masks. Do not memcpy a struct or use bit-fields.
 *
 * Test case:
 *   chunk_type  = 0xA
 *   flags       = 0x5
 *   sequence_num = 0x1234
 *   payload_len  = 0x010203
 *
 * Expected bytes: A5 12 34 01 02 03
 */

#include <stdint.h>
#include <stdio.h>

void encode_header(uint8_t out[6],
                   uint8_t chunk_type,
                   uint8_t flags,
                   uint16_t sequence_num,
                   uint32_t payload_len) {
    // Your implementation
}
