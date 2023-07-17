// Question:-

// There are n people that are split into some unknown number of groups. Each person is labeled with a unique ID from 0 to n - 1.

// You are given an integer array groupSizes, where groupSizes[i] is the size of the group that person i is in. For example, if groupSizes[1] = 3, then person 1 must be in a group of size 3.

// Return a list of groups such that each person i is in a group of size groupSizes[i].

// Each person should appear in exactly one group, and every person must be in a group. If there are multiple answers, return any of them. It is guaranteed that there will be at least one valid solution for the given input.

// Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < groupSizes.size(); i++) {
            int size = groupSizes[i];

            if (groups.count(size)) {
                groups[size].push_back(i);
            } else {
                groups[size] = {i};
            }
        }

        vector<vector<int>> result;

        for (auto& group : groups) {
            int size = group.first;
            vector<int>& members = group.second;

            for (int i = 0; i < members.size(); i += size) {
                result.push_back(vector<int>(members.begin() + i, members.begin() + i + size));
            }
        }

        return result;
    }

};

int main(){
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the number of people: ";
        cin >> n;

        vector<int> groupSizes(n);
        cout << "Enter the group sizes for each person: ";
        for (int i = 0; i < n; i++) {
            cin >> groupSizes[i];
        }

        Solution obj;
        vector<vector<int>> result = obj.groupThePeople(groupSizes);

        cout << "Groups: " << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << "Group " << i + 1 << ": ";
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;

}