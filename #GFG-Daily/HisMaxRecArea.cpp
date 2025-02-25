// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1

// Date-> 25/02/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMaxArea(vector<int> &arr)
    {
        int ans = 0;
        int n = arr.size();

        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push(i);
            }
            else if (arr[st.top()] <= arr[i])
            {
                st.push(i);
            }
            else
            {
                int index = st.top();
                st.pop();
                if (st.empty())
                {
                    ans = max(ans, arr[index] * (i));
                }
                else
                    ans = max(ans, arr[index] * (i - st.top() - 1));
                i--;
            }
        }

        while (!st.empty())
        {
            int index = st.top();
            st.pop();
            if (st.empty())
            {
                ans = max(ans, arr[index] * n);
            }
            else
                ans = max(ans, arr[index] * (n - st.top() - 1));
        }

        return ans;
    }
};