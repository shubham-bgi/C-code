#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> optimizedBubbleSort(vector<int> a)
{
    // your code  goes here
    int n = a.size();
    for (int times = 1; times < n; times++)
    {
        bool swapped = false;
        for (int j = 0; j <= n - times - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
    return a;
}

int main()
{
    vector<int> result = optimizedBubbleSort({4, 5, 1, 3, 2});
    for (auto x : result)
    {
        cout << x << ",";
    }
    return 0;
}