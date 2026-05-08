/* Reversing an array using pointers */

#include <stdio.h>

void reverseArray(int *arr, int size) {
    /* TODO: reverse the array arr using pointers */
    for (int n = 0; n < (size+1)/2; n++) {
        int* item1Ptr = arr+n;
        int* item2Ptr = arr+(size-1)-n;
        
        // then swap

        int tempValue1 = *item1Ptr;
        *item1Ptr = *item2Ptr;
        *item2Ptr = tempValue1;
    }
}

int main() {
    int n;
    printf("Enter the number of values: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers: ", n);
    for(int i=0; i< n; i++) {
        scanf("%d", arr+i);
    }

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    reverseArray(arr, n);    

    printf("Reversed Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
