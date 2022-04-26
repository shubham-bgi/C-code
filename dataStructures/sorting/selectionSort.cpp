#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> selectionSort(vector<int> v)
{
    // your code  goes here
    int n = v.size();
    int smallest;
    for (int i = 0; i < n - 1; i++)
    {
        smallest = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[smallest] > v[j])
            {
                smallest = j;
            }
        }
        swap(v[i], v[smallest]);
        for (auto x : v)
        {
            cout << x << ",";
        }
        cout << endl;
    }
    return v;
}

int main()
{
    vector<int> result = selectionSort({4, 6, 5, 0, 1, 3, 2});
    // for (auto x : result)
    // {
    //     cout << x << ",";
    // }
    return 0;
}