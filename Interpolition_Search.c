#include <stdio.h>

int main() {
    int n, i, Key, low, high, pos, found = 0;

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
        pos = low+((high-low)/(Arr[high]-Arr[low]))*(Key-Arr[low]);
        if (Arr[pos] == Key) {
            found = 1; // Key found
            break;
        } else if (Arr[pos] < Key) {
            low = pos+ 1; // Increase the lower bound
        } else {
            high = pos - 1; // Decrease the upper bound
        }
    }

    if (found) {
        printf("The key value position is %d\n", pos);
    } else {
        printf("The key value is not found in the array.\n");
    }

    return 0;
}
