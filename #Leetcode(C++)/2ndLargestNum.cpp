// #Question:-

// Link-> https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

vector<int> getSecondOrderElements(int n, vector<int> a) {
    vector<int>ans;
    sort(a.begin(),a.end());

    ans.push_back(a[n-2]);
    ans.push_back(a[1]);

    return ans;
}
