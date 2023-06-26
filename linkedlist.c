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
    }
    free(*tracer);
    *tracer = NULL;
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

int main() {
    Node* head = NULL;
    // int arr[] = { 1, 3, 4, 4, 5};
    // int len = sizeof(arr)/sizeof(arr[0]);
    // for (int i = len-1; i >= 0; i--) {
    //     insert_front(&head, arr[i]);
    // }

    int choice, val;
    do {
        printf("\n************\n");
        printf("1. Print list\n");
        printf("2. Insert node at front\n");
        printf("3. Insert node before the first larger number\n");
        printf("4. Insert node at end\n");
        printf("5. Delete node at front\n");
        printf("6. Delete node at end\n");
        printf("7. Delete the first occurence of a node\n");
        printf("8. EXIT");
        printf("\n************\n");

        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nList: ");
                print_list(head);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insert_front(&head, val);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(&head, val);
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d", &val);
                insert_end(&head, val);
                break;
            case 5:
                delete_front(&head);
                break;
            case 6:
                delete_end(&head);
                break;
            case 7:
                printf("Enter value: ");
                scanf("%d", &val);
                delete (&head, val);
                break;
            case 8:
                break;
            default:
                printf("\n Wrong Choice");
                break;
        }
    } while (choice != 8);

    delete_list(&head);
}
