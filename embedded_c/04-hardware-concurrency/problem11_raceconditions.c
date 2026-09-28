/*
 * PROBLEM 11: Race Conditions — Spot the Bug
 * ----------------------------------------------
 * This is the single most common concurrency interview question,
 * and it's directly relevant to your FreeRTOS work: two tasks (or
 * an ISR and a task) touching the same variable without protection.
 *
 * SCENARIO: Two FreeRTOS tasks both increment a shared counter.
 * Task A runs 100,000 times, Task B runs 100,000 times. You'd
 * expect the final counter to be 200,000. In practice, running
 * this on real hardware (or simulated with real threads), it's
 * almost always LESS than 200,000 — sometimes noticeably so.
 *
 * PART A: Explain why, at the ASSEMBLY/hardware level.
 * `counter++` looks like a single, atomic operation in C. It is
 * NOT. Break down what "counter++" actually compiles to as a
 * sequence of separate CPU steps, and explain how two tasks
 * interleaving those steps can cause an increment to be "lost."
 *
 * PART B: Propose fixes.
 * Name at least TWO different mechanisms you could use to make
 * this safe (a real embedded interview will ask you to name more
 * than one and discuss tradeoffs — e.g. cost, use case). Think
 * about: what's available in FreeRTOS specifically vs. what's
 * available in plain C without an RTOS.
 *
 * PART C (bonus): Would `volatile` on `counter` fix this race?
 * Why or why not? (This is a very common wrong answer to catch.)
 */

#include <stdio.h>
#include <pthread.h>

#define ITERATIONS 5000000

int counter = 0; // shared, unprotected

void *increment_task(void *arg) {
    (void)arg;
    for (int i = 0; i < ITERATIONS; i++) {
        counter++;  // NOT atomic — this is the bug under test
    }
    return NULL;
}

int main(void) {
    pthread_t task_a, task_b;

    pthread_create(&task_a, NULL, increment_task, NULL);
    pthread_create(&task_b, NULL, increment_task, NULL);

    pthread_join(task_a, NULL);
    pthread_join(task_b, NULL);

    printf("Final counter = %d (expected %d)\n", counter, ITERATIONS * 2);

    return 0;
}
