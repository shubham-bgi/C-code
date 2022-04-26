#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    int arr[] = {4, 6, 5, 0, 1, 3, 2};
    int n = sizeof(arr) / sizeof(int);
    // sort(arr, arr + n, compare);
    sort(arr, arr + n, greater<int>());
    // reverse(arr, arr + n);
    for (auto x : arr)
    {
        cout << x << ",";
    }
    return 0;
}