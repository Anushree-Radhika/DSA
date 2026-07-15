#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[]) {
    int count = 0;

    for (int i = 1; i < 20; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // shift
            j--;
            count++;

            // print array after every shift
            for (int k = 0; k < 20; k++)
                printf("%d ", arr[k]);
            printf("\n");
        }
        arr[j + 1] = key;
    }

    printf("\nThe sorted array is:\n");
    for (int i = 0; i < 20; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("%d shifts happened in insertion sort.\n", count);
}



void avoidSwapInsertion(int arr[]) {
    int count = 0;

    for (int i = 1; i < 20; i++) {
        int key = arr[i];
        int j = i - 1;

        // shift-only version (avoid swapping)
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // shift right
            j--;
            count++;

            // print array state
            for (int k = 0; k < 20; k++)
                printf("%d ", arr[k]);
            printf("\n");
        }

        arr[j + 1] = key;
    }

    printf("\nThe sorted array is:\n");
    for (int i = 0; i < 20; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("%d shifts happened in avoid-swap insertion sort.\n", count);
}



int main() {
    int arr1[20] = {22, 20, 81, 38, 95, 84, 99, 12, 79, 44,
                    26, 87, 96, 10, 48, 80, 1, 31, 16, 92};

    int arr2[20] = {1, 16, 12, 26, 25, 35, 33, 58, 45, 42,
                    56, 67, 83, 75, 74, 86, 81, 88, 99, 95};

    printf("MENU\n");
    printf("1. Insertion Sort\n");
    printf("2. Avoid-Swap Insertion Sort\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insertionSort(arr1);
            break;

        case 2:
            avoidSwapInsertion(arr2);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}
