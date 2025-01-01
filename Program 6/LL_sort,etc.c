#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list
struct Node* createLinkedList(int n) {
    struct Node *head = NULL, *temp = NULL;
    int data;

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        struct Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    return head;
}

// Function to display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to sort the linked list
void sortLinkedList(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    struct Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("Linked list sorted.\n");
}

// Function to reverse the linked list
struct Node* reverseLinkedList(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    printf("Linked list reversed.\n");
    return prev;
}

// Function to concatenate two linked lists
struct Node* concatenateLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) {
        return head2;
    }

    struct Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    printf("Linked lists concatenated.\n");
    return head1;
}

int main() {
    struct Node *head1 = NULL, *head2 = NULL;
    int choice, n;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Linked List 1\n");
        printf("2. Create Linked List 2\n");
        printf("3. Sort Linked List 1\n");
        printf("4. Reverse Linked List 1\n");
        printf("5. Concatenate Linked List 1 and 2\n");
        printf("6. Display Linked List 1\n");
        printf("7. Display Linked List 2\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes for Linked List 1: ");
                scanf("%d", &n);
                head1 = createLinkedList(n);
                break;
            case 2:
                printf("Enter the number of nodes for Linked List 2: ");
                scanf("%d", &n);
                head2 = createLinkedList(n);
                break;
            case 3:
                sortLinkedList(head1);
                break;
            case 4:
                head1 = reverseLinkedList(head1);
                break;
            case 5:
                head1 = concatenateLists(head1, head2);
                break;
            case 6:
                display(head1);
                break;
            case 7:
                display(head2);
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
