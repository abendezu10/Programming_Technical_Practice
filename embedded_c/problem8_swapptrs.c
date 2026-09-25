/*
 * PROBLEM 8: Swap Two Pointers (via double pointers)
 * ------------------------------------------------------
 * Different scenario, same underlying concept as Problem 7.
 * This tests whether "double pointers let you modify the
 * caller's pointer variable" has actually generalized in your
 * head, or whether it was just memorized for linked lists.
 *
 * You have two Sensor structs already allocated. Write a function
 * that swaps which sensor two POINTERS point to — i.e. after the
 * call, sensor_a and sensor_b in main() should have traded places,
 * without copying/modifying the actual Sensor structs themselves.
 *
 * TASK: implement swap_sensor_ptrs(). Think carefully about:
 *   - What type do the parameters need to be?
 *   - How many dereferences do you need, and where?
 *   - What do you pass at the call site in main()?
 *
 * No hints beyond the comments below — work it out from what you
 * already know about push_front().
 */

#include <stdio.h>

typedef struct {
    int id;
    float reading;
} Sensor;

// TODO: implement this. Swap what *a and *b point to.
void swap_sensor_ptrs(Sensor **sensor_a, Sensor **sensor_b) {

  Sensor *temp = *sensor_a;
  *sensor_a = *sensor_b;
  *sensor_b = temp;
}

int main(void) {
    Sensor s1 = {1, 23.5f};
    Sensor s2 = {2, 88.1f};

    Sensor *sensor_a = &s1;
    Sensor *sensor_b = &s2;

    printf("Before swap: sensor_a->id=%d, sensor_b->id=%d\n",
           sensor_a->id, sensor_b->id);
    printf("(expect: sensor_a->id=1, sensor_b->id=2)\n\n");

    // TODO: call swap_sensor_ptrs with the right arguments
    swap_sensor_ptrs(&sensor_a, &sensor_b);

    printf("After swap:  sensor_a->id=%d, sensor_b->id=%d\n",
           sensor_a->id, sensor_b->id);
    printf("(expect: sensor_a->id=2, sensor_b->id=1)\n");

    return 0;
}
