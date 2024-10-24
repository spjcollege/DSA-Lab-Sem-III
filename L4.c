#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int size;

int isFull() {
    return ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)));
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear == size - 1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
    printf("Inserted %d\n", value);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty");
        return -1;
    }
    int data = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == size - 1) {
        front = 0;
    } else {
        front++;
    }
    printf("Deleted %d\n", data);
    return data;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < size; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice, value;
    printf("Enter the size of the queue (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    if (size > MAX_SIZE) {
        printf("Size exceeds maximum limit. Setting size to %d.\n", MAX_SIZE);
        size = MAX_SIZE;
    }
    
    do {
        printf("\nCircular Queue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}
