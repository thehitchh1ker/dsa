#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node {
    int key;
    struct _node *next;
} Node;

Node *create_node(int val) {
    Node *new_node = malloc(sizeof(Node));
    new_node->key = val;
    new_node->next = NULL;
    return new_node;
}

void print_list(Node **tracer) {
    if (*tracer) {
        printf("%d ", (*tracer)->key);
        print_list(&(*tracer)->next);
    }
    else printf("\n");
}

// inserts an element at the start of the linked list
void push(Node **head_ref, int val) {
    Node *temp = create_node(val);
    temp->next = *head_ref;
    *head_ref = temp;
}

// inserts an element into the linked list before the first larger element
void insert(Node **tracer, int val) {
    if (*tracer && (*tracer)->key < val) {
        insert(&(*tracer)->next, val);
    }
    else { 
        Node *new_node = create_node(val);
        new_node->next = *tracer;
        *tracer = new_node;
    }
}

void insert_end(Node **tracer, int val) {
    if (*tracer)
        insert_end(&(*tracer)->next, val);
    else {
        Node *new_node = create_node(val);

    }
}

int main() {
    int arr[] = { 1, 3, 4, 4, 5};
    int len = sizeof(arr)/sizeof(arr[0]);

    Node *head = NULL;

    for (int i = len-1; i >= 0; i--) {
        push(&head, arr[i]);
    }

    print_list(&head);
    insert(&head, 0);
    print_list(&head);
}
