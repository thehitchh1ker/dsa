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
void insert_front(Node **head_ref, int val) {
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
        *tracer = create_node(val);
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
    insert_end(&head, 2);
    insert(&head, 2);
    print_list(&head);

    int choice;
	do {
	    printf("\n*****\n");
	    printf("1. Print list\n");
	    printf("2. Insert node at front\n");
	    printf("3. Insert node before the first larger number\n");
	    printf("4. Insert node at end\n");
	    printf("5. Delete node at front\n");
	    printf("6. Delete node at end\n");
	    printf("7. Delete fisrt occurence of a node\n");
	    printf("8. ** To exit **");
	
		printf("\n Enter your choice: ");
		scanf("%d",&choice);
		switch (choice) {
            case 1: printf("List: ");
                    print_list();
					break;
			case 2: insert_front();
					break;
			case 3: insert();
					break;
			case 4: insert_end();
					break;
			case 5: delete_begin();
					break;
			case 6: delete_end();
					break;
			case 7: delete();
					break;
			default:printf("\n Wrong Choice");
                    break;
		}
	} while (choice != 8);
}
