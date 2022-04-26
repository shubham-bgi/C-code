#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> kRotate(vector<int> a, int k)
{
    // your code  goes here
    int n = a.size();
    vector<int> x;
    k %= n;
    k = n - k;
    for (int i = k; i < n; i++)
    {
        x.push_back(a[i]);
    }
    for (int i = 0; i < k; i++)
    {
        x.push_back(a[i]);
    }
    return x;
}

int main()
{
    vector<int> z = kRotate({1, 2, 3, 4}, 3);
    for (int i = 0; i < z.size(); i++)
    {
        cout << z[i] << endl;
    }
    return 0;
}