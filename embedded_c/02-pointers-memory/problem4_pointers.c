    /*
    * PROBLEM 4: Pointer Arithmetic & Array Decay
    * ---------------------------------------------
    * This is the most commonly-tested "do you actually understand C"
    * question. It shows up disguised as "predict the output" or
    * "find the bug" almost everywhere.
    *
    * PART A: Predict the output.
    * Before running anything, write down what you think each printf
    * will print. Pay attention to what TYPE each expression has, not
    * just its value — pointer arithmetic scales by the size of the
    * pointed-to type, not by bytes.
    *
    * PART B: Implement a function.
    * Write array_sum() using ONLY pointer arithmetic (no array
    * indexing with [] allowed) to sum all elements of an int array.
    */

    #include <stdio.h>


    int main(void) {
        int arr[5] = {10, 20, 30, 40, 50};
        int *p = arr;

        // PART A: predict each of these BEFORE running.
        printf("A1: *p            = %d\n", *p); 
        printf("A2: *(p+1)        = %d\n", *(p + 1)); 
        printf("A3: *(arr+2)      = %d\n", *(arr + 2)); 
        printf("A4: arr[3]        = %d\n", arr[3]); 
        printf("A5: *(p+3) - *p   = %d\n", *(p + 3) - *p); 
        printf("A6: p+1 - p       = %ld  (pointer difference, not raw bytes)\n", (long)((p + 1) - p)); // 1
        printf("A7: sizeof(arr)   = %zu\n", sizeof(arr)); 
        printf("A8: sizeof(p)     = %zu\n", sizeof(p)); 

        return 0;
    }

