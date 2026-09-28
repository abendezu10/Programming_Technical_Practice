/*
 * PROBLEM 10: const and Pointers
 * ----------------------------------
 * `const` combined with pointers has THREE distinct meanings
 * depending on where you put it. This is a classic "explain the
 * difference" interview question, and it matters in real code:
 * function signatures use const to document/enforce "I won't
 * modify this," which is important for driver APIs (e.g. a
 * function that reads a buffer should take `const uint8_t *buf`
 * to signal it never writes to it).
 *
 * PART A: For each declaration below, answer:
 *   - Can you change what the pointer POINTS TO (reassign the pointer)?
 *   - Can you change the VALUE at the address it points to?
 *
 *   1. const int *p1 (a pointer to a constant integer and cannot change the value at the addr)
 *   2. int * const p2 (a constant pointer to an integer and can change the value at the address)
 *   3. const int * const p3 (a const pointer to a constant integer and cannot change any values)
 *
 * (Trick to remember: read the declaration right-to-left from the
 * variable name. "const int *p1" reads as "p1 is a pointer to an
 * int that is const" — the const applies to what's on the LEFT
 * side of the *.)
 *
 * PART B: Find and fix the bugs.
 * The function below is supposed to safely print a buffer's
 * contents without any risk of modifying it. Two lines contain
 * compile errors caused by const violations — a good compiler
 * would refuse to build this. Find both, explain why each is a
 * violation, and fix them (fixing might mean removing an
 * incorrect line rather than changing const-ness).
 */

#include <stdio.h>

void print_buffer(const int *buf, int len) {
    printf("Buffer contents: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", buf[i]);
    }
    printf("\n");

    // BUG 1: this function promised not to modify the buffer.
    buf[0] = 999;
                  

    // BUG 2: another const violation.
    int *writable = buf;  
    writable[1] = 888;   
}

int main(void) {
    int data[3] = {10, 20, 30};
    print_buffer(data, 3);
    return 0;
}
