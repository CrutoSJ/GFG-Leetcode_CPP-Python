// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1

// Date-> 20/02/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<double> getMedian(vector<int> &arr)
    {
        vector<double> ans;
        multiset<int> s;
        auto it = s.begin();

        for (int i = 0; i < arr.size(); i++)
        {
            s.insert(arr[i]);

            if (i == 0)
                it = s.begin();
            else if (arr[i] >= *it && i % 2 == 0)
                ++it;
            else if (arr[i] < *it && i % 2 == 1)
                --it;

            if (i % 2 == 0)
            {
                ans.push_back((double)(*it));
            }
            else
            {
                auto nextIt = next(it);
                ans.push_back((*it + *nextIt) / 2.0);
            }
        }
        return ans;
    }
};