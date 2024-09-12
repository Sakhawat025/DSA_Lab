#include <bits/stdc++.h>
using namespace std;

int QuartileSearch(int arr[], int L, int R, int T)
{
    if (R >= L)
    {
        int Q1 = L + (R - L) / 4;
        int Q3 = R - (R - L) / 4;

        if (T == arr[Q1]) return Q1;
        if (T == arr[Q3]) return Q3;

        if (T < arr[Q1]){
            return QuartileSearch(arr, L, Q1 - 1, T);
        }
        else if (T < arr[Q3]){
            return QuartileSearch(arr, Q1 + 1, Q3 - 1, T);
        }
        else{
            return QuartileSearch(arr, Q3 + 1, R, T);
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int Key;
    cout << "Search Key value: ";
    cin >> Key;

    int result = QuartileSearch(arr, 0, n - 1, Key);

    if (result != -1){
        cout << "The position of " << Key << " is " << result << endl;
    }
    else{
        cout << "Element not found" << endl;
    }
    return 0;
}
