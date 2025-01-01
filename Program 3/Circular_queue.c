#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the circular queue

// Circular Queue structure
int queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return (rear + 1) % MAX == front;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to insert an element into the circular queue (enqueue)
void insert(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d.\n", value);
    } else {
        if (front == -1) {
            front = 0;  // First element inserted
        }
        rear = (rear + 1) % MAX;  // Circular increment
        queue[rear] = value;
        printf("%d inserted into the queue.\n", value);
    }
}

// Function to delete an element from the circular queue (dequeue)
int delete() {
    if (isEmpty()) {
        printf("Queue Empty! No elements to delete.\n");
        return -1;  // Return an invalid value when the queue is empty
    } else {
        int deletedValue = queue[front];
        if (front == rear) {
            front = rear = -1;  // Reset the queue when it's empty
        } else {
            front = (front + 1) % MAX;  // Circular increment
        }
        return deletedValue;
    }
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;  // Circular increment
        }
        printf("%d\n", queue[rear]);  // Print the last element
    }
}

// Main function
int main() {
    int choice, value;

    while (1) {
        // Menu for the user
        printf("\nCircular Queue Operations Menu:\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert operation (Enqueue)
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                // Delete operation (Dequeue)
                value = delete();
                if (value != -1) {
                    printf("%d deleted from the queue.\n", value);
                }
                break;
            case 3:
                // Display the queue
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
