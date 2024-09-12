#include <bits/stdc++.h>
using namespace std;

int TernarySearch(int arr[], int L, int R, int T)
{
    if (R >= L)
    {
        int M1 = L + (R - L) / 3;
        int M2 = R - (R - L) / 3;


        if (T == arr[M1]) return M1;
        if (T == arr[M2]) return M2;


            if (T < arr[M1])
            {
                return TernarySearch(arr, L, M1 - 1, T);
            }
            else if (T < arr[M2])
            {
                return TernarySearch(arr, M1 + 1, M2 - 1, T);
            }
            else
            {
                return TernarySearch(arr, M2 + 1, R, T);
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

    int result = TernarySearch(arr, 0, n - 1, Key);

    if (result != -1)
    {
        cout << "The position of " << Key << " is " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}
