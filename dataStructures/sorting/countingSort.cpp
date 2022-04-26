#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> countingSort(vector<int> v, int range)
{
    // your code  goes here
    int n = v.size();
    int arr[range + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        arr[v[i]]++;
    }

    int m = sizeof(arr) / sizeof(int);
    int k = 0;
    for (int j = 0; j < m; j++)
    {
        for (int l = 0; l < arr[j]; l++)
        {
            v[k] = j;
            k++;
        }
    }
    return v;
}

int main()
{
    vector<int> result = countingSort({4, 5, 1, 3, 2, 1, 2, 9, 8, 6, 4, 5, 9}, 9);
    for (auto x : result)
    {
        cout << x << ",";
    }
    return 0;
}