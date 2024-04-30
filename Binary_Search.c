#include <stdio.h>

int main() {
    int n, i, Key, low, high, mid, found = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int Arr[n]; // Declare the array after knowing its size

    for (i = 0; i < n; ++i) {
        scanf("%d", &Arr[i]);
    }

    printf("Enter key value: ");
    scanf("%d", &Key);

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (Arr[mid] == Key) {
            found = 1; // Key found
            break;
        } else if (Arr[mid] < Key) {
            low = mid + 1; // Increase the lower bound
        } else {
            high = mid - 1; // Decrease the upper bound
        }
    }

    if (found) {
        printf("The key value position is %d\n", mid);
    } else {
        printf("The key value is not found in the array.\n");
    }

    return 0;
}
