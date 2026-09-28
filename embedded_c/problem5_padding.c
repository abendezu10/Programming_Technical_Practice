/*
 * PROBLEM 5: Struct Padding & Alignment
 * ----------------------------------------
 * The compiler doesn't pack struct members back-to-back by default —
 * it inserts padding so each member lands on an address that's a
 * multiple of its own size (its "alignment requirement"). This
 * matters constantly in embedded work: it affects struct size,
 * and it's exactly why your fw_chunk_t in WiFiWare_FOTA needed
 * __attribute__((packed)) for the UART wire format to line up
 * byte-for-byte with what the sender expected.
 *
 * PART A: Predict sizeof() for each struct below BEFORE compiling.
 * Assume a typical 64-bit system:
 *   char   = 1 byte,  alignment 1
 *   short  = 2 bytes, alignment 2
 *   int    = 4 bytes, alignment 4
 *   double = 8 bytes, alignment 8
 *
 * Rule of thumb: each member is placed at the next address that's a
 * multiple of its own alignment; the whole struct's total size is
 * rounded up to a multiple of its LARGEST member's alignment.
 *
 * PART B: Reorder the members of StructC (don't change the types,
 * just the order) to minimize its total size. Report the new size.
 */

#include <stdio.h>

struct StructA {
    char c;
    int i;
    char c2;
}; // 1 + 3 + 4 + 1 + 3 = 12 bytes (6 bytes and 6 byte sof padding)

struct StructB {
    char c;
    char c2;
    int i;
}; // 1 + 1 + 2 + 4 = 8 bytes and 2 bytes of padding

struct StructC {
    char a;
    char c; 
    char e;
    short d;
    double b; 
}; // 1 + 1 + 2 + 1 + 7 + 8 + 4 = 24 bytes total with 11 bytes of padding
   //
   // ne whas 3 bytes of padding and 16 bytes total 

int main(void) {
    printf("sizeof(struct StructA) = %zu\n", sizeof(struct StructA));
    printf("sizeof(struct StructB) = %zu\n", sizeof(struct StructB));
    printf("sizeof(struct StructC) = %zu\n", sizeof(struct StructC));
    return 0;
}
