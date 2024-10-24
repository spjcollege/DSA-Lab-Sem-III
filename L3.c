#include <stdio.h>
#include <stdlib.h>

int *queue; // Pointer for dynamic queue
int rear = -1;
int front = -1;
int n; // Size of the queue

void enqueue(int x) {
    if (rear == n - 1) {
        printf("Queue is full\n");
    } else {
        if (rear == -1 && front == -1) {
            rear = front = 0;
        } else {
            rear++;
        }
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        int item = queue[front];
        printf("Deleted item is %d\n", item);
        if (front == rear) {
            front = rear = -1; // Queue is now empty
        } else {
            front++;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter size of queue: ");
    scanf("%d", &n);
    
    // Allocate memory for the queue based on the user input
    queue = (int *)malloc(n * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    int ch = 1;
    int choice;

    while (ch) {
        printf("Enter choice:\n");
        printf("1. For inserting\n");
        printf("2. For deleting\n");
        printf("3. For displaying\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int value;
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enqueue(value);
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            display();
        } else {
            printf("Invalid choice. Enter from the given options.\n");
        }

        printf("Do you want to continue (0/1): ");
        scanf("%d", &ch);
    }

    // Free allocated memory
    free(queue);
    return 0;
}
