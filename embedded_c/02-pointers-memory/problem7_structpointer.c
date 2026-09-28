/*
 * PROBLEM 7 (REDO): Pointers to Structs & Double Pointers
 * ----------------------------------------------------------
 * Same problem as before, blanked out. Rebuild it from scratch,
 * without looking at your previous solution.
 *
 * TASK:
 * push_front() should allocate a new node and insert it at the
 * HEAD of the linked list, such that the caller's `list` variable
 * in main() actually gets updated to point at the new node.
 *
 * Fix BOTH:
 *   1. The function signature (what type does `head` need to be?)
 *   2. The function body (two lines need a dereference)
 *   3. The call sites in main() (what do you need to pass in?)
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

// TODO: fix the signature
void push_front(Node **head, int value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    // TODO: fix this line
    new_node->next = *head;
    // TODO: fix this line
    *head = new_node;
}

int main(void) {
    Node *list = NULL;

    // TODO: fix these two calls
    push_front(&list, 10);
    push_front(&list, 20);

    printf("Expected list: 20 -> 10 -> NULL\n");
    printf("Actual list:   ");
    Node *cur = list;
    while (cur != NULL) {
        printf("%d -> ", cur->value);
        cur = cur->next;
    }
    printf("NULL\n");

    return 0;
}
