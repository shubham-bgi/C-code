/*
4, 5, 6, 8
7

=> 6
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> A, int Val) {
    // your code goes here
   int n = A.size();
    int s=0;
    int p = n-1;
    while(p>s){
        int m = (s+p)/2 ;
        if(A[m] >= Val){
            p=m;
        }
        else{
            s = m + 1;
        }
    }
    if(s==0 and Val<A[s]) return -1;
    return A[s];
    
}

int main (){
    cout<< lowerBound({-1, -1, 2, 3, 5}, 4);
    return 0;
}