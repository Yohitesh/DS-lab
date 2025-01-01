#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the stack

// Global variables for stack and top pointer
int stack[MAX];
int top = -1;  // Initial state of the stack (empty)

// Function to check if the stack is full
int isFull() {
    return top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to push an element into the stack
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d onto the stack.\n", value);
    } else {
        stack[++top] = value;  // Increment top and add the value to the stack
        printf("%d pushed onto the stack.\n", value);
    }
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! No elements to pop.\n");
        return -1;  // Return an invalid value when stack is empty
    } else {
        return stack[top--];  // Return and remove the top element
    }
}

// Function to display the elements of the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, value;

    while (1) {
        // Menu for the user
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Push operation
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                // Pop operation
                value = pop();
                if (value != -1) {
                    printf("%d popped from the stack.\n", value);
                }
                break;
            case 3:
                // Display the stack
                display();
                break;
            case 4:
                // Exit the program
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
