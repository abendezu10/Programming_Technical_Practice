/*
 * PROBLEM 6: volatile — What It Does and Why
 * ---------------------------------------------
 * `volatile` tells the compiler: "this memory can change for reasons
 * you (the compiler) can't see — don't optimize away reads/writes
 * to it, and don't assume its value stays the same between accesses."
 *
 * This matters in THREE classic embedded scenarios:
 *   1. Memory-mapped hardware registers (a peripheral can change
 *      the value out from under you)
 *   2. Variables shared with an ISR (interrupt handler can change
 *      it at any time, asynchronously to your main code)
 *   3. Variables shared between threads/tasks in an RTOS
 *
 * PART A: Explain the bug.
 * The function below is meant to poll a hardware status register
 * until a "ready" flag is set. Assume STATUS_REG is a real hardware
 * register that an external device sets to 1 when it's ready — the
 * CPU has no other way to know except by reading this address.
 *
 * With optimizations enabled (-O2), this function can hang FOREVER,
 * even once the hardware sets the flag. Explain WHY, in terms of
 * what the compiler is allowed to assume about a plain (non-volatile)
 * uint32_t* that it doesn't see written anywhere in this function.
 *
 * PART B: Fix it with the minimum change needed.
 *
 * PART C: A common misconception — does `volatile` make an access
 * atomic (safe from race conditions)? Does it add any locking?
 * What's the actual difference between volatile and something like
 * a mutex? (One-line answer is fine, but be precise.)
 */

#include <stdint.h>
#include <stdio.h>

#define STATUS_REG_ADDR 0x40001000
#define READY_FLAG      0x1

// Simulate polling a hardware status register until it's ready.
// BUG: as written, an optimizing compiler is allowed to hang here
// forever even if the hardware sets the flag.
void wait_until_ready(uint32_t *status_reg) {
    while ((*status_reg & READY_FLAG) == 0) {
        // spin — waiting for hardware to set the flag
    }
}

int main(void) {
    // (This won't actually do anything meaningful without real
    // hardware or a simulated memory-mapped address — the point
    // of this problem is the explanation and the fix, not the
    // runtime output.)
    printf("See PART A/B/C in the comment above.\n");
    return 0;
}