#include <stdio.h>

// Function prototypes
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void printArray(int arr[], int size);

// Menu function
void menu() {
    int choice, n, arr[100];
    do {
        printf("\nMenu:\n");
        printf("1. Selection Sort\n");
        printf("2. Bubble Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // If the choice is valid, get array input
        if (choice >= 1 && choice <= 3) {
            printf("Enter the number of elements: ");
            scanf("%d", &n);
            printf("Enter the elements: ");
            for (int i = 0; i < n; i++)
                scanf("%d", &arr[i]);
        }

        switch (choice) {
            case 1:
                selectionSort(arr, n);
                printf("Sorted array using Selection Sort: ");
                printArray(arr, n);
                break;
            case 2:
                bubbleSort(arr, n);
                printf("Sorted array using Bubble Sort: ");
                printArray(arr, n);
                break;
            case 3:
                insertionSort(arr, n);
                printf("Sorted array using Insertion Sort: ");
                printArray(arr, n);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
}

// Selection Sort implementation
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Bubble Sort implementation
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap if the element found is greater than the next element
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Insertion Sort implementation
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    menu();
    return 0;
}
