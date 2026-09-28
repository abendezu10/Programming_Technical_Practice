/*
 * PROBLEM 1d: Swap Without a Temp Variable
 * -------------------------------------------
 * Write a function that swaps the values of *a and *b WITHOUT
 * using a third/temporary variable. Use only XOR.
 *
 * This comes up because it tests whether you actually understand
 * XOR's properties, not just that you can use it. Three properties
 * of XOR make this work:
 *
 *   1. x ^ x = 0        (a value XORed with itself is 0)
 *   2. x ^ 0 = x        (XOR with 0 changes nothing)
 *   3. XOR is its own inverse: if c = a ^ b, then c ^ a = b
 *      and c ^ b = a.
 *
 * The classic pattern is three lines:
 *   *a = *a ^ *b;
 *   *b = *a ^ *b;
 *   *a = *a ^ *b;
 *
 * Don't just memorize that — trace it by hand with a=5, b=9 first,
 * writing out what *a and *b actually hold after EACH line, so you
 * can explain it if an interviewer asks "walk me through why this
 * works" (they will ask this).
 *
 * BONUS gotcha: what happens if someone calls swap(&x, &x) — i.e.
 * a and b point to the SAME variable? Trace that too. Is your
 * function safe against that case? If not, why not, and how would
 * you guard it?
 */

#include <stdio.h>
#include <stdint.h>

void xor_swap(uint32_t *a, uint32_t *b) {
    
    if(a == b)
      return;

    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *b ^ *b;
    // it is c = a ^ b formula
    // And if you use
}

int main(void) {
    uint32_t x = 5, y = 9;
    xor_swap(&x, &y);
    printf("After swap: x=%u (expect 9), y=%u (expect 5)\n", x, y);

    uint32_t z = 42;
    xor_swap(&z, &z); // same-variable edge case
    printf("After self-swap: z=%u (expect 42)\n", z);

    return 0;
}
