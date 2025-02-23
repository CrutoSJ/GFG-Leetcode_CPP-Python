// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

// Date-> 23/02/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= arr[i])
                st.pop();
            if (!st.empty())
                res[i] = st.top();
            st.push(arr[i]);
        }
        return res;
    }
};