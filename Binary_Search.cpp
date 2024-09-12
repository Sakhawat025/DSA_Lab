#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int L, int R, int T) {
    if (L <= R) {
        int M = L + (R - L) / 2;
        if (arr[M] == T) {
            return M;
        }
        if (T < arr[M]) {
            return BinarySearch(arr, L, M - 1, T);
        } else {
            return BinarySearch(arr, M + 1, R, T);
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int Key;
    cout << "Search Key value: ";
    cin >> Key;

    int L = 0;
    int R = n - 1;
    int result = BinarySearch(arr, L, R, Key);

    if (result != -1) {
        cout << "The position of " << Key << " is " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
