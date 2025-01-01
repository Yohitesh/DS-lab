#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

// Queue structure
int queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return rear == MAX - 1;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Function to insert an element into the queue
void insert(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d.\n", value);
    } else {
        if (front == -1) {
            front = 0;  // First element inserted
        }
        rear++;
        queue[rear] = value;
        printf("%d inserted into the queue.\n", value);
    }
}

// Function to delete an element from the queue
int delete() {
    if (isEmpty()) {
        printf("Queue Empty! No elements to delete.\n");
        return -1;  // Return an invalid value when queue is empty
    } else {
        int deletedValue = queue[front];
        front++;
        if (front > rear) {  // Reset queue when all elements are deleted
            front = rear = -1;
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
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, value;

    while (1) {
        // Menu for the user
        printf("\nQueue Operations Menu:\n");
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
