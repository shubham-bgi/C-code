#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

vector<pair<int, int>> sortCartesian(vector<pair<int, int>> v)
{
    int N = v.size();
    // your code goes here
    for (pair<int, int> x : v)
    {
            cout <<x.first;
        
    }
    return v;
}

int main()
{
    vector<pair<int, int>> result = sortCartesian({{1, 2}, {3, 2}, {1, 5}});
    // for (auto x : result)
    // {
    //     cout << x << ",";
    // }
    return 0;
}