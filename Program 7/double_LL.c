#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct DoublyLinkedList {
    Node* head;
} DoublyLinkedList;

DoublyLinkedList* create_list() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    return list;
}

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void append(DoublyLinkedList* list, int data) {
    Node* new_node = create_node(data);
    if (!list->head) {
        list->head = new_node;
    } else {
        Node* temp = list->head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void insert_left_of(DoublyLinkedList* list, int target, int data) {
    if (!list->head) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp = list->head;
    while (temp && temp->data != target) {
        temp = temp->next;
    }

    if (!temp) {
        printf("Node with value %d not found.\n", target);
        return;
    }

    Node* new_node = create_node(data);
    new_node->next = temp;
    new_node->prev = temp->prev;

    if (temp->prev) {
        temp->prev->next = new_node;
    } else {
        list->head = new_node;
    }

    temp->prev = new_node;
}

void delete_node(DoublyLinkedList* list, int value) {
    if (!list->head) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp = list->head;
    while (temp && temp->data != value) {
        temp = temp->next;
    }

    if (!temp) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    if (temp->prev) {
        temp->prev->next = temp->next;
    } else {
        list->head = temp->next;
    }

    if (temp->next) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

void display(DoublyLinkedList* list) {
    Node* temp = list->head;
    while (temp) {
        printf("%d%s", temp->data, temp->next ? " <-> " : "\n");
        temp = temp->next;
    }
}

int main() {
    DoublyLinkedList* dll = create_list();

    printf("Creating list with values [1, 2, 3, 4]:\n");
    append(dll, 1);
    append(dll, 2);
    append(dll, 3);
    append(dll, 4);
    display(dll);

    printf("Inserting 5 to the left of 3:\n");
    insert_left_of(dll, 3, 5);
    display(dll);

    printf("Deleting node with value 2:\n");
    delete_node(dll, 2);
    display(dll);

    return 0;
}
