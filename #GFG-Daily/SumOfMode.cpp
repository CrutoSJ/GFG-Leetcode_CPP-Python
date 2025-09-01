// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/sum-of-mode/1

// Date-> 01/09/25

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();

          unordered_map<int, int> mp;

          map<int, set<int>> mp2;

          long long ans = 0;

          for (int i = 0; i < k; i++) {
              int el = arr[i];

              if (mp.count(el)) {
                  mp2[-mp[el]].erase(el);
                  if (mp2[-mp[el]].size() == 0) mp2.erase(-mp[el]);
              }

              mp[el]++;
              mp2[-mp[el]].insert(el);
          }

          ans = abs(*mp2.begin()->second.begin());

          for (int i = k; i < n; i++) {
              int el = arr[i];

              if (mp[el] > 0) {
                  mp2[-mp[el]].erase(el);
                  if (mp2[-mp[el]].size() == 0) mp2.erase(-mp[el]);
              }

              mp[el]++;

              mp2[-mp[el]].insert(el);

              int oldEl = arr[i - k];

              mp2[-mp[oldEl]].erase(oldEl);

              if (mp2[-mp[oldEl]].size() == 0) mp2.erase(-mp[oldEl]);

              mp[oldEl]--;

              if (mp[oldEl] > 0) mp2[-mp[oldEl]].insert(oldEl);

              int _min = *mp2.begin()->second.begin();
              ans += abs(_min);
          }

          return ans;
        
    }
};
