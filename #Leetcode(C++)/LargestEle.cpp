// #Question:-

// Link-> https://www.codingninjas.com/studio/problems/largest-element-in-the-array-largest-element-in-the-array_5026279

// #Solution:-

#include <bits/stdc++.h> 
using namespace std;

int largestElement(vector<int> &arr, int n) {
    return *max_element(arr.begin(), arr.end());
}
