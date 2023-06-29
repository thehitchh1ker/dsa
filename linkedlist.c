#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int key;
    struct _node* next;
} Node;

Node* create_node(int val) {
    Node* new_node = malloc(sizeof(Node));
    new_node->key = val;
    new_node->next = NULL;
    return new_node;
}
void print_list(Node* current) {
    if (current) {
        printf("%d ", current->key);
        print_list(current->next);
    } else
        printf("\n");
}

void insert_front(Node** head_ref, int val) {
    Node* temp = create_node(val);
    temp->next = *head_ref;
    *head_ref = temp;
}

// inserts a node before the first larger element
void insert(Node** tracer, int val) {
    if (*tracer && (*tracer)->key < val) {
        insert(&(*tracer)->next, val);
    } else {
        Node* new_node = create_node(val);
        new_node->next = *tracer;
        *tracer = new_node;
    }
}

void insert_end(Node** tracer, int val) {
    if (*tracer)
        insert_end(&(*tracer)->next, val);
    else {
        *tracer = create_node(val);
    }
}

void delete_front(Node** head_ref) {
    if (*head_ref) {
        Node* old = *head_ref;
        *head_ref = (*head_ref)->next;
        free(old);
    }
}

void delete_end(Node** tracer) {
    if (*tracer && (*tracer)->next) {
        delete_end(&(*tracer)->next);
    } else {
        free(*tracer);
        *tracer = NULL;
    }
}

// delete first occurence of val
void delete(Node** tracer, int val) {
    char present = 0;
    if (*tracer && !(present = (*tracer)->key == val)) {
        delete(&(*tracer)->next, val);
    } else if (present) {
        Node* old = *tracer;
        *tracer = (*tracer)->next;
        free(old);
    }
}

void delete_list(Node** tracer) {
    if (*tracer && (*tracer)->next) delete_list(&(*tracer)->next);
    free(*tracer);
    *tracer = NULL;
}

Node* reverse(Node* head) {
    if (!head || !head->next) return head;
    Node* rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

int main() {
    Node* head = NULL;
    int arr[] = {-5, 1, 3, 2, 2, 7, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = len - 1; i >= 0; i--) {
        insert_front(&head, arr[i]);
    }

    // head = create_node(4);
    // head->next = create_node(2);
    print_list(head);
    head = reverse(head);
    print_list(head);

    delete_list(&head);
}
