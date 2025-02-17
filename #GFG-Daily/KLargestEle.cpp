// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/k-largest-elements4206/1

// Date-> 17/02/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> kLargest(vector<int> &arr, int k)
    {
        vector<int> res;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < arr.size(); i++)
        {
            if (minHeap.size() < k)
            {
                minHeap.push(arr[i]);
            }
            else
            {
                if (minHeap.top() < arr[i])
                {
                    minHeap.pop();
                    minHeap.push(arr[i]);
                }
            }
        }

        while (!minHeap.empty())
        {
            res.push_back(minHeap.top());
            minHeap.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};