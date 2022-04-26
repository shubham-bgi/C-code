#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> insertionSort(vector<int> v)
{
    // your code  goes here
    int n = v.size();
    int temp;
    for (int i = 1; i < n; i++)
    {
        temp = v[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (v[j] > temp)
            {
                v[j + 1] = v[j];
                v[j] = temp;
            }
            else
            {
                break;
            }
            for (auto x : v)
            {
                cout << x << ",";
            }
            cout << endl;
        }
    }
    return v;
}

int main()
{
    vector<int> result = insertionSort({4, 6, 5, 0, 1, 3, 2});
    // for (auto x : result)
    // {
    //     cout << x << ",";
    // }
    return 0;
}