#include <stdio.h>
#include <stdlib.h>
int cap;
int *stack;
int top = -1;

int isFull() {
    return top == cap - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int newItem) {
    if (isFull()) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = newItem;
    printf("Item %d pushed to stack\n", newItem);
}

int pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack items are: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter the capacity of stack: ");
    scanf("%d", &cap);
    
    // Dynamically allocate memory for the stack
    stack = (int *)malloc(cap * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    int choice, value;
    do {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped value is %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Top value is %d\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
        }
    } while (choice != 5);

    // Free the allocated memory
    free(stack);
    return 0;
}
