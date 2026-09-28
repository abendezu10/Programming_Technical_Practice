#include <stdio.h>

typedef struct {
    int id;
    float reading;
} Sensor;

// Choose the parameter types and implement the swap.
void swap_sensor_ptrs() {
  


}

int main(void) {
    Sensor s1 = {1, 23.5f};
    Sensor s2 = {2, 88.1f};

    Sensor *sensor_a = &s1;
    Sensor *sensor_b = &s2;

    printf("Before: %d, %d\n", sensor_a->id, sensor_b->id);

    // Call swap_sensor_ptrs here.


    printf("After:  %d, %d\n", sensor_a->id, sensor_b->id);
    return 0;
}
